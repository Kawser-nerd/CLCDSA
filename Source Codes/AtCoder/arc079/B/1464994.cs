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
		
		int N = 50;
		long[] ans = new long[N];
		for(int i=0;i<N;i++) ans[i] = K/N + N-1;
		int c = 0;
		for(int i=0;i<K%N;i++){
			if(ans[c] + N > 10000000000000000L + 1000) c++;
			for(int j=0;j<N;j++){
				if(j != c) ans[j]--;
				if(j == c) ans[j]+=N;
			}
		}
		
		Console.WriteLine(N);
		Console.WriteLine(String.Join(" ",ans));
		
	}
	long K;
	public Sol(){
		K = rl();
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