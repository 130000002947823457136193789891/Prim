#ifndef ADJMATRIX_UNDIR_NETWORK_H
#define ADJMATRIX_UNDIR_NETWORK_H
#define DEFAULT_INFINITY 100
#define DEFAULT_VERTEXMAXNUM 10
#include<iostream>
using namespace std;

enum VisitStatus{VISIT,UNVISIT};
class AdjMatrix_UndirNetWork{
public:
	AdjMatrix_UndirNetWork(int vertexMaxNum=DEFAULT_VERTEXMAXNUM,int infinite=DEFAULT_INFINITY);
	AdjMatrix_UndirNetWork(char * vers,int vertexNum,int vertexMaxNum=DEFAULT_VERTEXMAXNUM,int infinite=DEFAULT_INFINITY);
	~AdjMatrix_UndirNetWork();
	void InsertArc(int vex1,int vex2,int weight);   //输入合法，vex1与vex2小于vexNum，vex1!=vex2，不考虑平行边
	void Display();
	int GetElem(int vex,char &data);   //返回状态
	int GetVexNum();
	int GetArcNum();
	int FirstAdjVex(int vex);   //返回顶点vex的第一个邻接顶点的序号，若没有则返回-1
	int NextAdjVex(int vex,int vex2);   //返回顶点vex的相对于vex2的下一个邻接顶点的序号，若没有则返回-1
	int GetWeight(int vex1,int vex2);
	int GetInfinity();

private:
	char * vertexes;
	int arcnum;
	int vernum;
	int verMaxNum;
	int * *arc;
	int infinity;
	VisitStatus *tag;
};

AdjMatrix_UndirNetWork::AdjMatrix_UndirNetWork(int vertexMaxNum,int infinite)
{
	arcnum=0;
	vernum=0;
	verMaxNum=vertexMaxNum;
	vertexes=new char[verMaxNum];
	tag=new VisitStatus[verMaxNum];
	arc=new int *[verMaxNum];
	for(int i=0;i<verMaxNum;i++)
	{
		arc[i]=new int [verMaxNum];
	}
	infinity=infinite;
}

AdjMatrix_UndirNetWork::AdjMatrix_UndirNetWork(char * vers,int vertexNum,int vertexMaxNum,int infinite)
{
	arcnum=0;
	verMaxNum=vertexMaxNum;
	vernum=vertexNum;
	infinity=infinite;
	vertexes=new char[verMaxNum];
	tag=new VisitStatus[verMaxNum];
	arc=new int * [verMaxNum];
	for(int k=0;k<verMaxNum;k++)
		arc[k]=new int[verMaxNum];
	for(int i=0;i<verMaxNum;i++)
	{
		vertexes[i]=vers[i];
		tag[i]=UNVISIT;
		for(int j=0;j<verMaxNum;j++)
		{	arc[i][j]=infinity;
		}
	}
}

AdjMatrix_UndirNetWork::~AdjMatrix_UndirNetWork()
{
	if(vertexes!=NULL)
		delete[] vertexes;
	if(arc!=NULL)
		delete  arc;
	if(tag!=NULL)
		delete [] tag;
}

void AdjMatrix_UndirNetWork::InsertArc(int vex1,int vex2,int weight)
{
	arc[vex1][vex2]=weight;
	arc[vex2][vex1]=weight;
	arcnum++;
}

void AdjMatrix_UndirNetWork::Display(){
	if(vernum!=0)
	{
		for(int i=0;i<verMaxNum;i++)
		{
			cout<<"[";
			for(int j=0;j<verMaxNum;j++)
			{
					cout<<arc[i][j]<<"  ";
			}
			cout<<"]"<<endl;
		}
	}
}

int AdjMatrix_UndirNetWork::GetElem(int vex,char &data){
	if(vex<0&&vex>=vernum)
		return 0;
	data=vertexes[vex];
	return 1;
}

int AdjMatrix_UndirNetWork::GetVexNum(){
	return vernum;
}

int AdjMatrix_UndirNetWork::GetArcNum(){
	return arcnum;
}

int AdjMatrix_UndirNetWork::FirstAdjVex(int vex){
	for(int i=0;i<verMaxNum;i++)
	{
		if(arc[vex][i]!=infinity)
			return i;
	}
	return -1;
}

int AdjMatrix_UndirNetWork::NextAdjVex(int vex,int vex2){
	for(int i=vex2+1;i<verMaxNum;i++)
	{
		if(arc[vex][i]!=infinity)
				return i;
	}
	return -1;
}

int AdjMatrix_UndirNetWork::GetWeight(int vex1,int vex2){

		return arc[vex1][vex2];
}


int AdjMatrix_UndirNetWork::GetInfinity(){return infinity;}
#endif