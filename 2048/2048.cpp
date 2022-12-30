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

int** create_matrix(int n,int m); // Create dynamic matrix
void move(); //function to move
// Graphic interface
void gui();
int numbers(int num);
int** arr; //global dynamic matrix




int main(){
    //Enter file name and say hello to players
    string file_name;
    cout<<"         HELLO AND WELCOME TO MY 2048 GAME" <<endl;
    cout<<"Enter name of the file new or saved game: "<<endl;
    // don't need press enter
    system("stty raw");
    cin>>file_name;
    system("stty cooked");

    const char *name=file_name.c_str();

    arr= create_matrix( size1, size1); //create matrix
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
    }else{
        //create new file

        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size1; ++j) {
                arr[i][j]=0;
            }
        }
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

}