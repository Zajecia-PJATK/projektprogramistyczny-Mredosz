//
// Created by mredo on 28.12.2022.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
struct zero_point{
    int length;
    int x,y;
};
struct graphic_interface{
    int r,l,top,down,space,x;
};

int** create_matrix(int n,int m);
void move();
// Graphic interface
void gui(int size);
int numbers(int num);
int** arr;




int main(){
    //Enter file name and say hello to players
    string file_name;
    cout<<"                   HELLO TO MY 2048 GAME" <<endl;
    cout<<"Enter name of the file new or saved game: "<<endl;
    cin>>file_name;
    const char *name=file_name.c_str();
    //Enter length and width and create matrix
    auto *size = new zero_point;
    arr= create_matrix( size->x, size->x);
    //load and create file
    //Load file
    fstream file1;
    file1.open(name,ios::in);
    if (!file1.fail()){

        file1>>size->x;
        for (int i = 0; i < size->x; ++i) {
            for (int j = 0; j < size->x; ++j) {
                file1>>arr[i][j];
            }
        }
    }else{
        //create file
        cout<<"Enter size of the board: "<<endl;
        cin>>size->x;
        for (int i = 0; i < size->x; ++i) {
            for (int j = 0; j < size->x; ++j) {
                arr[i][j]=0;
            }
        }
        //Random
        srand(time(nullptr));
        arr[rand()%size->x][rand()%size->y]=2;
        arr[rand()%size->x][rand()%size->y]=2;

    }
    file1.close();
    //Gui
    gui(size->x);

    //Delete array

    for (int i = 0; i < size->x; ++i) {
        delete[] arr[i];
    }
    delete [] arr;
    //Delete structure
    delete size;
    return 0;
}
int** create_matrix(int n,int m){
    int **tablica = new int*[n];
    for (int i = 0; i < n; ++i) {
        tablica[i] = new int [m];

    }
    return tablica;
}
void gui(int size){
auto* gui1 = new graphic_interface;

    for (gui1->r = 0;gui1->r  < size; ++gui1->r) {
        for (gui1->top = 1; gui1->top <= size ; ++gui1->top) {
            cout<<"   --------- ";
        }
        cout<<endl;

        for (gui1->x = 1; gui1->x <= 3; ++gui1->x) {
            for (gui1->l = 0; gui1->l < size; ++gui1->l) {
                if (gui1->x==2 && arr[gui1->r][gui1->l]!= 0){

                    cout << "  |    " << arr[gui1->r][gui1->l];
                    for (gui1->space = 0; gui1->space < 5- numbers(arr[gui1->r][gui1->l]); ++gui1->space)
                        cout<<" ";
                        cout<<"|";

                }else cout << "  |         |";
            }
            cout<<endl;
        }
        for (gui1->down = 1; gui1->down <= size; ++gui1->down) {
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