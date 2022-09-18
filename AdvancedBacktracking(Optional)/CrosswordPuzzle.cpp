#include<bits/stdc++.h>
using namespace std;
vector<string>ans;
bool canFillHorizontally(vector<string>&crossword,int i,int j,string&word){
    int k;
    for(k=j;k<j+word.length()&&k<crossword[0].size();k++){
        if(crossword[i][k]!='-'&&crossword[i][k]!=word[k-j]){
            return false;
        }
    }
    if(k==j+word.length())
        return true;
    return false;
}
bool canFillVertically(vector<string>&crossword,int i,int j,string&word){
    int k;
    for(k=i;k<i+word.length()&&k<crossword.size();k++){
        if(crossword[k][j]!='-'&&crossword[k][j]!=word[k-i]){
            return false;
        }
    }
    if(k==i+word.length())
        return true;
    return false;
}
vector<int> fillHorizontally(vector<string>&crossword,int i,int j,string&word){
    vector<int>v;
    for(int k=j;k<j+word.length();k++){
        if(crossword[i][k]!='-'){
            v.push_back(k);
        }
        crossword[i][k]=word[k-j];
    }
    return v;
}
vector<int> fillVertically(vector<string>&crossword,int i,int j,string&word){
    vector<int>v;
    for(int k=i;k<i+word.length();k++){
        if(crossword[k][j]!='-'){
            v.push_back(k);
        }
        crossword[k][j]=word[k-i];
    }
    return v;
}
void unFillHorizontally(vector<string>&crossword,int i,int j,int len,vector<int>&v){
    int idx=0;
    for(int k=0;k<len;k++){
        if(!v.empty()&&v[idx]==k+j){
            idx++;
        }
        else{
            crossword[i][j+k]='-';
        }
    }
}
void unFillVertically(vector<string>&crossword,int i,int j,int len,vector<int>&v){
    int idx=0;
    for(int k=0;k<len;k++){
        if(!v.empty()&&v[idx]==k+i){
            idx++;
        }
        else{
            crossword[i+k][j]='-';
        }
    }
}
bool solve(vector<string>&crossword,vector<string>&words,int idx){
    if(idx==words.size()){
        ans=crossword;
        return true;
    }
    for(int i=0;i<crossword.size();i++){
        for(int j=0;j<crossword[0].size();j++){
            if(canFillHorizontally(crossword,i,j,words[idx])){
                vector<int>v=fillHorizontally(crossword,i,j,words[idx]);
                if(solve(crossword, words, idx+1))return true;
                unFillHorizontally(crossword,i,j,words[idx].length(),v);
            }
            if(canFillVertically(crossword,i,j,words[idx])){
                vector<int>v=fillVertically(crossword,i,j,words[idx]);
                if(solve(crossword,words,idx+1))return true;
                unFillVertically(crossword,i,j,words[idx].length(),v);
            }
        }
    }
    return false;
}
vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    ans.clear();
    vector<string>Words;
    char *ptr=strtok((char*)words.c_str(),";");
    Words.push_back((string)ptr);
    while(ptr){
        ptr=strtok(NULL,";");
        if(!ptr)break;
        Words.push_back((string)ptr);
    }
    solve(crossword,Words,0);
    return ans;
}
int main(){
	vector<string>crossword(10);
	for(int i=0;i<10;i++){
		cin>>crossword[i];
	}
	string words;
	cin>>words;
	vector<string>ans=crosswordPuzzle(crossword,words);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
}