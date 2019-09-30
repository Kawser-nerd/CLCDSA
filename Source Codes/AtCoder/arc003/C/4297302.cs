using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
static class Program{
	const int mod=1000000007;
	const long o=1;
	static void Main(){
		Sc sc=new Sc();
		int[] s=sc.Ia;
		int sy=-1,sx=-1;
		bool e=false;
		double ans=double.MaxValue;
		string[] h=new string[s[0]];
		int[,] b=new int[s[0],s[1]];
		for(int i = 0;i<s[0];i++){
			h[i]=sc.S;
			for(int j = 0;j<s[1];j++){
				if(h[i][j]=='s'){sy=i;sx=j;b[i,j]=1;}
				else if(h[i][j]=='#'){b[i,j]=1;}
				else{b[i,j]=int.MaxValue;}
			}
		}
		var pq=new Pq<Mo<int[]>>(s[0]*s[1]*3,false);
		if(sy!=0&&b[sy-1,sx]!=1){pq.Push(new Mo<int[]>((h[sy-1][sx]-'0')*0.99,new int[]{sy-1,sx,2}));b[sy-1,sx]=2;}
		if(sy!=s[0]-1&&b[sy+1,sx]!=1){pq.Push(new Mo<int[]>((h[sy+1][sx]-'0')*0.99,new int[]{sy+1,sx,2}));b[sy+1,sx]=2;}
		if(sx!=0&&b[sy,sx-1]!=1){pq.Push(new Mo<int[]>((h[sy][sx-1]-'0')*0.99,new int[]{sy,sx-1,2}));b[sy,sx-1]=2;}
		if(sx!=s[1]-1&&b[sy,sx+1]!=1){pq.Push(new Mo<int[]>((h[sy][sx+1]-'0')*0.99,new int[]{sy,sx+1,2}));b[sy,sx+1]=2;}
		while(pq.cnt>0){
			int ky=pq.Top.d[0],kx=pq.Top.d[1],t=pq.Top.d[2];
			ans=Math.Min(pq.Top.n,ans);
			pq.Pop();
			if(ky!=0&&b[ky-1,kx]>t+1){
				if(h[ky-1][kx]=='g'){e=true;break;}
				pq.Push(new Mo<int[]>((h[ky-1][kx]-'0')*Math.Pow(0.99,t),new int[]{ky-1,kx,t+1}));
				b[ky-1,kx]=t+1;
			}
			if(ky!=s[0]-1&&b[ky+1,kx]>t+1){
				if(h[ky+1][kx]=='g'){e=true;break;}
				pq.Push(new Mo<int[]>((h[ky+1][kx]-'0')*Math.Pow(0.99,t),new int[]{ky+1,kx,t+1}));
				b[ky+1,kx]=t+1;
			}
			if(kx!=0&&b[ky,kx-1]>t+1){
				if(h[ky][kx-1]=='g'){e=true;break;}
				pq.Push(new Mo<int[]>((h[ky][kx-1]-'0')*Math.Pow(0.99,t),new int[]{ky,kx-1,t+1}));
				b[ky,kx-1]=t+1;
			}
			if(kx!=s[1]-1&&b[ky,kx+1]>t+1){
				if(h[ky][kx+1]=='g'){e=true;break;}
				pq.Push(new Mo<int[]>((h[ky][kx+1]-'0')*Math.Pow(0.99,t),new int[]{ky,kx+1,t+1}));
				b[ky,kx+1]=t+1;
			}
		}
		Console.WriteLine(e?ans:-1);
	}
}
public class Mo<T>:IComparable{
	public double n;
	public T d;
	public Mo(double n,T d){this.n=n;this.d=d;}
	public int CompareTo(object obj){
		Mo<T> mymo=(Mo<T>)obj;
		if(mymo.n>n){return -1;}
		else if(mymo.n<n){return 1;}
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
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}