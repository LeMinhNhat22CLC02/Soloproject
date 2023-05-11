#include<iostream>
#include<fstream>
#include<SFML/Graphics.hpp>
#include<string>
#include"Buttons.h"
#include"TextBox.h"
#include"external/tinyfiledialogs.h"

#define ENTER_KEY 13

std::vector<std::string> Initialize()
{
    srand((int)time(NULL));
    std::vector<std::string> Temp;

    Temp.push_back(std::to_string(rand() % 100));
    Temp.push_back(std::to_string(rand() % 100));
    Temp.push_back(std::to_string(rand() % 100));
    Temp.push_back(std::to_string(rand() % 100));

    return Temp;
}

std::vector<std::string> ReadFromFile(const char* inputPath)
{
    std::ifstream file(inputPath);
    std::vector<std::string> Temp;
    std::string ToAdd;
    while (file >> ToAdd)
    {
        Temp.push_back(ToAdd);
    }
    file.close();
    return Temp;
}

const char* FindPath()
{
    const char* inputPath = tinyfd_openFileDialog("Open File", "", 0, NULL, NULL, 0);
    return inputPath;
}

int WhatType(std::string X, int Datasize)
{
    for (int i = 0; i < X.size(); i++)
        if ('0' > X[i] || '9' < X[i]) return 2;
    if (X.size() > 3) return 1;
    int Temp = 0;
    for (int i = 0; i < X.size(); i++)
        Temp = Temp * 10 + (int)(X[i] - '0');
    return (Temp > Datasize);
}