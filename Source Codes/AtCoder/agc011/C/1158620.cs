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
		
		long iso0 = 0;
		long iso = 0;
		for(int i=0;i<N;i++) if(E[i].Count == 0) iso0++;
		iso = iso0 * N * 2 - (iso0 * iso0);
		long bi = 0;
		long nbi = 0;
		
		int[] used = new int[N];
		for(int i=0;i<N;i++){
			if(used[i] != 0) continue;
			used[i] = 1;
			Queue<int> Q = new Queue<int>();
			Q.Enqueue(i);
			bool chk = true;
			while(Q.Count>0){
				var now = Q.Dequeue();
				foreach(var nxt in E[now]){
					if(used[nxt] == 0){
						used[nxt] = 3 - used[now];
						Q.Enqueue(nxt);
					} else {
						if(used[nxt] == 3 - used[now]) continue;
						chk = false;
					}
				}
			}
			if(chk){
				bi++;
			}else{
				nbi++;
			}
			//Console.WriteLine(String.Join(" ",used));
		}
		//Console.WriteLine("{0} {1}",bi,nbi);
		
		bi -= iso0;
		long bb = 2 * bi * bi;
		long bn = bi * nbi;
		long nb = nbi * bi;
		long nn = nbi * nbi;
		Console.WriteLine(iso + bb + bn + nb + nn);
		
	}
	int N,M;
	List<int>[] E;
	public Sol(){
		var d = ria();
		N = d[0]; M = d[1];
		E = new List<int>[N];
		for(int i=0;i<N;i++) E[i] = new List<int>();
		for(int i=0;i<M;i++){
			d = ria();
			E[d[0]-1].Add(d[1]-1);
			E[d[1]-1].Add(d[0]-1);
		}
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