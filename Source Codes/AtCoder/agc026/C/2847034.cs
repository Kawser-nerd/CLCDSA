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
		
		int N2 = N * 2;
		
		int[] cnt0 = new int[26];
		for(int i=0;i<N;i++) cnt0[S[i] - 'a']++;
		
		int[] cnt1 = new int[26];
		for(int i=N;i<N2;i++) cnt1[S[i] - 'a']++;
		
		for(int j=0;j<26;j++){
			if(cnt0[j] != cnt1[j]){
				Console.WriteLine(0);
				return;
			}
		}
		
		var di1 = new Dictionary<Pair,long>();
		for(int i=0;i<1<<N;i++){
			var ca0 = new List<char>();
			var ca1 = new List<char>();
			for(int j=0;j<N;j++){
				if(((i >> j) & 1) == 0){
					ca0.Add(S[j]);
				} else {
					ca1.Add(S[j]);
				}
			}
			var s = new String(ca0.ToArray());
			var t = new String(ca1.ToArray());
			var p = new Pair(s, t);
			if(di1.ContainsKey(p) == false) di1.Add(p, 0);
			di1[p]++;
		}
//Console.WriteLine("ok");		
		
		var di2 = new Dictionary<Pair,long>();
		for(int i=0;i<1<<N;i++){
			var ca0 = new List<char>();
			var ca1 = new List<char>();
			for(int j=0;j<N;j++){
				if(((i >> j) & 1) == 0){
					ca0.Add(S[N2 - 1 - j]);
				} else {
					ca1.Add(S[N2 - 1 - j]);
				}
			}
			var s = new String(ca0.ToArray());
			var t = new String(ca1.ToArray());
			var p = new Pair(s, t);
			if(di2.ContainsKey(p) == false) di2.Add(p, 0);
			di2[p]++;
		}
		
		long ans = 0;
		foreach(var p in di1.Keys){
			if(di2.ContainsKey(p)){
//Console.WriteLine("p;{0} di1:{1}, di2:{2}",p.ToString(), di1[p], di2[p]);
				ans += di1[p] * di2[p];
			}
		}
		
		Console.WriteLine(ans);
		
		
		
		
		
		
	}
	
	struct Pair{
		public String S,T;
		public Pair(String s, String t){
			S = s; T = t;
		}
		public override String ToString(){
			return S + "," + T;
		}
	}
	
	
	int N;
	String S;
	public Sol(){
		N = ri();
		S = rs();
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