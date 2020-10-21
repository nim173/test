#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
#define N 3

using namespace std;

void printMatrix(int matrix[][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int matrix[N][N] = {{2,2,0},{4,3,1},{2,0,0}};
	cout<<"Before"<<endl;
	printMatrix(matrix);
	cout<<endl;
	
	vector<stack<int> > v;
	for(int i=0;i<N;i++){
		stack<int> s;
		for(int j=N-1;j>=0;j--){
			if(matrix[j][i]!=0)
				s.push(matrix[j][i]);
		}
		if(s.size()!=N){
			while(s.size()!=N){
				s.push(0);
			}
		}
		v.push_back(s);
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			matrix[i][j]=v.at(j).top();
			v.at(j).pop();
		}
	}
	cout<<"After"<<endl;
	printMatrix(matrix);
	return 0;
}
