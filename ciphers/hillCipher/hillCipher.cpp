#include <iostream>
using namespace std;
 
void getKey(string key, int keyMatrix[][3])
{
    int k = 0;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            keyMatrix[i][j] = (key[k++]) % 65;
        }
    }
	return;
}
 
void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1])
{
    int x, i, j;
    for (i = 0; i < 3; i++) 
    {
        for (j = 0; j < 1; j++)
        {
            cipherMatrix[i][j] = 0;
          
             for (x = 0; x < 3; x++)
            {
                cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
            }
         
            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
	return;
}
 
void hillCipher(string message, string key)
{
    int keyMatrix[3][3] = {};
    getKey(key, keyMatrix);
 
    int messageVector[3][1] = {};
 
    for (int i = 0; i < 3; i++)
        messageVector[i][0] = (message[i]) % 65;
 
    int cipherMatrix[3][1];
 
    encrypt(cipherMatrix, keyMatrix, messageVector);
 
    string encryptText;
 
    for (int i = 0; i < 3; i++)
        encryptText += cipherMatrix[i][0] + 65;
 
    cout<<encryptText;
    return;
}
 
int main(int argc, char **argv)
{
    string message = argv[1];
 
    // Key Length is 9 Letters.
    string key = argv[2];
    cout<<"Encrypted Text : ";
    if(message.size()%3 != 0){
	l:
	message += 'Z';
	if(message.size()%3 != 0)
		goto l;
    }
    for(int i = 0; i < message.size(); i+=3){
	hillCipher(message.substr(i, 3), key);
    }
    cout<<endl;
    return 0;
}
