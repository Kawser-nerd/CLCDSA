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
		
		var di = new Dictionary<long, int>();
		for(int i=0;i<N;i++){
			if(!di.ContainsKey(A[i])) di.Add(A[i], 0);
			di[A[i]]++;
		}
		
		int cnt = 0;
		for(int j=33;j>=0;j--){
			var t = 1L << j;
			var l = di.Keys.ToList();
			for(int i=0;i<l.Count;i++){
				if(l[i] >= t) continue;
				if(di[l[i]] > 0 && di.ContainsKey(t - l[i]) && di[t - l[i]] > 0){
					if(l[i] == t - l[i]){
						int c = di[l[i]] / 2;
						di[l[i]] -= 2 * c;
						cnt += c;
					} else {
						int c = Math.Min(di[l[i]], di[t - l[i]]);
						di[l[i]] -= c;
						di[t - l[i]] -= c;
						cnt += c;
					}
				}
			}
			
		}
		Console.WriteLine(cnt);
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