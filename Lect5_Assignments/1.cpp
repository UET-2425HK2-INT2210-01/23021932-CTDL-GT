#include <iostream>  // Thư viện nhập xuất cơ bản

using namespace std;  // Sử dụng không gian tên std để không cần gọi std::

// Cấu trúc Node biểu diễn mỗi nút trong cây
struct Node {
    int value;         // Giá trị của nút
    Node* firstChild;  // Con trỏ đến con đầu tiên
    Node* nextSibling; // Con trỏ đến anh chị em tiếp theo
};

// Hàm tạo một nút mới
Node* createNode(int value) {
    Node* newNode = new Node();  // Cấp phát bộ nhớ cho nút mới
    newNode->value = value;      // Gán giá trị cho nút
    newNode->firstChild = nullptr;  // Khởi tạo con đầu tiên là null
    newNode->nextSibling = nullptr; // Khởi tạo anh chị em tiếp theo là null
    return newNode;             // Trả về nút mới tạo
}

// Hàm thêm một nút con vào nút cha
void addChild(Node* parent, Node* child) {
    if (parent->firstChild == nullptr) {  // Nếu cha chưa có con nào
        parent->firstChild = child;      // Thêm làm con đầu tiên
    } else {
        Node* sibling = parent->firstChild;  // Bắt đầu từ con đầu tiên
        while (sibling->nextSibling != nullptr) {  // Duyệt đến con cuối cùng
            sibling = sibling->nextSibling;
        }
        sibling->nextSibling = child;  // Thêm vào vị trí cuối
    }
}

// Hàm xây dựng cây từ danh sách cạnh
Node* buildTree(int N, int M, int edges[][2]) {
    Node* nodes[100] = {nullptr};  // Mảng các nút (giả sử N ≤ 100)
    
    // Tạo các nút từ 1 đến N
    for (int i = 1; i <= N; i++) {
        nodes[i] = createNode(i);  // Tạo nút với giá trị i
    }

    // Thêm các quan hệ cha-con từ danh sách cạnh
    for (int i = 0; i < M; i++) {
        int u = edges[i][0];  // Nút cha
        int v = edges[i][1];   // Nút con
        addChild(nodes[u], nodes[v]);  // Thêm quan hệ cha-con
    }

    // Tìm nút gốc (nút không có cha)
    bool isChild[100] = {false};  // Mảng đánh dấu nút là con
    for (int i = 0; i < M; i++) {
        isChild[edges[i][1]] = true;  // Đánh dấu các nút là con
    }
    for (int i = 1; i <= N; i++) {
        if (!isChild[i]) {  // Nếu nút không phải là con của ai
            return nodes[i];  // Đây là nút gốc
        }
    }
    return nullptr;  // Trường hợp không tìm thấy gốc (không xảy ra với input hợp lệ)
}

// Hàm tính chiều cao của cây
int calculateHeight(Node* root) {
    if (root == nullptr) return 0;  // Cây rỗng có chiều cao 0
    
    int maxHeight = 0;  // Chiều cao tối đa của các cây con
    // Duyệt qua tất cả các con
    for (Node* child = root->firstChild; child != nullptr; child = child->nextSibling) {
        int childHeight = calculateHeight(child);  // Tính chiều cao cây con
        if (childHeight > maxHeight) {
            maxHeight = childHeight;  // Cập nhật chiều cao tối đa
        }
    }
    return maxHeight + 1;  // Chiều cao cây = chiều cao cây con lớn nhất + 1
}

// Hàm duyệt tiền thứ tự (Pre-order)
void preorderTraversal(Node* root) {
    if (root == nullptr) return;  // Nút rỗng thì dừng
    
    cout << root->value << " ";  // nút gốc trước
    
    // Duyệt các cây con theo thứ tự từ trái sang phải
    for (Node* child = root->firstChild; child != nullptr; child = child->nextSibling) {
        preorderTraversal(child);
    }
}

// Hàm duyệt hậu thứ tự (Post-order)
void postorderTraversal(Node* root) {
    if (root == nullptr) return;  // Nút rỗng thì dừng
    
    // Duyệt các cây con trước
    for (Node* child = root->firstChild; child != nullptr; child = child->nextSibling) {
        postorderTraversal(child);
    }
    
    cout << root->value << " ";  // nút gốc sau cùng
}

// Hàm kiểm tra cây nhị phân
bool isBinaryTree(Node* root) {
    if (root == nullptr) return true;  // Cây rỗng là cây nhị phân
    
    int childCount = 0;  // Đếm số con của nút hiện tại
    // Đếm số con
    for (Node* child = root->firstChild; child != nullptr; child = child->nextSibling) {
        childCount++;
        if (childCount > 2) return false;  // Nếu có >2 con thì không phải nhị phân
    }
    
    // Kiểm tra đệ quy cho các cây con
    for (Node* child = root->firstChild; child != nullptr; child = child->nextSibling) {
        if (!isBinaryTree(child)) return false;  // Nếu cây con không phải nhị phân
    }
    
    return true;  // Tất cả điều kiện đều thỏa mãn
}

// Hàm duyệt trung thứ tự (In-order) cho cây nhị phân
void inorderTraversal(Node* root) {
    if (root == nullptr) return;  // Nút rỗng thì dừng
    
    Node* leftChild = root->firstChild;  // Con trái (con đầu tiên)
    Node* rightChild = (leftChild != nullptr) ? leftChild->nextSibling : nullptr;  // Con phải (con thứ hai)
    
    inorderTraversal(leftChild);  // Duyệt cây con trái
    cout << root->value << " ";   // nút gốc
    inorderTraversal(rightChild); // Duyệt cây con phải
}

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int N, M;  // Số nút và số cạnh
    cin >> N >> M;  // Đọc N và M từ input
    
    int edges[100][2];  // Mảng lưu các cạnh (giả sử M ≤ 100)
    // Đọc các cạnh từ input
    for (int i = 0; i < M; i++) {
        cin >> edges[i][0] >> edges[i][1];  // Đọc cặp nút cha-con
    }
    
    // Xây dựng cây từ input
    Node* root = buildTree(N, M, edges);
    
    // 1. Tính và in chiều cao cây (trừ 1 vì hàm tính từ gốc là 1)
    cout << calculateHeight(root) - 1 << endl;
    
    // 2. Duyệt tiền thứ tự
    preorderTraversal(root);
    cout << endl;
    
    // 3. Duyệt hậu thứ tự
    postorderTraversal(root);
    cout << endl;
    
    // 4. Kiểm tra và in kết quả duyệt trung thứ tự
    if (isBinaryTree(root)) {
        inorderTraversal(root);  // Nếu là cây nhị phân
    } else {
        cout << "NOT BINARY TREE";  // Nếu không phải
    }
}