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
	
		long Inf = (long) 1e18;
		Func<long, long, long> A = (x, y) => y >= x ? y - x : Inf;
		
		var L = new List<long>();
		
		// X X Y Y;
		L.Add(0 + A(X,Y) + 0);
		// X -X Y Y;
		L.Add(1 + A(-X,Y) + 0);
		// X X -Y Y;
		L.Add(0 + A(X,-Y) + 1);
		// X -X -Y Y;
		L.Add(1 + A(-X,-Y) + 1);
		// X Y X Y;
		L.Add(A(X,Y) + A(Y,X) + A(X,Y));
		// X -Y X Y;
		L.Add(A(X,-Y) + A(-Y,X) + A(X,Y));
		// X Y -X Y;
		L.Add(A(X,Y) + A(Y,-X) + A(-X,Y));
		// X -Y -X Y;
		L.Add(A(X,-Y) + A(-Y,-X) + A(-X,Y));
		
		Console.WriteLine(L.Min());
		
		
		
		
	}
	long X, Y;
	public Sol(){
		var d = rla();
		X = d[0]; Y = d[1];
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