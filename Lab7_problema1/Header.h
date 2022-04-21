template <typename T>
class vector
{
    T* elements;
    T count;
    public:
    vector(){
        count=0;
        elements=(T*)malloc(sizeof(T));
        memset(elements, 0, 4);
     }
    
    void Push(T element)
    {
      elements=(T*)realloc(elements, (count+1)*sizeof(T));
      elements[count++]=element;
    }
    T Pop()
    {
        elements=(T*)realloc(elements, (count)*sizeof(T));
        --count;
        return elements[count+1];
    }
    void Delete(T index)
    {
        if(index==count) {
            elements=(T*)realloc(elements, count*sizeof(T));
            elements[count]=0; 
            }
            else {
                for(int i=index;i<count-1;i++) elements[i]=elements[i+1];
                elements=(T*)realloc(elements, count*sizeof(T));
            }

        --count;
    }
    void Insert(T index, T x)
    {
        elements=(T*)realloc(elements, (count+1)*sizeof(T));
        if(index>=count){
            ++count;
            elements[count-1]=x;
        }
        else {
            for(int i=count-1;i>=index;i--) elements[i+1]=elements[i];
            elements[index]=x;
            ++count;
        }


    }

    void Print()
    {
        for(int i=0;i<count;i++) std::cout << "Elementul de pe pozitia " << i+1 << " este " << elements[i] << "\n";
    }
    const T& get();
    void set();
    

};


