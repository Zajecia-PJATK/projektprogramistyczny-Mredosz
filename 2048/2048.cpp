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


int main(){

    zero_point *dimension = new zero_point;
    cout<<"Enter length of the board: "<<endl;
    cin>>dimension->length;
    cout<<"Enter width of the board: "<<endl;
    cin>>dimension->width;
    create_matrix( dimension->length, dimension->width);


    return 0;
}
int** create_matrix(int n,int m){

    int **tablica = new int*[n];
    for (int i = 0; i < n; ++i) {
        tablica[i] = new int [m];

    }
    return tablica;
}