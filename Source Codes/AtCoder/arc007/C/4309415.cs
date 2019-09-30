using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
static class Program{
	const int mod=1000000007;
	const long o=1;
	static void Main(){
		Sc sc=new Sc();
		string s=sc.S;
		int n=0,m=1<<s.Length,ans=0;
		int[] dp=new int[m];
		for(int i = 0;i<s.Length;i++) {if(s[i]=='o'){n|=1<<i;}}
		var pq=new Pq<Mo<int>>(200,true);
		pq.Push(new Mo<int>(1,n));
		if(n==m-1){ans=1;}
		while(ans==0){
			int k=pq.Top.n,d=pq.Top.d;
			pq.Pop();
			for(int i = 1;i<s.Length;i++) {
				int q=(((n|(n<<s.Length))>>i)&(m-1))|d;
				if(q==m-1){ans=k+1;break;}
				else if(dp[q]==0){
					pq.Push(new Mo<int>(k+1,q));
					dp[q]=k+1;
				}
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