#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void inputArray(int arr[], int& n) {
    cout << "Masukkan banyaknya elemen(1-100) : ";
    cin >> n;

    while (n < 1 || n > MAX_SIZE || cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Input tidak valid, masukkan angka dari 1 sampai 100 : ";
        cin >> n;
    }

    cout << "Masukkan elemen array :\n";
    for (int i = 0; i < n; ++i) {
        cout << "Elemen [" << i << "] : ";
        cin >> arr[i];

        while (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Input tidak valid, masukkan angka : ";
            cin >> arr[i];
        }
    }
}

void linearSearch(int arr[], int n, int target, int indices[], int& count) {
    count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            indices[count++] = i;
        }
    }
    if (count > 0) {
        cout << "Angka " << target << " muncul " << count << " kali.\n";
        cout << "Muncul pada indeks ke : ";
        for (int i = 0; i < count; ++i) {
            cout << indices[i] << " ";
        }
        cout << endl;
    }   
    else {
    cout << "Angka " << target << " tidak ditemukan pada array.\n";
    }
}

int main() {
    int arr[MAX_SIZE], indices[MAX_SIZE];
    int n, target, count;

    inputArray(arr, n);

    cout << "Masukkan angka untuk dicari : ";
    cin >> target;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Input tidak valid, masukkan angka untuk dicari : ";
        cin >> target;
    }
    linearSearch(arr, n, target, indices, count);
    return 0;
}