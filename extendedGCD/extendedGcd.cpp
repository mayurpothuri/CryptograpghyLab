#include<bits/stdc++.h>
#include<gmp.h>

using namespace std;

void gcdExtended(mpz_t &a, mpz_t &b, mpz_t &x, mpz_t &y){

	if(mpz_cmp_ui(a, 0) == 0){			//a == 0
		mpz_set_str(x, "0", 10);		//x = 0
		mpz_set_str(y, "1", 10);		//y = 1
		cout<<"GCD = ";
		mpz_out_str(stdout, 10, b);		//cout<<b<<endl;
		cout<<endl;
		return;
	}
	mpz_t x1, y1, r;
	mpz_init(x1);
	mpz_init(y1);
	mpz_init(r);

	mpz_mod(r, b, a);
	gcdExtended(r, a, x1, y1);

	mpz_t temp;
	mpz_init(temp);
	mpz_div(temp, b, a);				//temp = b/a
	mpz_mul(temp, temp, x1);			//temp *= x1
	mpz_sub(x, y1, temp);				//x = y1 - temp;
	
	mpz_set(y, x1);					//y = x1
	return;
}

int main(int argc, char **argv){

	mpz_t a, b, x, y;
	mpz_init(a);
	mpz_init(b);
	mpz_init(x);
	mpz_init(y);

	mpz_set_str(a, argv[1], 10);			//a = argv[1]
	mpz_set_str(b, argv[2], 10);			//b = argv[2]

	gcdExtended(a, b, x, y);

	cout<<"X = ";
	mpz_out_str(stdout, 10, x);		//cout<<x<<endl;
	cout<<"\nY = ";
	mpz_out_str(stdout, 10, y);		//cout<<y<<endl;
	cout<<endl;
	return 0;
}
