using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
static class Program{
	const int mod=1000000007;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		var pq=new Pq<Mo<int>>(100000,true);
		bool[] b=new bool[100000];
		pq.Push(new Mo<int>(1,1));
		b[1]=true;
		while(pq.Top.d!=0){
			int p=pq.Top.n,q=pq.Top.d;
			pq.Pop();
			b[q]=true;
			if(!b[(q*10)%n]){pq.Push(new Mo<int>(p,(q*10)%n));}
			if(!b[(q+1)%n]){pq.Push(new Mo<int>(p+1,(q+1)%n));}
		}
		Console.WriteLine("{0}",pq.Top.n);
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