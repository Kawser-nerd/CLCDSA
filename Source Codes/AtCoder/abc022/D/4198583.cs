using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class Program{
	const int mod=1000000007;
	const long o=1;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I,p=0;
		int[][] a=new int[n][];
		int[][] b=new int[n][];
		for(int i=0;i<n;i++){
			a[i]=sc.Ia;
			if(a[i][1]<a[p][1]){p=i;}
			else if(a[i][1]==a[p][1]&&a[i][0]>a[p][0]){p=i;}
		}
		Gs gs1=new Gs(a,p);
		double d1=gs1.Diameter();
		p=0;
		for(int i=0;i<n;i++){
			b[i]=sc.Ia;
			if(b[i][1]<b[p][1]){p=i;}
			else if(b[i][1]==b[p][1]&&b[i][0]>b[p][0]){p=i;}
		}
		Gs gs2=new Gs(b,p);
		double d2=gs2.Diameter();
		Console.WriteLine(d2/d1);
	}
}
public class Gs{
	public class Mo{
		public int n;
		public long x,y;
		public double d;
		public Mo(double d,int n,long x,long y){this.d=d;this.n=n;this.x=x;this.y=y;}
	}
	private Mo[] arr;
	public List<Mo> li=new List<Mo>();
	public Gs(int[][] a,int p){
		int n=a.Length,q=2;
		arr=new Mo[n];
		for(int i=0;i<n;i++){
			if(i!=p){arr[i]=new Mo(Math.Atan2(a[i][1]-a[p][1],a[i][0]-a[p][0])*180/Math.PI,i,a[i][0],a[i][1]);}
		}
		arr[p]=new Mo(-512,p,a[p][0],a[p][1]);
		Array.Sort(arr,Ca);
		li.Add(arr[0]);
		li.Add(arr[1]);
		while(q!=n){
			li.Add(arr[q]);
			q++;
			while(li.Count>2&&(li[li.Count-1].x-li[li.Count-2].x)*(li[li.Count-3].y-li[li.Count-2].y)-(li[li.Count-1].y-li[li.Count-2].y)*(li[li.Count-3].x-li[li.Count-2].x)<=0){li.RemoveAt(li.Count-2);}
		}
	}
	private int Ca(Mo a,Mo b){
		if(a.d>b.d){return 1;}
		else if(a.d<b.d){return -1;}
		else if(a.y>b.y){return 1;}else if(a.y<b.y){return -1;}
		else if(a.x<b.x){return 1;}else if(a.x>b.x){return -1;}
		else{return 0;}
	}
	public double Diameter(){
		double q=(li[0].x-li[li.Count-1].x),p=(li[0].y-li[li.Count-1].y),d=Math.Sqrt(q*q+p*p);
		for(int i=1;i<li.Count;i++){
			q=(li[i].x-li[i-1].x);
			p=(li[i].y-li[i-1].y);
			d+=Math.Sqrt(q*q+p*p);
		}
		return d;
	}
}

public class Sc{
	public int I{get{return int.Parse(Console.ReadLine());}}
	public long L{get{return long.Parse(Console.ReadLine());}}
	public double D{get{return double.Parse(Console.ReadLine());}}
	public string S{get{return Console.ReadLine();}}
	public int[] Ia{get{return Array.ConvertAll(Console.ReadLine().Split(),int.Parse);}}
	public long[] La{get{return Array.ConvertAll(Console.ReadLine().Split(),long.Parse);}}
	public double[] Da{get{return Array.ConvertAll(Console.ReadLine().Split(),double.Parse);}}
	public string[] Sa{get{return Console.ReadLine().Split();}}
}