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
		
		long[] sum = new long[2];
		long max = -(long) 1e18;
		int midx = -1;
		for(int i=0;i<N;i++){
			sum[i % 2] += Math.Max(0, A[i]);
			if(max < A[i]){
				max = A[i];
				midx = i; 
			}
		}
		
		int pref = sum[0] >= sum[1] ? 0 : 1;
		if(max <= 0) pref = midx % 2;
		
		List<Pair> L = new List<Pair>();
		for(int i=0;i<N;i++){
			if(i % 2 == pref){
				if(A[i] > 0 || i == midx) {
					L.Add(new Pair(A[i],2));
				} else {
					L.Add(new Pair(A[i],0));
				}
			} else {
				L.Add(new Pair(A[i], 1));
			}
		}
		
		List<int> ans = new List<int>();
		while(true){
			bool update = false;
			List<Pair> nxt = new List<Pair>();
			for(int i=0;i<L.Count;i++){
				if(update || L[i].Opt != 0){
					nxt.Add(L[i]);
				} else {
					update = true;
					if(i == 0 || i == L.Count - 1){
						ans.Add(i + 1);
					} else {
						var merge = nxt[nxt.Count - 1] + L[i + 1];
						nxt.RemoveAt(nxt.Count - 1);
						nxt.Add(merge);
						ans.Add(i + 1);
						i++;
					}
				}
			}
			L = nxt;
			if(!update) break;
		}
		while(true){
			bool update = false;
			List<Pair> nxt = new List<Pair>();
			for(int i=0;i<L.Count;i++){
				if(update || L[i].Opt != 1){
					nxt.Add(L[i]);
				} else {
					update = true;
					if(i == 0 || i == L.Count - 1){
						ans.Add(i + 1);
					} else {
						var merge = nxt[nxt.Count - 1] + L[i + 1];
						nxt.RemoveAt(nxt.Count - 1);
						nxt.Add(merge);
						ans.Add(i + 1);
						i++;
					}
				}
			}
			L = nxt;
			if(!update) break;
		}
		
		Console.WriteLine(L[0].Val);
		Console.WriteLine(ans.Count);
		Console.WriteLine(String.Join("\n", ans));
		
	}
	
	class Pair{
		public long Val;
		public int Opt;
		public Pair(long val, int opt){
			Val = val; Opt = opt;
		}
		public static Pair operator+ (Pair p, Pair q){
			return new Pair(p.Val + q.Val, p.Opt);
		}
	}
	
	
	
	int N;
	long[] A;
	public Sol(){
		N = ri();
		A = rla();
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