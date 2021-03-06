#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
struct Node{
	string state;
	string rath;
	Node(){}
	Node(string s,string r){
		state = s; rath = r; 
	}
}node;
struct Path{
	string rath;
	int step;
	Path(){}
	Path(string r,int s)
	{
		rath = r;
		step = s;
	}
	bool operator < (const Path& rhs)const
	{
		return ((step<rhs.step)||(step==rhs.step&&rath<rhs.rath));
	}
	void show(int id)
	{
		cout<<setw(2)<<id;
		cout<<". "<<rath<<" ("<<step<<"��)\n"; 
	}
}; 
typedef unordered_map<string,string> uss;
typedef queue<Node> qN;
uss::iterator it;
string op[9] = {
	"R2","U2","F2","R","U","F","R\'","U\'","F\'"
}; 
map<string,int> getOPNum;

int tR[3][5]  = {{2,18,6,20,2},{1,17,5,23,1},{15,14,13,12,15}};
int eR[2][5]  = {{1,17,5,23,1},{12,15,14,13,12}};  
int tR2[3][4] = {{1,2,5,6},{17,18,23,20},{12,13,14,15}};
int eR2[2][4] = {{1,17,5,23},{12,13,14,15}};
int tU[3][5]  = {{3,2,1,0,3},{12,20,8,16,12},{13,21,9,17,13}};
int eU[2][5]  = {{3,2,1,0,3},{8,16,12,20,8}};
int tU2[3][4] = {{0,1,2,3},{8,9,12,13},{16,17,20,21}};
int eU2[2][4] = {{0,1,2,3},{8,16,12,20}};
int tF[3][5]  = {{19,18,17,16,19},{2,9,4,15,2},{3,10,5,12,3}};
int eF[2][5]  = {{19,18,17,16,19},{2,9,4,15,2}};
int tF2[3][4] = {{16,17,18,19},{2,3,4,5},{9,10,15,12}};
int eF2[2][4] = {{2,15,4,9},{16,17,18,19}};
int tx[6][4]  = {{0,1,2,3},{16,17,18,19},{4,5,6,7},{22,23,20,21},{15,14,13,12},{8,9,10,11}};
int tx2[4][8] = {{0,1,2,3,4,5,6,7},{16,17,18,19,22,23,20,21},{8,9,10,11},{15,14,13,12}};
int ty[6][4]  = {{8,9,10,11},{16,17,18,19},{12,13,14,15},{20,21,22,23},{0,1,2,3},{4,5,6,7}};
int ty2[4][8] = {{8,9,10,11,12,13,14,15},{16,17,18,19,20,21,22,23},{3,2,1,0},{4,5,6,7}};
int tz[6][4]  = {{0,1,2,3},{11,8,9,10},{6,7,4,5},{13,14,15,12},{19,18,17,16},{20,21,22,23}};
int tz2[4][8] = {{0,1,2,3,6,7,4,5},{8,9,10,11,14,15,12,13},{0,1,2,3},{4,5,6,7}};
void cR (string,string&);
void cR_(string,string&);
void cR2(string,string&);
void cU (string,string&);
void cU_(string,string&);
void cU2(string,string&);
void cF (string,string&);
void cF_(string,string&);
void cF2(string,string&);
void cx (string,string&);		
void cx_(string,string&);
void cx2(string,string&);
void cy (string,string&);		
void cy_(string,string&);
void cy2(string,string&);
void cz (string,string&);		
void cz_(string,string&);
void cz2(string,string&);
char opColor(char);
string rev_op(string); 
void f(string,string&,int);
string get_rev_rath(string);
int get_step(string);
int simplify_rath(string&);
string getState(const string&);
//char st[50],Up[10],Down[10],Left[10],Right[10],Front[10],Back[10];
typedef char str50[100];
str50 st,Up,Down,Left,Right,Front,Back,Daluan;
str50 _u,_d,_l,_r,_f,_b;
string get_ed(str50 Up,str50 Down,str50 Left,str50 Right,str50 Front,str50 Back) 
{
	string ed; 
	char dColor = Down[3],bColor = Back[2],lColor = Left[3];
	char uColor = opColor(dColor);
	char fColor = opColor(bColor);
	char rColor = opColor(lColor);
	string tmp = string("")+uColor+dColor+lColor+rColor+fColor+bColor;
	int cnt = 0;
	for(int i=0;i<6;++i)
		for(int j=0;j<4;++j)
			ed += tmp[i];
	return ed;
}
int main()
{
	for(int i=0;i<9;++i)
		getOPNum[op[i]] = i;
	string sdf;
	while(cin>>sdf)
	{
		cout<<sdf<<endl; 
		cout<<getState(sdf)<<endl;
		
	}
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	freopen("out.txt","w",stdout);
//	string Up,Down,Left,Right,Front,Back;R2F'R2U2FU'F2UR2   BYGGYGWWORRBYRBWWOOBGYOR
//	fclose(stdin);
//	fclose(stdout); 
	
	
	return 0;		
} 
char opColor(char c)
{
	switch (c){
		case 'R': return 'O';
		case 'O': return 'R';
		case 'B': return 'G';
		case 'G': return 'B';
		case 'Y': return 'W';
		case 'W': return 'Y';
	}
	return '0';
}
string rev_op(string a)
{
	if(a=="R") return string("R\'");
	else if(a=="R\'") return string("R");
	else if(a=="U")   return string("U\'");
	else if(a=="U\'") return string("U");
	else if(a=="F")   return string("F\'");
	else if(a=="F\'") return string("F");
	else return a;
}
void f(string a,string& b,int op)
{
	switch (op){
		case 0:cR2(a,b);break;
		case 1:cU2(a,b);break;
		case 2:cF2(a,b);break;
		case 3: cR(a,b);break;
		case 4: cU(a,b);break;
		case 5: cF(a,b);break;
		case 6:cR_(a,b);break;
		case 7:cU_(a,b);break;
		case 8:cF_(a,b);break;
	}
}
void cR(string a,string& b)
{
	b = a;
	for(int i=0;i<3;++i) //corner block
    	for(int j=0;j<4;++j)
	    	b[tR[i][j]] = a[tR[i][j+1]];
	for(int i=0;i<2;++i) //edge block
		for(int j=0;j<4;++j)
			b[eR[i][j]+24] = a[eR[i][j+1]+24];
}
void cR_(string a,string& b)
{
	b = a;
	for(int i=0;i<3;++i) //corner block
		for(int j=4;j>0;--j)
        	b[tR[i][j]] = a[tR[i][j-1]];
    for(int i=0;i<2;++i) //edge block
		for(int j=4;j>0;--j)
			b[eR[i][j]+24] = a[eR[i][j-1]+24];
}
void cR2(string a,string& b)
{
	b = a;
	for(int i=0;i<3;++i)
		for(int j=0;j<4;++j)
			b[tR2[i][j]] = a[tR2[i][(j+2)%4]];
	for(int i=0;i<2;++i)
		for(int j=0;j<4;++j)
			b[eR2[i][j]+24] = a[eR2[i][(j+2)%4]+24];
}
void cU(string a,string &b)
{
	b = a;
	for(int i=0;i<3;++i) //corner block
	   for(int j=0;j<4;++j)
	   	   b[tU[i][j]] = a[tU[i][j+1]];
	for(int i=0;i<2;++i) //edge block
		for(int j=0;j<4;++j)
			b[eU[i][j]+24] = a[eU[i][j+1]+24];
}
void cU_(string a,string &b)
{
	b = a;
	for(int i=0;i<3;++i)//corner block
	   for(int j=4;j>0;--j)
	   	   b[tU[i][j]] = a[tU[i][j-1]];
	for(int i=0;i<2;++i) //edge block
		for(int j=4;j>0;--j)
			b[eU[i][j]+24] = a[eU[i][j-1]+24];	
}
void cU2(string a,string &b)
{
	b = a;
	for(int i=0;i<3;++i)
	   for(int j=0;j<4;++j)
	   	   b[tU2[i][j]] = a[tU2[i][(j+2)%4]];
	for(int i=0;i<2;++i)
		for(int j=0;j<4;++j)
			b[eU2[i][j]+24] = a[eU2[i][(j+2)%4]+24];
}
void cF(string a,string& b)
{
	b = a;
	for(int i=0;i<3;++i) //corner block
	   for(int j=0;j<4;++j)
	   	   b[tF[i][j]] = a[tF[i][j+1]];
	for(int i=0;i<2;++i) //edge block
	   for(int j=0;j<4;++j)
	   	   b[eF[i][j]+24] = a[eF[i][j+1]+24];
}
void cF_(string a,string& b)
{
	b = a;
	for(int i=0;i<3;++i) //corner block 
   		for(int j=4;j>0;--j)
   	   		b[tF[i][j]] = a[tF[i][j-1]];
	for(int i=0;i<2;++i) //edge block
   		for(int j=4;j>0;--j)
   	   		b[eF[i][j]+24] = a[eF[i][j-1]+24];
}
void cF2(string a,string& b)
{
	b = a;
	for(int i=0;i<3;++i)
	   for(int j=0;j<4;++j)
	       b[tF2[i][j]] = a[tF2[i][(j+2)%4]];
	for(int i=0;i<2;++i)
	   for(int j=0;j<4;++j)
	       b[eF2[i][j]+24] = a[eF2[i][(j+2)%4]+24];
} 
string get_rev_rath(string a)
{
	string b = string("");
	int len = a.length();
	int i = 0;
	stack<string> sta; 
	while(i<len)
	{
		if(a[i]!='R'&&a[i]!='U'&&a[i]!='F') return false;
		string now = "";
		now +=a[i];
		if(i+1<len&&(a[i+1]=='2'||a[i+1]=='\'')) now+=a[i+1],i+=2;
		else ++i; 
		sta.push(rev_op(now));
	}
	while(!sta.empty())
	{
		b += sta.top();
		sta.pop();
	}
	return b;
}
int get_step(string a)
{
	int len = a.length();
	int i = 0, step = 0;
	while(i<len)
	{
		if(i+1<len&&(a[i+1]=='2'||a[i+1]=='\'')) i+=2;
		else ++i; 
		++step; 
	}
	return step;
}
int simplify_rath(string &a)
{
	vector<string> v;
	int len = a.length();
	int i = 0, step = 0;
	while(i<len)
	{
		string tmp;
		tmp += a[i];
		if(i+1<len&&(a[i+1]=='2'||a[i+1]=='\'')) tmp+=a[i+1],i+=2;
		else ++i; 
		if(step==0)
		{
			v.push_back(tmp); ++step;
		}
		else if(v[step-1]==rev_op(tmp))
		{
			v.pop_back();--step; 
		} 
		else if(v[step-1]==tmp) 
		{
			if(tmp=="R"||tmp=="R\'")
				v.pop_back(),v.push_back("R2");
			else if(tmp=="U"||tmp=="U\'") 
				v.pop_back(),v.push_back("U2");
			else if(tmp=="F"||tmp=="F\'")
				v.pop_back(),v.push_back("F2");
			else
				v.push_back(tmp),++step;
		}
		else if((tmp=="U2"&&v[step-1]=="U")||(tmp=="U"&&v[step-1]=="U2"))
		{
			v.pop_back(); v.push_back("U\'");			
		} 
		else if((tmp=="U2"&&v[step-1]=="U\'")||(tmp=="U\'"&&v[step-1]=="U2"))
		{
			v.pop_back(); v.push_back("U");			
		}
		else if((tmp=="R2"&&v[step-1]=="R")||(tmp=="R"&&v[step-1]=="R2"))
		{
			v.pop_back(); v.push_back("R\'");			
		}
		else if((tmp=="R2"&&v[step-1]=="R\'")||(tmp=="R\'"&&v[step-1]=="R2"))
		{
			v.pop_back(); v.push_back("R");			
		}
		else if((tmp=="F2"&&v[step-1]=="F")||(tmp=="F"&&v[step-1]=="F2"))
		{
			v.pop_back(); v.push_back("F\'");			
		}
		else if((tmp=="F2"&&v[step-1]=="F\'")||(tmp=="F\'"&&v[step-1]=="F2"))
		{
			v.pop_back(); v.push_back("F");			
		}
		else
		{
			v.push_back(tmp); ++step;
		}
	}
	a.clear();
	for(int i=0;i<step;++i)
		a += v[i];
	return step;
}
string getState(const string& a)
{
	vector<string> v;
	int len = a.length();
	int i = 0, step = 0;
	while(i<len)
	{
		string tmp;
		tmp += a[i];
		if(i+1<len&&(a[i+1]=='2'||a[i+1]=='\'')) tmp+=a[i+1],i+=2;
		else ++i; 
		if(step==0)
		{
			v.push_back(tmp);++step;
		}
		else if(v[step-1]==rev_op(tmp))
		{
			v.pop_back();--step; 
		} 
		else if(v[step-1]==tmp) 
		{
			if(tmp=="R"||tmp=="R\'")
				v.pop_back(),v.push_back("R2");
			else if(tmp=="U"||tmp=="U\'") 
				v.pop_back(),v.push_back("U2");
			else if(tmp=="F"||tmp=="F\'")
				v.pop_back(),v.push_back("F2");
			else
				v.push_back(tmp),++step;
		}
		else if((tmp=="U2"&&v[step-1]=="U")||(tmp=="U"&&v[step-1]=="U2"))
		{
			v.pop_back(); v.push_back("U\'");			
		} 
		else if((tmp=="U2"&&v[step-1]=="U\'")||(tmp=="U\'"&&v[step-1]=="U2"))
		{
			v.pop_back(); v.push_back("U");			
		}
		else if((tmp=="R2"&&v[step-1]=="R")||(tmp=="R"&&v[step-1]=="R2"))
		{
			v.pop_back(); v.push_back("R\'");			
		}
		else if((tmp=="R2"&&v[step-1]=="R\'")||(tmp=="R\'"&&v[step-1]=="R2"))
		{
			v.pop_back(); v.push_back("R");			
		}
		else if((tmp=="F2"&&v[step-1]=="F")||(tmp=="F"&&v[step-1]=="F2"))
		{
			v.pop_back(); v.push_back("F\'");			
		}
		else if((tmp=="F2"&&v[step-1]=="F\'")||(tmp=="F\'"&&v[step-1]=="F2"))
		{
			v.pop_back(); v.push_back("F");			
		}
		else
		{
			v.push_back(tmp); ++step;
		}
	}
	string st = "YYYYWWWWBBBBGGGGRRRROOOOYYYYWWWWBBBBGGGGRRRROOOO"; 
	string ed;
	ed = st;
	for(int i=0;i<step;++i)
	{
		f(st,ed,getOPNum[v[i]]);
		st = ed;
	}
	return ed;
}
