#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>
#include"Buttons.h"
#include<vector>

std::vector<std::string> Initialize();
std::vector<std::string> ReadFromFile(const char* inputPath);
const char* FindPath();
int WhatType(std::string X, int Datasize);