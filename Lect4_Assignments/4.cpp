#include <iostream>

using namespace std;

struct Student {
    int id;
    string name;
    string className;
};

const int MAX_STUDENTS = 1000; 
Student students[MAX_STUDENTS]; 
int studentCount = 0; 

void insertStudent(int id, string name, string className) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            students[i].name = name;
            students[i].className = className;
            return;
        }
    }
    students[studentCount++] = {id, name, className};
}

void deleteStudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            return;
        }
    }
}

void inforStudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            cout << students[i].name << "," << students[i].className << endl;
            return;
        }
    }
    cout << "NA,NA" << endl;
}

int main() {
    string command;
    
    while (cin >> command) {
        if (command.find("Insert(") == 0) {
            int id;
            string name, className;
            
            command = command.substr(7, command.length() - 8); 
            size_t comma1 = command.find(",");
            size_t comma2 = command.rfind(",");

            id = stoi(command.substr(0, comma1));
            name = command.substr(comma1 + 1, comma2 - comma1 - 1);
            className = command.substr(comma2 + 1);

            insertStudent(id, name, className);
        }
        else if (command.find("Delete(") == 0) {
            int id = stoi(command.substr(7, command.length() - 8));
            deleteStudent(id);
        }
        else if (command.find("Infor(") == 0) {
            int id = stoi(command.substr(6, command.length() - 7));
            inforStudent(id);
        }
    }
    
    return 0;
}
