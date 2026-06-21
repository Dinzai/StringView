
#pragma once
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct StringSlice
{
    const char *buffer;
    int count;
} StringView;

StringView ToSlice(const char *word)
{
    StringView view;
    view.buffer = word;
    view.count = strlen(word);
    return view;
}

void ChopLeft(StringView* view)
{
    view->buffer++;
    view->count--;
}

void ChopRight(StringView* view)
{
    if(view->count > 0)
    {
        view->count--;
    }    
}

char PlaceRight(StringView* view)
{
    
    return view->buffer[view->count];   
}

void PrintView(StringView* view)
{
    printf("%.*s", view->count, view->buffer);
}

clock_t previousTime;

float DeltaTime()
{
    clock_t currentTime = clock();
    float deltaTime = (float)(currentTime - previousTime) / CLOCKS_PER_SEC;
    previousTime = currentTime;
    return deltaTime;

}

void Dialouge(StringView* view)
{
    float dt = 0;
    float timer = 0;
    float speed = 10.0f;
    

    int originalCount = view->count;
    while(view->count > 0)
    {
        ChopRight(view);
    }

    while(view->count < originalCount)
    {
        dt = DeltaTime();    
        if(timer > 2.00)
        {
            printf("%c", PlaceRight(view));    
            fflush(stdout);
            view->count++;    
            timer = 0;
            dt = 0;
        }
        else
        {
            timer += speed * dt;
        }

    }
    printf("\n");

}