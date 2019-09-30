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
		
		var mx = A.Max();
		var mn = A.Min();
		mn *= -1;
		
		List<String> L = new List<String>();
		if(mx > mn){
			int idx = -1;
			for(int i=0;i<N;i++) if(A[i] == mx) idx = i;
			for(int i=0;i<N;i++) L.Add(String.Format("{0} {1}",idx + 1, i + 1));
			for(int i=0;i<N-1;i++) L.Add(String.Format("{0} {1}",i + 1, i + 2));
		} else {
			int idx = -1;
			for(int i=0;i<N;i++) if(A[i] == -mn) idx = i;
			for(int i=0;i<N;i++) L.Add(String.Format("{0} {1}",idx + 1, i + 1));
			for(int i=N-1;i>0;i--) L.Add(String.Format("{0} {1}",i + 1, i));
		}
		Console.WriteLine(L.Count);
		foreach(var s in L) Console.WriteLine(s);
		
		
		
	}
	int N;
	int[] A;
	public Sol(){
		N = ri();
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