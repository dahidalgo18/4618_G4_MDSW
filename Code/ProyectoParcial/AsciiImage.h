#pragma once
#include <string>
#include <vector>
#include <Windows.h>
#include <cwchar>
#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>

class AsciiImage
{
private:
	cv::Mat image{ 0 };
	int type{ 0 };
	std::string ascii;

public:
	AsciiImage(const std::string, const int);
	void showAscii();
	void consoleFont(int, int);
	void grayColor();
	std::string charAscii(int);
	inline void intensity();
	void resize(int, int);
	void generateFile(std::string);
};



