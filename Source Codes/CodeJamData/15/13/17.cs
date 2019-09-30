using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class TEST{
	static void Main(){
		int T=int.Parse(Console.ReadLine());
		for(int i=1;i<=T;i++){
			Sol mySol =new Sol(i);
			mySol.Solve();
		}
	}
}

class Sol{
	public void Solve(){
		N=ri();
		P=new Pair[N];
		for(int i=0;i<N;i++){
			var dd=rla();
			P[i]=new Pair(dd[0],dd[1]);
		}
		
		Dictionary<Pair,int> D=new Dictionary<Pair,int>();
		for(int i=0;i<N;i++){
			D.Add(P[i],i);
		}
		
		
		
		int[] ord=new int[N];
		for(int i=0;i<N;i++){
			ord[i]=N*2;
		}
		
		for(int s=0;s<(1<<N);s++){
			List<Pair> L=new List<Pair>();
			for(int i=0;i<N;i++){
				if(((s>>i)&1)>0)L.Add(P[i]);
			}
			var CH=CreateConvHull(L);
			int t=N-bitCount(s);
			for(int i=0;i<CH.Count;i++){
				ord[D[CH[i]]]=Math.Min(ord[D[CH[i]]],t);
			}
		}
		for(int i=0;i<N;i++)Console.WriteLine(ord[i]);
	}
	int N;
	Pair[] P;
	public Sol(int T){
		Console.WriteLine("Case #{0}:",T);
	}

	int bitCount(int x){
		int ret=0;
		for(int i=0;i<30;i++){
			if(((x>>i)&1)>0)ret++;
		}
		return ret;
	}


	static String rs(){return Console.ReadLine();}
	static int ri(){return int.Parse(Console.ReadLine());}
	static long rl(){return long.Parse(Console.ReadLine());}
	static double rd(){return double.Parse(Console.ReadLine());}
	static String[] rsa(){return Console.ReadLine().Split(' ');}
	static int[] ria(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>int.Parse(e));}
	static long[] rla(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>long.Parse(e));}
	static double[] rda(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>double.Parse(e));}
	
	
	struct Pair{
		public long X;
		public long Y;
		public Pair(long x,long y){
			X=x;Y=y;
		}
		public override String ToString(){
			return "("+X.ToString()+","+Y.ToString()+")";
		}
	}

	static List<Pair> CreateConvHull(List<Pair> L_){
		List<Pair> L=new List<Pair>(L_);
		L.Sort((x,y)=>x.X.CompareTo(y.X)==0?x.Y.CompareTo(y.Y):x.X.CompareTo(y.X));
		if(L.Count<=2)return L;
		
		List<Pair> ret=new List<Pair>();
		int k=0;
		//下半分
		for(int i=0;i<L.Count;i++){
			//末尾削除はO(1)なのでどんどん使う。
			k=ret.Count;
			while(k>1 && det((ret[k-1].X-ret[k-2].X),(ret[k-1].Y-ret[k-2].Y),(L[i].X-ret[k-1].X),(L[i].Y-ret[k-1].Y))<0){
				ret.RemoveAt(k-1);
				k=ret.Count;
			}
			ret.Add(L[i]);
		}
		//上半分
		int t=ret.Count;
		for(int i=L.Count-2;i>=0;i--){
			//末尾削除はO(1)なのでどんどん使う。
			k=ret.Count;
			while(k>t && det((ret[k-1].X-ret[k-2].X),(ret[k-1].Y-ret[k-2].Y),(L[i].X-ret[k-1].X),(L[i].Y-ret[k-1].Y))<0){
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

