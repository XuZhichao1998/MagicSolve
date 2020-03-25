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
		cout<<". "<<rath<<" ("<<step<<"步)\n"; 
	}
}; 
typedef unordered_map<string,string> uss;
typedef queue<Node> qN;
uss::iterator it;
string op[] = {
	"R2","U2","F2","R","U","F","R\'","U\'","F\'","L","D","B","L\'","D\'","B\'","L2","D2","B2",
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

int tD[3][5]  = {{19,11,23,15,19},{18,10,22,14,18},{7,6,5,4,7}};
int eD[2][5]  = {{18,10,22,14,18},{7,6,5,4,7}};  
int tD2[3][4] = {{19,18,23,22},{11,10,15,14},{4,5,6,7}};
int eD2[2][4] = {{18,10,22,14},{4,5,6,7}};

int tL[3][5]  = {{0,22,4,16,0},{3,21,7,19,3},{11,10,9,8,11}};
int eL[2][5]  = {{3,21,7,19,3},{11,10,9,8,11}};  
int tL2[3][4] = {{0,3,4,7},{16,19,22,21},{8,9,10,11}};
int eL2[2][4] = {{3,21,7,19},{11,10,9,8}};

int tB[3][5]  = {{0,13,6,11,0},{1,14,7,8,1},{23,22,21,20,23}};
int eB[2][5]  = {{0,13,6,11,0},{23,22,21,20,23}};  
int tB2[3][4] = {{0,1,6,7},{11,8,13,14},{20,21,22,23}};
int eB2[2][4] = {{0,11,6,13},{20,21,22,23}};

void cR (string,string&);
void cR_(string,string&);
void cR2(string,string&);
void cU (string,string&);
void cU_(string,string&);
void cU2(string,string&);
void cF (string,string&);
void cF_(string,string&);
void cF2(string,string&);
void cL (string,string&);
void cL_(string,string&);
void cL2(string,string&);
void cD (string,string&);
void cD_(string,string&);
void cD2(string,string&);
void cB (string,string&);
void cB_(string,string&);
void cB2(string,string&);
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
void two_dir_bfs(string st,string ed,int Daluan_step)
{
	set<string> Set;
//	int MinStep = 200;
//	vector<string> v;
	if(st==ed)
	{
		puts("The magic cube is already perfect.");
		return;
	}
	uss mp,rmp;
	queue<string> Q,rQ;
	string rath(""),nexrath,now,to,ans,res;
	int sz = 0, rsz = 0, nowStep = 0,Len;
	mp[st] = rath;
	rmp[ed] = rath;
	Q.push(st);
	rQ.push(ed);
	while(!Q.empty()||!rQ.empty())
	{
		sz = Q.size(), rsz = rQ.size();
		if(sz<=rsz&&!Q.empty())
		{
			now = Q.front();Q.pop();
			rath = mp[now];
			for(int i=3;i<9;++i)
			{
				f(now,to,i);
				it = mp.find(to);
				if(it!=mp.end()) continue;
				nexrath = rath+op[i];
				it = rmp.find(to);
				if(it!=rmp.end())
				{
					ans = nexrath + get_rev_rath(it->second);
					int _step = simplify_rath(ans);
					if(_step<=Daluan_step+5)
					{
//						cout<<"还原："<<ans<<"\n";
//						cout<<"步数："<<_step<<endl; 
						Set.insert(ans);
						if(Set.size()>=99)
						{
							vector<Path> vp; 
							for(auto x:Set)
								vp.push_back(Path(x,get_step(x)));
							sort(vp.begin(),vp.end());
							Len = vp.size();
							for(int i=0;i<Len;++i)
								vp[i].show(i+1);
							return;
						}
					}
//					return;
				}
				Q.push(to);
				mp[to] = nexrath;
//				cout<<nexrath<<": "<<to<<endl; 
			}
		}
		else
		{
			now = rQ.front();rQ.pop();
			rath = rmp[now];
			for(int i=3;i<9;++i)
			{
				f(now,to,i);
				it = rmp.find(to);
				if(it!=rmp.end()) continue;
				nexrath = rath + op[i];
				it = mp.find(to);
				if(it!=mp.end())
				{
					ans = (it->second) + get_rev_rath(nexrath);
					int _step = simplify_rath(ans);
					if(_step<=Daluan_step+5)
					{
//						cout<<"还原："<<ans<<"\n";
//						cout<<"步数："<<_step<<endl; 
						Set.insert(ans);
						if(Set.size()>=99)
						{
							vector<Path> vp; 
							for(auto x:Set)
								vp.push_back(Path(x,get_step(x)));
							sort(vp.begin(),vp.end());
							Len = vp.size();
							for(int i=0;i<Len;++i)
								vp[i].show(i+1);
							return;
						}
					}
//					return;
				}
				rQ.push(to);
				rmp[to] = rath+op[i];
//				cout<<nexrath<<": "<<to<<endl;
			}	
		}
	}
	vector<Path> vp; 
	for(auto x:Set)
		vp.push_back(Path(x,get_step(x)));
	sort(vp.begin(),vp.end());
	Len = vp.size();
	for(int i=0;i<Len;++i)
		vp[i].show(i+1);
} 
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
	for(int i=0;i<18;++i)
		getOPNum[op[i]] = i;
//	string sdf;cin>>sdf;cout<<getState(sdf)<<endl;return 0;
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	freopen("out.txt","w",stdout);
//	string Up,Down,Left,Right,Front,Back;R2F'R2U2FU'F2UR2   BYGGYGWWORRBYRBWWOOBGYOR
	while(scanf("%s%s",Daluan,st)!=EOF)
	{
		int Daluan_step = get_step(Daluan);
		sscanf(st,"%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s",Up,Down,Left,Right,Front,Back,_u,_d,_l,_r,_f,_b);
		cout<<"黄顶红前打乱: "<<Daluan<<endl;
		cout<<"初始状态为："<<st<<endl;
		string corner_ed = get_ed(Up,Down,Left,Right,Front,Back);
		string edge_ed = get_ed(_u,_d,_l,_r,_f,_b);
		string ed = corner_ed+edge_ed;
		cout<<"最终状态为："<<ed<<endl;
		two_dir_bfs(st,ed,Daluan_step);
//		bfs(st,ed);
//		BFS(st,ed);
	}
	fclose(stdin);
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
	if     (a=="R")   return string("R\'");
	else if(a=="R\'") return string("R");
	else if(a=="U")   return string("U\'");
	else if(a=="U\'") return string("U");
	else if(a=="F")   return string("F\'");
	else if(a=="F\'") return string("F");
	else if(a=="L")   return string("L\'");
	else if(a=="L\'") return string("L");
	else if(a=="D")   return string("D\'");
	else if(a=="D\'") return string("D");
	else if(a=="B")   return string("B\'");
	else if(a=="B\'") return string("B");
	else return a;
}
void f(string a,string& b,int op)
{
	switch (op){
		case  0:cR2(a,b);break;
		case  1:cU2(a,b);break;
		case  2:cF2(a,b);break;
		case  3: cR(a,b);break;
		case  4: cU(a,b);break;
		case  5: cF(a,b);break;
		case  6:cR_(a,b);break;
		case  7:cU_(a,b);break;
		case  8:cF_(a,b);break;
		case  9: cL(a,b);break;
		case 10: cD(a,b);break;
		case 11: cB(a,b);break;
		case 12:cL_(a,b);break;
		case 13:cD_(a,b);break;
		case 14:cB_(a,b);break;
		case 15:cL2(a,b);break;
		case 16:cD2(a,b);break;
		case 17:cB2(a,b);break;
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
void cL(string a,string& b)
{
	b = a;
	for(int i=0;i<3;++i) //corner block
    	for(int j=0;j<4;++j)
	    	b[tL[i][j]] = a[tL[i][j+1]];
	for(int i=0;i<2;++i) //edge block
		for(int j=0;j<4;++j)
			b[eL[i][j]+24] = a[eL[i][j+1]+24];
}
void cL_(string a,string& b)
{
	b = a;
	for(int i=0;i<3;++i) //corner block
		for(int j=4;j>0;--j)
        	b[tL[i][j]] = a[tL[i][j-1]];
    for(int i=0;i<2;++i) //edge block
		for(int j=4;j>0;--j)
			b[eL[i][j]+24] = a[eL[i][j-1]+24];
}
void cL2(string a,string& b)
{
	b = a;
	for(int i=0;i<3;++i)
		for(int j=0;j<4;++j)
			b[tL2[i][j]] = a[tL2[i][(j+2)%4]];
	for(int i=0;i<2;++i)
		for(int j=0;j<4;++j)
			b[eL2[i][j]+24] = a[eL2[i][(j+2)%4]+24];
}
void cD(string a,string& b)
{
	b = a;
	for(int i=0;i<3;++i) //corner block
    	for(int j=0;j<4;++j)
	    	b[tD[i][j]] = a[tD[i][j+1]];
	for(int i=0;i<2;++i) //edge block
		for(int j=0;j<4;++j)
			b[eD[i][j]+24] = a[eD[i][j+1]+24];
}
void cD_(string a,string& b)
{
	b = a;
	for(int i=0;i<3;++i) //corner block
		for(int j=4;j>0;--j)
        	b[tD[i][j]] = a[tD[i][j-1]];
    for(int i=0;i<2;++i) //edge block
		for(int j=4;j>0;--j)
			b[eD[i][j]+24] = a[eD[i][j-1]+24];
}
void cD2(string a,string& b)
{
	b = a;
	for(int i=0;i<3;++i)
		for(int j=0;j<4;++j)
			b[tD2[i][j]] = a[tD2[i][(j+2)%4]];
	for(int i=0;i<2;++i)
		for(int j=0;j<4;++j)
			b[eD2[i][j]+24] = a[eD2[i][(j+2)%4]+24];
}

void cB(string a,string& b)
{
	b = a;
	for(int i=0;i<3;++i) //corner block
    	for(int j=0;j<4;++j)
	    	b[tB[i][j]] = a[tB[i][j+1]];
	for(int i=0;i<2;++i) //edge block
		for(int j=0;j<4;++j)
			b[eB[i][j]+24] = a[eB[i][j+1]+24];
}
void cB_(string a,string& b)
{
	b = a;
	for(int i=0;i<3;++i) //corner block
		for(int j=4;j>0;--j)
        	b[tB[i][j]] = a[tB[i][j-1]];
    for(int i=0;i<2;++i) //edge block
		for(int j=4;j>0;--j)
			b[eB[i][j]+24] = a[eB[i][j-1]+24];
}
void cB2(string a,string& b)
{
	b = a;
	for(int i=0;i<3;++i)
		for(int j=0;j<4;++j)
			b[tB2[i][j]] = a[tB2[i][(j+2)%4]];
	for(int i=0;i<2;++i)
		for(int j=0;j<4;++j)
			b[eB2[i][j]+24] = a[eB2[i][(j+2)%4]+24];
}

string get_rev_rath(string a)
{
	string b = string("");
	int len = a.length();
	int i = 0;
	stack<string> sta; 
	while(i<len)
	{
		if(a[i]!='R'&&a[i]!='U'&&a[i]!='F'&&a[i]!='L'&&a[i]!='D'&&a[i]!='B') return false;
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
			else if(tmp=="L"||tmp=="L\'") 
				v.pop_back(),v.push_back("L2");
			else if(tmp=="D"||tmp=="D\'") 
				v.pop_back(),v.push_back("D2");
			else if(tmp=="B"||tmp=="B\'") 
				v.pop_back(),v.push_back("B2");
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
		else if((tmp=="L2"&&v[step-1]=="L")||(tmp=="L"&&v[step-1]=="L2"))
		{
			v.pop_back(); v.push_back("L\'");			
		}
		else if((tmp=="L2"&&v[step-1]=="L\'")||(tmp=="L\'"&&v[step-1]=="L2"))
		{
			v.pop_back(); v.push_back("L");			
		}  
		else if((tmp=="D2"&&v[step-1]=="D\'")||(tmp=="D\'"&&v[step-1]=="D2"))
		{
			v.pop_back(); v.push_back("D");			
		}
		else if((tmp=="D2"&&v[step-1]=="D")||(tmp=="D"&&v[step-1]=="D2"))
		{
			v.pop_back(); v.push_back("D\'");			
		}
		else if((tmp=="B2"&&v[step-1]=="B\'")||(tmp=="B\'"&&v[step-1]=="B2"))
		{
			v.pop_back(); v.push_back("B");			
		}
		else if((tmp=="B2"&&v[step-1]=="B")||(tmp=="B"&&v[step-1]=="B2"))
		{
			v.pop_back(); v.push_back("B\'");			
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
			v.push_back(tmp);
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
			else if(tmp=="L"||tmp=="L\'")
				v.pop_back(),v.push_back("L2");
			else if(tmp=="D"||tmp=="D\'") 
				v.pop_back(),v.push_back("D2");
			else if(tmp=="B"||tmp=="B\'") 
				v.pop_back(),v.push_back("B2");
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
		else if((tmp=="L2"&&v[step-1]=="L")||(tmp=="L"&&v[step-1]=="L2"))
		{
			v.pop_back(); v.push_back("L\'");			
		}
		else if((tmp=="L2"&&v[step-1]=="L\'")||(tmp=="L\'"&&v[step-1]=="L2"))
		{
			v.pop_back(); v.push_back("L");			
		}  
		else if((tmp=="D2"&&v[step-1]=="D\'")||(tmp=="D\'"&&v[step-1]=="D2"))
		{
			v.pop_back(); v.push_back("D");			
		}
		else if((tmp=="D2"&&v[step-1]=="D")||(tmp=="D"&&v[step-1]=="D2"))
		{
			v.pop_back(); v.push_back("D\'");			
		}
		else if((tmp=="B2"&&v[step-1]=="B\'")||(tmp=="B\'"&&v[step-1]=="B2"))
		{
			v.pop_back(); v.push_back("B");			
		}
		else if((tmp=="B2"&&v[step-1]=="B")||(tmp=="B"&&v[step-1]=="B2"))
		{
			v.pop_back(); v.push_back("B\'");			
		}
		else
		{
			v.push_back(tmp); ++step;
		}
	}
	string st = "YYYYWWWWBBBBGGGGRRRROOOOYYYYWWWWBBBBGGGGRRRROOOO"; 
	string ed;
	for(int i=0;i<step;++i)
	{
		f(st,ed,getOPNum[v[i]]);
		st = ed;
	}
	return ed;
}
