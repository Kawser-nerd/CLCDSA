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
		
		int ret = inf;
		for(int i=0;i<N;i++){
			ret = Math.Min(ret, calc(i));
		}
		Console.WriteLine(ret);
		
	}
	const int inf = (int) 1e9;
	int calc(int midx){
		
		List<int> candi = new List<int>();
		List<int> compo = new List<int>();
		int min = A[midx];
		for(int i=0;i<N;i++){
			if(A[i] < min){
				compo.Sort();
				compo.Reverse();
				while(compo.Count >= K){
					candi.Add(compo[compo.Count - 1]);
					compo.RemoveAt(compo.Count - 1);
				}
				compo = new List<int>();
			} else {
				compo.Add(A[i]);
			}
		}
		if(compo.Count >= K){
			compo.Sort();
			compo.Reverse();
			while(compo.Count >= K){
				candi.Add(compo[compo.Count - 1]);
				compo.RemoveAt(compo.Count - 1);
			}
		}
		
		if(candi.Count < Q) return inf;
		candi.Sort();
		return candi[Q-1] - min;
		
	}
	
	
	
	
	int N, K, Q;
	int[] A;
	public Sol(){
		var d = ria();
		N = d[0]; K = d[1]; Q = d[2];
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