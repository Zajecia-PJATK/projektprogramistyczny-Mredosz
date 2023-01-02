//
// Created by mredo on 28.12.2022.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#define size1 4

using namespace std;

struct graphic_interface{
    int r,l,top,down,space,x;
};
struct game{
    int score;
};

//void functions
void move(); //function to move
void gui();  // Graphic interface
void undo(); //undo players move
void menu(char option);
void rotation(char option);

// int functions
int numbers(int num);

//int** functions
int** create_matrix(int n,int m); // Create dynamic matrix

//global dynamic matrix
int** arr;
int** arr2;





int main(){
    //Enter file name and say hello to players
    string file_name;
    cout<<"         HELLO AND WELCOME TO MY 2048 GAME" <<endl;
    cout<<"Enter name of the file new or saved game: "<<endl;


//    char option;
//    cin>>option;
//    menu(option);

    // don't need press enter
    system("stty raw");
    cin>>file_name;
    system("stty cooked");

    const char *name=file_name.c_str();

    auto* game1 = new game;

    arr= create_matrix( size1, size1); //create matrix
    arr2 = create_matrix(size1,size1);
    //load and create file
    //Load saved file
    fstream file1;
    file1.open(name,ios::in);
    if (!file1.fail()){

        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size1; ++j) {
                file1>>arr[i][j];
            }
        }
        file1>>game1->score;
    }else{
        //create new file

        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size1; ++j) {
                arr[i][j]=0;
            }
        }
        game1->score = 0;
        //ADD random 2 at board
        srand(time(nullptr));
        arr[rand()%size1][rand()%size1]=2;
        arr[rand()%size1][rand()%size1]=2;

    }
    file1.close();
    //Gui
    gui();

    //Delete array

    for (int i = 0; i < size1; ++i) {
        delete[] arr[i];
    }
    delete [] arr;
    //Delete structure
    delete game1;

    return 0;
}
int** create_matrix(int n,int m){
    int **tablica = new int*[n];
    for (int i = 0; i < n; ++i) {
        tablica[i] = new int [m];

    }
    return tablica;
}
void gui(){
    auto* gui1 = new graphic_interface;
//Top of square
    for (gui1->r = 0;gui1->r  < size1; ++gui1->r) {
        for (gui1->top = 1; gui1->top <= size1 ; ++gui1->top) {
            cout<<"   --------- ";
        }
        cout<<endl;
//Left and right of square
        for (gui1->x = 1; gui1->x <= 3; ++gui1->x) {
            for (gui1->l = 0; gui1->l < size1; ++gui1->l) {
                if (gui1->x==2 && arr[gui1->r][gui1->l]!= 0){
//Display numbers on GUI
                    cout << "  |    " << arr[gui1->r][gui1->l];
                    for (gui1->space = 0; gui1->space < 5- numbers(arr[gui1->r][gui1->l]); ++gui1->space) {
                        cout << " ";
                    }
                    cout << "|";

                }else cout << "  |         |";
            }
            cout<<endl;
        }
//bottom of square
        for (gui1->down = 1; gui1->down <= size1; ++gui1->down) {
            cout << "   --------- ";
        }
        cout<<endl;
    }
    delete gui1;
}
int numbers(int num){
    int i=0;
    while (num>0){
        num /= 10;
        i++;
    }
    return i;
}
void move(){

    int shom;

    for (int i = 0; i < size1; ++i) {

        shom = size1 -1;
        int  temp = -1;

        for (int j = size1 - 1; j >=0 ; --j) {
            if (arr[j][i] && temp != arr[j][i]){
                temp = arr[j][i];
                arr[j][i] = arr[shom][i];
                arr[shom][i] = temp;
                shom--;
            }else if (arr[j][i]){
                arr[shom + 1][i] = 2*arr[shom  + 1][i];
                arr[j][i] = 0;
                temp = -1;
            }
        }
    }
}
void rotation(char option){

    int temp,shom;
    switch (option) {

        case 's':
            shom = 0;
            break;
        case 'd':
            shom  = 1;
            break;
        case 'w':
            shom = 2;
            break;
        case 'a':
            shom = 3;
            break;
    }
    while (shom--) {
        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size1; ++j) {
                if (i > j) {
                    temp = arr[i][j];
                    arr[i][j] = arr[j][i];
                    arr[j][i] = temp;
                }
            }
        }

        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size1 / 2; ++j) {
                temp = arr[i][j];
                arr[i][j] = arr[i][size1 - j - 1];
                arr[i][size1 - j - 1] = temp;
            }
        }
    }
}
void menu(char option){

//    switch (option) {
//        case 'q':
//
//
//    }


}