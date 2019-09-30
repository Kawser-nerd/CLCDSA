using System;
using System.Collections.Generic;
class Program{
	static List<int[]> he=new List<int[]>();
	static void Main(){
		int n=int.Parse(Console.ReadLine());
		int[][] a=new int[n][];
		int[][] b=new int[n][];
		long ans=0,ih=1;
		for(int i=0;i<n;i++){
			int[] q=Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
			a[i]=new int[]{q[0],i};
			b[i]=new int[]{q[1],i};
		}
		Array.Sort(a,(u,v)=>u[0]-v[0]);
		Array.Sort(b,(u,v)=>u[0]-v[0]);
		for(int i=0;i<n-1;i++){
			heapa(a[i+1][0]-a[i][0],a[i][1],a[i+1][1]);
			heapa(b[i+1][0]-b[i][0],b[i][1],b[i+1][1]);
		}
		uf t=new uf(n);
		while(ih!=n){
			if(!t.same(he[0][1],he[0][2])){
				t.union(he[0][1],he[0][2]);
				ans+=he[0][0];
				ih++;
			}
			heapr();
		}
		Console.WriteLine("{0}",ans);
	}
	static void heapa(int a,int b,int c){
		he.Add(new int[]{a,b,c});
		int j=he.Count-1;
		while(he[j][0]<he[(j-1)/2][0]){
			int v=he[j][0];
			he[j][0]=he[(j-1)/2][0];
			he[(j-1)/2][0]=v;
			v=he[j][1];
			he[j][1]=he[(j-1)/2][1];
			he[(j-1)/2][1]=v;
			v=he[j][2];
			he[j][2]=he[(j-1)/2][2];
			he[(j-1)/2][2]=v;
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
			v=he[j][2];
			he[j][2]=he[(j-1)/2][2];
			he[(j-1)/2][2]=v;
		}
	}
}
public class uf{//union find
	private int[] arr;
	private int[] hi;
	public uf(int n){
		arr=new int[n];
		hi=new int[n];
		for(int i=0;i<n;i++){arr[i]=-1;}
	}
	public void union(int a,int b){
		a=root(a);
		b=root(b);
		if(a!=b){
			if(hi[a]<hi[b]){
				int v=b;
				b=a;
				a=v;
			}
			arr[a]+=arr[b];
			hi[a]=Math.Max(hi[a],hi[b]+1);
			arr[b]=a;
		}
	}
	public bool same(int a,int b){return root(a)==root(b);}
	public int total(int a){return -arr[root(a)];}
	private int root(int a){return arr[a]<0?a:arr[a]=root(arr[a]);}
}