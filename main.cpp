#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

std::chrono::microseconds bubbleSort (std::vector<unsigned int> &vec)
{
    /*Get Start Time*/
    auto startTime = std::chrono::high_resolution_clock::now();

    /*Bubble Sort*/
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        for(size_t j = 0; j < vec.size() - i - 1; j++)
        {
            if (vec[j] > vec[j + 1]) //If first element is not less than or equal to
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }

    /*Get End Time*/
    auto endTime = std::chrono::high_resolution_clock::now();

    /*Get and Print Duration*/
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    std::cout << "Bubble sort took " << duration.count() << " microseconds.\n";

}

std::chrono::microseconds selectionSort (std::vector<unsigned int> &vec)
{

    /*Get Start Time*/
    auto startTime = std::chrono::high_resolution_clock::now();

    /*Selection Sort*/
    size_t minIndex;
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        minIndex = i;
        for (size_t j = minIndex + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(vec[minIndex], vec[i]);  
    }

    /*Get End Time*/
    auto endTime = std::chrono::high_resolution_clock::now();

    /*Get and Print Duration*/
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    std::cout << "Selection sort took " << duration.count() << " microseconds.\n";
}

std::chrono::microseconds insertionSort (std::vector<unsigned int> &vec)
{

    /*Get Start Time*/
    auto startTime = std::chrono::high_resolution_clock::now();

    /*Insertion Sort*/
    unsigned int insert;
    int insertIndex;
    for (size_t i = 1; i < vec.size(); i++)
    {
        insert = vec[i];
        insertIndex = i - 1;
 
        while(insertIndex >= 0 && vec[insertIndex] > insert)
        {
            vec[insertIndex + 1] = vec[insertIndex];
            insertIndex--;
        }
        vec[insertIndex + 1] = insert;
    }

    /*Get End Time*/
    auto endTime = std::chrono::high_resolution_clock::now();

    /*Get and Print Duration*/
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    std::cout << "Insertion sort took " << duration.count() << " microseconds.\n";
}

void initVector(std::vector<unsigned int> &vec, std::string filepath)
{
    /*Clear Vector*/
    vec.clear();

    /*Open Data File and Error Check*/
    std::fstream dataFile(filepath);
    std::string line;
    if (!dataFile.is_open())
    {
        std::cout << "Error " << filepath << " not found!\n";
        return;
    }

    /*Copy Data Into Vector*/
    while (std::getline (dataFile, line))
    {
        vec.push_back(strtoul(line.c_str(), nullptr, 0)); //strtoul converts the string into an unsigned int
    }
}

int main()
{

    std::vector<unsigned int> vec;
    std::string filepath;
    size_t selection;
    
    /*Get Data File Path and Init Vector*/
    std::cout << "Sort Analyzer!\nPlease enter the file to sort: ";
    std::cin >> filepath;
    std::cout << std::endl;
    initVector(vec, filepath);



    /*Bubble Sort*/
    std::chrono::microseconds average = std::chrono::duration_cast<std::chrono::microseconds>((bubbleSort(vec) + bubbleSort(vec) + bubbleSort(vec)) / 3);
    std::cout << "The average is " << average << " microseconds.\n";


    std::string a;
    std::cin >> a;


    return 0;
}