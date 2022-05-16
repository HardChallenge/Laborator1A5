#include <unistd.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>
#include <stdexcept>
using std::string, std::function, std::map, std::vector;
// the CommandManager class should implement a mini terminal that receive commands and dispatches them.
// example: copy a.jpg b.jpg
// this will search the map for a "copy" command, and if it finds it, it will invoke its callback with a vector made of {"a.jpg", "b.jpg"}
// no global variables allowed

class CommandManager
{
private:
    map<string, function<void(vector<string>)>> commands;

public:
    void add(string name, function<void(vector<string>)> fn);

    // run shall read a line from stdin in a loop, split it by whitespaces.
    // the first word will be the command name. if no word has been found, it will do nothing
    // then it will search the map for the name, and it will invoke the callback if it founds it
    // or it will show a message if it can't find it
    // the args for the callback will not contain the command name
    // if the `stop` command is found, the function will return
    // try doing this yourself; if you spent too much time on this, look at https://gist.github.com/xTachyon/9e698a20ce6dfcae9a483b28778af9fb
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
        catch (std::exception &e)
        {
            fprintf(stderr, e.what());
            printf("\n");
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
            throw std::runtime_error("The file doesn't exist!");
        }
        FILE *fd = fopen(args[0].c_str(), "a");
        for (int i = 1; i < args.size(); i++)
        {
            if (fprintf(fd, args[i].c_str()) < 0)
            {
                fclose(fd);
                throw std::runtime_error("Cannot write a character!");
            }
            if (fprintf(fd, " ") < 0)
            {
                fclose(fd);
                throw std::runtime_error("Cannot write a blank space!");
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
            throw std::runtime_error("Give the file's names!");
        }
        if (access(args[0].c_str(), F_OK) == -1 || access(args[1].c_str(), F_OK) == -1)
        {
            throw std::runtime_error("One of the specified files doesn't exist!");
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

    manager.run();
}