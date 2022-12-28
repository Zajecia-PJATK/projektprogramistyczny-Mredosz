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



int** create_matrix(int n,int m);
void move();




int main(){
    //Enter file name and say hello to players
    string file_name;
    cout<<"                                             HELLO TO MY 2048 GAME" <<endl;
    cout<<"Enter name of the file new or saved game: "<<endl;
    cin>>file_name;
    const char *name=file_name.c_str();

    //Enter length and width and create matrix

   zero_point *size = new zero_point;

    int** arr= create_matrix( size->x, size->x);

    //load and create file
    //Load file
    fstream file1;
    file1.open(name,ios::in);
    if (!file1.is_open()){

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
        srand(time(0));
        arr[rand()%size->x][rand()%size->y]=2;
        arr[rand()%size->x][rand()%size->y]=2;

    }
    file1.close();


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