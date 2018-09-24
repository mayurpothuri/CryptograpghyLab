#include<bits/stdc++.h>

using namespace std;
	
void printMatrix(char matrix[][5]){
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return;
}

void getMatrix(string key, char matrix[][5], char *m){
	
	
	int i = 0, j = 0, k = 0;
	for(k = 0; k < key.size(); k++){
		if(j == 5){
		   j = 0;
		   i++;
		}
		matrix[i][j] = key[k];
		m[ matrix[i][j++] - 'a' ] = 1;
	}
	
	for(int p=0;p<26;p++)
	{
		if(m[p] == 0)
		{
			matrix[i][j] = 'a'+ p;
			m[p] = 1;
			j++;
			if(j == 5)
			{
				j = 0;
				i++;
			}
		}
	}
	return;
}

string groupingMessage(string message){

	int ind = 0;
	string temp;
	while(ind < message.length())
	{
		if(ind == message.length()-1)
		{
			temp.push_back(message[ind]);
			ind++;
			continue;
		}
		char a,b;
		a = message[ind];
		b = message[ind+1];

		if(a==b)
		{
			b = 'x';
			ind+=2;
		}
		else
		{
			ind+=2;
		}
		temp.push_back(a);
		temp.push_back(b);
	
	}
	int len = message.size();
	if(len%2 == 1)
	{
		temp.push_back('x');
	}
	return temp;
}

void search_mat(char mat[5][5],char ch,int &row,int &col)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(mat[i][j] == ch)
			{
				row = i;
				col = j;
				return;
			}
		}
	}
}

string getCipher(string text,char mat[5][5],bool encrypt)
{
	string res;
	int len = text.length();
	for(int i=0;i<len-1;i+=2)
	{
		int r1,c1;
		int r2,c2;
		char a,b;
		a = text[i];
		b = text[i+1];

		search_mat(mat,a,r1,c1);
		search_mat(mat,b,r2,c2);

		if(r1 != r2 && c1 != c2)
		{
			swap(r1,r2);
			res.push_back(mat[r2][c2]);
			res.push_back(mat[r1][c1]);	
		}
		else if(r1 == r2)
		{
			if(encrypt)
			{
				c1 = (c1+1)%5;
				c2 = (c2+1)%5;	
			}
			else
			{
				c1 = (c1+4)%5;
				c2 = (c2+4)%5;
			}
			res.push_back(mat[r1][c1]);
			res.push_back(mat[r2][c2]);
		}
		else
		{
			if(encrypt)
			{
				r1 = (r1+1)%5;
				r2 = (r2+1)%5;
			}
			else
			{
				r1 = (r1+4)%5;
				r2 = (r2+4)%5;
			}
			res.push_back(mat[r1][c1]);
			res.push_back(mat[r2][c2]);
		}

	}
	if(!encrypt)
	{
		len = res.length();
		string ans;
		for(int i=0;i<len;i++)
		{
			if(i!=0 && i!=len-1 && res[i] == 'x' && res[i-1]==res[i+1])
			{
				
			}
			else
			{
				ans.push_back(res[i]);
			}
		}
		return ans;
	}
	
	return res;
}

int main(int argc, char **argv){
	
	string key = argv[1];
	string message = argv[2];
	
	char matrix[5][5] = {};
	char m[26] = {};
	//getting matrix
	getMatrix(key, matrix, m);
	//print matrix
	printMatrix(matrix);
	//grouping message
	string temp = groupingMessage(message);
	cout<<"Groupped Text : "<<temp<<endl;
	//getting encrypted message.
	string encryptedText = getCipher(temp, matrix, true);
	cout<<"Encrypted Text : "<<encryptedText<<endl;
	encryptedText = getCipher(encryptedText, matrix, false);
	cout<<"Decrypted Text : "<<encryptedText<<endl;
	return 0;
}
