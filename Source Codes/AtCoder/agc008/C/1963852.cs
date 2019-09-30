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
		
		long I = A[0];
		long O = A[1];
		long J = A[3];
		long L = A[4];
		
		long ans = 0;
		
		ans += O;
		long x = (I/2) * 2 + (L/2) * 2 + (J/2) * 2;
		long y = (L > 0 & J > 0 & I > 0) ? (3 + (L-1)/2 * 2 + (I-1)/2 * 2 + (J-1)/2 * 2) : 0;
		ans += Math.Max(x, y);
		Console.WriteLine(ans);
		
	}
	long[] A;
	public Sol(){
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