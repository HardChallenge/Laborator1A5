#include <unistd.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>
#include <stdexcept>
using std::string, std::function, std::map, std::vector;

class MyException : public std::exception
{
protected:
    string error;
    string name;

public:
    MyException();
    MyException(string error) : error(error)
    {
        MyException::what();
    }

    const char *what() noexcept
    {
        return error.c_str();
    }
};

class OpenFileException : public MyException
{
public:
    OpenFileException(string name) : MyException("Cannot open file: " + name)
    {
        std::cout << error << "\n";
    }
};
class ReadFileException : public MyException
{
public:
    ReadFileException(string name) : MyException("Cannot read from file: " + name)
    {
        std::cout << error << "\n";
    }
};
class WriteFileException : public MyException
{
public:
    WriteFileException(string name) : MyException("Cannot write on file: " + name)
    {
        std::cout << error << "\n";
    }
};

class CommandManager
{
private:
    map<string, function<void(vector<string>)>> commands;

public:
    void add(string name, function<void(vector<string>)> fn);

    void run();
};

void CommandManager::add(string name, function<void(vector<string>)> fn)
{
    commands[name] = fn;
}

void CommandManager::run()
{

    string name, word = "";
    map<string, function<void(vector<string>)>>::iterator it;
    bool ok = false;
    vector<string> vector;

    while (1)
    {
        std::getline(std::cin, name);
        if (name == "stop")
            return;

        for (auto i : name)
        {
            if (i == ' ')
            {
                if (word != "")
                {
                    vector.push_back(word);
                    word = "";
                }
            }

            else
                word += i;
        }
        vector.push_back(word);

        it = commands.find(vector[0]);
        try
        {
            if (it != commands.end())
            {
                vector.erase(vector.begin());
                ok = true;
                it->second(vector);
            }
        }
        catch (MyException &e)
        {
        }

        if (ok == false)
        {
            printf("Can't find the function!\n");
        }
        ok = false;
        vector.clear();
        word = "";
    }
}

int main()
{
    CommandManager manager;

    auto ping = [](vector<string> args)
    { printf("pong!\n"); };
    manager.add("ping", ping);

    auto count = [](vector<string> args)
    { printf("Counted %lu args.\n", args.size()); };

    manager.add("count", count);

    auto append = [](vector<string> args)
    {
        if (access(args[0].c_str(), F_OK) == -1)
        {
            throw OpenFileException(args[0]);
        }
        FILE *fd = fopen(args[0].c_str(), "a");
        for (int i = 1; i < args.size(); i++)
        {
            if (fprintf(fd, args[i].c_str()) < 0)
            {
                fclose(fd);
                throw WriteFileException(args[0]);
            }
            if (fprintf(fd, " ") < 0)
            {
                fclose(fd);
                throw WriteFileException(args[0]);
            }
        }
        fclose(fd);
    };
    manager.add("append", append);

    auto times = [](vector<string> args) {

    };
    manager.add("times", times);

    auto copy = [](vector<string> args)
    {
        if (args[0] == "" || args[1] == "")
        {
            throw ReadFileException(args[0]);
        }
        if (access(args[0].c_str(), F_OK) == -1 || access(args[1].c_str(), F_OK) == -1)
        {
            throw OpenFileException(args[0]);
        }
        auto source = fopen(args[0].c_str(), "r");
        auto destination = fopen(args[1].c_str(), "w");
        char ch;
        while ((ch = fgetc(source)) != EOF)
            fputc(ch, destination);

        fclose(source);
        fclose(destination);
    };
    manager.add("copy", copy);

    auto sort_size = [](vector<string> args)
    {
        std::sort(args.begin(), args.end(), [](string a, string b)
                  { return a.size() < b.size(); });
        std::for_each(args.begin(), args.end(), [](string args)
                      { std::cout << args << " "; });

        std::cout << '\n';
    };
    manager.add("sort_size", sort_size);

    auto resize = [](vector<string> args)
    {
        args.erase(args.begin());
        args.pop_back();
        for (int i = 0; i < args.size(); ++i)
            std::cout << args[i] << " ";
        std::cout << "\n";
    };

    manager.add("resize", resize);

    auto alloc = [](vector<string> memory)
    {
        long long size = stoi(memory[0]);
        if (size <= 0)
            throw std::runtime_error("You cannot allocate a negative amount of bytes!");
        long pages = sysconf(_SC_PHYS_PAGES);
        long page_size = sysconf(_SC_PAGE_SIZE);
        std::cout << pages * page_size;
        if (size > pages * page_size)
            throw std::runtime_error("Your memory < the amount you want to allocate :(");

        auto x = malloc(size);
    };

    manager.add("alloc", alloc);

    manager.run();
}