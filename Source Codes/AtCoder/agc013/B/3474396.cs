using System;
using System.Collections.Generic;
class Program{
	static List<int>[] li;
	static int[] h;
	static int[] d;
	static int ans=0;
	static void Main(){
		int[] s=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
		li=new List<int>[s[0]+1];
		d=new int[3];
		d[0]=int.MaxValue;
		h=new int[s[0]+1];
		for(int i=1;i<=s[0];i++){li[i]=new List<int>();}
		for(int i=0;i<s[1];i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			li[q[0]].Add(q[1]);
			li[q[1]].Add(q[0]);
		}
		for(int i=1;i<=s[0];i++){
			if(d[0]>li[i].Count){
				d[0]=li[i].Count;
				d[1]=i;
				if(d[0]==2&&(li[li[i][0]].Count>2||li[li[i][1]].Count>2)){d[2]=1;}
			}
			else if(d[0]==2&&li[i].Count==2&&(li[li[i][0]].Count>2||li[li[i][1]].Count>2)){d[2]=1;}
		}
		h[d[1]]=-1;
		fu(d[1],1);
		Console.WriteLine(ans);
		int[] v=new int[ans];
		v[ans-1]=d[2];
		for(int i=ans-2;i>=0;i--){
			d[2]=h[d[2]];
			v[i]=d[2];
		}
		Console.WriteLine(String.Join(" ",v));
	}
	static void fu(int a,int b){
		for(int i=0;i<li[a].Count&&ans==0;i++){
			if(h[li[a][i]]==0){
				h[li[a][i]]=a;
				fu(li[a][i],b+1);
				if(ans==0){h[li[a][i]]=0;}
			}
		}
		if(ans==0){
			bool l=false;
			for(int i=0;i<li[d[1]].Count;i++){
				if(h[li[d[1]][i]]==0){
					l=true;
					break;
				}
			}
			if(!l){ans=b;d[2]=a;}
		}
	}
}