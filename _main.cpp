#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include "SingleInstance.h"

using namespace std;

int main(){
	char buffer[128];
	DWORD size = 128;
	GetComputerName(buffer, &size);

	char s[256] = "MYAPPLICATION-";
	strcat(s, buffer);

	LPCTSTR _id = s;

	cout << "id = " << _id << endl;

	LPTSTR _buffer = (LPTSTR)alloca(MAX_PATH);

	LPTSTR _myUniqueName = CreateUniqueName(_id, _buffer);

	cout << "myUniqueName = " << _myUniqueName << endl;

	if (IsInstancePresent(_myUniqueName)){
		cout << "FAIL" << endl;
	}
	else {
		cout << "NICE" << endl;
	}

	//cout << s.c_str() << endl;

	getchar();
	return 0;
}