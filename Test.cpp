#include <iostream>
#include <fstream>
#include <string>

bool Compare_Files(const std::string& path1, const std::string& path2) {
    std::ifstream file1(path1);
    std::ifstream file2(path2);

    if (!file1.is_open()) {
        std::cerr << "Cannot open file: " << path1 << std::endl;
        return false;
    }

    if (!file2.is_open()) {
        std::cerr << "Cannot open file: " << path2 << std::endl;
        return false;
    }

    std::string line1, line2;
    int line_number = 1;

    while (true) {
        bool file1_end = !std::getline(file1, line1);
        bool file2_end = !std::getline(file2, line2);

        if (file1_end && file2_end) {
            // Cả hai file kết thúc → giống nhau hoàn toàn
            std::cout << "The files are identical." << std::endl;
            return true;
        }

        if (file1_end || file2_end || line1 != line2) {
            std::cout << "Files differ at line " << line_number << ":" << std::endl;
            std::cout << "File 1: " << (file1_end ? "<EOF>" : line1) << std::endl;
            std::cout << "File 2: " << (file2_end ? "<EOF>" : line2) << std::endl;
            return false;
        }

        ++line_number;
    }
}

int main() {
    std::string file1 = "output.txt";
    std::string file2 = "results_test.txt";

    Compare_Files(file1, file2);

    return 0;
}
