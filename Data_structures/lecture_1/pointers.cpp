/**
 * To dynamically allocate memory in c++
 * we have the new operator which wroks exactly like malloc in c
 * 
 * we need a pointer in order to use new, for example:
 *      int *ptr = new int;  ==> single memory block
 *      int *pter = new int[size] ==> more than one memory block (size)
 * 
 * after allocating we need to free that memory by using delete operator
 * freeing the memory is very important to avoid memory leaks
 * for example:
 *      delete ptr; ==> deleting a single memory block
 *      delete []ptr ==> to delete multiple memory blocks
 *      *note* when deleting multi the brackets coms before the pointer name!!
 */

#include <iostream>
using namespace std;

int main()
{
    int size;
    int *numbers;

    cout << "Enter number of elements\n";
    cin >> size;

    numbers = new int[size];
    for(int i = 0; i < size; i++)
        cin >> numbers[i];
    for(int i = 0; i < size; i++)
        cout << numbers[i];
    delete []numbers;
    return 0;   
}