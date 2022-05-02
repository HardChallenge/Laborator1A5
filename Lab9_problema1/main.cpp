#include<iostream>


template<typename Key, typename Value>
struct Element{
  Key key;
  Value value;
  unsigned index;
};

template<typename Key, typename Value>
struct Map{
    Element<Key, Value> array[40];
    int count = 0;
    Value& operator[](Key index)
    {
        for(int i = 0; i<count; i++)
        {
            if(array[i].key == index) return array[i].value;
        }
        array[count].index = count;
        array[count].key = index;
        ++count;
        return array[count-1].value;

    }

    Element<Key, Value>* begin()
    {
        return array;
    }

    Element<Key, Value>* end()
    {
        return array + count;
    }

    
};
int main()
{

    Map<int, const char *> m;

    m[10] = "C++";

    m[20] = "test";

    m[30] = "Poo";

    for (auto [key, value, index] : m)

    {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }

    m[20] = "result";

    for (auto[key, value, index] : m)

    {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }

    return 0;

}