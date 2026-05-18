#include <iostream>

int* Foo(int a) {

    int* pa = new int(a);

    std::cout << "Значение: " << *pa << std::endl;
    return pa;
}

int* FooArr(int SIZE)
{
    int* pArr = new int[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        pArr[i] = i * 10;
    }
    return pArr;
}

void FooDelete(int *ptr)
{
    delete ptr;
}

void* FooPrint(int size, int *arr)
{
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        std::cout << " ";
    }
    std::cout << std::endl;
    return arr;
}

void FooDeleteArr(int *parr)
{
    delete[] parr;
}

int* FooAppend(int* arr, int& size, int newValue)
{
    int* newArr = new int[size + 1];

    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }

    newArr[size] = newValue;
    size++;

    return newArr;  
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int size = 5;

    int* p = (int*)Foo(77);

    std::cout << "\nИзначальный массив: ";
    int* arr = (int*)FooArr(size);
    FooPrint(size, arr);

    std::cout << "\nИзмененный массив: ";
    arr = FooAppend(arr, size, 777);
    FooPrint(size, arr);
  
    FooDelete(p);
    FooDeleteArr(arr);
    return 0;
}

