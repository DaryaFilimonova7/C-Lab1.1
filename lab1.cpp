#include <iostream>


// Bubble Sort

template <typename T>
void bubble_sort(T arr[], int idx_start, int idx_end)
{
    // счет подходов, их общее кол-во равно кол-ву элементов в массиве
    for (int n= idx_start;n < idx_end;n++)
    {
        // в подходе меняем местами, если эл-т больше следующего
        for (int i = idx_start; i < idx_end; i++)
        {
            if (arr[i]>arr[i+1])
            {
                std::swap(arr[i],arr[i+1]);
            }
        }
    }
    std::cout << "A sorted array is";
    for (int i = 0;i<idx_end+1;i++)
    {
        std::cout << " " << arr[i];
    }
}


// Insertion Sort

template <typename T>
void insertion_sort(T arr[], int idx_start, int idx_end)
{
    // начинаем сортировку со 2го элемента, тк 1ый сместится на свое место в процессе
    for (int i = 1; i <= idx_end; i++)
    {
        int element = arr[i];           // выбираем эл-т
        int idx_right = i-1;
        // сравниваем с элем-том справа, пока не пришли к началу
        while (arr[idx_right] > element && idx_right >= idx_start)
        {
            arr[idx_right+1]=arr[idx_right];            // меняем выбранный элемент
            idx_right = idx_right -1;           // перемещаемся вправо
        }
        arr[idx_right+1] = element;             //меняем правый эл-т
    }

    std::cout << "A sorted array is";
    for (int i = 0;i<idx_end+1;i++)
    {
        std::cout << " " << arr[i];
    }
}


// Selection Sort

template <typename T>
void selection_sort(T arr[], int idx_start, int idx_end)
{
    for (int n=idx_start; n<idx_end+1;n++)
    {
        int idx_min = n;
        // поиск индекса минимального эл-та
        for (int i= n+1;i<idx_end+1;i++)
        {
            if (arr[i] < arr[idx_min])
            {
                idx_min = i;
            }
        }
        // перемещаем минимальный эл-т на позицию
        std::swap(arr[idx_min],arr[n]);
    }

    std::cout << "A sorted array is";
    for (int i = 0;i<idx_end+1;i++)
    {
        std::cout << " " << arr[i];
    }
}

int main() {
    {
        std::cout << "Bubble sort \n";
        int arr[6]={6,4,3,1,2,9};
        int size_arr = sizeof(arr)/sizeof(arr[0]);
        // вывод исходного массива
        for (int i = 0; i < size_arr; ++i)
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        bubble_sort(arr,0,size_arr-1);
    }
    std::cout << "\n";
    {
        std::cout << "Insertion sort \n";
        int arr[10]={6,7,14,1,4,9, 11, 2, 16, 3};
        int size_arr = sizeof(arr)/sizeof(arr[0]);
        // вывод исходного массива
        for (int i = 0; i < size_arr; ++i)
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        insertion_sort(arr,0,size_arr-1);
    }
    std::cout << "\n";
    {
        std::cout << "Selection sort \n";
        int arr[10]={8,27,14,1,14,46, 11, 2, 16, 3};
        int size_arr = sizeof(arr)/sizeof(arr[0]);
        // вывод исходного массива
        for (int i = 0; i < size_arr; ++i)
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        selection_sort(arr,0,size_arr-1);
    }


    return 0;
}
