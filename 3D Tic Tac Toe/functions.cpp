
#include <iostream>
#include <stdlib.h>
#include "functions.hpp"

using namespace std;
void greetAndInstruct(){
    string input;
    cout<< "Hello and welcome to the Tic-Tac_toe challgenge: Player against Computer.\n" << endl << "The board is numbered from 1 to 17 as per the following:\n";
    cout<< "1|2|3                 10|11|12              19|20|21\n";
    cout<< "-----                 --------              --------\n";
    cout<< "4|5|6                 12|14|15              22|23|24\n";
    cout<< "-----                 --------              --------\n";
    cout<< "7|8|9                 16|17|18              25|26|27\n";
    cout<< "Player starts first. Simply input the number of the cell you want to occupy. Player's move is marked with X. Computer's move is marked with O.\n";
    cout<<"Start?(y/n)";
    cin>> input;
    if(input == "y"){
        cout << "Game start" <<endl;
    } else if (input == "n"){
        exit(2);
    }else{
        cout<< "Unidentified input!\n";
        exit(3);
    }
}

void displayBoard (char board[]){
    string boardnum[]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27"};
    for (int i=0; i<27; i++){
        if(board[i]=='X'){
            boardnum[i]="X";
        } else if (board[i]=='O' ){
            boardnum[i]="O";
        }
    }
    cout<<boardnum[0]<<'|'<<boardnum[1]<<'|'<<boardnum[2]<<"       "<<boardnum[9]<<'|'<<boardnum[10]<<'|'<<boardnum[11]<<"       "<<boardnum[18]<<'|'<<boardnum[19]<<'|'<<boardnum[20]<<"\n";
    cout<< "-----       --------       --------\n";
    cout<<boardnum[3]<<'|'<<boardnum[4]<<'|'<<boardnum[5]<<"       "<<boardnum[12]<<'|'<<boardnum[13]<<'|'<<boardnum[14]<<"       "<<boardnum[21]<<'|'<<boardnum[22]<<'|'<<boardnum[23]<<"\n";
    cout<< "-----       --------       --------\n";
    cout<<boardnum[6]<<'|'<<boardnum[7]<<'|'<<boardnum[8]<<"       "<<boardnum[15]<<'|'<<boardnum[16]<<'|'<<boardnum[17]<<"       "<<boardnum[24]<<'|'<<boardnum[25]<<'|'<<boardnum[26]<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Question 3(1)
bool checkIfLegal​ (int cellNbre, char board[]){
    //out of range checking
    if (cellNbre<0 || cellNbre>26){
        cout<<"input out of range!!";
        return false;
    }
    //occupied checking
    else if (board[cellNbre]=='X' || board[cellNbre]=='O'){
        cout<<"Already occpied!!";
        return false;
    }
    else{
        return true;
    }
}

bool checkWinner(char board[]){
    //check  palyer X
     //clue used to check different table
     int clue[]={0,0,0,0,0,0,0,0,0};
     int x[3][9]={{false,false,false,false,false,false,false,false,false,},{false,false,false,false,false,false,false,false,false,}
                 ,{false,false,false,false,false,false,false,false,false,}};
    //choose all the 'X'
    for(int j=0;j<3;j++){
        //start=9*j-1
        int start=j*9;
        int end=j*9+9;
         for(int i =0;i<9;i++){
             if (board[start+i]=='X'){
                 x[j][i]=true;
                 int a=clue[i];
                 clue[i]=a+1;
                 //cout<<clue[i];
                 //cout<<i<<"\n";
                 //check 3 table same position
                 if (clue[i]==3){
                     //cout<<clue[i];
                     cout<<"Player win\n!";
                     exit(1);
                     return true;
                 }
             }
         }
         //check the same table
         if (x[j][0]==true && x[j][3]==true && x[j][6]==true){
             
             cout<<"Player win\n!";
             exit(1);
             return true;
             
         }else if(x[j][1]==true && x[j][4]==true && x[j][7]==true){
             cout<<"Player win\n!";
             exit(1);
             return true;
         }else if(x[j][2]==true && x[j][5]==true && x[j][8]==true){
             cout<<"Player win\n!";
             exit(1);
             return true;
         }else if(x[j][0]==true && x[j][1]==true && x[j][2]==true){
             cout<<"Player win\n!";
             exit(1);
             return true;
         }else if(x[j][3]==true && x[j][4]==true && x[j][5]==true){
             cout<<"Player win\n!";
             exit(1);
             return true;
         }else if(x[j][6]==true && x[j][7]==true && x[j][8]==true){
             cout<<"Player win\n!";
             exit(1);
             return true;
         }else if(x[j][0]==true && x[j][4]==true && x[j][8]==true){
             cout<<"Player win\n!";
             exit(1);
             return true;
         }else if(x[j][2]==true && x[j][4]==true && x[j][6]==true){
             cout<<"Player win\n!";
             exit(1);
             return true;
         }
    }
     //check different table
     //0-12-24
     for(int i=0;i<3;i++){
         if(board[0+i]=='X'&& board[12+i]=='X'&&board[24+i]=='X'){
             cout<<"Player win\n!";
             exit(1);
             return true;
         }
     }
     //6-12-18
     for(int i=0;i<3;i++){
         if(board[6+i]=='X'&& board[12+i]=='X'&&board[18+i]=='X'){
             cout<<"Player win\n!";
             exit(1);
                 return true;
         }
     }
     //6-10-20
     for(int i=0;i<7;i=i+3){
         if(board[0+i]=='X'&& board[10+i]=='X'&&board[20+i]=='X'){
             cout<<"Player win\n!";
             exit(1);
                 return true;
         }
     }
     //2-20-28
      for(int i=0;i<7;i=i+3){
         if(board[2+i]=='X'&& board[20+i]=='X'&&board[28+i]=='X'){
             cout<<"Player win\n!";
             exit(1);
                 return true;
         }
     }
     //2 diagonal
     if(board[0]=='X'&& board[13]=='X'&&board[26]=='X'){
             cout<<"Player win\n!";
             exit(1);
                 return true;
     }
     if(board[6]=='X'&& board[13]=='X'&&board[20]=='X'){
             cout<<"Player win\n!";
             exit(1);
                 return true;
     }


     
     

     ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

     //check  computer  O
     //clue used to check different table
     int clue1[]={0,0,0,0,0,0,0,0,0};
     int o[3][9]={{false,false,false,false,false,false,false,false,false,},{false,false,false,false,false,false,false,false,false,}
                 ,{false,false,false,false,false,false,false,false,false,}};
    //choose all the 'O'
    for(int j=0;j<3;j++){
        //start=9*j-1
        int start=j*9;
        int end=j*9+9;
         for(int i =0;i<9;i++){
             if (board[i+start]=='O'){
                 o[j][i]=true;
                 clue1[i]=clue1[i]+1;
                 //check 3 table same position
                 if (clue1[i]==3){
                     cout<<"Computer win!\n";
                     exit(1);
                     return true;
                 }
             }
         }
         //check the same table
         if (o[j][0]==true && o[j][3]==true && o[j][6]==true){
             cout<<"Computer win!\n";
             exit(1);
             return true;
         }else if(o[j][1]==true && o[j][4]==true && o[j][7]==true){
             cout<<"Computer win!\n";
             exit(1);
             return true;
         }else if(o[j][2]==true && o[j][5]==true && o[j][8]==true){
             cout<<"Computer win!\n";
             exit(1);
             return true;
         }else if(o[j][0]==true && o[j][1]==true && o[j][2]==true){
             cout<<"Computer win!\n";
             exit(1);
             return true;
         }else if(o[j][3]==true && o[j][4]==true && o[j][5]==true){
            cout<<"Computer win!\n";
            exit(1);
             return true;
         }else if(o[j][6]==true && o[j][7]==true && o[j][8]==true){
             cout<<"Computer win!\n";
             exit(1);
             return true;
         }else if(o[j][0]==true && o[j][4]==true && o[j][8]==true){
             cout<<"Computer win!\n";
             exit(1);
             return true;
         }else if(o[j][2]==true && o[j][4]==true && o[j][6]==true){
             cout<<"Computer win!\n";
             exit(1);
             return true;
         }
    }
     //check different table
     //0-12-24
     for(int i=0;i<3;i++){
         if(board[0+i]=='O'&& board[12+i]=='O'&&board[24+i]=='O'){
             cout<<"Player win\n!";
             exit(1);
                 return true;
         }
     }
     //6-12-18
     for(int i=0;i<3;i++){
         if(board[6+i]=='O'&& board[12+i]=='O'&&board[18+i]=='O'){
             cout<<"Player win\n!";
             exit(1);
                 return true;
         }
     }
      //6-10-20
     for(int i=0;i<7;i=i+3){
         if(board[0+i]=='O'&& board[10+i]=='O'&&board[20+i]=='O'){
             cout<<"Player win\n!";
             exit(1);
                 return true;
         }
     }
     //2-20-28
      for(int i=0;i<7;i=i+3){
         if(board[2+i]=='O'&& board[20+i]=='O'&&board[28+i]=='O'){
             cout<<"Player win\n!";
             exit(1);
                 return true;
         }
     }

     //2 diagonal
     if(board[0]=='O'&& board[13]=='O'&&board[26]=='O'){
             cout<<"Player win\n!";
             exit(1);
                 return true;
     }
     if(board[6]=='O'&& board[13]=='O'&&board[20]=='O'){
             cout<<"Player win\n!";
             exit(1);
                 return true;
     }

     //check if tie
     int space=0;
     for (int i=0; i<27; i++){
         if (board[i]!='O' || board[i]!='X'){
             space=space+1;
         }
     }
     if (space==0){
         cout<<"A tie exists!";
         exit(1);
         return true;
     }
     return false;
}

//Move method
void Move(char input, int position, char board[]){
    board[position]=input;
}

void computerMove(char board[]){
    if(winNextRound(board)!=100){
        cout<< "Computer played: " << winNextRound(board)+1 << "\n";
        Move('O', winNextRound(board), board);
    } else{
        int a=26;
            while(board[a]!='\0'){
                a--;
            }
            Move('O', a, board);
        cout<< "Computer played: " << a+1 << "\n";
    }
    displayBoard(board);
}

//predict neat move
int winNextRound(char board[]){
    //2d horizontal
    for(int i=0; i<3; i++){
        int a=0;
        a=a+9*i;
        if(board[a]==board[a+1] && board[a]=='X' && board[a+2]!='X' && board[a+2]!='O'){
            return a+2;
        } else if(board[a+1]==board[a+2] && board[a]=='X'&& board[a]!='X' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+2] && board[a]=='X' && board[a+1]!='X' && board[a+1]!='O'){
            return a+1;
        }else if(board[a]==board[a+1] && board[a]=='O' && board[a+2]!='O' && board[a+2]!='O'){
            return a+2;
        } else if(board[a]==board[a+2] && board[a]=='O' && board[a]!='O' && board[a]!='O'){
            return a;
        }else if(board[a]==board[a+2] && board[a]=='O' && board[a+1]!='O' && board[a+1]!='O'){
            return a+1;
        }
    }
    
    for(int i=0; i<3; i++){
        int a=3;
        a=a+9*i;
        if(board[a]==board[a+1] && board[a]=='X' && board[a+2]!='X' && board[a+2]!='O'){
            return a+2;
        } else if(board[a+1]==board[a+2] && board[a]=='X'&& board[a]!='X' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+2] && board[a]=='X' && board[a+1]!='X' && board[a+1]!='O'){
            return a+1;
        }else if(board[a]==board[a+1] && board[a]=='O' && board[a+2]!='O' && board[a+2]!='O'){
            return a+2;
        } else if(board[a]==board[a+2] && board[a]=='O' && board[a]!='O' && board[a]!='O'){
            return a;
        }else if(board[a]==board[a+2] && board[a]=='O' && board[a+1]!='O' && board[a+1]!='O'){
            return a+1;
        }
    }
    
    for(int i=0; i<3; i++){
        int a=6;
        a=a+9*i;
        if(board[a]==board[a+1] && board[a]=='X' && board[a+2]!='X' && board[a+2]!='O'){
            return a+2;
        } else if(board[a+1]==board[a+2] && board[a]=='X'&& board[a]!='X' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+2] && board[a]=='X' && board[a+1]!='X' && board[a+1]!='O'){
            return a+1;
        }else if(board[a]==board[a+1] && board[a]=='O' && board[a+2]!='O' && board[a+2]!='O'){
            return a+2;
        } else if(board[a]==board[a+2] && board[a]=='O' && board[a]!='O' && board[a]!='O'){
            return a;
        }else if(board[a]==board[a+2] && board[a]=='O' && board[a+1]!='O' && board[a+1]!='O'){
            return a+1;
        }
    }
    
    //2d vertical
    for(int i=0; i<3; i++){
        int a=0;
        a=a+9*i;
        if(board[a]==board[a+3] && board[a]=='X' && board[a+6]!='X' && board[a+6]!='O'){
            return a+6;
        } else if(board[a+3]==board[a+6] && board[a]=='X'&& board[a]!='X' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+6] && board[a]=='X' && board[a+3]!='X' && board[a+3]!='O'){
            return a+3;
        }else if(board[a]==board[a+3] && board[a]=='O' && board[a+6]!='O' && board[a+6]!='O'){
            return a+6;
        } else if(board[a]==board[a+6] && board[a]=='O' && board[a]!='O' && board[a]!='O'){
            return a;
        }else if(board[a]==board[a+6] && board[a]=='O' && board[a+3]!='O' && board[a+3]!='O'){
            return a+3;
        }
    }
    
    for(int i=0; i<3; i++){
        int a=1;
        a=a+9*i;
        if(board[a]==board[a+3] && board[a]=='X' && board[a+6]!='X' && board[a+6]!='O'){
            return a+6;
        } else if(board[a+3]==board[a+6] && board[a]=='X'&& board[a]!='X' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+6] && board[a]=='X' && board[a+3]!='X' && board[a+3]!='O'){
            return a+3;
        }else if(board[a]==board[a+3] && board[a]=='O' && board[a+6]!='O' && board[a+6]!='O'){
            return a+6;
        } else if(board[a]==board[a+6] && board[a]=='O' && board[a]!='O' && board[a]!='O'){
            return a;
        }else if(board[a]==board[a+6] && board[a]=='O' && board[a+3]!='O' && board[a+3]!='O'){
            return a+3;
        }
    }
    
    for(int i=0; i<3; i++){
        int a=2;
        a=a+9*i;
        if(board[a]==board[a+3] && board[a]=='X' && board[a+6]!='X' && board[a+6]!='O'){
            return a+6;
        } else if(board[a+3]==board[a+6] && board[a]=='X'&& board[a]!='X' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+6] && board[a]=='X' && board[a+3]!='X' && board[a+3]!='O'){
            return a+3;
        }else if(board[a]==board[a+3] && board[a]=='O' && board[a+6]!='O' && board[a+6]!='O'){
            return a+6;
        } else if(board[a]==board[a+6] && board[a]=='O' && board[a]!='O' && board[a]!='O'){
            return a;
        }else if(board[a]==board[a+6] && board[a]=='O' && board[a+3]!='O' && board[a+3]!='O'){
            return a+3;
        }
    }
    
    //2D diagonal
    for(int i=0; i<3; i++){
        int a=0;
        a=a+9*i;
        if(board[a]==board[a+4] && board[a]=='X' && board[a+8]!='X' && board[a+8]!='O'){
            return a+8;
        } else if(board[a+4]==board[a+8] && board[a]=='X'&& board[a]!='X' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+8] && board[a]=='X' && board[a+4]!='X' && board[a+4]!='O'){
            return a+4;
        }else if(board[a]==board[a+4] && board[a]=='O' && board[a+8]!='O' && board[a+8]!='O'){
            return a+8;
        } else if(board[a]==board[a+8] && board[a]=='O' && board[a]!='O' && board[a]!='O'){
            return a;
        }else if(board[a]==board[a+8] && board[a]=='O' && board[a+4]!='O' && board[a+4]!='O'){
            return a+4;
        }
    }
    
    for(int i=0; i<3; i++){
        int a=2;
        a=a+9*i;
        if(board[a]==board[a+2] && board[a]=='X' && board[a+4]!='X' && board[a+4]!='O'){
            return a+4;
        } else if(board[a+2]==board[a+4] && board[a]=='X'&& board[a]!='X' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+4] && board[a]=='X' && board[a+2]!='X' && board[a+2]!='O'){
            return a+2;
        }else if(board[a]==board[a+2] && board[a]=='O' && board[a+4]!='O' && board[a+4]!='O'){
            return a+4;
        } else if(board[a+2]==board[a+4] && board[a]=='O' && board[a]!='O' && board[a]!='O'){
            return a;
        }else if(board[a]==board[a+4] && board[a]=='O' && board[a+2]!='O' && board[a+2]!='O'){
            return a+2;
        }
    }
    
    //3D horizontal
    for(int i=0; i<3; i++){
        int a=0;
        a=a+3*i;
        if(board[a]==board[a+10] && board[a]=='X' && board[a+20]!='X' && board[a+20]!='O'){
            return a+20;
        } else if(board[a+10]==board[a+20] && board[a]=='X'&& board[a]!='X' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+20] && board[a]=='X' && board[a+10]!='X' && board[a+10]!='O'){
            return a+10;
        }else if(board[a]==board[a+10] && board[a]=='O' && board[a+20]!='O' && board[a+20]!='O'){
            return a+20;
        } else if(board[a+10]==board[a+20] && board[a]=='O' && board[a]!='O' && board[a]!='O'){
            return a;
        }else if(board[a]==board[a+20] && board[a]=='O' && board[a+10]!='O' && board[a+10]!='O'){
            return a+10;
        }
    }
    
    for(int i=0; i<3; i++){
        int a=2;
        a=a+3*i;
        if(board[a]==board[a+8] && board[a]=='X' && board[a+16]!='X' && board[a+16]!='O'){
            return a+16;
        } else if(board[a+8]==board[a+16] && board[a]=='X'&& board[a]!='X' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+16] && board[a]=='X' && board[a+8]!='X' && board[a+8]!='O'){
            return a+8;
        } else if(board[a]==board[a+8] && board[a]=='O' && board[a+16]!='O' && board[a+16]!='O'){
            return a+16;
        } else if(board[a+8]==board[a+16] && board[a]=='O' && board[a]!='O' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+16] && board[a]=='O' && board[a+8]!='O' && board[a+8]!='O'){
            return a+8;
        }
    }
    
    //3D vertical
    for(int i=0; i<3; i++){
        int a=0;
        a=a+3*i;
        if(board[a]==board[a+9] && board[a]=='X' && board[a+18]!='X' && board[a+18]!='O'){
            return a+18;
        } else if(board[a+9]==board[a+18] && board[a]=='X'&& board[a]!='X' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+18] && board[a]=='X' && board[a+9]!='X' && board[a+9]!='O'){
            return a+9;
        } else if(board[a]==board[a+9] && board[a]=='O' && board[a+18]!='O' && board[a+18]!='O'){
            return a+18;
        } else if(board[a+9]==board[a+18] && board[a]=='O' && board[a]!='O' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+18] && board[a]=='O' && board[a+9]!='O' && board[a+9]!='O'){
            return a+9;
        }
    }
    
    for(int i=0; i<3; i++){
        int a=1;
        a=a+3*i;
        if(board[a]==board[a+9] && board[a]=='X' && board[a+18]!='X' && board[a+18]!='O'){
            return a+18;
        } else if(board[a+9]==board[a+18] && board[a]=='X'&& board[a]!='X' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+18] && board[a]=='X' && board[a+9]!='X' && board[a+9]!='O'){
            return a+9;
        } else if(board[a]==board[a+9] && board[a]=='O' && board[a+18]!='O' && board[a+18]!='O'){
            return a+18;
        } else if(board[a+9]==board[a+18] && board[a]=='O' && board[a]!='O' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+18] && board[a]=='O' && board[a+9]!='O' && board[a+9]!='O'){
            return a+9;
        }
    }
    
    for(int i=0; i<3; i++){
        int a=2;
        a=a+3*i;
        if(board[a]==board[a+9] && board[a]=='X' && board[a+18]!='X' && board[a+18]!='O'){
            return a+18;
        } else if(board[a+9]==board[a+18] && board[a]=='X'&& board[a]!='X' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+18] && board[a]=='X' && board[a+9]!='X' && board[a+9]!='O'){
            return a+9;
        } else if(board[a]==board[a+9] && board[a]=='O' && board[a+18]!='O' && board[a+18]!='O'){
            return a+18;
        } else if(board[a+9]==board[a+18] && board[a]=='O' && board[a]!='O' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+18] && board[a]=='O' && board[a+9]!='O' && board[a+9]!='O'){
            return a+9;
        }
    }
    
    //3D diagonal
    for(int i=0; i<3; i++){
        int a=0;
        a=a+i;
        if(board[a]==board[a+12] && board[a]=='X' && board[a+24]!='X' && board[a+24]!='O'){
            return a+24;
        } else if(board[a+12]==board[a+24] && board[a]=='X'&& board[a]!='X' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+24] && board[a]=='X' && board[a+12]!='X' && board[a+12]!='O'){
            return a+12;
        } else if(board[a]==board[a+12] && board[a]=='O' && board[a+24]!='O' && board[a+24]!='O'){
            return a+24;
        } else if(board[a+12]==board[a+24] && board[a]=='O' && board[a]!='O' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+24] && board[a]=='O' && board[a+12]!='O' && board[a+12]!='O'){
            return a+12;
        }
    }
    
    for(int i=0; i<3; i++){
        int a=6;
        a=a+i;
        if(board[a]==board[a+6] && board[a]=='X' && board[a+12]!='X' && board[a+12]!='O'){
            return a+12;
        } else if(board[a+6]==board[a+12] && board[a]=='X'&& board[a]!='X' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+12] && board[a]=='X' && board[a+6]!='X' && board[a+6]!='O'){
            return a+6;
        } else if(board[a]==board[a+6] && board[a]=='O' && board[a+12]!='O' && board[a+12]!='O'){
            return a+12;
        } else if(board[a+6]==board[a+12] && board[a]=='O' && board[a]!='O' && board[a]!='O'){
            return a;
        } else if(board[a]==board[a+12] && board[a]=='O' && board[a+6]!='O' && board[a+6]!='O'){
            return a+6;
        }
    }
    
    int a=0;
    if(board[a]==board[a+13] && board[a]=='X' && board[a+26]!='X' && board[a+26]!='O'){
        return a+26;
    } else if(board[a+13]==board[a+26] && board[a]=='X'&& board[a]!='X' && board[a]!='O'){
        return a;
    } else if(board[a]==board[a+26] && board[a]=='X' && board[a+13]!='X' && board[a+13]!='O'){
        return a+13;
    } else if(board[a]==board[a+13] && board[a]=='O' && board[a+26]!='O' && board[a+26]!='O'){
        return a+26;
    } else if(board[a+13]==board[a+26] && board[a]=='O' && board[a]!='O' && board[a]!='O'){
        return a;
    } else if(board[a]==board[a+26] && board[a]=='O' && board[a+13]!='O' && board[a+13]!='O'){
        return a+13;
    }
    
    int b=6;
    if(board[b]==board[b+7] && board[b]=='X' && board[b+14]!='X' && board[b+14]!='O'){
        return b+14;
    } else if(board[b+7]==board[b+14] && board[b]=='X'&& board[b]!='X' && board[b]!='O'){
        return b;
    } else if(board[b]==board[b+14] && board[b]=='X' && board[b+7]!='X' && board[b+7]!='O'){
        return b+7;
    } else if(board[b]==board[a+7] && board[b]=='O' && board[b+14]!='O' && board[b+14]!='O'){
        return b+14;
    } else if(board[b+7]==board[b+14] && board[b]=='O' && board[b]!='O' && board[b]!='O'){
        return b;
    } else if(board[b]==board[b+14] && board[b]=='O' && board[b+7]!='O' && board[b+7]!='O'){
        return b+7;
    }
    return 100;
}
