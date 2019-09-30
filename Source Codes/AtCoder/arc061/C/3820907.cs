using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		int[][] a=new int[s[1]][];
		int[] h=new int[s[0]+1];
		HashSet<int>[] hs=new HashSet<int>[s[0]+1];
		Dictionary<int,List<int>>[] hl=new Dictionary<int,List<int>>[s[0]+1];
		List<int[]>[] li=new List<int[]>[s[0]+1];
		for(int i=1;i<=s[0];i++){
			li[i]=new List<int[]>();
			hs[i]=new HashSet<int>();
			h[i]=int.MaxValue;
			hl[i]=new Dictionary<int,List<int>>();
		}
		h[1]=0;
		for(int i=0;i<s[1];i++){
			a[i]=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			li[a[i][0]].Add(new int[]{a[i][1],a[i][2]});
			li[a[i][1]].Add(new int[]{a[i][0],a[i][2]});
			if(!hl[a[i][0]].ContainsKey(a[i][2])){hl[a[i][0]].Add(a[i][2],new List<int>());}
			if(!hl[a[i][1]].ContainsKey(a[i][2])){hl[a[i][1]].Add(a[i][2],new List<int>());}
			hl[a[i][0]][a[i][2]].Add(a[i][1]);
			hl[a[i][1]][a[i][2]].Add(a[i][0]);
		}
		for(int i=0;i<li[1].Count;i++){
			hpa(1,li[1][i][0],li[1][i][1]);
			h[li[1][i][0]]=1;
		}
		while(he.Count>0&&hs[s[0]].Count==0){
			if(h[he[0][1]]==he[0][0]){
				if(hs[he[0][1]].Count==0){
					hs[he[0][1]].Add(he[0][2]);
					for(int i=0;i<li[he[0][1]].Count;i++){
						int q=li[he[0][1]][i][1]==he[0][2]?he[0][0]:he[0][0]+1;
						if(h[li[he[0][1]][i][0]]>=q&&(!hs[li[he[0][1]][i][0]].Contains(li[he[0][1]][i][1]))){
							hpa(q,li[he[0][1]][i][0],li[he[0][1]][i][1]);
							h[li[he[0][1]][i][0]]=q;
						}
					}
				}
				else if(!hs[he[0][1]].Contains(he[0][2])){
					hs[he[0][1]].Add(he[0][2]);
					if(hl[he[0][1]][he[0][2]].Count>1){
						for(int i=0;i<hl[he[0][1]][he[0][2]].Count;i++){
							if(h[hl[he[0][1]][he[0][2]][i]]>=he[0][0]&&(!hs[hl[he[0][1]][he[0][2]][i]].Contains(he[0][2]))){
								hpa(he[0][0],hl[he[0][1]][he[0][2]][i],he[0][2]);
								h[hl[he[0][1]][he[0][2]][i]]=he[0][0];
							}
						}
					}
				}
			}
			hpr();
		}
		Console.WriteLine(h[s[0]]==int.MaxValue?-1:h[s[0]]);
	}
	static List<int[]> he=new List<int[]>();
	static void hpa(int a,int b,int c){
		he.Add(new int[]{a,b,c});
		int j=he.Count-1;
		while(he[j][0]<he[(j-1)/2][0]){//
			int v=he[j][0];he[j][0]=he[(j-1)/2][0];he[(j-1)/2][0]=v;
			v=he[j][1];he[j][1]=he[(j-1)/2][1];he[(j-1)/2][1]=v;
			v=he[j][2];he[j][2]=he[(j-1)/2][2];he[(j-1)/2][2]=v;
			j=(j-1)/2;
		}
	}
	static void hpr(){
		he[0]=he[he.Count-1];
		he.RemoveAt(he.Count-1);
		int j=0;
		while(true){
			if(j*2+2<he.Count){
				if(he[j*2+1][0]<he[j*2+2][0]){j=j*2+1;}//
				else{j=j*2+2;}
			}
			else if(j*2+1<he.Count){j=j*2+1;}
			else{break;}
			if(he[j][0]>=he[(j-1)/2][0]){break;}//
			int v=he[j][0];he[j][0]=he[(j-1)/2][0];he[(j-1)/2][0]=v;
			v=he[j][1];he[j][1]=he[(j-1)/2][1];he[(j-1)/2][1]=v;
			v=he[j][2];he[j][2]=he[(j-1)/2][2];he[(j-1)/2][2]=v;
		}
	}
}