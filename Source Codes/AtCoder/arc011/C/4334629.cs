using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
static class Program{
	const int mod=1000000007;
	const long o=1;
	static List<int>[] li;
	static void Main(){
		Sc sc=new Sc();
		string[] s=sc.Sa;
		int n=sc.I;
		int m=0;
		int[] h=new int[n+2];
		h[0]=-2;
		h[n+1]=-1;
		var sb=new StringBuilder();
		if(s[0]==s[1]||Le(s[0],s[1])==1){
			sb.Append(0+"\n"+s[0]+"\n"+s[1]+"\n");
			Console.Write(sb);
		}
		else{
			string[] a=new string[n+2];
			a[0]=s[0];
			a[n+1]=s[1];
			li=new List<int>[n+2];
			li[0]=new List<int>();
			li[n+1]=new List<int>();
			for(int i=1;i<=n;i++){
				h[i]=-1;
				a[i]=sc.S;
				li[i]=new List<int>();
				for(int j=0;j<i;j++){
					if(Le(a[i],a[j])==1){
						li[i].Add(j);
						li[j].Add(i);
						m++;
					}
				}
				if(Le(a[i],a[n+1])==1){
					li[i].Add(n+1);
					li[n+1].Add(i);
					m++;
				}
			}
			var pq=new Pq<Mo<int[]>>(m,true);
			for(int i=0;i<li[0].Count;i++){pq.Push(new Mo<int[]>(0,new int[]{li[0][i],0}));}
			while(pq.cnt>0){
				if(h[pq.Top.d[0]]==-1){
					h[pq.Top.d[0]]=pq.Top.d[1];
					for(int i=0;i<li[pq.Top.d[0]].Count;i++){
						if(h[li[pq.Top.d[0]][i]]==-1){pq.Push(new Mo<int[]>(pq.Top.n+1,new int[]{li[pq.Top.d[0]][i],pq.Top.d[0]}));}
					}
				}
				if(pq.Top.d[0]==n+1){break;}
				pq.Pop();
			}
			if(pq.cnt==0){Console.WriteLine(-1);}
			else{
				int q=n+1,z=-1;
				while(h[q]!=-2){
					z++;
					sb.Insert(0,a[q]+"\n");
					q=h[q];
				}
				sb.Insert(0,z+"\n"+a[0]+"\n");
				Console.Write(sb);
			}
		}
	}
	static int Le(string a,string b){
		int q=0;
		for(int i=0;i<a.Length&&q<2;i++){
			if(a[i]!=b[i]){q++;}
		}
		return q;
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
	public int[] Ia2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public long[] La2{get{return Array.ConvertAll(("0 "+Console.ReadLine()).Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}