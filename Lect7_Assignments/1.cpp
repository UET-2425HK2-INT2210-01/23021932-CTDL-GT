#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input("numbers.txt");         // Mở file input để đọc.
    ofstream output("numbers.sorted");    // Mở file output để ghi.

    int arr[1000];                        // Mảng lưu trữ các số đọc từ file.
    int n = 0;                            // Biến đếm số lượng số đã đọc.
    int x;

    while (input >> x) {                   // Đọc số từ file vào biến x.
        arr[n++] = x;                      // Lưu số vào mảng và tăng biến đếm.
    }

    for (int i = 0; i < n - 1; ++i) {       // Vòng lặp ngoài của Bubble Sort.
        for (int j = 0; j < n - i - 1; ++j) { // Vòng lặp trong của Bubble Sort.
            if (arr[j] > arr[j + 1]) {     // So sánh hai phần tử liền kề.
                swap(arr[j], arr[j + 1]);  // Hoán đổi nếu phần tử trước lớn hơn phần tử sau.
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        output << arr[i];                  // Ghi số đã sắp xếp vào file output.
        if (i < n - 1) output << " ";
    }

    input.close();                         // Đóng file input.
    output.close();                        // Đóng file output.

    return 0;
}