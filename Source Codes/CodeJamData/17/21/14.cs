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
		
		double tmax = 0;
		for(int i=0;i<N;i++){
			var t = (D - K[i])/(double) S[i];
			tmax = Math.Max(t,tmax);
		}
		
		Console.WriteLine(D / tmax);
		
		
	}
	int N,D;
	int[] K,S;
	public Sol(int T){
		Console.Write("Case #{0}: ",T);
		var d = ria();
		D = d[0]; N = d[1];
		K = new int[N];
		S = new int[N];
		for(int i=0;i<N;i++){
			d = ria();
			K[i] = d[0];
			S[i] = d[1];
		}
	}




	static String rs(){return Console.ReadLine();}
	static int ri(){return int.Parse(Console.ReadLine());}
	static long rl(){return long.Parse(Console.ReadLine());}
	static double rd(){return double.Parse(Console.ReadLine());}
	static String[] rsa(){return Console.ReadLine().Split(' ');}
	static int[] ria(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>int.Parse(e));}
	static long[] rla(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>long.Parse(e));}
	static double[] rda(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>double.Parse(e));}

}

struct Pair{
	public char C;
	public int N;
	public Pair(char c,int n){
		this.N=n;
		this.C=c;
	}
}