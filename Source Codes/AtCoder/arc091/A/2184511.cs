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
		
		if(N > 2 && M > 2){
			Console.WriteLine((N-2) * (M-2));
			return;
		}
		
		if(N == 1 && M == 1){
			Console.WriteLine(1);
			return;
		}
		if(N == 1 && M == 2){
			Console.WriteLine(0);
			return;
		}
		if(N == 1){
			Console.WriteLine(M - 2);
			return;
		}
		if(N == 2){
			Console.WriteLine(0);
			return;
		}
		
		
		
	}
	long N,M;
	public Sol(){
		var d = rla();
		N = d[0]; M = d[1];
		if(N > M){
			var t = N; N = M; M = t;
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