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
		
		// clockwise 90 == transpose |> left-right inverse
		
		char[,] transpose = new char[N,N];
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) transpose[j,i] = S[i][j];
		
		char[,] ans = new char[N,N];
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) ans[i,N-j-1] = transpose[i,j];
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++) Console.Write(ans[i,j]);
			Console.WriteLine();
		}
		
		
	}
	int N;
	String[] S;
	public Sol(){
		N = ri();
		S = new String[N];
		for(int i = 0; i < N; i++) S[i] = rs();
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