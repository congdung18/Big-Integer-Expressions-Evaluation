#include "BigIntImplementation.cpp"

// Hàm main đọc được command line, đọc dữ liệu từ tests.txt, xử lý và xuất ra output_24120043.txt
int main(int argc, char* argv[]) {
    // Nếu có ít hơn 3 tham số dòng lệnh -> syntax lỗi
    // if (argc != 3) {
    //     std::cerr << "Invalid syntax." << std::endl;
    //     return -1;
    // }

    //"D:\DSA\Lab 1\tests.txt"
    // Địa chỉ file input nằm ở tham số dòng lệnh số 2
    std::string file_input = "test.txt";

    // Địa chỉ file output nằm ở tham số dòng lệnh số 3
    std::string file_output = "output.txt";

    // Luồng ghi file
    std::ifstream fin(file_input);

    // Xử lý lỗi luồng ghi
    if (!fin.is_open()) {
        std::cerr << "Cannot open input file." << std::endl;
        return -1;
    }

    // Luồng xuất file
    std::ofstream fout(file_output);

    // Xử lý lỗi luồng xuất
    if (!fout.is_open()) {
        std::cerr << "Cannot open output file." << std::endl;
        return -1;
    }

    // Chuỗi biểu thức infix
    std::string infix_arithmetic_expression;

    // Dừng khi hết chuỗi biểu thức infix trong file
    while (std::getline(fin, infix_arithmetic_expression)){
        // Chuyển sang postfix
        std::string postfix_arithmetic_expression = Infix_to_Postfix(infix_arithmetic_expression);
        std::cout << postfix_arithmetic_expression << std::endl;

        // Ghi kết quả
        std::string result = Calculate_Arithmetic_Expression(postfix_arithmetic_expression);
        
        // Xuất file
        File_Writing(file_output, result);
    }

    // Đóng file
    fin.close();
    fout.close();

    return 0;
}
