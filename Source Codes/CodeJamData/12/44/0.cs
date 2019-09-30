using System;
using System.Collections;
using System.Collections.Generic;

public class D {
	int r, c;
	string[] map;
	
	void go(bool[,] av, int i, int j) {
		if (av[i, j] || map[i][j] == '#') {
			return;
		}
		
		av[i, j] = true;
		go (av, i, j - 1);
		go (av, i, j + 1);
		go (av, i - 1, j);
	}
		
	bool[,] getState(int i, int j) {
		bool[,] ok = new bool[r, c];
		go (ok, i, j);
		return ok;
	}
	
	int getSize(bool[,] state) {
		int cnt = 0;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				if (state[i, j])
					++cnt;
		return cnt;
	}
	
	string getKey(bool[,] state) {
		char[] cc = new char[r * c];
		int k = 0;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				cc[k++] += state[i, j] ? '1' : '0';
		
		return new string (cc);
	}
	
	bool[,] goo(bool[,] old, int dr, int dc) {
		bool[,] res = new bool[r, c];
		
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				int ii = i + dr;
				int jj = j + dc;
				if (ii < 0 || ii >= r || jj < 0 || jj >= c)
					continue;
				
				if (map[i][j] == '#')
					res[ii, jj] |= old[ii, jj];
				else
					res[i, j] |= old[ii, jj];
			}
		}
		
		return res;
	}
	
	bool solve(bool[,] state, int rr, int cc) {
		HashSet<string> visited = new HashSet<string>();
		Queue toVisit = new Queue();
		
		visited.Add(getKey (state));
		toVisit.Enqueue(state);
		
		while (toVisit.Count > 0) {
			state = (bool[,])toVisit.Dequeue();
			if (getSize (state) == 1 && state[rr, cc]) {
				return true;
			}
			
			bool[,] sl = goo(state, 0, 1);
			bool[,] sr = goo(state, 0, -1);
			bool[,] sd = goo(state, -1, 0);
			
			string kl = getKey (sl);
			string kr = getKey (sr);
			string kd = getKey (sd);
			
			if (!visited.Contains(kl)) {
				visited.Add(kl);
				toVisit.Enqueue(sl);
			}
			
			if (!visited.Contains(kr)) {
				visited.Add(kr);
				toVisit.Enqueue(sr);
			}
			
			if (!visited.Contains(kd)) {
				visited.Add(kd);
				toVisit.Enqueue(sd);
			}
		}
		
		return false;
	}
	
	public string solve() {
		string[] ss = Console.ReadLine ().Split (' ');
		r = int.Parse (ss[0]);
		c = int.Parse (ss[1]);
		
		map = new string[r];
		for (int i = 0; i < r; ++i) {
			map[i] = Console.ReadLine ();
		}
		
		int[] ra = new int[10];
		bool[] rb = new bool[10];
		
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				char ccc = map[i][j];
				if (ccc >= '0' && ccc <= '9') {
					int cc = ccc - '0';
					var state = getState(i, j);
					ra[cc] = getSize(state);
					rb[cc] = solve(state, i, j);
				}
			}
		}
		
		for (int i = 0; i < 10; ++i) {
			if (ra[i] != 0) {
				Console.WriteLine ("{0}: {1} {2}", i, ra[i], rb[i] ? "Lucky" : "Unlucky");
			}
		}
		return "";
	}
	
	public static void Main() {
		var instance = new D();
		int n = int.Parse(Console.ReadLine ());
		
		for (int i = 1; i <= n; ++i) {
			Console.WriteLine("Case #{0}:", i);
			instance.solve();
		}
	}
}
