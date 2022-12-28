//
// Created by mredo on 28.12.2022.
//

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


struct zero_point{
    int i,j,length,width;
};

int** create_matrix(int n,int m);
void move();




int main(){
    //Enter file name and say hello to players
    string file_name;
    cout<<"                                             HELLO TO MY 2048 GAME" <<endl;
    cin>>file_name;

    //Enter length and width and create matrix

    zero_point *dimension = new zero_point;
    cout<<"Enter length of the board: "<<endl;
    cin>>dimension->length;
    cout<<"Enter width of the board: "<<endl;
    cin>>dimension->width;
   int** arr= create_matrix( dimension->length, dimension->width);


    return 0;
}
int** create_matrix(int n,int m){

    int **tablica = new int*[n];
    for (int i = 0; i < n; ++i) {
        tablica[i] = new int [m];

    }
    return tablica;
}