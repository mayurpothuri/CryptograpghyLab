#include<bits/stdc++.h>

using namespace std;

void clear_zeros(string &v)
{
	while(v.size()>0 && v[0] == 0)
	{
		v.erase(v.begin());
	}
	return;
}

bool is_greater(string &A, string &B)
{
	int len1,len2;
	len1 = A.size();
	len2 = B.size();

	if(len1 > len2) return true;
	if(len1 < len2) return false;

	for(int i = 0; i < len1; i++){
		if(A[i] > B[i]) return true;
		if(A[i] < B[i]) return false;
	}
	return true;
}

string subtract(string A, string B)
{
	int len1,len2;
	len1 = A.size();
	len2 = B.size();

	int ind = len1-1;
	int jnd = len2-1;

	int borrow = 0;
	while(ind >= 0 && jnd >= 0)
	{
		if(A[ind] >= B[jnd])
		{
			A[ind] -= B[jnd] - '0';
			ind--;
			jnd--;
		}
		else
		{
			int k = ind-1;
			while(A[k] - '0' == 0)
			{
				k--;
			}
			A[k]--;
			k++;
			while(k!=ind)
			{
				A[k] = 9 + '0';
				k++;
			}
			A[ind] = A[ind] - '0' + 10 - B[jnd] - '0';
			ind--;
			jnd--;
		}
	}
	clear_zeros(A);
	return A;
}

string addMod(string a, string b, string n){
	string res;
	if(a > b)
	swap(a, b);

	//addition code
	int c = 0, i = a.size() - 1, j = b.size() - 1;
	while(i >= 0 && j >= 0){
		int x = a[i--] - '0', y = b[j--] - '0';
		int temp = (x + y + c)%10;
		res += temp + '0';
		int c = (x + y + c)/10;;
	}
	while(i >= 0){
		res += a[i--];
	}
	while(j >= 0){
		res += b[j--];
	}
	reverse(res.begin(), res.end());
	clear_zeros(res);
	//modulo code
	while(is_greater(res, n)){

	    res = subtract(res, n);
	    clear_zeros(res);
	}
	return res;
}

int main(int argc, char **argv){

	string a, b, n;
	a = argv[1];
	b = argv[2];
	n = argv[3];
	//cin>>a>>b>>n;

	//addition modulo
	string res = addMod(a, b, n);
	cout<<res<<endl;
	return 0;
}
