#include <fstream>
#include <iostream>
#include "../include/LibApp.h"
#include "../include/Date.h"
#include "../include/Menu.h"
using namespace myproject;
void runApp(const char *filename)
{
   size_t i{};
   char ch;
   char original[31] = "orig";
   // creating original file name
   while (filename[i])
      original[4u + i] = filename[i++];
   original[4u + i] = char(0);
   // copying original values to data file;
   std::ofstream outFile(filename);
   std::ifstream inFile(original);
   while (inFile.get(ch))
   {
      outFile << ch;
   }
   outFile.close();
   inFile.close();
   // setting test values
   myproject::sdds_day = 10;
   myproject::sdds_mon = 8;
   myproject::sdds_year = 2023;
   myproject::sdds_test = true;
   myproject::LibApp app(filename);
   app.run();
   std::cout << "Content of " << filename << "\n=========>\n";
   inFile.open(filename);
   while (inFile.get(ch))
      std::cout << ch;
   std::cout << "<=========\n";
}
int main()
{
   Menu outFile("Select Data File");
   outFile << "../data/LibRecsSmall.txt"
           << "../data/LibRecs.txt";
   switch (outFile.run())
   {
   case 1:
      std::cout << "Test started using small data: " << std::endl;
      runApp("../data/LibRecsSmall.txt");
      break;
   case 2:
      std::cout << "Test started using big data: " << std::endl;
      runApp("../data/LibRecs.txt");
      break;
   default:
      std::cout << "Aborted by user! " << std::endl;
      break;
   }
   return 0;
}