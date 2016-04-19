#include<iostream>
#include<sstream>
#include<string>
#include<fstream>


using namespace std;

int sti(string s){
	istringstream iss(s);
	int tem;
	return iss>>tem ? tem : -1;
}
string its(int n){
	ostringstream oss;
	oss<<n;
	return oss.str();
}

string cal(int & tem, int &n){
	//n+= tem;
	tem += n;
	return its(tem);
}
string count(int n){
	if(n == 0) return "INSOMNIA";
	else{
	int tem =0;
	string s ;
	string re = "0000000000";
	while(re.find('0')!= -1){
		s = cal(tem, n);
		for(int i = 0; i<10; i++){
			if( re[i] == '0' && (s.find( its(i) ) != -1) ){
				re[i] = '1';
			}
		}
	}
	return its(tem);
	}
}
int main(){
	ifstream in("cs-l.in");
	ofstream out("cs-l.txt");
	int caseN,n;
	string tem;
	getline(in, tem);
	caseN = sti(tem);
	for(int i =1; i<= caseN; i++){
		getline(in, tem);
		n = sti(tem);
		out<<"case #"<<i<<": "<<count(n)<<endl;
	}
	in.close();
	out.close();
	return 0;
}