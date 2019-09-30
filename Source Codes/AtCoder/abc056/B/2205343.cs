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
		
		if(InRange(B, A, A + W + 1)){
			Console.WriteLine(0);
			return;
		}
		if(InRange(A, B, B + W + 1)){
			Console.WriteLine(0);
			return;
		}
		if(A < B){
			Console.WriteLine(B - (A + W));
		} else {
			Console.WriteLine(A - (B + W));
		}
		
	}
	
	bool InRange(int t, int l, int r){
		return l <= t && t < r;
	}
	
	int W, A, B;
	public Sol(){
		var d = ria();
		W = d[0]; A = d[1]; B = d[2];
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