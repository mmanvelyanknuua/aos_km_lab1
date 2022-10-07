#include <bits/stdc++.h>

using namespace std;

string signs[20] = {"+", "-", "*", "/", "+", "-", "*", "/", "+", "-", "*", "/", "+", "-", "*", "/", "+", "-", "*", "/"};
string types[20] = {"long    ", "long    ","long    ","long    ","float   ","float   ","float   ","float   ", "char    ", "char    ", "char    ", "char    ", "int     ", "int         ", "int        ", "int         ", "double  ", "double  ", "double  ", "double  "};
string cnt[20], diag[20], perc[20];
const int addsub = 1000000000, multdiv = 100000000;

template <typename T>
double multtest(T a1, T a2, T a3, T a4, T b1, T b2, T b3, T b4, T c1, T c2, T c3, T c4){
	double time = clock();
	for (auto i = 0; i < multdiv; i++)
	{
        a1 = a1*c1;
        a2 = a2*c2;
        a3 = a3*c3;
        a4 = a4*c4;
        a1 = a1*c1;
        a2 = a2*c2;
        b3 = b1*c3;
        b4 = b2*c4;
        b1 = b3*c1;
        b2 = b4*c2;
        b3 = b1*c3;
        b4 = b2*c4;
        //cout << a1 << " " << a2 << " " << a3 << " " << a4 << " " << b1 << " " << b2 << " " << b3 << " " << b4 << endl;
	}
	return (clock() - time) / CLOCKS_PER_SEC;
}

template <typename T>
double divtest(T a1, T a2, T a3, T a4, T b1, T b2, T b3, T b4, T c1, T c2, T c3, T c4){
	double time = clock();
	T x = c1, y = c2;
	for (auto i = 0; i < multdiv; i++)
	{
        a1 = b1/x;
        a2 = b1/y;
        b3 = a1/x;
        b4 = a2/y;
        c1 = a1/x;
        c2 = a1/y;
        a3 = b3/x;
        a4 = b3/y;
        b3 = a3/x;
        b4 = a4/y;
        c3 = a3/x;
        c4 = a3/y;
	}
	return (clock() - time) / CLOCKS_PER_SEC;
}


template <typename T>
double addtest(T a1, T a2, T a3, T a4, T b1, T b2, T b3, T b4, T c1, T c2, T c3, T c4){
	double time = clock();
	for (auto i = 0; i < addsub; i++){
        a1 = b1+c1;
        a2 = b1+c2;
        b1 = a1+c1;
        b2 = a2+c1;
        c1 = a1+b1;
        c2 = a1+b2;
        a3 = b3+c3;
        a4 = b3+c4;
        b3 = a3+c3;
        b4 = a4+c3;
        c3 = a3+b3;
        c4 = a3+b4;
	}
	return (clock() - time) / CLOCKS_PER_SEC;
}

template <typename T>
double subtrtest(T a1, T a2, T a3, T a4, T b1, T b2, T b3, T b4, T c1, T c2, T c3, T c4){
	double time = clock();
	for (auto i = 0; i < addsub; i++){
        a1 = b1-c1;
        a2 = b1-c2;
        b1 = a1-c1;
        b2 = a2-c1;
        c1 = a1-b1;
        c2 = a1-b2;
        a3 = b3-c3;
        a4 = b3-c4;
        b3 = a3-c3;
        b4 = a4-c3;
        c3 = a3-b3;
        c4 = a3-b4;
	}
	return (clock() - time) / CLOCKS_PER_SEC;
}

void test(){
    cnt[0] = to_string(12*(addsub/(addtest(1381723l, 128318l, 1391389l, 123199l, 123918l, 1231310l, 98219182l, 293019l, 303291l, 123918213l, 1387183l, 182313l))));
    cnt[1] = to_string(12*(addsub/(subtrtest(1381723l, 128318l, 1391389l, 123199l, 123918l, 1231310l, 98219182l, 293019l, 303291l, 123918213l, 1387183l, 182313l))));
    cnt[2] = to_string(12*(multdiv/(multtest(1381723l, 128318l, 1391389l, 123199l, 123918l, 1231310l, 98219182l, 293019l, 303291l, 123918213l, 1387183l, 182313l))));
    cnt[3] = to_string(12*(multdiv/(divtest(1381723l, 128318l, 1391389l, 123199l, 123918l, 1231310l, 98219182l, 293019l, 303291l, 123918213l, 1387183l, 182313l))));

    cnt[4] = to_string(12*(addsub/(addtest(138.0f, 1283.4f, 1391.3f, 1231.9f, 1239.1f, 12313.7f, 98219.8f, 2930.0f, 3032.5f, 12391.6f, 13871.1f, 182.3f))));
    cnt[5] = to_string(12*(addsub/(subtrtest(138.0f, 1283.4f, 1391.3f, 1231.9f, 1239.1f, 12313.7f, 98219.8f, 2930.0f, 3032.5f, 12391.6f, 13871.1f, 182.3f))));
    cnt[6] = to_string(12*(multdiv/(multtest(138.0f, 1283.4f, 1391.3f, 1231.9f, 1239.1f, 12313.7f, 98219.8f, 2930.0f, 3032.5f, 12391.6f, 13871.1f, 182.3f))));
    cnt[7] = to_string(12*(multdiv/(divtest(138.0f, 1283.4f, 1391.3f, 1231.9f, 1239.1f, 12313.7f, 98219.8f, 2930.0f, 3032.5f, 12391.6f, 13871.1f, 182.3f))));

    cnt[8] = to_string(12*(addsub/(addtest('0', '1', 'a', ' ', 'Z', 'F', '/', ',', 'q', '9','#', '.'))));
    cnt[9] = to_string(12*(addsub/(subtrtest('0', '1', 'a', ' ', 'Z', 'F', '/', ',', 'q', '9','#', '.'))));
    cnt[10] = to_string(12*(multdiv/(multtest('0', '1', 'a', ' ', 'Z', 'F', '/', ',', 'q', '9','#', '.'))));
    cnt[11] = to_string(12*(multdiv/(divtest('0', '1', 'a', ' ', 'Z', 'F', '/', ',', 'q', '9','#', '.'))));

    cnt[12] = to_string(12*(addsub/(addtest(1381723, 128318, 1391389, 123199, 123918, 1231310, 98219182, 293019, 303291, 123918213, 1387183, 182313))));
    cnt[13] = to_string(12*(addsub/(subtrtest(1381723, 128318, 1391389, 123199, 123918, 1231310, 98219182, 293019, 303291, 123918213, 1387183, 182313))));
    cnt[14] = to_string(12*(multdiv/(multtest(1381723, 128318, 1391389, 123199, 123918, 1231310, 98219182, 293019, 303291, 123918213, 1387183, 182313))));
    cnt[15] = to_string(12*(multdiv/(divtest(1381723, 128318, 1391389, 123199, 123918, 1231310, 98219182, 293019, 303291, 123918213, 1387183, 182313))));

    cnt[16] = to_string(12*(addsub/(addtest(138.0, 1283.4, 1391.3, 1231.9, 1239.1, 12313.7, 98219.8, 2930.0, 3032.5, 12391.6, 13871.1, 182.3))));
    cnt[17] = to_string(12*(addsub/(subtrtest(138.0, 1283.4, 1391.3, 1231.9, 1239.1, 12313.7, 98219.8, 2930.0, 1.018123, 1.0193919, 1.0083918, 1.0123198))));
    cnt[18] = to_string(12*(multdiv/(multtest(138.0, 1283.4, 1391.3, 1231.9, 1239.1, 12313.7, 98219.8, 2930.0, 3032.5, 12391.6, 13871.1, 182.3))));
    cnt[19] = to_string(12*(multdiv/(divtest(138.0, 1283.4, 1391.3, 1231.9, 1239.1, 12313.7, 98219.8, 2930.0, 3032.5, 12391.6, 13871.1, 182.3))));
}

void diagram(){
	double mx = stod(cnt[0]);
	for (int i = 0; i < 20; i++){
		if (stod(cnt[i]) > mx){
			mx = stod(cnt[i]);
		}
	}
	for (int i = 0; i < 20; i++){
		perc[i] = to_string((int)round((stod(cnt[i])/mx) * 100));
	}
	for (int i = 0; i < 20; i++){
		int a = stoi(perc[i]);
		for (int j = 0; j < a; j++){
			diag[i] += "X";
		}
	}
	int mxl = cnt[0].length();
	for (int i = 1; i < 20; i++){
		if ((int)cnt[i].length() > mxl){
			mxl = cnt[i].length();
		}
	}
	for (int i = 0; i < 20; i++){
		if ((int)cnt[i].length() < mxl){
			for (int j = 0; j < mxl - (int)cnt[i].length(); j++)
				cnt[i] += " ";
		}
	}
}


int main(){
	test();
    diagram();
	for (int i = 0; i < 20; i++){
		cout << signs[i] << "\t" << types[i] << "\t" << setprecision(4) << scientific << stod(cnt[i]) << "\t" << perc[i] << "%" << "\t" << diag[i] << endl;
	}
	return 0;
}
