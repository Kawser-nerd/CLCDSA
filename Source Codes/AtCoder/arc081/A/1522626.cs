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
		
		var D = new Dictionary<long,int>();
		for(int i=0;i<N;i++){
			if(D.ContainsKey(A[i]) == false) D.Add(A[i],0);
			D[A[i]]++;
		}
		
		var L = D.Keys.ToList();
		L.Sort();
		L.Reverse();
		long h = 0;
		long w = 0;
		for(int i=0;i<L.Count;i++){
			if(D[L[i]] >= 2){
				h = L[i];
				D[L[i]] -= 2;
				break;
			}
		}
		//foreach(var kvp in D) Console.WriteLine(kvp);
		for(int i=0;i<L.Count;i++){
			if(D[L[i]] >= 2){
				w = L[i];
				D[L[i]] -= 2;
				break;
			}
		}
		//foreach(var kvp in D) Console.WriteLine(kvp);
		
		Console.WriteLine(w*h);
	}
	int N;
	long[] A;
	public Sol(){
		N = ri();
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