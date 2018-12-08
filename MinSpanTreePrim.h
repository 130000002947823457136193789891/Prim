#include"AdjMatrix_UndirNetWork.h"
#include<iostream>
using namespace std;

struct PrimNode
{
	int lowweight;
	int nearverex;
};

void MinSpanTreePrim(AdjMatrix_UndirNetWork & UndirNetWork,int startvex=0)
{
	int VexNum=UndirNetWork.GetVexNum ();
	int k;
	PrimNode *vexs;
	vexs=new PrimNode[VexNum];
	vexs[startvex].lowweight =0;
	vexs[startvex].nearverex =-1;
	for(int i=0;i<VexNum;i++)
	{
		if(startvex!=i)
		{
			vexs[i].lowweight =UndirNetWork.GetWeight (startvex,i);
			vexs[i].nearverex =startvex;
		}
	}
	for(i=1;i<VexNum;i++)
	{
		int minLowweight=UndirNetWork.GetInfinity (),minOrder;
		for(int j=0;j<VexNum;j++)
		{
			if(vexs[j].lowweight !=0 && vexs[j].lowweight <minLowweight)
			{
				minLowweight=vexs[j].lowweight ;
				minOrder=j;
			}
		}

		if(minLowweight==UndirNetWork.GetInfinity ())
		{
			cout<<"该图不连通"<<endl;
			break;
		}
		else
		{
			vexs[minOrder].lowweight =0;
			char v1,v2;
			UndirNetWork.GetElem (vexs[minOrder].nearverex ,v1);
			UndirNetWork.GetElem (minOrder,v2);
			cout<<"连接边 :("<<v1<<","<<v2<<") ,权: "<<minLowweight<<endl;

			for(k=UndirNetWork.FirstAdjVex (minOrder);k!=-1;k=UndirNetWork.NextAdjVex (minOrder,k))
				if(vexs[k].lowweight!=0  && UndirNetWork.GetWeight (minOrder,k)<vexs[k].lowweight )	
				{
					vexs[k].lowweight =UndirNetWork.GetWeight (minOrder,k);
					vexs[k].nearverex =minOrder;

				}
		}
	}
	if(i==VexNum)
		cout<<"最小生成树创建成功！"<<endl;
	delete []vexs;
}