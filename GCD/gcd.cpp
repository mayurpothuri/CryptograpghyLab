#include<bits/stdc++.h>
#include<gmp.h>

using namespace std;

int main(int argc, char **argv){

	mpz_t a, b, r, zero;
	mpz_init(a);
	mpz_init(b);
	mpz_init(r);
	mpz_init(zero);

	mpz_set_str(a, argv[1], 10);
	mpz_set_str(b, argv[2], 10);
	mpz_set_str(r, "0", 10);
	mpz_set_str(zero, "0", 10);

	while(mpz_cmp(a, zero)){
		mpz_mod(r, b, a);
		mpz_set(b, a);
		mpz_set(a, r);
		cout<<"r = ";
		mpz_out_str(stdout, 10, a);
		cout<<endl;
	}
	
	cout<<"GCD = ";mpz_out_str(stdout, 10, b);cout<<endl;
	return 0;
}
