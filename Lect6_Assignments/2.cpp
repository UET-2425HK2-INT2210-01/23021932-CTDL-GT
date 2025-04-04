#include <iostream>
using namespace std;

// Cấu trúc một nút trong cây nhị phân tìm kiếm (BST)
struct Node {
    int val;        // Giá trị của nút
    Node* left;     // Con trỏ đến nút con bên trái
    Node* right;    // Con trỏ đến nút con bên phải

    // Hàm khởi tạo nút với giá trị được truyền vào
    Node(int x) {
        val = x;
        left = right = nullptr;  // Khởi tạo con trái và phải là null
    }
};

// Hàm thêm một giá trị mới vào cây BST
Node* insert(Node* root, int x) {
    if (root == nullptr)         // Nếu cây rỗng, tạo nút mới và trả về
        return new Node(x);
    if (x < root->val)           // Nếu giá trị nhỏ hơn nút hiện tại, thêm vào cây con trái
        root->left = insert(root->left, x);
    else                         // Nếu lớn hơn hoặc bằng, thêm vào cây con phải
        root->right = insert(root->right, x);
    return root;                 // Trả lại gốc cây sau khi chèn
}

// Hàm tìm nút có giá trị nhỏ nhất trong cây con
Node* getMin(Node* root) {
    while (root->left != nullptr)  // Lặp đến khi không còn con trái
        root = root->left;         // Di chuyển sang trái
    return root;                   // Trả về nút nhỏ nhất
}

// Hàm xóa một giá trị khỏi cây BST
Node* remove(Node* root, int x) {
    if (root == nullptr)           // Nếu cây rỗng, không làm gì cả
        return nullptr;
    if (x < root->val)             // Nếu giá trị cần xóa nhỏ hơn, tìm bên trái
        root->left = remove(root->left, x);
    else if (x > root->val)        // Nếu lớn hơn, tìm bên phải
        root->right = remove(root->right, x);
    else {
        // Tìm thấy nút cần xóa

        if (root->left == nullptr) {       // Nếu không có con trái
            Node* tmp = root->right;       // Lưu con phải
            delete root;                   // Xóa nút hiện tại
            return tmp;                    // Trả về con phải
        } else if (root->right == nullptr) { // Nếu không có con phải
            Node* tmp = root->left;        // Lưu con trái
            delete root;                   // Xóa nút hiện tại
            return tmp;                    // Trả về con trái
        }

        // Trường hợp có 2 con: tìm nút nhỏ nhất bên phải
        Node* tmp = getMin(root->right);    // Lấy nút nhỏ nhất ở cây con phải
        root->val = tmp->val;               // Gán giá trị đó cho nút hiện tại
        root->right = remove(root->right, tmp->val); // Xóa nút trùng lặp ở cây con phải
    }
    return root;    // Trả lại gốc cây sau khi xóa
}

// Hàm duyệt cây theo thứ tự LNR (in-order)
void inorder(Node* root) {
    if (root == nullptr) return;    // Nếu cây rỗng thì dừng
    inorder(root->left);            // Duyệt cây con trái
    cout << root->val << " ";       // In giá trị nút hiện tại
    inorder(root->right);           // Duyệt cây con phải
}

// Hàm chính
int main() {
    Node* root = nullptr; // Khởi tạo cây rỗng

    // Mảng giá trị khởi tạo ban đầu
    int initial[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int x : initial)
        root = insert(root, x);  // Chèn từng phần tử vào cây

    cout << "BST ban dau (in-order): ";
    inorder(root); // Duyệt và in cây ban đầu
    cout << endl;

    // Mảng giá trị cần thêm
    int toAdd[] = {14, 0, 35};
    for (int x : toAdd)
        root = insert(root, x); // Chèn thêm giá trị mới

    cout << "BST sau khi them 14, 0, 35: ";
    inorder(root); // Duyệt và in cây sau khi thêm
    cout << endl;

    // Mảng giá trị cần xóa
    int toDel[] = {6, 13, 35};
    for (int x : toDel)
        root = remove(root, x); // Xóa từng phần tử khỏi cây

    cout << "BST sau khi xoa 6, 13, 35: ";
    inorder(root); // Duyệt và in cây sau khi xóa
}
