#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct employee {
    string fio;
    string date;
    string job;
    string salary;
};

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "rus");
    if (argc != 4) {
        cout << argv[0] << " args: <text> <read | write> <filename>" << endl;
        return 1;
    }
    string vid = argv[1];
    string method = argv[2];
    string filename = argv[3];
    vector<employee> worker;
    if (method == "write") {
        int n;
        cout << "Введите количество сотрудников - ";
        cin >> n;
        cin.ignore(); 
        cout << endl;
        for (int i = 0; i < n; i++) {
            employee emp;

            cout << "Сотрудник №" << i + 1 << endl;

            cout << "Введите ФИО сотрудника - ";
            getline(cin, emp.fio); 
            cout << endl;

            cout << "Введите дату приема на работу - ";
            cin >> emp.date;
            cin.ignore(); 
            cout << endl;

            cout << "Введите должность - ";
            getline(cin, emp.job); 
            cout << endl;

            cout << "Введите базовый оклад - ";
            cin >> emp.salary;
            cin.ignore(); 
            cout << endl;

            worker.push_back(emp);
        }

        if (vid == "text") {
            ofstream file(filename);
            if (!file) {
                cerr << "Ошибка открытия файла для записи!" << endl;
                return 1;
            }
            for (const auto& emp : worker) {
                file << emp.fio << "\n" << emp.date << "\n" << emp.job << "\n" << emp.salary << "\n";
            }
            file.close();
        }
    }
    else if (method == "read") {
        if (vid == "text") {
            ifstream file(filename);
            if (!file) {
                cerr << "Ошибка открытия файла для чтения!" << endl;
                return 1;
            }
            while (file) {
                employee emp;
                if (!getline(file, emp.fio)) break;
                getline(file, emp.date);
                getline(file, emp.job);
                getline(file, emp.salary);
                worker.push_back(emp);
            }
            file.close();
        }
        for (const auto& emp : worker) {
            cout << "ФИО: " << emp.fio << "\n";
            cout << "Дата приема: " << emp.date << "\n";
            cout << "Должность: " << emp.job << "\n";
            cout << "Оклад: " << emp.salary << "\n" << endl;
        }
    }

    return 0;
}