#include "BigIntHeader.hpp"

// CÁC HÀM SỬ DỤNG ĐƯỢC CHIA THÀNH 7 LOẠI:

    // 1. Hàm hỗ trợ xây dựng stack và queue

// tạo node mới
NODE* createNode(std::string key){
    // cung cấp bộ nhớ cho node
    NODE* temp = new NODE;
    
    // gán giá trị cho node
    temp->value = key;

    // mặc định next là null
    temp->next = nullptr;

    return temp;
}

    // 2. Các chức năng của Stack

// kiểm tra xem stack có rỗng không
bool Is_Stack_Empty(STACK* s){
    // nếu head rỗng tức là stack rỗng
    return s->head == nullptr;
}

// thêm node vào stack
void Push_Stack(std::string key, STACK*& s){
    // thêm vào head để đảm bảo quy tắc FIFO và đạt hiệu quả tối đa O(1)
    NODE* temp = createNode(key);

    // stack rỗng thì gán cả head và tail là temp
    if (Is_Stack_Empty(s)){
        s->head = temp;
        s->tail = temp;
    // stack có phần tử thì thêm head
    }else{
        temp->next = s->head;
        s->head = temp;
    }
}

// xóa node khỏi stack
void Pop_Stack(STACK*& s){
    // xóa ở head để đảm bảo quy tắc FIFO và hiệu quả tối đa O(1)
    if (Is_Stack_Empty(s)){
        // stack rỗng thì báo lại
        std::cerr << "Empty Stack, cannot pop." << std::endl;
    }else{
        // stack có phần tử thì xóa head
        NODE* temp = s->head;
        s->head = s->head->next;
        delete temp;
    }
}

// lấy phần tử trên đỉnh stack
std::string Top_Stack(STACK* s){
    // stack rỗng thì báo lại
    if (Is_Stack_Empty(s)){
        std::cerr << "Empty stack, there is no top value" << std::endl;
        return "\0";
    }

    // stack có thì lấy head để đảm bảo FIFO
    return s->head->value;
}

// in stack
void Print_Stack(STACK* s){
    // nếu stack rỗng báo lại
    if (Is_Stack_Empty(s)){
        std::cerr << "Empty Stack." << std::endl;
        return;
    }

    // dùng node temp duyệt qua stack
    NODE* temp = s->head;
    while (temp != nullptr){
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

    // 3. Các chức năng của Queue

// kiểm tra xem queue có rỗng không
bool Is_Queue_Empty(QUEUE* q){
    // nếu head là null thì queue rỗng
    return q->head == nullptr;
}

// thêm node vào queue
void Push_Queue(std::string key, QUEUE*& q){
    // thêm đuôi để đảm bảo quy tắc LIFO và đạt hiệu quả tối đa O(1)
    NODE* temp = createNode(key);
    if (Is_Queue_Empty(q)){
        // queue rỗng thì head và tail là temp
        q->head = temp;
        q->tail = temp;
        // queue không rỗng thì thêm đuôi
    }else{
        q->tail->next = temp;
        q->tail = temp;
    }
}

// xóa node khỏi queue
void Pop_Queue(QUEUE*& q){
    // xóa head để đảm bảo LIFO và O(1)
    if(Is_Queue_Empty(q)){
        // queue rỗng báo lại
        std::cerr << "Empty queue, cannot pop." << std::endl;
    }else{
        // queue không rỗng thì xóa đầu
        NODE* temp = q->head;
        q->head = q->head->next;
        delete temp;
    }
}

// lấy phần tử trên đỉnh queue
std::string Top_Queue(QUEUE* q){
    // lấy head để đảm bảo LIFO
    if (Is_Queue_Empty(q)){
        // queue rỗng báo lại
        std::cerr << "Empty queue, there is no top value." << std::endl;
        return "\0";
    }

    // queue không rỗng thì lấy head
    return q->head->value;
}

// in queue
void Print_Queue(QUEUE* q){
    // queue rỗng báo lại
    if (Is_Queue_Empty(q)){
        std::cerr << "Empty queue." << std::endl;
    }

    // dùng temp duyệt queue
    NODE* temp = q->head;
    while (temp != nullptr){
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

    // 4. Hỗ trợ xử lý số và biểu thức

// xác định mức độ ưu tiên của toán tử
int Operator_Precedence(char s){
    // toán tử * và / được ưu tiên hơn + và -
    if (s == '*' || s == '/'){
        return 2;
    }else if (s == '+' || s == '-'){
        return 1;
    }

    return -1;
}

// xác định quy tắc xử lý biểu thức từ trái qua phải
bool Is_Left_Associative(char s){
    // tránh trường hợp đang xử lý thì có nhiều toán tử cùng lúc
    return (s == '+' || s == '-' || s == '*' || s == '/');
}

// nếu thỏa 2 tính chất trên, ta đẩy nó qua postfix
bool Pop_Stack_To_Queue(char op1, char op2){
    // dùng để kiểm tra xem phần tử nào được pop khỏi stack toán tử
    // và push qua queue postfix lưu kết quả trong thuật toán shunting_yard
    return ((Operator_Precedence(op2) > Operator_Precedence(op1)) || (Operator_Precedence(op2) == Operator_Precedence(op1) && Is_Left_Associative(op1)));
}

// kiểm tra xem số A có trị tuyệt đối lớn hơn số B không
bool Is_Abs_NumA_Larger_Or_Equal_NumB(std::string num1, std::string num2){
    // nếu 2 số bằng nhau, trả về true
    if (num1 == num2){
        return true;
    }

    // bỏ dấu âm vì đang xử lý trị tuyệt đối
    if (num1[0] == '-'){
        num1.erase(0, 1);
    }
    if (num2[0] == '-'){
        num2.erase(0, 1);
    }

    // nếu chênh lệch độ dài thì trả về kết quả để giảm độ phức tạp thuật toán
    if (num1.length() != num2.length())
        return num1.length() > num2.length();

    // duyệt từ chữ số có giá trị lớn nhất xuống
        // số nào lớn hơn thì trả về
    for (int i = 0; i < num1.length(); ++i) {
        if (num1[i] != num2[i])
            return num1[i] > num2[i];
    }

    return true;
}

// kiểm tra xem số A có lớn hơn số B không
bool Is_NumA_Larger_Or_Equal_NumB(std::string num1, std::string num2){
    // kiểm tra tính chất âm
    bool is_num1_negative = false, is_num2_negative = false;
    
    // xóa dấu âm
    if (num1[0] == '-'){
        num1.erase(0, 1);
        // đặt tính chất âm
        is_num1_negative = true;
    }
    if (num2[0] == '-'){
        num2.erase(0, 1);
        is_num2_negative = true;
    }

    // nếu 1 trong 2 cái âm, trả về kết quả số âm là số nhỏ hơn
    if (is_num1_negative && !is_num2_negative){
        return false;
    } else if (!is_num1_negative && is_num2_negative){
        return true;
    }

    // kiểm tra độ dài số để tiết kiệm thời gian
        // nếu số 1 ít chữ số hơn số 2 thì trả về false và ngược lại
    if (num1.length() > num2.length()){
        return true;
    } else if (num1.length() < num2.length()){
        return false;
    } else {
        // duyệt từ chữ số có giá trị lớn nhất về, nếu lớn hơn thì trả về true và ngược lại
        for (int i = 0; i < num1.length(); i++){
            if (num1[i] > num2[i]){
                return true;
            } else if (num1[i] < num2[i]){
                return false;
            }
        }
        // bằng nhau thì trả về true
        return true;
    }
}

    // 5. Xử lý biểu thức

// chuyển từ infix sang postfix
std::string Infix_to_Postfix(std::string s){

    // stack để lưu lại những toán tử
    STACK* st = new STACK;

    // queue để lưu số và toán tử đã được phép xử lý thông qua hàm Pop_Stack_To_Queue
    QUEUE* qu = new QUEUE;

    // lưu lại số
    std::string token;

    // kí tự viết tắt để lưu lại loại toán tử được xử lý gần nhất
    char prev_token = 0;

    for (int i = 0; i < s.length(); i++) {
        // duyệt từng kí tự
        char c = s[i];
        
        // khoảng trắng thì tiếp tục
        if (c == ' '){
            continue;
        }

        // nếu kí tự là số hoặc dấu trừ trước số âm, ta làm các thao tác:
        // lấy hết số
        // lưu vào token
        // đẩy token vào queue để in ra postfix

            // ở đây logic để xác định dấu trừ trước số âm (dấu âm) hay dấu trừ là ở toán tử trước đó (prev_token)
            // nếu phần tử trong stack là các toán tử thì tức là đây không phải dấu trừ vì không thể có 2 toán tử liên tiếp
            // nếu phần tử trong stack là dấu ngoặc thì tức là đây là dấu âm chứ để là dấu trừ thì phải có số trước đó
            // nếu là phần tử đầu tiên thì dấu trừ ở đây sẽ là dấu âm vì chưa có số để là dấu trừ

        if ((c >= '0' && c <= '9') || (c == '-' && (i == 0 || prev_token == '(' || prev_token == '+' || prev_token == '-' || prev_token == '*' || prev_token == '/'))) {
            // thêm kí tự đang duyệt vào string token có chức năng xử lý số
            token += c;
            // duyệt liên tiếp từ vị trí đang duyệt đến khi hết là số
            while (i + 1 < s.length() && s[i + 1] >= '0' && s[i + 1] <= '9') {
                // thêm số đang duyệt vào token
                token += s[++i];
            }
            // đẩy số vào queue để đưa ra postfix
            Push_Queue(token, qu);
            // đặt lại token
            token = "";
            // đặt prev_token là n để tính là số, tránh trường hợp lẫn lộn giữa dấu trừ và dấu âm ở trên
            prev_token = 'n';
        }
        
        // nếu kí tự đang duyệt là toán tử
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // ta so sánh độ ưu tiên của toán tử hiện tại và toán tử trên đỉnh stack
            while (!Is_Stack_Empty(st)) {
                // nếu thấp hơn, lấy toán tử trên đỉnh staack và đưa qua queue
                if (Pop_Stack_To_Queue(c, Top_Stack(st)[0])) {
                    char op = Top_Stack(st)[0];
                    Pop_Stack(st);
                    Push_Queue(std::string(1, op), qu);
                } else {
                    break;
                }
            }
            // đẩy toán tử vừa duyệt vào stack
            Push_Stack(std::string(1, c), st);
            // đánh dấu prev_token là toán tử
            prev_token = c;
        }
        // nếu toán tử được duyệt là dấu mở ngoặc (
        else if (c == '(') {
            // đẩy vào để làm điểm dừng khi gặp dấu đóng ngoặc ) và đánh dấu prev_token
            Push_Stack(std::string(1, c), st);
            prev_token = c;
        }
        // nếu toán tử được duyệt là dấu đóng ngoặc )
        else if (c == ')') {
            // lấy hết toán tử từ ) đến ( và push qua queue
            while (Top_Stack(st)[0] != '(') {
                char op = Top_Stack(st)[0];
                Pop_Stack(st);
                Push_Queue(std::string(1, op), qu);
            }
            // xóa (
            Pop_Stack(st);
            // đánh dấu token
            prev_token = ')';
        }
    }

    // khi hết kí tự ta đẩy hết trong stack qua queue
    while (!Is_Stack_Empty(st)) {
        char op = Top_Stack(st)[0];
        Pop_Stack(st);
        Push_Queue(std::string(1, op), qu);
    }

    // duyệt hết trong queue qua res
    std::string res;
    while (!Is_Queue_Empty(qu)) {
        res += Top_Queue(qu) + " ";
        Pop_Queue(qu);
    }

    return res;

    // ý tưởng của thuật toán biến infix thành postfix là
    // ưu tiên đưa số ra trước, phép tính ra sau theo thứ tự ưu tiên
    // từ thấp lên cao
}

// tính toán biểu thức postfix
std::string Calculate_Arithmetic_Expression(std::string s){
    // dùng stack để duyệt postfix
    STACK* exp = new STACK;

    // token lưu số, result lưu kết quả
    std::string token, result;

    // duyệt biểu thức
    for (int i = 0; i < s.length(); i++){
        // gặp số hoặc dấu âm
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] == '-' && i + 1 < s.length() && s[i + 1] >= '0' && s[i + 1] <= '9')){
            // đưa hết vào token để xử lý
            token += s[i];
            while (i + 1 < s.length() && (s[i + 1] >= '0' && s[i + 1] <= '9')){
                token += s[++i];
            }
            // đẩy vào stack chờ gặp toán tử
            Push_Stack(token, exp);
            // đặt lại token
            token.clear();
        }

        // gặp toán tử
        else if (s[i] == '+' || (s[i] == '-' && i + 1 < s.length() && !(s[i + 1] >= '0' && s[i + 1] <= '9')) || s[i] == '*' || s[i] == '/'){
            // lấy 2 số trên đỉnh
            std::string num1, num2;
            num2 = Top_Stack(exp);
            Pop_Stack(exp);
            num1 = Top_Stack(exp);
            Pop_Stack(exp);

            // tính toán bằng hàm Calculate_Arithmetic_Large_Number
            result = Calculate_Arithmetic_Large_Number(num1, num2, s[i]);
            Push_Stack(result, exp);
        }
    }

    return result;

    // ý tưởng ở đây là xử lý các số và toán tử ở biểu thức postfix theo hướng
    // đọc vào 2 số
    // gặp toán tử thì thực hiện toán tử
    // đẩy lại kết quả vào
    // đọc vào số và toán tử
    // đẩy kết quả
    // lặp lại
}

    // 6. Xử lý số

// trừ 2 số dương (phụ trợ hàm cộng)
std::string Subtract_Two_Positive_Numbers_Function(std::string num1, std::string num2){
    // kiểm tra xem kết quả có âm không
    bool is_negative = false;

    // nếu số trừ lớn hơn số bị trừ thì kết quả âm
    if (!Is_Abs_NumA_Larger_Or_Equal_NumB(num1, num2)) {
        std::swap(num1, num2);
        is_negative = true;
    }

    // đoạn này em nhờ ChatGPT hỗ trợ nhưng đại khái thuật toán là:
        // trừ giá trị ở digit1 và digit2 (duyệt từ phải qua)
        // nếu âm lưu vào sub
        // sub âm thì + 10 vào sub để đưa về dương và đặt carry bằng 1
        // sub dương thì carry = 0
        // ghi sub vào result


    // khởi tạo result có độ dài bằng length vì trong phép trừ thì kết quả chỉ có thể nhỏ hơn hoặc bằng số bị trừ
    std::string result(num1.length(), '0');
    int carry = 0;
    // duyệt từ phải qua ở số bị trừ
    int i = num1.length() - 1;
    // duyệt từ phải qua ở số trừ
    int j = num2.length() - 1;
    // duyệt từ phải qua ở kết quả
    int k = num1.length() - 1;

    while (i >= 0) {
        // lấy đơn vị của số bị trừ và số trừ
        int digit1 = num1[i] - '0';
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        // lưu kết quả phép trừ
        int sub = digit1 - digit2 - carry;
        if (sub < 0) {
            // mượn 10 để đưa về dương và ghi nợ vào carry nếu kết quả âm
            sub += 10;
            carry = 1;
        }
        else {
            carry = 0;
        }

        // ghi sub vào vị trí k của chuỗi kết quả
        result[k] = sub + '0';

        i--;
        j--;
        k--;
    }

    // xóa số 0 không cần thiết
    // tìm vị trí đầu tiên không có số 0 không cần thiết
    int start = 0;
    while (start < result.length() - 1 && result[start] == '0') {
        start++;
    }

    // gán result là chuỗi từ vị trí vừa tìm được trở đi
    std::string final_result = result.substr(start);
    if (is_negative) {
        final_result = '-' + final_result;
    }

    return final_result;
}
    
// cộng 2 số
std::string Add_Big_Integer(std::string num1, std::string num2){
    // kiểm tra số âm
    bool is_negative1 = false, is_negative2 = false;
    if (num1[0] == '-'){
        is_negative1 = true;
    }
    if (num2[0] == '-'){
        is_negative2 = true;
    }

    std::string result = "";
    // carry là số dư, i và j duyệt num1 num2
    int carry = 0, i = num1.length() - 1, j = num2.length() - 1;

    // nếu 2 số đều dương
    if (is_negative1 == false && is_negative2 == false){
        // cộng từng chữ số và số dư vào sum
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
    
            if (i >= 0){
                sum += (num1[i--] - '0');
            }
            if (j >= 0){
                sum += (num2[j--] - '0');
            }
            
            // đặt carry là phần dư của sum
            carry = sum / 10;
            
            // ghi kết quả ở hàng đơn vị của sum vào result
            result = char(sum % 10 + '0') + result;
        }
    }
    
    // nếu 1 âm 1 dương thì gọi hàm trừ 2 số dương
    else if (is_negative1 == true && is_negative2 == false){
        num1.erase(0, 1);
        result = Subtract_Two_Positive_Numbers_Function(num2, num1);
    }
    else if (is_negative1 == false && is_negative2 == true){
        num2.erase(0, 1);
        result = Subtract_Two_Positive_Numbers_Function(num1, num2);
    }
    
    // nếu 2 âm thì thực hiện như 2 dương nhưng thêm âm vào trước
    else if (is_negative1 == true && is_negative2 == true){
        num1.erase(0, 1);
        num2.erase(0, 1);
        i--;
        j--;
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
    
            if (i >= 0){
                sum += (num1[i--] - '0');
            }
            if (j >= 0){
                sum += (num2[j--] - '0');
            }
            carry = sum / 10;
            result = char(sum % 10 + '0') + result;
        }
        result = "-" + result;
    }

    return result;
}

// trừ 2 số
std::string Subtract_Big_Integer(std::string num1, std::string num2){
    // kiểm tra dấu âm
    bool is_negative1 = false, is_negative2 = false;
    if (num1[0] == '-'){
        is_negative1 = true;
    }
    if (num2[0] == '-'){
        is_negative2 = true;
    }

    std::string result = "";
    // 2 số không âm -> gọi hàm trừ 2 số dương
    if (is_negative1 == false && is_negative2 == false){
        result = Subtract_Two_Positive_Numbers_Function(num1, num2);
    }
    
    // âm trừ dương, chuyển dấu trừ thành dấu âm ở số 2 và thực hiện cộng 2 số âm
    else if (is_negative1 == true && is_negative2 == false){
        num2 = "-" + num2;
        result = Add_Big_Integer(num1, num2);
    }
    
    // dương trừ âm, xóa dấu trừ và cộng 2 số dương
    else if (is_negative1 == false && is_negative2 == true){
        std::string temp = num2;
        temp.erase(0, 1);
        result = Add_Big_Integer(num1, temp);
    }
    
    // 2 âm thì xóa dấu âm, trừ 2 số dương với num2 là số bị trừ còn num1 là số trừ
    else if (is_negative1 == true && is_negative2 == true){
        num1.erase(0, 1);
        num2.erase(0, 1);
        result = Subtract_Two_Positive_Numbers_Function(num2, num1);
    }

    return result;
}

// nhân 2 số
std::string Multiply_Big_Integer(std::string num1, std::string num2){
    // kiểm tra dấu âm
    bool is_negative = false;
    std::string result = "";

    if (num1[0] == '-') {
        is_negative = !is_negative;
        num1.erase(0, 1);
    }
    if (num2[0] == '-') {
        is_negative = !is_negative;
        num2.erase(0, 1);
    }

    if (num1 == "0" || num2 == "0"){
        return "0";
    }

    // Đoạn này em nhờ ChatGPT hỗ trợ.
    // Ý tưởng thuật toán theo em hiểu là:
        // nhân từng chữ số từ dưới lên
        // lưu kết quả vào vector res theo đúng thứ tự hàng đơn vị lên hàng chục, hàng trăm
        // cộng các kết quả ở res vào
        // chuyển kết quả ở res qua result

    // 2 con trỏ duyệt 2 string
    int size_num1 = num1.length(), size_num2 = num2.length();

    // vector lưu kết quả (kết quả ngược, hàng đơn vị từ phải qua trái)
    std::vector<int> res(size_num1 + size_num2, 0);

    // nhân từng giá trị của num1
    for (int i = size_num1 - 1; i >= 0; i--){
        // với từng giá trị của num2
        for (int j = size_num2 - 1; j >= 0; j--){
            // lấy giá trị của digit
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';
            int multiply = digit1 * digit2;

            // position1 là vị trí nhớ
            int position1 = i + j;
            // position2 là vị trí được ghi
            int position2 = i + j + 1;
            // sum là tổng giá trị hiện có và giá trị phép nhân
            int sum = multiply + res[position2];

            // ghi lại hàng đơn vị
            res[position2] = sum % 10;
            // ghi lại giá trị cần nhớ
            res[position1] += sum / 10;
        }
    }

    // lấy vị trí đầu tiên khác 0
    int position_of_first_digit_not_zero = 0;
    for (int i = 0; i < res.size(); i++){
        if (res[i] != 0){
            position_of_first_digit_not_zero = i;
            break;
        }
    }

    // chuyển thành string
    for (int i = position_of_first_digit_not_zero; i < res.size(); i++){
        result += res[i] + '0';
    }

    // nếu âm thêm dấu
    if (is_negative){
        result = "-" + result;
    }

    return result;
}

// chia 2 số
std::string Divide_Big_Integer(std::string num1, std::string num2){
    // Phần này ban đầu em làm được đoạn chia không thập phân nhưng tới đoạn thập phân em bí
    // Tham khảo phần chia thập phân của ChatGPT
    
    // kiểm tra âm
    bool neg1 = false, neg2 = false;
    if (num1[0] == '-') {
        neg1 = true;
        num1.erase(0, 1);
    }
    if (num2[0] == '-') {
        neg2 = true;
        num2.erase(0, 1);
    }

    // kiểm tra xem có chia cho 0 không
    bool is_dividing_by_zero = true;
    for (int i = 0; i < num2.length(); i++){
        if (num2[i] != '0') {
            is_dividing_by_zero = false;
            break;
        }
    }

    if (is_dividing_by_zero) {
        std::cerr << "Dividing by zero" << std::endl;
        return "Error dividing by zero";
    }

    // kiểm tra xem 0 có đang chia không
    bool is_zero_dividend = true;
    for (int i = 0; i < num1.length(); i++){
        if (num1[i] != 0){
            is_zero_dividend = false;
            break;
        }
    }

    if (is_zero_dividend){
        return "0";
    }

    // nếu chia 2 số bằng nhau
    if (num1 == num2){
        return (neg1 != neg2 ? "-1" : "1");
    }
    std::string result = "";
    std::string current = "";
    int i = 0;

    while (i < num1.length()) {
        // lấy từng chữ số của số bị chia
        current += num1[i++];

        // xóa số 0 ở đầu nếu có
        while (current.length() > 1 && current[0] == '0'){
            current.erase(0, 1);
        }

        // nếu số đang lấy nhỏ hơn số chia và đã chia rồi, thêm số 0 vào kết quả
        // nếu chưa chia thì tiếp tục lấy thêm chữ số ở số bị chia
        if (!Is_NumA_Larger_Or_Equal_NumB(current, num2) && current != num2) {
            if (!result.empty())
                result += '0';
            continue;
        }

        // chặt nhị phân tìm thương
        int x = 0, low = 0, high = 9;
        while (low <= high) {
            int mid = (low + high) / 2;
            // nếu mid thỏa mãn điều kiện thì thương là mid
            // product là kết quả phép nhân của mid và số chia
            std::string product = Multiply_Big_Integer(num2, std::to_string(mid));
            if (Is_NumA_Larger_Or_Equal_NumB(product, current) && product != current){
            // giảm high nếu mid * num2 > current
                high = mid - 1;
            }
            else {
            // gán mid là kết quả tạm
            // tăng low lên mid + 1
            // nếu low >= high kết quả tạm chính là kết quả
            // nếu chưa thì tăng tiếp
                x = mid;
                low = mid + 1;
            }
        }

        // gắn kết quả cho result
        result += std::to_string(x);
        std::string sub = Multiply_Big_Integer(num2, std::to_string(x));
        // tính số dư
        current = Subtract_Big_Integer(current, sub);
    }

    // còn dư
    if (current != "0") {
        // dấu chấm thập phân
        result += '.';
        int count = 0;
        // lấy tới 10 chữ số hoặc chia hết
        while (count < 10 && current != "0") {
            // thêm 0 vào số dư
            current += '0';
            // xóa số 0 dư
            while (current.length() > 1 && current[0] == '0'){
                current.erase(0, 1);
            }

            // chặt nhị phân tìm thương
            // logic tương tự như nãy
            int x = 0, low = 0, high = 9;
            while (low <= high) {
                int mid = (low + high) / 2;
                std::string product = Multiply_Big_Integer(num2, std::to_string(mid));
                if (Is_NumA_Larger_Or_Equal_NumB(product, current))
                    high = mid - 1;
                else {
                    x = mid;
                    low = mid + 1;
                }
            }

            // gán kết quả
            result += std::to_string(x);
            current = Subtract_Big_Integer(current, Multiply_Big_Integer(num2, std::to_string(x)));
            count++;
        }
    }

    // nếu số bị chia nhỏ hơn số chia, thêm số 0 thập phân ra trước vì kết quả đã có dấu . thập phân
    if (!Is_Abs_NumA_Larger_Or_Equal_NumB(num1, num2)){
        result = "0" + result;
    }

    // nếu âm thêm dấu 
    if (neg1 != neg2 && result != "0"){
        result = "-" + result;
    }

    return result;
}

// đọc biểu thức postfix và tính toán biểu thức postfix
std::string Calculate_Arithmetic_Large_Number(std::string num1, std::string num2, char op){
    // xử lý các trường hợp phép tính
    std::string result;
    switch(op){
        case '+':{
            result = Add_Big_Integer(num1, num2);
            break;
        }
        case '-':{
            result = Subtract_Big_Integer(num1, num2);
            break;
        }
        case '*':{
            result = Multiply_Big_Integer(num1, num2);
            break;
        }
        case '/':{
            result = Divide_Big_Integer(num1, num2);
            break;
        }
    }

    return result;
}

    // 7. Xử lý file

// đọc file input (nếu cần để bảo trì tốt hơn)
std::string File_Reading(std::ifstream& fin){
    // mở file và đọc file
    std::string result_from_reading;

    if (!fin.is_open()) {
        std::cerr << "Cannot open file input." << std::endl;
        return "";
    }

    std::getline(fin, result_from_reading);
    fin.close();
    return result_from_reading;
}

// ghi file output (nếu cần để bảo trì tốt hơn)
void File_Writing(std::string file_output, std::string result){
    // mở trong trạng thái app để ghi chèn không ghi đè
    std::ofstream fout (file_output, std::ios::app);

    if (!fout.is_open()){
        std::cerr << "Cannot open file output." << std::endl;
    }

    fout << result << std::endl;
    fout.close();
}
