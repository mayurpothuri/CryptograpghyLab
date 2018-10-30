#include <bits/stdc++.h>
using namespace std;

map<string, int> btoi;
map<int, string> itob;
map<string, char> tohex;
vector<string> keyVec;
int ip[64]={58,50,42,34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,
    64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,
    59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,
    63,55,47,39,31,23,15,7};

int iip[64]={40,8,48,16,56,24,64,32,
    39,7,47,15,55,23,63,31,
    38,6,46,14,54,22,62,30,
    37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28,
    35,3,43,11,51,19,59,27,
    34,2,42,10,50,18,58,26,
    33,1,41,9,49,17,57,25};

int pc1[56]={57,49,41,33,25,17,9,
    1,58,50,42,34,26,18,
    10,2,59,51,43,35,27,
    19,11,3,60,52,44,36,
    63,55,47,39,31,23,15,
    7,62,54,46,38,30,22,
    14,6,61,53,45,37,29,
    21,13,5,28,20,12,4};

int pc2[48]={14,17,11,24,1,5,3,28,
    15,6,21,10,23,19,12,4,
    26,8,16,7,27,20,13,2,
    41,52,31,37,47,55,30,40,
    51,45,33,48,44,49,39,56,
    34,53,46,42,50,36,29,32};

int expa[48]={32,1,2,3,4,5,
    4,5,6,7,8,9,
    8,9,10,11,12,13,
    12,13,14,15,16,17,
    16,17,18,19,20,21,
    20,21,22,23,24,25,
    24,25,26,27,28,29,
    28,29,30,31,32,1};

int  perm[32]={16,7,20,21,29,12,28,17,
    1,15,23,26,5,18,31,10,
    2,8,24,14,32,27,3,9,
    19,13,30,6,22,11,4,25};

int leftshift[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

int sbox[8][4][16]={
            {{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
            {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
            {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
            {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}},
    
           {{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
            {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
            {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
            {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}},
        
          {{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
            {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
            {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
            {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}},
        
          {{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
            {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
            {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
            {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}},
        
          {{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
            {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
            {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
            {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}},
        
          {{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
            {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
            {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
            {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}},
        
           {{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
            {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
            {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
            {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}},
        
           {{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
            {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
            {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
            {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}}
           };

string to_binary(char c)
{
	switch(c)
	{
		case '0':return "0000";break;
		case '1':return "0001";break;
		case '2':return "0010";break;
		case '3':return "0011";break;
		case '4':return "0100";break;
		case '5':return "0101";break;
		case '6':return "0110";break;
		case '7':return "0111";break;
		case '8':return "1000";	break;
		case '9':return "1001";break;
		case 'A':return "1010";break;
		case 'B':return "1011";break;
		case 'C':return "1100";break;
		case 'D':return "1101";break;
		case 'E':return "1110";break;
		case 'F':return "1111";break;
	}
}

void fill_map()
{
	//binary to interger
	btoi["0000"]=0;  btoi["0001"]=1;
	btoi["0010"]=2;  btoi["0011"]=3;
	btoi["0100"]=4;  btoi["0101"]=5;
	btoi["0110"]=6;	 btoi["0111"]=7;
	btoi["1000"]=8;  btoi["1001"]=9;
	btoi["1010"]=10; btoi["1011"]=11;
	btoi["1100"]=12; btoi["1101"]=13;
	btoi["1110"]=14; btoi["1111"]=15;
	
	//interger to binary
	itob[0]="0000";  itob[1]="0001";
	itob[2]="0010";  itob[3]="0011";
	itob[4]="0100";  itob[5]="0101";
	itob[6]="0110";	 itob[7]="0111";
	itob[8]="1000";  itob[9]="1001";
	itob[10]="1010"; itob[11]="1011";
	itob[12]="1100"; itob[13]="1101";
	itob[14]="1110"; itob[15]="1111";
	
	//binary to hex
	tohex["0000"]='0';  tohex["0001"]='1';
	tohex["0010"]='2';  tohex["0011"]='3';
	tohex["0100"]='4';  tohex["0101"]='5';
	tohex["0110"]='6';  tohex["0111"]='7';
	tohex["1000"]='8';  tohex["1001"]='9';
	tohex["1010"]='A';  tohex["1011"]='B';
	tohex["1100"]='C';  tohex["1101"]='D';
	tohex["1110"]='E';  tohex["1111"]='F';
	return;
}

//get the binary form.
string hextobinary(string str)
{
	string ret="";
	for(int i = 0; i < str.length(); i++){
	    ret+=to_binary(str[i]);	
	}
	return ret;
}

//binary to hex.
string binarytohex(string str){
	
	string ret = "";
	for(int i = 0; i < str.size(); i += 4){
		ret += tohex[str.substr(i, 4)];
	}
	return ret;
}

//circular leftshift
string left_shift(string str, int n)
{
	string ret, temp;
	int i=0;
	for(i=0;i<n;i++) temp+=str[i];
	for(;i<28;i++) ret+=str[i];
	
	return ret+temp; 
}

//get all the 16 round subkeys.
void getKeys(string key){
	
	//for subkey generation --> Pc1 -> left shift --> Pc2 and cycle starts again from left shift for 16 rounds.
	string left = "", right = "", newLeft = "", newRight = "", temp = "", subkey = "";
	//pc1 step.
	for(int i = 0; i < 56; i++){
		temp += key[pc1[i] - 1];
	}
	left = temp.substr(0, 28);
	right = temp.substr(28);
	for(int i = 0; i < 16; i++){
		//circular leftshift part.
		
		newLeft = left_shift(left, leftshift[i]);
		newRight = left_shift(right, leftshift[i]);
		//pc2 step.
		key = newLeft + newRight;
		for(int j = 0; j < 48; j++){
			subkey += key[pc2[j] - 1];
		}
		keyVec.push_back(subkey);
		subkey.clear();
		left = newLeft;
		right = newRight;
	}
	return;
}

//decrption algorithm implementation.

void decrypt(string text){

	string temp = "";
	//IP step.
	for(int i = 0; i < 64; i++){
		temp += text[ip[i] - 1];
	}
	string  left = temp.substr(0, 32), right = temp.substr(32), newRight = "", subkey = "";
	int ind = 15;
	//16 rounds.
	for(int i = 0; i < 16; i++){
		string prevRight = right;
		//expansion step for right substring.
		for(int j = 0; j < 48; j++){
			newRight += right[expa[j] - 1];
		}
		//xor step with 16 rounds subkey.
		subkey = keyVec[ind];
		for(int j = 0; j < 48; j++){
			if(newRight[j] == subkey[j])
				newRight[j] = '0';
			else
				newRight[j] = '1';
		}
		//s-box step to convert 48-bit to 32-bit.
		int m = 0;
		right.clear();
		for(int j = 0; j < 48; j+=6){
			string str = newRight.substr(j, 6);
			string row = "00" + str.substr(0, 1) + str.substr(5, 1), col = str.substr(1, 4);
			right += itob[sbox[m++][btoi[row]][btoi[col]]];
		}
		//permutation step.
		newRight.clear();
		for(int j = 0; j < 32; j++){
			newRight += right[perm[j] - 1];
		}
		right.clear();
		//xor step.
		for(int j = 0; j < 32; j++){
			if(newRight[j] == left[j])
				right += '0';
			else
				right += '1';
		}
		newRight.clear();
		left = prevRight;
		cout<<"Subkey = "<<ind + 1<<" "<<binarytohex(keyVec[ind--])<<"\t"<<"L = "<<binarytohex(left)<<" : R = "<<binarytohex(right)<<endl;
	}
	//32-bit swap and inverse permutation step.
	temp = "";
	temp = left;
	left = right;
	right = temp;
	
	newRight = left + right;
	temp = "";
	for(int i = 0; i < 64; i++){
		temp += newRight[iip[i] - 1];
	}
	cout<<"Decrypted Text = "<<binarytohex(temp)<<endl;
	cout<<temp.size()<<endl;
	return;
}

//implementation of DES
void des(string text){

	string temp = "";
	//IP step.
	for(int i = 0; i < 64; i++){
		temp += text[ip[i] - 1];
	}
	string  left = temp.substr(0, 32), right = temp.substr(32), newRight = "", subkey = "";
	//16 rounds.
	for(int i = 0; i < 16; i++){
		string prevRight = right;
		//expansion step for right substring.
		for(int j = 0; j < 48; j++){
			newRight += right[expa[j] - 1];
		}
		//xor step with 16 rounds subkey.
		subkey = keyVec[i];
		for(int j = 0; j < 48; j++){
			if(newRight[j] == subkey[j])
				newRight[j] = '0';
			else
				newRight[j] = '1';
		}
		//s-box step to convert 48-bit to 32-bit.
		int m = 0;
		right.clear();
		for(int j = 0; j < 48; j+=6){
			string str = newRight.substr(j, 6);
			string row = "00" + str.substr(0, 1) + str.substr(5, 1), col = str.substr(1, 4);
			right += itob[sbox[m++][btoi[row]][btoi[col]]];
		}
		//permutation step.
		newRight.clear();
		for(int j = 0; j < 32; j++){
			newRight += right[perm[j] - 1];
		}
		right.clear();
		//xor step.
		for(int j = 0; j < 32; j++){
			if(newRight[j] == left[j])
				right += '0';
			else
				right += '1';
		}
		newRight.clear();
		left = prevRight;
		cout<<"Subkey = "<<i + 1<<" "<<binarytohex(keyVec[i])<<"\t"<<"L = "<<binarytohex(left)<<" : R = "<<binarytohex(right)<<endl;
	}
	//32-bit swap and inverse permutation step.
	temp = "";
	temp = left;
	left = right;
	right = temp;
	
	newRight = left + right;
	temp = "";
	for(int i = 0; i < 64; i++){
		temp += newRight[iip[i] - 1];
	}
	cout<<"Encrypted Text = "<<binarytohex(temp)<<endl;
	cout<<temp.size()<<endl;
	//decrption step.
	decrypt(temp);
	return;
}

int main(int argc, char **argv){

	fill_map();
	string newKey = "", newText = "", text = argv[1], key = argv[2];
	newKey = hextobinary(key);
	newText = hextobinary(text);
	//get all keys.
	getKeys(newKey);
	//call des
	des(newText);
	return 0;
}
/*
02468ACEECA86420
0F1571C947D9E859
*/


