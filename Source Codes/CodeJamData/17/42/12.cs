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
		
		int[] cnt = new int[C];
		for(int i=0;i<M;i++) cnt[B[i]]++;
		int mn0 = 0;
		for(int i=0;i<C;i++) mn0 = Math.Max(cnt[i],mn0);
		
		int[] seat = new int[N+1];
		for(int i=0;i<M;i++) seat[P[i]]++;
		
		int Inf = (int)1e9;
		int minRide = Inf;
		for(int i=mn0;i<=M;i++){
			int tot = 0;
			bool chk = true;
			for(int j=1;j<=N;j++){
				tot += seat[j];
				if(tot > j*i){
					chk = false;
					break;
				}
			}
			if(chk){
				minRide = i;
				break;
			}
		}
		
		int prom = 0;
		for(int i=1;i<=N;i++){
			if(seat[i] > minRide) prom += seat[i] - minRide;
		}
		
		
		Console.WriteLine("{0} {1}",minRide,prom);
		
		
	}
	int N,C,M;
	int[] P,B;
	
	public Sol(int T){
		Console.Write("Case #{0}: ",T);
		
		var d = ria();
		N = d[0]; C = d[1]; M = d[2];
		P = new int[M];
		B = new int[M];
		for(int i=0;i<M;i++){
			d = ria();
			P[i] = d[0]; B[i] = d[1]-1;
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