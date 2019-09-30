using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class TEST{
	static void Main(){
		Sol mySol =new Sol();
		mySol.Solve();
	}
}

class Sol{
	public void Solve(){
		
		if(N == 2){
			Console.WriteLine("0.5\n0.5");
			return;
		}
		
		var L = new List<Pair>();
		for(int i=0;i<N;i++){
			L.Add(new Pair(X[i], Y[i], i));
		}
		
		var CH = Geo.GrahamScan(L);
		double[] ans = new double[N];
		if(CH.Count == 2){
			foreach(var p in CH){
				ans[p.Idx] = 0.5;
			}
			for(int i=0;i<N;i++){
				Console.WriteLine(ans[i]);
			}
			return;
		}
		
		int M = CH.Count;
		for(int i=0;i<M;i++){
			double theta = Pair.ang(CH[(i+1)%M] - CH[i], CH[(i+M-1)%M] - CH[i]);
			ans[CH[i].Idx] = (Math.PI - theta) / (2 * Math.PI);
		}
		for(int i=0;i<N;i++){
			Console.WriteLine(ans[i]);
		}
		
		
	}
	int N;
	long[] X,Y;
	public Sol(){
		N = ri();
		X = new long[N];
		Y = new long[N];
		for(int i=0;i<N;i++){
			var d = rla();
			X[i] = d[0]; Y[i] = d[1];
		}
	}

	static String rs(){return Console.ReadLine();}
	static int ri(){return int.Parse(Console.ReadLine());}
	static long rl(){return long.Parse(Console.ReadLine());}
	static double rd(){return double.Parse(Console.ReadLine());}
	static String[] rsa(char sep=' '){return Console.ReadLine().Split(sep);}
	static int[] ria(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>int.Parse(e));}
	static long[] rla(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>long.Parse(e));}
	static double[] rda(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>double.Parse(e));}
}

class Pair{
	public long X;
	public long Y;
	public int Idx;
	public Pair(long x,long y, int idx){
		X=x;Y=y;Idx = idx;
	}
	public static Pair operator-(Pair p,Pair q){
		return new Pair(p.X-q.X,p.Y-q.Y, -1);
	}
	public static long det(Pair p,Pair q){
		return (p.X*q.Y-p.Y*q.X);
	}
	public static double ang(Pair p, Pair q){
		double a = (double) p.X;
		double b = (double) p.Y;
		double c = (double) q.X;
		double d = (double) q.Y;
		
		double cos = (a * c + b * d) / (Math.Sqrt( a *a + b * b) * Math.Sqrt(c * c + d * d)); 
		return Math.Acos(cos);
	}
	
	
	
}


class Geo{
	public static List<Pair> GrahamScan(List<Pair> L_){
		List<Pair> L=new List<Pair>(L_);
		L.Sort((x,y)=>x.X.CompareTo(y.X)==0?x.Y.CompareTo(y.Y):x.X.CompareTo(y.X));
		
		List<Pair> ret=new List<Pair>();
		int k=0;
		//???
		for(int i=0;i<L.Count;i++){
			//?????O(1)??????????
			k=ret.Count;
			while(k>1 && det((ret[k-1].X-ret[k-2].X),(ret[k-1].Y-ret[k-2].Y),(L[i].X-ret[k-1].X),(L[i].Y-ret[k-1].Y)) <= 0){
				ret.RemoveAt(k-1);
				k=ret.Count;
			}
			ret.Add(L[i]);
		}
		//???
		int t=ret.Count;
		for(int i=L.Count-2;i>=0;i--){
			//?????O(1)??????????
			k=ret.Count;
			while(k>t && det((ret[k-1].X-ret[k-2].X),(ret[k-1].Y-ret[k-2].Y),(L[i].X-ret[k-1].X),(L[i].Y-ret[k-1].Y)) <= 0){
				ret.RemoveAt(k-1);
				k=ret.Count;
			}
			ret.Add(L[i]);
		}
		ret.RemoveAt(ret.Count-1);
		return ret;
	}
	static long det(long a,long b,long c,long d){
		return a*d-b*c;
	}
}