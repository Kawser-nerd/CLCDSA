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
		
		if(H % h == 0 && W % w == 0){
			Console.WriteLine("No");
			return;
		}
		
		
		long b = 1000000000;
		long a = b / ( h * w - 1) - 1;
		
		long[][] M = new long[H][];
		for(int i=0;i<H;i++){
			M[i] = new long[W];
			for(int j=0;j<W;j++){
				if(i % h == h - 1 && j % w == w - 1){
					M[i][j] = - b;
				} else {
					M[i][j] = a;
				}
			}
		}
		
		Console.WriteLine("Yes");
		Console.WriteLine(String.Join("\n", M.Select(ar => String.Join(" ",ar))));
		
	}
	int H,W,h,w;
	public Sol(){
		 var d = ria();
		 H = d[0]; W = d[1]; h = d[2]; w = d[3];
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