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
		
		Array.Sort(A);
		Array.Reverse(A);
		
		int l = 0, r = N;
		if(!isEssential(0)){
			Console.WriteLine(N);
			return;
		}
		
		while(r - l > 1){
			int c = (l + r) / 2;
			if(isEssential(c)){
				l = c;
			} else {
				r = c;
			}
		}
		
		Console.WriteLine(N - (l + 1));
	}
	
	bool isEssential(int t){
		
		bool[] reach = new bool[K];
		reach[0] = true;
		for(int i=0;i<N;i++){
			if(i == t) continue;
			for(int j=K-1;j>=0;j--){
				if(!reach[j]) continue;
				if(j + A[i] < K) reach[j + A[i]] = true;
			}
		}
		
		bool chk = false;
		for(int i=K-1;i>= Math.Max(0, K - A[t]);i--) chk |= reach[i];
		
		return chk;
		
	}
	
	int N;
	int K;
	long[] A;
	public Sol(){
		var d = ria();
		N = d[0]; K = d[1];
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