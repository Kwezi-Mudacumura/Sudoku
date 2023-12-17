#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdexcept>

using namespace std;
using std::stack;


bool validrows(vector<vector<int>>grid) {
    vector<int> check ;
    for (int i = 0; i < 9; ++i) {
       for (int k =0;k<9;++k) {
           if (grid[i][k] != 0) {
               check.push_back(grid[i][k]);
           }
       }
       for (int l=1; l <=9;++l){
           if (count(check.begin(),check.end(),l) > 1){
               return false;
           }
       }
       check.clear();
       }


    return true;

}
bool validcolumns(vector<vector<int>>grid){
    vector<int>hold;
    for (int i =0;i<9;++i){
        for (int k =0;k<9;++k){
            if (grid[k][i]!=0) {
                hold.push_back(grid[k][i]);
            }
        }
        for (int l =1; l<=9; ++l){
            if (count(hold.begin(),hold.end(),l)>1){
                return false;
            }
        }
        hold.clear();

    }
    return true;
}

bool validblock(vector<vector<int>>grid){
    vector<int>hold;
    for(int i =0;i<9;i=i+3){
        for(int k =0 ;k <3; ++k){
            if (grid[i][k]!= 0) {
                hold.push_back(grid[i][k]);
            }
            if (grid[i+1][k] != 0) {
                hold.push_back(grid[i+1][k]);
            }
            if (grid[i+2][k] != 0){
                hold.push_back(grid[i+2][k]);
            }

        }
        for (int l =1; l <= 9; ++l){
            if (count(hold.begin(),hold.end(),l) > 1){
                return false;
            }
        }
        hold.clear();
        for(int k =3 ;k <6; ++k) {
            if (grid[i][k] != 0) {
                hold.push_back(grid[i][k]);
            }
            if (grid[i + 1][k] != 0) {
                hold.push_back(grid[i + 1][k]);
            }
            if (grid[i + 2][k] != 0) {
                hold.push_back(grid[i + 2][k]);
            }
        }
        for (int l =1; l <= 9; ++l){
            if (count(hold.begin(),hold.end(),l) > 1){
                return false;
            }
        }
        hold.clear();
        for(int k =6 ;k <9; ++k) {
            if (grid[i][k] != 0) {
                hold.push_back(grid[i][k]);
            }
            if (grid[i + 1][k] != 0) {
                hold.push_back(grid[i + 1][k]);
            }
            if (grid[i + 2][k] != 0) {
                hold.push_back(grid[i + 2][k]);
            }
        }
        for (int l =1; l <= 9; ++l){
            if (count(hold.begin(),hold.end(),l) > 1){
                return false;
            }
        }
        hold.clear();

    }
    return true;
}
bool complete(vector<vector<int>> grid){
    for (int i =0; i <9 ;++i){
        for(int k =0; k<9; ++k){
            if (grid[i][k] ==0){
                return false;
            }
        }
    }
    return true;
}

vector<int> empty(vector<vector<int>>grid){
        vector<int>re;
        for (int i =0;i <9;++i){
            for (int k =0; k<9;++k){
                if (grid[i][k]==0){
                    re.push_back(i);
                    re.push_back(k);
                    return re;

                }
            }
        }
}

vector<vector<int>> solve(vector<vector<int>>grid){
    stack<pair<int,int>>button;
    vector<int>recent;
    while(complete(grid) == false){
        if ((validrows(grid)==false) || (validcolumns(grid) == false)||(validblock(grid) == false)){
           if ((recent[0] != (button.top()).first)&&(recent[1] != (button.top()).second)){
               button.push({recent[0],recent[1]});
           }

            while(grid[(button.top()).first][(button.top()).second] == 9 ){
                grid[(button.top()).first][(button.top()).second] =0;
                button.pop();
            }
            if (button.empty() == true){
                throw std::invalid_argument("No solution");
            }
            else{
                grid[(button.top()).first][(button.top()).second] += 1;
            }
        }
        else{
            recent= empty(grid);

            grid[recent[0]][recent[1]]=1;
            button.push({recent[0],recent[1]});
        }





    }
    return grid;


}


int main() {
    vector<vector<int>>grid;
    vector<int>hold;
    int holder =0;
    for (int n =0;n<9 ;++n){
            for (int m =0;m<9;++m){
                cin>>holder;
                hold.push_back(holder);
                holder =0;
            }
            grid[n] =hold;
            hold.clear();
    }




        grid = solve(grid);
        for (int i =0;i<9 ;++i){
            for (int k =0; k<9; ++k){
                cout<<grid[i][k]<<' ';
            }
            cout<<endl;
        }




}
