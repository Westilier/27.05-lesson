﻿#include <iostream>


void AddColInTwiceArray(size_t** arr, size_t* cols, size_t* rows, size_t position)//фунция из задания
{
    *cols += 1;
    arr[*cols - 1] = new size_t[*rows];
    for (size_t i = *cols - 1; i > position; --i)
    {
        for (size_t j = 0; j < *rows; ++j)
        {
            arr[j][i] = arr[j][i - 1];
        }
    }
    for (size_t i = 0; i < *rows; ++i)
    {
        arr[i][position] = 0;
    }
}

void OutputTwiceArray(size_t** arr, size_t* cols, size_t* rows)
{
    for (size_t i = 0; i < *rows; ++i)
    {
        for (size_t j = 0; j < *cols; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void InitializationTwiceArray(size_t** arr, size_t* cols, size_t* rows)
{
    size_t x = 1;
    for (size_t i = 0; i < *rows; ++i)
    {
        for (size_t j = 0; j < *cols; ++j)
        {
            arr[i][j] = x++;
        }
    }
}

int main()
{
    size_t rows = 5;
    size_t* ptrrows = &rows;
    size_t cols = 5;
    size_t* ptrcols = &cols;
    size_t** array = new size_t* [cols];
    for (size_t i = 0; i < cols; i++)
    {
        array[i] = new size_t[rows];
    }

    InitializationTwiceArray(array, ptrcols, ptrrows);

    OutputTwiceArray(array, ptrcols, ptrrows);

    size_t position = 3;
    AddColInTwiceArray(array, ptrcols, ptrrows, position);

    OutputTwiceArray(array, ptrcols, ptrrows);

    return 0;
}