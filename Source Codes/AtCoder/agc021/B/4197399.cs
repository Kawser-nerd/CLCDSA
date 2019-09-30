using System;
using System.Collections.Generic;
using System.Linq;
class Program{
	const int mod=1000000007;
	const long o=1;
	static void Main(){
		Sc sc=new Sc();
		int n=sc.I;
		int[][] a=new int[n][];
		int p=0;
		double[] ans=new double[n];
		for(int i = 0;i<n;i++) {
			a[i]=sc.Ia;
			if(a[i][1]<a[p][1]){p=i;}
		}
		Gs gs=new Gs(a,p);
		int m=gs.li.Count-1;
		for(int i = 1;i<m;i++) {ans[gs.li[i].n]=1.0*(180-Gp4(gs.li[i-1].x,gs.li[i-1].y,gs.li[i].x,gs.li[i].y,gs.li[i+1].x,gs.li[i+1].y))/360;}
		ans[gs.li[0].n]=1.0*(180-Gp4(gs.li[m].x,gs.li[m].y,gs.li[0].x,gs.li[0].y,gs.li[1].x,gs.li[1].y))/360;
		ans[gs.li[m].n]=1.0*(180-Gp4(gs.li[m-1].x,gs.li[m-1].y,gs.li[m].x,gs.li[m].y,gs.li[0].x,gs.li[0].y))/360;
		Console.WriteLine(String.Join("\n",ans));
	}
	static double Gp4(double ax,double ay,double bx,double by,double cx,double cy){
		double a1=ax-bx,a2=ay-by,c1=cx-bx,c2=cy-by;
		return Math.Acos((a1*c1+a2*c2)/Math.Sqrt((a1*a1+a2*a2)*(c1*c1+c2*c2)))*180/Math.PI;
	}
}
public class Gs{
	public class Mo{
		public int n;
		public long x,y;
		public double d;
		public Mo(double d,int n,int x,int y){this.d=d;this.n=n;this.x=x;this.y=y;}
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
			while(li.Count>2&&(li[li.Count-1].x-li[li.Count-2].x)*(li[li.Count-3].y-li[li.Count-2].y)-(li[li.Count-1].y-li[li.Count-2].y)*(li[li.Count-3].x-li[li.Count-2].x)<=0){li.RemoveAt(li.Count-2);}//
		}
	}
	private int Ca(Mo a,Mo b){
		if(a.d>b.d){return 1;}
		else if(a.d<b.d){return -1;}
		else if(a.y>b.y){return 1;}
		else if(a.y<b.y){return -1;}
		else{return 0;}
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