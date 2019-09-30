using System;
using System.Collections.Generic;
class Program{
	const int mod=1000000007;
	static List<int[]> he=new List<int[]>();
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[][] a=new int[n][];
		int[][] b=new int[n][];
		int[,,] hn=new int[n,4,2];
		bool[] h=new bool[n];
		long ans=0,ih=1;
		for(int i=0;i<n;i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			a[i]=new int[]{q[0],i};
			b[i]=new int[]{q[1],i};
		}
		Array.Sort(a,(u,v)=>u[0]-v[0]);
		Array.Sort(b,(u,v)=>u[0]-v[0]);
		for(int i=0;i<n-1;i++){
			hn[a[i][1],1,0]=a[i+1][0]-a[i][0];
			hn[a[i][1],1,1]=a[i+1][1];
			hn[a[i+1][1],0,0]=a[i+1][0]-a[i][0];
			hn[a[i+1][1],0,1]=a[i][1];
			hn[b[i][1],3,0]=b[i+1][0]-b[i][0];
			hn[b[i][1],3,1]=b[i+1][1];
			hn[b[i+1][1],2,0]=b[i+1][0]-b[i][0];
			hn[b[i+1][1],2,1]=b[i][1];
		}
		hn[a[0][1],0,1]=-1;
		hn[a[n-1][1],1,1]=-1;
		hn[b[0][1],2,1]=-1;
		hn[b[n-1][1],3,1]=-1;
		for(int i=0;i<4;i++){
			if(hn[0,i,1]!=-1){heapa(hn[0,i,0],hn[0,i,1]);}
		}
		h[0]=true;
		while(ih!=n){
			if(h[he[0][1]]==false){
				int q=he[0][1];
				h[q]=true;
				ans+=he[0][0];
				ih++;
				heapr();
				for(int i=0;i<4;i++){
					if(hn[q,i,1]!=-1){heapa(hn[q,i,0],hn[q,i,1]);}
				}
			}
			else{heapr();}
		}
		Console.WriteLine("{0}",ans);
	}
	static void heapa(int a,int b){
		he.Add(new int[]{a,b});
		int j=he.Count-1;
		while(he[j][0]<he[(j-1)/2][0]){
			int v=he[j][0];
			he[j][0]=he[(j-1)/2][0];
			he[(j-1)/2][0]=v;
			v=he[j][1];
			he[j][1]=he[(j-1)/2][1];
			he[(j-1)/2][1]=v;
			j=(j-1)/2;
		}
	}
	static void heapr(){
		he[0]=he[he.Count-1];
		he.RemoveAt(he.Count-1);
		int j=0;
		while(true){
			if(j*2+2<he.Count){
				if(he[j*2+1][0]<he[j*2+2][0]){j=j*2+1;}
				else{j=j*2+2;}
			}
			else if(j*2+1<he.Count){j=j*2+1;}
			else{break;}
			if(he[j][0]>=he[(j-1)/2][0]){break;}
			int v=he[j][0];
			he[j][0]=he[(j-1)/2][0];
			he[(j-1)/2][0]=v;
			v=he[j][1];
			he[j][1]=he[(j-1)/2][1];
			he[(j-1)/2][1]=v;
		}
	}
}