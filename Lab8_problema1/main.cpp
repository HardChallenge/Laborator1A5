#include<string>
#include<iostream>
#include<map>
#include<queue>
using namespace std;

char toLower(char x)
{
    if(x>='A' && x<='Z') x+=32;
    return x;
}

using myComparator = bool(*)(string& a, string& b);

bool myCompare(string& a, string& b)
{
    for ( int i = 0; i<std::min(a.size(), b.size()); ++i)
    {
        if(a[i]>b[i]) return true;
        if(a[i]<b[i]) return false;
    }
    if(a.size() > b.size() ) return true;
            else return false;
}

int main()
{
   string str, word="";
   map<string, int> map;
   priority_queue<string, vector<string>, myComparator> coada(myCompare);
   FILE* source;
   int x;
   char array[256];
   source = fopen("lab8.txt", "r");
   if ( source == nullptr ) {perror("Eroare : "); return 1;}
            else 
                    {
                        while(true){
                            x = fscanf(source, "%s", array);
                            if(x==1) {str += array;
                                    str += " ";
                                }
                                else break;
                        }
                    }

    
     for ( auto i : str )
     {
        if (i == ' ' || i == '!' || i == '?' || i == '.') {map[word]++; word="";}
            else word += toLower(i);
     }

     for ( auto i = map.begin(); i!=map.end(); ++i)
     {
         coada.push(i->first);
     }

    while(!coada.empty())
    {
        cout<<coada.top()<< "=>" << map[coada.top()]<<"\n";
        coada.pop();
    }

    return 0;
}