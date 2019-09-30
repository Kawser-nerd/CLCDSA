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
		
		var D = new Dictionary<int,int>();
		foreach(var n in A){
			if(!D.ContainsKey(n)) D.Add(n, 0);
			D[n]++;
		}
		
		var L = new List<Tuple<int,int>>();
		foreach(var k in D.Keys){
			L.Add(new Tuple<int,int>(k, D[k]));
		}
		L.Sort((p,q) => p.Item2.CompareTo(q.Item2));
		L.Reverse();
		int tot = 0;
		for(int i=0;i<Math.Min(K,L.Count);i++){
			tot += L[i].Item2;
		}
		Console.WriteLine(N-tot);
		
		
	}
	int N,K;
	int[] A;
	public Sol(){
		var d = ria();
		N = d[0]; K = d[1];
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