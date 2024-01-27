/*Name	    :-	Abhi Chakrani
 Email id   :- amchakrani@myseneca.ca
 Student No.:-111568234
 Date		:-18/01/2024
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Assessment.h"
using namespace std;
namespace seneca {
	double m_mark;

	bool read(int& value, FILE* fptr) {
		if (fscanf(fptr, "%d", &value) == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool read(double& value, FILE* fptr) {
		if (fscanf(fptr, "%lf", &value) == 1) {
			return true;
		}
		else {
			return false;
		}

	}

	bool read(char* cstr, FILE* fptr) {
		if (fscanf(fptr, ",") == 0) {
			if (fscanf(fptr, "%60[^,\n]", cstr) == 1) {
				fscanf(fptr, "\n");
				return true;
			}
		}
		return false;

	}

	bool read(Assessment& assess, FILE* fptr) {
			
		double mark;
		char size[61];
		if (fscanf(fptr, "%lf %60s", &mark, size) == 2) {
			assess.m_mark = new double(mark);
			assess.m_title = new char[61];
			*assess.m_mark = mark;
			/*for (int i = 0; i < 61;  i++)
				cout << size[i] << endl;*/
			int i = 0;
			while (i < 61 && size[i] != '\0') {
				assess.m_title[i] = size[i];
				++i;
			}

			assess.m_title[60] = '\0';
			return true;
		}
		else {
			return false;
		}
	}

	void freeMem(Assessment*& aptr, int size) {
		for (int i = 0; i < size; i++) {
			delete aptr[i].m_mark;
			delete [] aptr[i].m_title;
		}
		delete[] aptr;
		aptr = nullptr;
	}

	int read(Assessment*& aptr, FILE* fptr) {
		int record;
		if (fscanf(fptr, "%d", &record) != 1 || record <= 0) {
			return 0;
		}
		aptr = new Assessment[record];
		int number = 0;
		bool success = true;  
		for (int i = 0; i < record; ++i) {
			if (!read(aptr[i], fptr)) {
				success = false;
			}
			++number;
		}
		if (!success) {
			freeMem(aptr, record);
			return 0;
		}
		return record;

	}

}

