#include <iostream>
#include <conio.h>
using namespace std;
void Getch();
void clearScreen();
string menu(string option);
void header();
void inputData(int arr[][3], int size);
void showData(int arr[][3], int size);
void addition(int arr[][3], int arr2[][3], int result[][3], int size);
void subtraction(int arr[][3], int arr2[][3], int result[][3], int size);
void Multiplication(int arr[][3], int arr2[][3], int result[][3], int size);
void scalarMultiplication(int arr[][3], int result[][3], int k, int size);
void transpose(int arr[][3], int result[][3], int size);
bool checkDiagonal(int arr[][3], int size);
bool CheckSymmetric(int arr[][3], int result[][3], int size);
main()
{
    int k;
    int size = 3;
    int A[3][3];
    int B[3][3];
    int C[3][3];
    int arr[3][3];
    string option;
    while (option != "8")
    {
        clearScreen();
        string choice = menu(option);
        if (choice == "1") // addition
        {
            clearScreen();
            header();
            cout << "Enter element of 1st matrix: " << endl;
            inputData(A, size);
            cout << "\nEnter elements of 2nd matrix: " << endl;
            inputData(B, size);
            // Display data
            clearScreen();
            header();
            cout << "\nElements of 1st matrix" << endl;
            showData(A, size);
            cout << "\nElements of 2nd matrix" << endl;
            showData(B, size);
            addition(A, B, C, size);
            cout << "\nAddition of two matrix is: " << endl;
            showData(C, size);
            Getch();
        }
        if (choice == "2") // subtraction
        {
            clearScreen();
            header();
            cout << "Enter element of 1st matrix: " << endl;
            inputData(A, size);
            cout << "\nEnter elements of 2nd matrix: " << endl;
            inputData(B, size);
            // Display data
            clearScreen();
            header();
            cout << "\nElements of 1st matrix" << endl;
            showData(A, size);
            cout << "\nElements of 2nd matrix" << endl;
            showData(B, size);
            subtraction(A, B, C, size);
            cout << "\nSubtraction of two matrix is: " << endl;
            showData(C, size);
            Getch();
        }
        if (choice == "3") // Multiplication
        {
            clearScreen();
            header();
            cout << "Enter element of 1st matrix: " << endl;
            inputData(A, size);
            cout << "\nEnter elements of 2nd matrix: " << endl;
            inputData(B, size);
            // Display data
            clearScreen();
            header();
            cout << "\nElements of 1st matrix" << endl;
            showData(A, size);
            cout << "\nElements of 2nd matrix" << endl;
            showData(B, size);
            Multiplication(A, B, C, size);
            cout << "\nMultiplication of matrices is: " << endl;
            showData(C, size);
            Getch();
        }
        if (choice == "4") // Scalar Multiplication
        {
            clearScreen();
            header();
            cout << "Enter element of 1st matrix: " << endl;
            inputData(A, size);
            // Display data
            clearScreen();
            header();
            cout << "\nElements of 1st matrix" << endl;
            showData(A, size);
            cout << "\nEnter the number you want to multiply: ";
            cin >> k;
            scalarMultiplication(A, C, k, size);
            cout << "\nScalar Multiplication of matrix is: " << endl;
            showData(C, size);
            Getch();
        }
        if (choice == "5") // Transpose of matrix
        {
            clearScreen();
            header();
            cout << "Enter element of 1st matrix: " << endl;
            inputData(A, size);
            // Display data
            clearScreen();
            header();
            cout << "\nElements of 1st matrix" << endl;
            showData(A, size);
            transpose(A, C, size);
            cout << "\nTranspose of matrix is" << endl;
            showData(C, size);
            Getch();
        }
        if (choice == "6") // Check Diagonal matrix
        {
            clearScreen();
            header();
            cout << "Enter element of 1st matrix: " << endl;
            inputData(A, size);
            // Display data
            clearScreen();
            header();
            cout << "\nElements of 1st matrix" << endl;
            showData(A, size);
            bool check = checkDiagonal(A, size);
            if (check == true)
            {
                cout << "\nMatrix is Diagonal" << endl;
            }
            else
            {
                cout << "\nMatrix is not a Diagonal" << endl;
            }
            Getch();
        }
        if (choice == "7") // check symmetric matrix
        {
            clearScreen();
            header();
            cout << "Enter element of 1st matrix: " << endl;
            inputData(A, size);
            // Display data
            clearScreen();
            header();
            cout << "\nElements of 1st matrix" << endl;
            showData(A, size);
            transpose(A, C, size);
            cout << "\nTraspose of this matrix is: " << endl;
            showData(C, size);
            bool check = CheckSymmetric(A, C, size);
            if (check == true)
            {
                cout << "\nMatrix is symmetric" << endl;
            }
            else
            {
                cout << "\nMatrix is not a symmetric" << endl;
            }
            Getch();
        }
    }
}
void clearScreen()
{
    system("cls");
}
void Getch()
{
    cout << "\nPress any key to continue...";
    getch();
}
void header()
{
    cout << "*******************************************************************" << endl;
    cout << "*                        MATRIX CALCULATOR                        *" << endl;
    cout << "*******************************************************************" << endl;
}
string menu(string option)
{
    header();
    cout << "---------------------------------" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Scalar Multiplication" << endl;
    cout << "5. Transpose" << endl;
    cout << "6. Diagonal Matrix" << endl;
    cout << "7. Symmetric Matrix" << endl;
    cout << "------------------------------------" << endl;
    cout << "Enter your option: ";
    cin >> option;
    return option;
}
void inputData(int arr[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter Values A: " << i << j << ":";
            cin >> arr[i][j];
        }
    }
}

void showData(int arr[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void addition(int arr[][3], int arr2[][3], int result[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = arr[i][j] + arr2[i][j];
        }
    }
}

void subtraction(int arr[][3], int arr2[][3], int result[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = arr[i][j] - arr2[i][j];
        }
    }
}

void Multiplication(int arr[][3], int arr2[][3], int result[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = arr[i][j] * arr2[j][i];
        }
    }
}

void scalarMultiplication(int arr[][3], int result[][3], int k, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = k * arr[i][j];
        }
    }
}

void transpose(int arr[][3], int result[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = arr[j][i];
        }
    }
}

bool checkDiagonal(int arr[][3], int size)
{
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                if (arr[i][j] != 0)
                {
                    count1++;
                }
            }
            if (i != j)
            {
                if (arr[i][j] == 0)
                {
                    count2++;
                }
            }
        }
    }
    if (count1 == 3 && count2 == 6)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CheckSymmetric(int arr[][3], int result[][3], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (result[i][j] = arr[i][j])
            {
                count++;
            }
        }
    }
    if (count == 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}
