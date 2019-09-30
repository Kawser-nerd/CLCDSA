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
		
		if(N == 1){
			Console.WriteLine(2);
			return;
		}
		
		long mod = (long)1e9 + 7;
		
		long[] dpA = new long[N+1];
		long[] dpB = new long[N+1];
		long[] sumA = new long[N+2];
		long[] sumB = new long[N+2];
		
		dpA[0] = 1;
		sumA[1] = 1;
		dpB[0] = 1;
		sumB[1] = 1;
		
		int clA = 0;// [0,clA) ?0?????? (S[clA-1] ? S[clA] - A ????????
		int clB = 0;
		
		int okA = 0;// [0,okA) ?????????S[i]-A ? S[okA] ???????????? + 1
		int okB = 0;
		
		for(int i=1;i<N;i++){
			while(S[okA] <= S[i+1] - A && okA < i) okA++;
			while(S[okB] <= S[i+1] - B && okB < i) okB++;
			
			// dpB[*]? [0,okA) ??dpA[i] ??????[0,clB)? 0 ??????
			// ? ???????? [clB,okA)  
			if(okA >= clB) dpA[i] = sumB[okA] - sumB[clB] + mod; if(dpA[i] >= mod) dpA[i] -= mod;
			if(okB >= clA) dpB[i] = sumA[okB] - sumA[clA] + mod; if(dpB[i] >= mod) dpB[i] -= mod;
			
			// dpA[*] [0,i) ? S[i+1] >= S[i] + A ?? ???? dpA[*] ???
			// ? ??????? dpA[*] [0,i)? ??? 0 ??? 
			if(S[i+1] - A < S[i]) clA = i;
			if(S[i+1] - B < S[i]) clB = i;
			
			sumA[i+1] = sumA[i] + dpA[i]; if(sumA[i+1] >= mod) sumA[i+1] -= mod;
			sumB[i+1] = sumB[i] + dpB[i]; if(sumB[i+1] >= mod) sumB[i+1] -= mod;
		}
		
		long ans = sumA[N] + sumB[N] +(-sumA[clA] + mod) + (-sumB[clB] + mod);
		ans %= mod;
		
		Console.WriteLine(ans);
		
	}
	int N;
	long A,B;
	long[] S;
	public Sol(){
		var d = rla();
		N = (int) d[0]; A = d[1]; B = d[2];
		S = new long[N+1];
		S[0] = -(long)3e18;
		for(int i=0;i<N;i++) S[i+1] = rl();
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