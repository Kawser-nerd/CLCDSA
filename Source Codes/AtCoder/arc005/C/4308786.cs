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
		string[] h=new string[s[0]];
		int[,] b=new int[s[0],s[1]];
		var pq=new Pq<Mo<int[]>>(s[0]*s[1],true);
		string ans="NO";
		for(int i = 0;i<s[0];i++) {
			h[i]=sc.S;
			for(int j = 0;j<s[1]&&pq.cnt==0;j++) {
				if(h[i][j]=='s'){
					pq.Push(new Mo<int[]>(1,new int[]{i,j}));
					b[i,j]=1;
					break;
				}
			}
		}
		while(pq.cnt>0){
			int y=pq.Top.d[0],x=pq.Top.d[1],d=pq.Top.n;
			if(h[y][x]=='g'){ans="YES";break;}
			pq.Pop();
			if(y!=0&&b[y-1,x]==0){
				if(h[y-1][x]!='#'){pq.Push(new Mo<int[]>(d,new int[]{y-1,x}));b[y-1,x]=d;}
				else if(d<3){pq.Push(new Mo<int[]>(d+1,new int[]{y-1,x}));b[y-1,x]=d+1;}
			}
			if(y!=s[0]-1&&b[y+1,x]==0){
				if(h[y+1][x]!='#'){pq.Push(new Mo<int[]>(d,new int[]{y+1,x}));b[y+1,x]=d;}
				else if(d<3){pq.Push(new Mo<int[]>(d+1,new int[]{y+1,x}));b[y+1,x]=d+1;}
			}
			if(x!=0&&b[y,x-1]==0){
				if(h[y][x-1]!='#'){pq.Push(new Mo<int[]>(d,new int[]{y,x-1}));b[y,x-1]=d;}
				else if(d<3){pq.Push(new Mo<int[]>(d+1,new int[]{y,x-1}));b[y,x-1]=d+1;}
			}
			if(x!=s[1]-1&&b[y,x+1]==0){
				if(h[y][x+1]!='#'){pq.Push(new Mo<int[]>(d,new int[]{y,x+1}));b[y,x+1]=d;}
				else if(d<3){pq.Push(new Mo<int[]>(d+1,new int[]{y,x+1}));b[y,x+1]=d+1;}
			}
		}
		Console.WriteLine(ans);
	}
}
public class Mo<T>:IComparable{
	public int n;
	public T d;
	public Mo(int n,T d){this.n=n;this.d=d;}
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