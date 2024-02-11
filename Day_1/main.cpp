#include <iostream>
#include <fstream>
#include <sstream> //std::istringstream
#include <string>
#include <vector>
#include <cctype> //std::isdigit
#include <cmath>

//Function Declaration 
void solution(const std::string& filename);

int main(int argc, char* argv[]) {

    if (argc < 2){
        std::cerr << "Please give a file to use as an argument" << std::endl;
        return 1;
    } 

    if (argc > 2) {
        std::cerr << "Please only give one argument, the file you want to use" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "The file is in use else where, cannot open. "<<  std::endl;
    }

    //std::cout<< "Change happened" << std::endl;
    solution(argv[1]);
    
    return 0;
}


void solution(const std::string& filename) {
    // We need to loop through the file
    std::ifstream file(filename);
    std::string line;
    std::vector<int> temp;
    int vector_to_int{};
    int total{};
    char character;


    while (std::getline(file,line)) {
        
        temp.clear(); // every loop we need to clear this. 

        // This for will go through each char in the line and append all the numbers in that line into a vector. 
        for (char character: line) {
            if (isdigit(character)){
          //      std::cout << "adding: " << character<< " To the vector. " ;
                temp.push_back(character - '0'); // Convert from 'char' to 'int' and subtract ASCII value of '0' to get the actual numerical value.

            }
            
        }
        // As long as the element is not the first (0) and the last (-1), then we will remove it:
        if (temp.size() > 1) {
        std::vector<int>::iterator it = temp.begin() +1;
        while (it != temp.end() -1) {
             //   std::cout << "Erasing the number: " << *it << std::endl;
                it = temp.erase(it);

            } 
        } 

        // Now to find the total.
        // If you just have `vector_to_int = temp[0] * pow(10, temp.size() - 1) + temp[1]` this will not correctly handle lines with only single digits. 
        if (temp.size() > 1) {
            vector_to_int = temp[0] * pow(10, temp.size() - 1) + temp[1]; // so {1,2} becomes 10, 2 and we add together so 12.
            total += vector_to_int;
        } else if (temp.size() == 1) {
            vector_to_int = temp[0] * 11;
            total += vector_to_int;
        }
 
        
        std::cout << "\nFull vector after manipulation for line: " << line << std::endl;
        for (auto element: temp) { 
            std::cout << element;;            
        }
        std::cout << " Adding to total: " << total;
        std::cout << std::endl;
    }
    std::cout<< "The total amount is: " <<total  <<std::endl;
    file.close();
}
