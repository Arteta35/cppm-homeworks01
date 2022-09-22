#include <iostream>
#include <fstream>

using namespace std;

int *create_array(int* rows, ifstream & f_in) {

    f_in >> *rows;

    int* arr = new int[*rows]();

    for (int i = 0; i < *rows; i++) {

        f_in >> arr[i];
    }

    return arr;

}


void print_array_1(int rows, int *arr, ofstream *f_out) {

    if (rows < 1) {

        cout << "Некорректный размер массива." << endl;

    }
    else {

        *f_out << rows << endl;

        for (int i = 1; i < rows; i++) {

            *f_out << arr[i] << " ";

        }

        *f_out << arr[0] << endl;

    }

   
}

void print_array_2(int rows, int *arr, ofstream *f_out) {


    if (rows < 1) {

        cout << "Некорректный размер массива." << endl;

    }
    else {

        *f_out << rows << endl;

        *f_out << arr[rows - 1] << " ";

        for (int i = 0; i < rows - 1; i++) {

            *f_out << arr[i] << " ";
        }

        *f_out << endl;
    }

}


void delete_array(int* arr) {

    delete[] arr;
    arr = nullptr;
}


int main()
{

    setlocale(LC_ALL, "Russian");

    int rows1 = 0, rows2 = 0;

    ifstream f_in("in.txt");

    if (f_in.is_open()) {

        int* arr1 = create_array(&rows1, f_in);

        int* arr2 = create_array(&rows2, f_in);

        ofstream f_out("out.txt");

        if (f_out.is_open()) {

            print_array_2(rows2, arr2, &f_out);

            print_array_1(rows1, arr1, &f_out);

        }

        f_out.close();

        delete_array(arr1);

        delete_array(arr2);

    }

    f_in.close();

    return 0;
   
}
