using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
static class Program{
	const int mod=1000000007;
	const long o=1;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I,t=n-2;
		double ans=0;
		var pq=new Pq<Mo<int>>(n*n,true);
		int[][] a=new int[n][];
		double[] h=new double[n];
		a[0]=sc.Ia;
		for(int i = 1;i<n;i++) {
			a[i]=sc.Ia;
			double d=Math.Sqrt((a[0][0]-a[i][0])*(a[0][0]-a[i][0])+(a[0][1]-a[i][1])*(a[0][1]-a[i][1]));
			d/=Math.Min(a[0][2],a[i][3]);
			pq.Push(new Mo<int>(d,i));
		}
		while(t>=0){
			double k=pq.Top.n;
			int g=pq.Top.d;
			if(h[g]==0){
				h[g]=k;
				ans=Math.Max(ans,k+t);
				t--;
				for(int i = 1;i<n;i++) {
					if(h[i]==0){
						double d=Math.Sqrt((a[g][0]-a[i][0])*(a[g][0]-a[i][0])+(a[g][1]-a[i][1])*(a[g][1]-a[i][1]));
						d/=Math.Min(a[g][2],a[i][3]);
						pq.Push(new Mo<int>(d+k,i));
					}
				}
			}
			pq.Pop();
		}
		Console.WriteLine(ans);
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