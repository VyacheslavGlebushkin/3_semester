#include <iostream>
#include "strutil.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    char a1[] = "H";
    char str1[] = "Hello, world!";
    char a2[] = "wor";
    char str2[] = "Hello, world!";
    char a3[] = "MAI";
    char str3[] = "Hello, world!";
    cout << "Найти символ в начале: " << strConteins(a1, str1) << endl;
    cout << "Найти символы в середине: " << strConteins(a2, str2) << endl;
    cout << "Найти символы, которых нет: " << strConteins(a3, str3) << endl;
    return 0;
}