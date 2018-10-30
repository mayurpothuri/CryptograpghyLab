#include<bits/stdc++.h>
using namespace std;

//mx = 1+x+x3+x4+x8 -> 110110001

void get_xor(string &result, string &mx){
	int x = 0;
	for(int i = 0; i < mx.size(); i++){
		x = (result[i] - '0')^(mx[i] - '0');
		result[i] = x + '0';
	}
	return;
}

void leftShift(string &result, string &mx){
	reverse(result.begin(), result.end());
	result.erase(result.begin());
	result += '0';
	reverse(result.begin(), result.end());
	if(result[result.size() - 1] == '1')
		get_xor(result, mx);
	return;
}

void fastMultiply(string &fx, string &gx, string &mx){

	string result = "00000000";
	for(int i = 0; i < gx.size(); i++){
		if(i == 0){
			if(gx[i] == '1'){
				get_xor(result, fx);
			}
		}
		else{
			leftShift(fx, mx);
			if(gx[i] == '1')
				get_xor(result, fx);
		}
	}
	cout<<"(fx * gx)%mx = "<<result<<endl;
	return;
}

int main(int argc, char **argv){

	//here the fast multiplication is regarded with G.F(pow(2, 8)).
	//index of string represents the degree of polynomial.

	string fx, gx, mx = "11011000";//mx - x8 -> 11011000
	fx = argv[1];
	gx = argv[2];

	fastMultiply(fx, gx, mx);
	return 0;
}