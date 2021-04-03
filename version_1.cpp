#include <iostream>
#include <iterator>

using namespace std;

class PseudoArr
{
 private:
    int* arr;
 public:
    PseudoArr(int arrSize) : arr(nullptr)
    {
        if(arrSize > 0)
        {
            arr = new int[arrSize];
        }
    }

    PseudoArr(std::initializer_list<int> myList) : arr(nullptr)
    {
        int length = myList.size();
        if(length > 0)
        {
            arr = new int[length];
            int i = 0;
            for(std::initializer_list<int>::iterator iter = myList.begin(); iter != myList.end(); iter++, i++)
            {
                arr[i] = *iter;
            }
        }
    }

    ~PseudoArr()
    {
        if(arr)
        {
            delete[] arr;
        }
    }

    int& operator[](int i)
    {
        return arr[i];
    }
};

int main()
{
    PseudoArr myArr({1, 5, 3, 2, 8});
    for(int i = 0; i < 5; i++)
    {
        cout << myArr[i] << "  ";
    }
    cout << endl;
    return 0;
}
