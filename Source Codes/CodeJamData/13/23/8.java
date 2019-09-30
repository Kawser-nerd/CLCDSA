package RoundB2013;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C implements Runnable {
	BufferedReader br;

	public static void main(String[] args) {
		new Thread(new C()).run();
	}

	StringTokenizer in;
	PrintWriter out;

	public String nextToken() throws IOException {
		while (in == null || !in.hasMoreTokens()) {
			in = new StringTokenizer(br.readLine());
		}

		return in.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	int sid = 0;
	Trie[] tries = new Trie[1125078];

	HashMap<State, Integer> cache = new HashMap<C.State, Integer>();

	public class State {
		int tid;
		int l;
		int le;

		public State(int tid, int l, int le) {
			this.tid = tid;
			this.l = l;
			this.le = le;
		}

		public boolean equals(Object o) {
			State s = (State) o;
			return s.tid == tid && s.l == l && s.le == le;
		}

		public int hashCode() {
			return (tid * 41 + l) * 6 + le;
		}
	}

	public class Trie {
		Trie[] next = new Trie[26];
		boolean end;
		int id = sid++;

		public Trie() {
			tries[id] = this;
		}

		public void add(String word) {

			Trie now = this;
			for (int i = 0; i < word.length(); i++) {
				int z = word.charAt(i) - 'a';
				if (now.next[z] == null)
					now.next[z] = new Trie();
				now = now.next[z];
			}

			now.end = true;
		}
	}

	int cnt = 0;

	String s;

	int INF = Integer.MAX_VALUE / 2;

	public int find(Trie t, int l, int le) {
		State st = new State(t.id, l, le);

		if (cache.containsKey(st))
			return cache.get(st);

		cnt++;

		int min = INF;

		if (t.end) {
			if (l < s.length())
				min = Math.min(find(tries[0], l, le), min);
			else
				return 0;
		}

		if (l == s.length())
			return INF;

		int z = s.charAt(l) - 'a';
		for (int i = 0; i < 26; i++) {
			if (t.next[i] == null)
				continue;

			if (i == z) {
				min = Math
						.min(find(t.next[i], l + 1, Math.min(le + 1, 5)), min);
			} else {
				if (le >= 5) {
					min = Math.min(min, find(t.next[i], l + 1, 1) + 1);
				}
			}
		}

		cache.put(st, min);

		return min;
	}

	public void solve() throws IOException {
		s = nextToken();

		cache.clear();

		find(tries[0], 0, 5);

		System.err.println(cnt);

		int min = Integer.MAX_VALUE;
		for (int i = 0; i < 6; i++) {
			State st = new State(0, 0, i);

			if (cache.containsKey(st))
				min = Math.min(min, cache.get(st));
		}
		out.println(min);
	}

	public void run() {
		try {
			BufferedReader dic = new BufferedReader(new FileReader(
					"dictionary.txt"));

			tries[0] = new Trie();

			String line;
			while ((line = dic.readLine()) != null) {
				tries[0].add(line);
			}

			System.err.println("Build dic " + sid);

			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");

			int t = nextInt();
			for (int i = 0; i < t; i++) {
				System.err.println(i);
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
