//assuming numbers are co-prime.
#include<bits/stdc++.h>

using namespace std;

//implementation of modInverse function
int modInverse(int r, int m){
	r %= m;
	for(int i = 1; i < m; i++){
		if((r*i)%m == 1)
		return i;
	}
	return -1;
}

int main(int argc, char **argv){
	vector<int> r, m, Mi, inv;
	int ind = 0, jnd = 0, M = 1, ans = 0;
	//taking input (ri's, mi's and M)
	for(int i = 1; i < argc;){
		r.push_back(atoi(argv[i]));
		m.push_back(atoi(argv[i + 1]));
		M = M*m[jnd++];
		i+=2;
	}
	//CRT step.
	for(int i = 0; i < m.size(); i++){
		Mi.push_back(M/m[i]);			//Mi = M/mi;
		int x = modInverse(Mi[i], m[i]);
		if(x == -1){cout<<"Does not exist :\n";exit(1);}
		else	inv.push_back(x);
	}

	for(int i = 0; i < m.size(); i++){
		ans += (r[i]*Mi[i]*inv[i]);
	}
	
	cout<<"X = "<<ans%M<<endl;
	return 0;
}
