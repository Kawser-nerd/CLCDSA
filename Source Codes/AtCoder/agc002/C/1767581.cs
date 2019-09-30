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
		
		int last = -1;
		for(int i=0;i<N-1;i++){
			if(A[i+1] + A[i] >= L){
				last = i;
				break;
			}
		}
		if(last == -1){
			Console.WriteLine("Impossible");
			return;
		}
		
		var ans = new List<int>();
		ans.Add(last + 1);
		int l = last - 1;
		while(l >= 0){
			ans.Add(l+1);
			l--;
		}
		
		int r = last + 1;
		while(r < N-1){
			ans.Add(r+1);
			r++;
		}
		Console.WriteLine("Possible");
		ans.Reverse();
		foreach(var n in ans) Console.WriteLine(n);
	}
	int N;
	long L;
	long[] A;
	public Sol(){
		var d = ria();
		N = d[0]; L = d[1];
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