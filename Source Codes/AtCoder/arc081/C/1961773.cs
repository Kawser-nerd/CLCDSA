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
		
		var Q = new Queue<int>[26];
		for(int i=0;i<26;i++) Q[i] = new Queue<int>();
		
		String S = "S" + A + "abcdefghijklmnopqrstuvwxyzG";
		int N = A.Length;
		int NN = S.Length;
		for(int i=1;i<NN-1;i++){
			Q[S[i] - 'a'].Enqueue(i);
		}
		List<int>[] E = new List<int>[NN];
		for(int i=0;i<NN;i++) E[i] = new List<int>();
		
		for(int i=0;i<26;i++){
			int n = Q[i].Peek();
			E[0].Add(n);
			E[n].Add(0);
		}
		
		for(int i=1;i<1+N;i++){
			Q[S[i] - 'a'].Dequeue();
			for(int j=0;j<26;j++){
				var n = Q[j].Peek();
				E[i].Add(n);
				E[n].Add(i);
			}
		}
		
		for(int i=1+N;i<1+N+26;i++){
			E[i].Add(NN-1);
			E[NN-1].Add(i);
		}
		
		int Inf = (int)1e9;
		int[] min = new int[NN];
		for(int i=0;i<NN;i++) min[i] = Inf;
		
		min[NN-1] = 0;
		var Q0 = new Queue<int>();
		Q0.Enqueue(NN-1);
		while(Q0.Count > 0){
			var now = Q0.Dequeue();
			foreach(var nxt in E[now]){
				if(min[nxt] == Inf){
					min[nxt] = min[now] + 1;
					Q0.Enqueue(nxt);
				}
			}
		}
		
		List<char> L = new List<char>();
		int nowp = 0;
		
		while(nowp != NN-1){
			int nxt = -1;
			char minc = (char)('z' + 1);
			foreach(var e in E[nowp]){
				if(min[e] == min[nowp] - 1){
					if(S[e] == 'G'){
						nxt = e;
						break;
					} else {
						if(S[e] < minc){
							nxt = e;
							minc = S[e];
						}
					}
				}
			}
			
			if(S[nxt] != 'G') L.Add(S[nxt]);
			nowp = nxt;
		}
		
		Console.WriteLine(new String(L.ToArray()));
		
		
		
	}
	String A;
	public Sol(){
		A = rs();
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