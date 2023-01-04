//
// Created by mredo on 28.12.2022.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

#define size1 4

using namespace std;

struct graphic_interface{
    int r,l,top,down,space,x;
};

//void functions
void move(); //function to move
void gui();  // Graphic interface
void undo(); //undo players move
void game2();
void clear_screen();
void display_loser_screen();
void display_win_screen();
void display_start_screen();
void rotation(char option);

// int functions
int numbers(int num);
int max_tile();
int check_is_game_over();
int score();

//int** functions
int** create_matrix(int n,int m); // Create dynamic matrix


//global dynamic matrix
int** arr;


int main() {

    string file_name;
    arr = create_matrix(size1, size1); //create matrix


    display_start_screen();

    char choise;
    system("stty raw");
    cin >> choise;
    system("stty cooked");
    fstream file1;

    const char *name = file_name.c_str();
    int scoree = score();

        switch (choise) {
            //create new board
            case '1':
                cout << "Inster your name game\n";

                cin >> file_name;

                file1.open(name, ios::in);
                for (int i = 0; i < size1; ++i) {
                    for (int j = 0; j < size1; ++j) {
                        arr[i][j] = 0;
                    }
                }
                scoree = 0;
                //ADD random 2 at board
                srand(time(nullptr));
                arr[rand() % size1][rand() % size1] = 2;
                arr[rand() % size1][rand() % size1] = 2;
                file1.close();

                clear_screen();
                gui();

                while (true) {
                    if (check_is_game_over() == 1) {
                        game2();

                        file1.open(name, ios::out);

                        //save
                        for (int i = 0; i < size1; ++i) {
                            for (int j = 0; j < size1; ++j) {
                                file1 << arr[i][j] << endl;
                            }
                        }
                         file1 << scoree << endl;

                        file1.close();

                    }else if (check_is_game_over() == 2){
                        display_win_screen();
                        return 0;
                    } else if (check_is_game_over() == 0) {
                        display_loser_screen();
                        return 0;
                    }

                }
                break;
            case '2':
                cout << "Inster your name game\n";

                cin >> file_name;


                file1.open(name, ios::in);
                for (int i = 0; i < size1; ++i) {
                    for (int j = 0; j < size1; ++j) {
                        file1 >> arr[i][j];
                    }
                }
                file1 >> scoree;
                file1.close();
                gui();

                while (true){
                    if (check_is_game_over()==1) {

                        game2();
                        //save
                        file1.open(name, ios::out);

                        for (int i = 0; i < size1; ++i) {
                            for (int j = 0; j < size1; ++j) {
                                file1 << arr[i][j] << endl;
                            }
                        }
                        file1 << scoree << endl;

                        file1.close();
                    } else if (check_is_game_over() == 2){
                        display_win_screen();
                        return 0;
                    } else if (check_is_game_over() == 0){
                        display_loser_screen();
                        return 0;
                    }
                }
                break;
            case '3':
                cout << "This is instruction to 2048\n";
                cout << "This game is very simple.\n"
                        "To move you use the keys w (up), s (down), a (left), d (right).\n"
                        "The game is about connecting the same tiles together until you reach the 2048 tile.\n"
                        "When you run out of moves, the game is over.\n"
                        "Good luck";

                break;

            case '4':
                return 0;
                break;
        }

    //Delete array
    for (int i = 0; i < size1; ++i) {
        delete[] arr[i];
    }
    delete [] arr;

    delete name;

    return 0;
}
int** create_matrix(int n,int m){
    int **ar = new int*[n];
    for (int i = 0; i < n; ++i) {
        ar[i] = new int [m];

    }
    return ar;
}
void gui(){

    cout<<"The greatest tile is: "<<max_tile()<<endl<<endl;
    cout<<"SCORE: "<<score()<<endl;

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

    int shom,temp;

    for (int i = 0; i < size1; ++i) {

        shom = size1 -1;
        temp = -1;

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
void game2(){
    bool check;
    int random1;
    char option;

    check = true;
    while (check) {
        check = false;
        cout << "Insert your next move: ";
        system("stty raw");
        cin >> option;
        system("stty cooked");

        if (option != 'w' && option != 's' && option != 'a' && option != 'd' && option != 'q') {
            check = true;
            cout << "try these keys to move: \n"
                    "( w (up), s (down), a (left), d (right) )";
        }
    }
    clear_screen();
    rotation(option);
    move();

    if (option == 'a') {
        option = 'd';
    } else if (option == 'd') {
        option = 'a';
    }

    rotation(option);

    while (true) {
        random1 = rand() % size1;

        if (arr[random1][random1] == 0) {
            arr[random1][random1] = 2;
            break;
        }
    }
    gui();
}
int max_tile(){

    int max;
    max = arr[0][0];

    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size1; ++j) {
            if (arr[i][j]>max){
                max = arr[i][j];
            }
        }
    }
    return max;
}
void clear_screen(){
#ifdef WINDOWS
    system("cls");
#else
    // Assume POSIX
    system("clear");
#endif
}
int check_is_game_over() {

    int k = 0;

    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size1; ++j) {
            if (max_tile() == 2048) {
                k = 2;
            } else{
                k = 1;
            }
        }
    }
    return k;
}
void display_loser_screen(){
    system("clear");

    cout<<"\n\n\n\t\t\t  [ G A M E  O V E R ] "
        <<"\n\n\n\n\t\t\t TILE\t     SCORE\t ";
    cout<<"\n\n\t\t\t "<<max_tile()<<"\t     "<<score();

}
void display_win_screen(){
    system("clear");

    cout<<endl<<endl;
    cout<<"\n\t\t\t   [  YOU MADE 2048!  ] "
        <<"\n\n\t\t\t   [ YOU WON THE GAME ] "
        <<"\n\n\n\n\t\t\t TILE\t     SCORE\t";
    cout<<"\n\n\t\t\t "<<max_tile()<<"\t     "<<score();

}
void display_start_screen(){
    char zero;

    // say hello to players

    cout << "\t\t   ___       __   __ __       __     \n"
            "\t\t /'___`\\   /'__`\\/\\ \\\\ \\    /'_ `\\   \n"
            "\t\t/\\_\\ /\\ \\ /\\ \\/\\ \\ \\ \\\\ \\  /\\ \\L\\ \\  \n"
            "\t\t\\/_/// /__\\ \\ \\ \\ \\ \\ \\\\ \\_\\/_> _ <_ \n"
            "\t\t   // /_\\ \\\\ \\ \\_\\ \\ \\__ ,__\\/\\ \\L\\ \\\n"
            "\t\t  /\\______/ \\ \\____/\\/_/\\_\\_/\\ \\____/\n"
            "\t\t  \\/_____/   \\/___/    \\/_/   \\/___/ \n\n\n";

    cout<<"\t\t\tPress any key to continue\n";

    system("stty raw");
    cin>>zero;
    system("stty cooked");

    clear_screen();

    cout << "Chose option: " << endl;
    cout << "1. Start New Game\n";
    cout << "2. Load Previous Game\n";
    cout << "3. Instruction\n";
    cout << "4. Quit\n";
}
int score(){
    int score = 0;
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size1; ++j) {
            score+=(((log2(max_tile()))-1)*arr[i][j]);
        }
    }
    return score;
}