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
		int N = S.Length;
		int min1 = N;
		for(int i=0;i<N;i++){
			if(S[i] == '0') continue;
			min1 = Math.Min(min1,Math.Max(i, N - i - 1));
		}
		int min0 = N;
		for(int i=0;i<N;i++){
			if(S[i] == '1') continue;
			min0 = Math.Min(min0,Math.Max(i, N - i - 1));
		}
		Console.WriteLine(Math.Max(min1,min0));
		
		
	}
	String S;
	public Sol(){
		S = rs();
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