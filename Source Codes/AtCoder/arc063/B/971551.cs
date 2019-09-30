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
		
		// N > 1 ????????
		int[] Max = new int[N];
		
		Max[N-1] = A[N-1];
		for(int i=N-2;i>=0;i--){
			Max[i] = Math.Max(Max[i+1],A[i]);
		}
		
		int M = 0;
		for(int i=0;i<N;i++){
			M = Math.Max(Max[i]-A[i],M);
		}
		
		int cnt = 0;
		Dictionary<int,int> D = new Dictionary<int,int>();
		for(int i=N-1;i>=0;i--){
//Console.WriteLine(i);
			if(D.ContainsKey(A[i]) == false)D.Add(A[i],0);
			D[A[i]]++;
			if(Max[i] - A[i] == M){
				cnt += D[(M + A[i])];
				D[(Max[i] + A[i])] = 0;
			}
		}
		
		Console.WriteLine(cnt);
		
	}
	int N,T;
	int[] A;
	public Sol(){
		var d = ria();
		N = d[0]; T = d[1];
		A = ria();
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