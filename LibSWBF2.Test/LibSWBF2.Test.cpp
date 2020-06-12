// LibSWBF2.Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

using LibSWBF2::Chunks::MSH::MSH;
using LibSWBF2::Tools::Level;

int main()
{
	Level* lvl = Level::FromFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Star Wars Battlefront II\\GameData\\data\\_lvl_pc\\geo\\geo1.lvl");

	std::cout << "Loaded" << (lvl != nullptr ? "TRUE" : "FALSE") << std::endl;

	Level::Destroy(lvl);

	//MSH* msh = MSH::Create();
	//const size_t size = sizeof(MSH);

	//std::cout << "sizeof(MSH) : " << size << std::endl;

	//std::ofstream stream;
	//stream.open("MSHdump.bin", std::ofstream::out | std::ofstream::binary | std::ofstream::trunc);
	//const bool success = stream.good() && stream.is_open();
	//if (!success)
	//{
	//	std::cout << "could not create file!" << std::endl;
	//	stream.close();
	//	return 0;
	//}
	//stream.write((char*)msh, size);
	//stream.close();
	//std::cout << "dumped binary!" << std::endl;

	//MSH::Destroy(msh);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
