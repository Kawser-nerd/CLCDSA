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
		
		int N,P;
		int[] G;
		
		var d = ria();
		N = d[0]; P = d[1];
		G = ria();
		int ans = 0;
		
		if(P == 2){
			int[] cnt = new int[2];
			for(int i=0;i<N;i++) cnt[G[i] % 2]++;
			ans += cnt[0];
			ans += cnt[1]/2;
			if(cnt[1] % 2 != 0) ans += 1;
			Console.WriteLine(ans);
			return;
		}
		
		if(P == 3){
			int[] cnt = new int[3];
			for(int i=0;i<N;i++) cnt[G[i] % 3]++;
			ans += cnt[0];
			int mm = Math.Min(cnt[1],cnt[2]);
			ans += mm;
			cnt[1] -= mm;
			cnt[2] -= mm;
			
			ans += cnt[1]/3; if(cnt[1] %3 != 0) ans++;
			ans += cnt[2]/3; if(cnt[2] %3 != 0) ans++;			
			
			Console.WriteLine(ans);
			return;
		}
		
		
		
		
	}
	
	public Sol(int T){
		Console.Write("Case #{0}: ",T);
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