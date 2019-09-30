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
		
		List<int>[] E = new List<int>[N];
		for(int i=0;i<N;i++) E[i] = new List<int>();
		for(int i=0;i<M;i++){
			E[A[i]-1].Add(B[i]-1);
			E[B[i]-1].Add(A[i]-1);
		}
		
		bool[] used = new bool[N];
		int a = A[0] - 1;
		int b = B[0] - 1;
		
		var L = new LinkedList<int>();
		
		int l = a;
		used[b] = true;
		while(!used[l]){
			L.AddLast(l);
			used[l] = true;
			foreach(var nxt in E[l]){
				if(!used[nxt]){
					l = nxt;
					break;
				}
			}
		}
		
		int r = b;
		used[r] = false;
		while(!used[r]){
			L.AddFirst(r);
			used[r] = true;
			foreach(var nxt in E[r]){
				if(!used[nxt]){
					r = nxt;
					break;
				}
			}
		}
		
		var ans = L.ToList();
		Console.WriteLine(ans.Count);
		Console.WriteLine(String.Join(" ",ans.Select(n => n + 1)));
		
		
	}
	int N,M;
	int[] A,B;
	public Sol(){
		var d = ria();
		N = d[0];
		M = d[1];
		A = new int[M];
		B = new int[M];
		for(int i=0;i<M;i++){
			d = ria();
			A[i] = d[0]; B[i] = d[1];
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