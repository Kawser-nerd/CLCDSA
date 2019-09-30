using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
static class Program{
	const int mod=1000000007;
	const long o=1;
	static readonly int[][] di=new int[][]{new int[]{-1,0},new int[]{1,0},new int[]{0,-1},new int[]{0,1}};
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		string[] a=new string[s[0]];
		int[,] g=new int[3,2];
		int[][] h=new int[s[0]][];
		int[,,,]dp=new int[3,s[0],s[1],s[2]+1];
		for(int i = 0;i<s[0];i++) {
			a[i]=sc.S;
			h[i]=Enumerable.Repeat(-1,s[1]).ToArray();
			for(int j = 0;j<s[1];j++) {
				if(a[i][j]=='S'){g[0,0]=i;g[0,1]=j;}
				else if(a[i][j]=='G'){g[1,0]=i;g[1,1]=j;}
				else if(a[i][j]=='C'){g[2,0]=i;g[2,1]=j;}
			}
		}
		for(int k = 0;k<3;k++) {
			if(k!=0){
				for(int i = 0;i<s[0];i++) {h[i]=Enumerable.Repeat(-1,s[1]).ToArray();}
			}
			h[g[k,0]][g[k,1]]=0;
			var pq=new Pq<Mo<int[]>>(s[0]*s[1]*(s[2]+1),true);
			for(int i = 0;i<4;i++) {
				int y=g[k,0]+di[i][0],x=g[k,1]+di[i][1];
				if(0<=y&&y<s[0]&&0<=x&&x<s[1]&&a[y][x]!='T'&&(a[y][x]!='E'||s[2]!=0)){
					pq.Push(new Mo<int[]>(a[y][x]=='E'?1:0,1,new int[]{y,x}));
				}
			}
			while(pq.cnt>0){
				Mo<int[]> q=pq.Top;
				pq.Pop();
				if(h[q.d[0]][q.d[1]]==q.n){continue;}
				h[q.d[0]][q.d[1]]=q.n;
				dp[k,q.d[0],q.d[1],q.n]=q.m;
				for(int i = 0;i<4;i++) {
					int y=q.d[0]+di[i][0],x=q.d[1]+di[i][1];
					if(0<=y&&y<s[0]&&0<=x&&x<s[1]&&a[y][x]!='T'){
						int p=q.n+(a[y][x]=='E'?1:0);
						if(s[2]>=p&&h[y][x]<p){pq.Push(new Mo<int[]>(p,q.m+1,new int[]{y,x}));}
					}
				}
			}
		}
		int ans=10000;
		for(int i = 0;i<s[0];i++) {
			for(int j = 0;j<s[1];j++) {
				if(a[i][j]=='T'){continue;}
				int[] z=Enumerable.Repeat(10000,s[2]+1).ToArray();
				if(a[i][j]!='E'){
					for(int k = 0;k<=s[2];k++) {
						for(int l = 0;l<=k;l++) {
							if((a[i][j]=='S'||dp[0,i,j,l]!=0)&&(a[i][j]=='C'||dp[2,i,j,k-l]!=0)){z[k]=Math.Min(z[k],dp[0,i,j,l]+dp[2,i,j,k-l]*2);}
						}
					}
					for(int k = 0;k<=s[2];k++){
						for(int l = 0;l<=k;l++) {
							if((a[i][j]=='G'||dp[1,i,j,l]!=0)){ans=Math.Min(ans,z[k-l]+dp[1,i,j,l]);}
						}
					}
				}
				else{
					for(int k = 1;k<=s[2];k++) {
						for(int l = 1;l<=k;l++) {
							if(dp[0,i,j,l]!=0&&dp[2,i,j,k-l+1]!=0){z[k]=Math.Min(z[k],dp[0,i,j,l]+dp[2,i,j,k-l+1]*2);}
						}
					}
					for(int k = 1;k<=s[2];k++){
						for(int l = 1;l<=k;l++) {
							if(dp[1,i,j,l]!=0){ans=Math.Min(ans,z[k-l+1]+dp[1,i,j,l]);}
						}
					}
				}
			}
		}
		Console.WriteLine(ans==10000?-1:ans);
	}
}
public class Mo<T>:IComparable{
	public int n,m;
	public T d;
	public Mo(int n,int m,T d){this.n=n;this.m=m;this.d=d;}
	public int CompareTo(object obj){
		Mo<T> mymo=(Mo<T>)obj;
		if(mymo.n>n){return -1;}
		else if(mymo.n<n){return 1;}
		else if(mymo.m>m){return -1;}
		else if(mymo.m<m){return 1;}
		else{return 0;}
	}
}
public class Pq<T> where T:IComparable{
	private T[] he;
	public int cnt=0;
	private Func<T,T,int> compare;
	public Pq(int max,bool mm){
		he=new T[max];
		if(mm){compare=Ao;}
		else{compare=Do;}
	}
	public void Push(T x){
		int j=cnt;
		while(j!=0&&compare(x,he[(j-1)/2])>0){he[j]=he[(j-1)/2];j=(j-1)/2;}
		he[j]=x;
		cnt++;
	}
	public void Pop(){
		cnt--;
		T r=he[cnt];
		int j=0;
		while(true){
			if(j*2+1<cnt){
				if(compare(he[j*2+1],he[j*2+2])>0){j=j*2+1;}
				else{j=j*2+2;}
			}
			else if(j*2<cnt){j=j*2+1;}
			else{break;}
			if(compare(he[j],r)<=0){j=(j-1)/2;break;}
			he[(j-1)/2]=he[j];
		}
		he[j]=r;
	}
	private int Ao(T x,T y){return y.CompareTo(x);}
	private int Do(T x,T y){return x.CompareTo(y);}
	public T Top{get{return he[0];}}
}

public class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public int[] Ia2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}