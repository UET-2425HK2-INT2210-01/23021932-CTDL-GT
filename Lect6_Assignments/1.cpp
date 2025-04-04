#include <iostream>
using namespace std;

// Lớp Node đại diện cho một nút trong cây nhị phân tìm kiếm
class Node {
public:
    int val;        // Giá trị của nút
    Node* left;     // Con trái
    Node* right;    // Con phải

    // Hàm khởi tạo
    Node(int v) {
        val = v;
        left = right = nullptr;  // Ban đầu con trái và con phải là null
    }
};

// Lớp Cây Nhị Phân Tìm Kiếm
class BST {
public:
    Node* root;  // Gốc của cây

    // Hàm khởi tạo
    BST() {
        root = nullptr;  // Ban đầu cây rỗng
    }

    // Hàm chèn giá trị mới vào cây
    void insert(int v) {
        root = insertRec(root, v);  // Gọi hàm đệ quy để chèn
    }

    // Hàm duyệt cây theo thứ tự giữa (LNR)
    void printInOrder() {
        inOrder(root);  // Gọi hàm đệ quy duyệt cây
        cout << endl;
    }

    // Hàm xóa giá trị khỏi cây
    void remove(int v) {
        root = removeRec(root, v);  // Gọi hàm đệ quy để xóa
    }

private:
    // Hàm đệ quy để chèn giá trị mới
    Node* insertRec(Node* node, int v) {
        if (node == nullptr) return new Node(v);  // Nếu vị trí trống thì tạo nút mới

        if (v < node->val)
            node->left = insertRec(node->left, v);   // Chèn về bên trái nếu nhỏ hơn
        else
            node->right = insertRec(node->right, v); // Chèn về bên phải nếu lớn hơn hoặc bằng

        return node;  // Trả lại nút gốc hiện tại
    }

    // Hàm đệ quy để xóa giá trị
    Node* removeRec(Node* node, int v) {
        if (node == nullptr) return nullptr;  // Nếu cây rỗng thì trả về null

        if (v < node->val) {
            node->left = removeRec(node->left, v);  // Tìm bên trái
        } else if (v > node->val) {
            node->right = removeRec(node->right, v); // Tìm bên phải
        } else {
            // Tìm thấy nút cần xóa

            if (node->left == nullptr) {
                Node* temp = node->right;  // Nếu không có con trái, gán con phải
                delete node;               // Xóa nút hiện tại
                return temp;
            }

            if (node->right == nullptr) {
                Node* temp = node->left;   // Nếu không có con phải, gán con trái
                delete node;               // Xóa nút hiện tại
                return temp;
            }

            // Trường hợp có cả 2 con: tìm nút nhỏ nhất bên phải
            Node* temp = findMin(node->right);
            node->val = temp->val;  // Gán giá trị nhỏ nhất cho nút hiện tại
            node->right = removeRec(node->right, temp->val);  // Xóa nút nhỏ nhất ở nhánh phải
        }

        return node;  // Trả lại nút gốc hiện tại
    }

    // Hàm tìm nút có giá trị nhỏ nhất trong cây
    Node* findMin(Node* node) {
        while (node->left != nullptr)  // Đi hết nhánh trái
            node = node->left;
        return node;  // Trả về nút nhỏ nhất
    }

    // Hàm đệ quy để duyệt cây theo thứ tự giữa (LNR)
    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);        // Duyệt nhánh trái
            cout << node->val << " ";   // In giá trị nút hiện tại
            inOrder(node->right);       // Duyệt nhánh phải
        }
    }
};

int main() {
    BST tree;  // Tạo cây nhị phân

    // Danh sách giá trị ban đầu
    int initVals[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int v : initVals)
        tree.insert(v);  // Chèn từng giá trị vào cây

    cout << "Cay ban dau: ";
    tree.printInOrder();  // In cây sau khi chèn ban đầu

    // Các giá trị cần chèn thêm
    int moreVals[] = {14, 0, 35};
    for (int v : moreVals)
        tree.insert(v);  // Chèn từng giá trị mới vào cây

    cout << "Sau khi chen 14, 0, 35: ";
    tree.printInOrder();  // In cây sau khi chèn thêm

    // Các giá trị cần xóa
    int delVals[] = {6, 13, 35};
    for (int v : delVals)
        tree.remove(v);  // Xóa từng giá trị khỏi cây

    cout << "Sau khi xoa 6, 13, 35: ";
    tree.printInOrder();  // In cây sau khi xóa
}
