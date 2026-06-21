// Brett Rogers May 11th, 2026
// Time to make a string slice, string view

#include "StringView.h"

int main()
{
    StringView theView = ToSlice("Hello World");
    Dialouge(&theView);
}