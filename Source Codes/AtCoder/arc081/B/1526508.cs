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
		
		int[] dx = {-1,0};
		int[] dy = {0,-1};
		
		long mod = (long) 1e9 + 7;
		
		long ans = 1;
		int nvh0 = 0;
		for(int j=0;j<N;j++){
			int nvh = 0;
			if(j<N-1 && S[0][j+1] == S[0][j]){
				nvh = 2;
			} else {
				nvh = 1;
			}
			long c = 0;
			if(nvh0 == 0){
				c = nvh == 1 ? 3 : 6;
			} else {
				if(nvh0 == 2 && nvh == 2) c = 3;
				if(nvh0 == 1 && nvh == 2) c = 2;
				if(nvh0 == 2 && nvh == 1) c = 1;
				if(nvh0 == 1 && nvh == 1) c = 2;
			}
			ans *= c; ans %= mod;
			nvh0 = nvh;
			if(nvh == 2) j++;
		}
		
		Console.WriteLine(ans);
		
	}
	
	bool InRange(int t,int l, int r){
		return l <= t && t < r;
	}
	
	int N;
	String[] S;
	public Sol(){
		N = ri();
		S = new String[2];
		for(int i=0;i<2;i++) S[i] = rs();
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