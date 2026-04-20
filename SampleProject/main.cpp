#include<iostream>

using namespace std;

int main() {

	char userName[50] = ""; //선언, 초기화

	cout << "[ User Name ] \n";
	cout << "Input your name : ";

	cin >> userName;  // 변수에 입력받은 값을 할당.

	cout << "::::::Welcome to the D&D World:::::: \n";
	cout << "User Name : [" << userName << "]!\n";


	return 0;
}