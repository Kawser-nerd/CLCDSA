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
		
		int[] cnt = new int[N+10];
		for(int i=0;i<M;i++){
			cnt[A[i]]++;
			cnt[B[i]]++;
		}
		
		bool chk = true;
		for(int i=0;i<N+1;i++){
			chk &= cnt[i] % 2 == 0;
		}
		Console.WriteLine(chk ? "YES" : "NO" );
		
		
	}
	int N,M;
	int[] A,B;
	public Sol(){
		var d = ria();
		N = d[0]; M = d[1];
		A = new int[M];
		B = new int[M];
		for(int i=0;i<M;i++){
			d = ria();
			if(d[0] > d[1]){ var t = d[0]; d[0] = d[1]; d[1] = t;}
			A[i] = d[0]; B[i] = d[1];
		}
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