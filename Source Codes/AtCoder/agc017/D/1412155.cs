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
		
		gr = new int[N];
		dfs(0,-1);
		Console.WriteLine(gr[0] == 0 ? "Bob" : "Alice" );
		
		
	}
	
	int[] gr;
	void dfs(int now, int pre){
		if(E[now].Count == 0){
			gr[now] = 0;
			return;
		}
		int g = 0;
		foreach(var nxt in E[now]){
			if(nxt == pre) continue;
			dfs(nxt,now);
			g ^= (gr[nxt] + 1);
		}
		gr[now] = g;
		return;
	}
	
	
	int N;
	List<int>[] E;
	public Sol(){
		N = ri();
		E = new List<int>[N];
		for(int i=0;i<N;i++) E[i] = new List<int>();
		
		for(int i=0;i<N-1;i++){
			var d = ria();
			E[d[0] - 1].Add(d[1] - 1);
			E[d[1] - 1].Add(d[0] - 1);
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