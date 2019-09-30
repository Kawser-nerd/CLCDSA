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
		
		var H = new HashSet<int>();
		foreach(var n in A) H.Add(n);
		
		if(H.Count > 2){
			Console.WriteLine("No");
			return;
		}
		
		int ma = A.Max();
		int mi = A.Min();
		if(ma - mi > 1){
			Console.WriteLine("No");
			return;
		}
		
		
		var ar = new List<int>();
		if(ma == mi){
			ar.Add(mi);
			ar.Add(mi + 1);
		} else {
			ar.Add(ma);
		}
		
		foreach(var n in ar){
			var ret = check(n);
			if(ret){
				Console.WriteLine("Yes");
				return;
			}
		}
		
		Console.WriteLine("No");
		
	}
	
	bool check(int n){
		
		int cnt = 0;
		for(int i=0;i<N;i++){
			if(A[i] == n - 1) cnt++;
		}
		
		int rest = n - cnt;
		if(rest == 0){
			return N - cnt == 0;
		}
		if(rest < 0 ){
			return false;
		}
		return N - cnt >= 2 * rest;
		
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