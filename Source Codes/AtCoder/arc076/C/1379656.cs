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
		
		List<Pair> L = new List<Pair>();
		for(int i=0;i<N;i++){
			if(IsOnTheKabe(P[i][0],P[i][1]) && IsOnTheKabe(P[i][2],P[i][3])){
				long f = Enc(P[i][0],P[i][1]);
				long t = Enc(P[i][2],P[i][3]);
				if(f > t){ var tmp = t; t = f; f = tmp; }
				L.Add(new Pair(f,t));
			}
		}
		
		L.Sort((p,q) => p.Fr.CompareTo(q.Fr));
		
		
		Stack<Pair> Stk = new Stack<Pair>();
		foreach(var p in L){
			while(Stk.Count > 0){
				var enclosure = Stk.Peek();
				if(p.Fr > enclosure.To){
					Stk.Pop();
					continue;
				} 
				if(p.Fr > enclosure.Fr && p.To < enclosure.To){
					break;
				} 
				Console.WriteLine("NO");
				return;
			}
			Stk.Push(p);
		}
		Console.WriteLine("YES");
	}
	
	class Pair{
		public long Fr,To;
		public Pair(long f, long t){
			Fr = f; To = t;
		}
	}
	
	bool IsOnTheKabe(long x, long y){
		return (x == 0 || x == R) || (y == 0 || y == C);
	}
	long Enc(long x, long y){
		if(y == 0) return x;
		if(x == R) return R + y;
		if(y == C) return R + C + (R - x);
		if(x == 0) return R + C + R + (C - y);
		return 0;
	}
	
	long R,C;
	int N;
	long[][] P;
	public Sol(){
		var d = rla();
		R = d[0]; C = d[1]; N = (int)d[2];
		P = new long[N][];
		for(int i=0;i<N;i++) P[i] = rla();
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