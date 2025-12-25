#ifndef LARGE_NUMBER_EXPRESSION
#define LARGE_NUMBER_EXPRESSION

// CÁC THƯ VIỆN SỬ DỤNG
    // iostream để dùng luồng cin cout
    #include <iostream>
    // string để dùng chuỗi
#include <string>
    // vector để dễ dùng mảng thuận tiện độ dài hơn
#include <vector>
    // fstream để nhập xuất file
#include <fstream>
    // getopt.h để đọc command line
#include <getopt.h>

// CÁC CẤU TRÚC (STRUCT) SỬ DỤNG
    // Node là phần tử của stack
        // có 2 phần tử
struct NODE{
    // chuỗi đại diện cho số
    std::string value;
    // node kế tiếp
    NODE* next;
};

    // Stack
        // có 2 phần tử
struct STACK{
    // head trỏ đến đầu stack
    NODE* head = nullptr;
    // tail trỏ đến cuối stack
    NODE* tail = nullptr;
};

    // Queue
        // có 2 phần tử
struct QUEUE{
    // head trỏ đến đầu queue
    NODE* head = nullptr;
    // tail trỏ đến cuối queue
    NODE* tail = nullptr;
};

// CÁC HÀM SỬ DỤNG
    // Gồm 7 loại chính:
        // phụ trợ xử lý stack và queue
        // chức năng của stack
        // chức năng của queue
        // phụ trợ xử lý các số và biểu thức
        // xử lý biểu thức
        // xử lý số
        // xử lý nhập xuất file

        // 1. Phụ trợ xử lý stack và queue
// tạo node
NODE* createNode(std::string key);

        // 2. Chức năng của stack
// kiểm tra xem stack có rỗng không
bool Is_Stack_Empty(STACK* s);

// đẩy vào stack
void Push_Stack(std::string key, STACK*& s);

// xóa khỏi stack
void Pop_Stack(STACK*& s);

// lấy phần tử trên đỉnh stack
std::string Top_Stack(STACK* s);

// in stack
void Print_Stack(STACK* s);

        // 3. Chức năng của queue
// kiểm tra xem queue có rỗng không
bool Is_Queue_Empty(QUEUE* q);

// đẩy vào queue
void Push_Queue(std::string key, QUEUE*& q);

// xóa khỏi queue
void Pop_Queue(QUEUE*& q);

// lấy phần tử trên đỉnh queue
std::string Top_Queue(QUEUE* q);

// in queue
void Print_Queue(QUEUE* q);

        // 4. Hỗ trợ xử lý số và biểu thức
    // xử lý từ infix sang postfix
// xác định mức độ ưu tiên của toán tử
int Operator_Precedence(char s);

// xác định xem có theo thứ tự từ trái qua phải trong biểu thức không
bool Is_Left_Associative(char s);

// nếu thỏa mức độ ưu tiên toán tử và từ trái qua
    // đẩy vào queue để đưa qua postfix
bool Pop_Stack_To_Queue(char op1, char op2);

    // xử lý độ lớn của số
// kiểm tra xem trị tuyệt đối của số a có lớn hơn của số b không
bool Is_Abs_NumA_Larger_Than_NumB(std::string num1, std::string num2);

// kiểm tra xem số a có lớn hơn số b không
bool Is_NumA_Larger_Or_Equal_NumB(std::string num1, std::string num2);

        // 5. Xử lý biểu thức
// chuyển biểu thức infix sang postfix
std::string Infix_to_Postfix(std::string s);

// thực hiện biểu thức postfix
std::string Calculate_Arithmetic_Expression(std::string s);

        // 6. Xử lý số
// trừ hai số dương (phụ trợ cho hàm cộng trong trường hợp cộng 1 dương 1 âm)
std::string Subtract_Two_Positive_Numbers_Function(std::string num1, std::string num2);

// cộng hai số
std::string Add_Big_Integer(std::string num1, std::string num2);

// trừ hai số
std::string Subtract_Big_Integer(std::string num1, std::string num2);

// nhân hai số
std::string Multiply_Big_Integer(std::string num1, std::string num2);

// chia hai số
std::string Divide_Big_Integer(std::string num1, std::string num2);

// đọc biểu thức postfix và xử lý phép tính bắt gặp
std::string Calculate_Arithmetic_Large_Number(std::string num1, std::string num2, char op);

        // 7. Xử lý file
// đọc file input
std::string File_Reading(std::string input_destination);

// ghi file output
void File_Writing(std::string output_destination, std::string result);

#endif