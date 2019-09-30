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
		
		var B = (int[]) A.Clone();
		Array.Sort(B);
		HashSet<int> H = new HashSet<int>();
		for(int i=0;i<N;i+=2) H.Add(B[i]);
		
		int cnt = 0;
		for(int i=0;i<N;i+=2) if(!H.Contains(A[i])) cnt++;
		
		Console.WriteLine(cnt);
		
		
	}
	int N;
	int[] A;
	public Sol(){
		N = ri();
		A = new int[N];
		for(int i=0;i<N;i++) A[i] =ri();
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