/*
**Author: Ricardo J. Cantarero
**Program: main.cpp
**Description: Parses out R Source code from an R Markdown File
**
*/
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

bool isValid(const std::string &, char); // check validity of filename
void convertrmdtor(const std::string &, const std::string &);

int main(int argc, char **argv) {

  if (argc == 1) {
    std::cerr << "Program requires input: *rmarkdownile*.rmd *targetrfile*.r\n";
    return 1;
  }

  if (argc == 2) {
    std::cerr << "Program requires second input: *rmarkdownfile*.rmd "
                 "*targetrfile*.r\n";
    return 1;
  }
  if (argc > 3) {
    std::cerr << "Program requires ONLY two inputs: *rmarkdownfile*.rmd "
                 "*targetrfile*.r\n";
    return 1;
  }

  const std::string inputFileName{argv[1]}; // Declare input file name as string

  if (!isValid(
          inputFileName,
          'I')) { // Check if the file name ends with rmd and is otherwise valid
    std::cerr << "Proposed Input File: " << inputFileName << " is invalid!\n";
    return 1;
  }

  std::ifstream inf(inputFileName);

  if (!inf) { // try to open file
    std::cerr << "Input File: " << inputFileName << " could not be read!\n";
    return 1;
  }

  inf.close();

  std::string outputFileName{argv[2]}; // same for output filek
                                       //
  if (!isValid(outputFileName, 'O')) {
    std::cerr << "Proposed Output File: " << outputFileName << " is invalid!\n";
    return 1;
  } else {
    std::cout << "Valid file name: " << outputFileName << std::endl;
    return 0;
  }
}

bool isValid(const std::string &filename, const char inOrOut) {
  std::regex valid_r_file;
  valid_r_file = (inOrOut == 'O') ? ("[A-Za-z0-9_].r") : ("[A-Za-z0-9_].rmd");
  return std::regex_match(filename, valid_r_file);
}

void convertrmdtor(const std::string &inputFileName,
                   const std::string &outputFileName) {

  std::string line;
  std::regex r_tag_open{"```{r*}"};
  std::regex r_tag_close{"```"};

  std::ifstream inputFile(inputFileName);
  std::ofstream outputFile(outputFileName);

  while (std::getline(inputFile, line)) {
    if (std::regex_match(line, r_tag_open)) {
    }
  }
}
