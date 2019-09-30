import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
public class B {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;
	
	static boolean[] processed;
	static boolean[] seen;
	static LinkedList<Integer>[] edges;
	
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new FileReader("b.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("b.out")));
		final int MAX_CASES = readInt();
		long[] fact = new long[101];
		final long MOD = 1000000007;
		fact[0] = 1;
		for(int i = 1; i < fact.length; i++) {
			fact[i] = fact[i-1] * i;
			fact[i] %= MOD;
		}
		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			pw.printf("Case #%d: ", casenum);
			int n = readInt();
			String[] list = new String[n];
			for(int i = 0; i < n; i++) {
				list[i] = nextToken();
			}
			boolean can = true;
			for(char ch = 'a'; ch <= 'z'; ch++) {
				int lockedInside = 0;
				int pureStart = 0;
				int pureEnd = 0;
				for(String out: list) {
					ArrayList<State> temp = new ArrayList<State>();
					for(int i = 0; i < out.length();) {
						if(out.charAt(i) != ch) {
							i++;
							continue;
						}
						int j = i+1;
						while(j < out.length() && out.charAt(i) == out.charAt(j)) {
							j++;
						}
						temp.add(new State(i, j-1));
						i = j;
					}
					if(temp.size() > 1) {
						can = false;
					}
					if(temp.isEmpty()) {
						continue;
					}
					State curr = temp.get(0);
					if(curr.x == 0 && curr.y == out.length()-1) {
						continue;
					}
					if(curr.x == 0) {
						pureStart++;
					}
					else if(curr.y == out.length()-1) {
						pureEnd++;
					}
					else {
						lockedInside++;
					}
				}
				if(pureStart > 1 || pureEnd > 1 || lockedInside > 1) {
					can = false;
				}
				if(lockedInside == 1 && (pureStart+pureEnd) > 0) {
					can = false;
				}
			}
			if(can == false) {
				pw.println(0);
			}
			else {
				long ret = 1;
				edges = new LinkedList[26];
				for(int i = 0; i < 26; i++) {
					edges[i] = new LinkedList<Integer>();
				}
				int[] pure = new int[26];
				int[] parent = new int[26];
				for(String out: list) {
					if(out.charAt(0) == out.charAt(out.length()-1)) {
						pure[out.charAt(0)-'a']++;
						continue;
					}
					else {
						edges[out.charAt(0)-'a'].add(out.charAt(out.length()-1)-'a');
						parent[out.charAt(out.length()-1)-'a']++;
					}
				}
				boolean cycle = false;
				processed = new boolean[26];
				seen = new boolean[26];
				for(int i = 0; i < 26; i++) {
					if(edges[i].size() > 1) {
						throw new RuntimeException("ASSERT DIRECTIONS");
					}
					cycle |= dfs(i);
				}
				int numComp = 0;
				for(int i = 0; i < 26; i++) {
					if(parent[i] == 0) {
						if(pure[i] == 0 && edges[i].isEmpty()) continue;
						numComp++;
						long num = 1;
						int now = i;
						while(true) {
							num *= fact[pure[now]];
							num %= MOD;
							if(edges[now].isEmpty()) {
								break;
							}
							now = edges[now].getFirst();
						}
						ret *= num;
						ret %= MOD;
					}
				}
				if(cycle) {
					ret = 0;
				}
				else {
					ret *= fact[numComp];
					ret %= MOD;
				}
				pw.println(ret);
			}
		}
		pw.close();
	}

	public static boolean dfs(int curr) {
		if(processed[curr]) return false;
		if(seen[curr]) return true;
		seen[curr] = true;
		for(int out: edges[curr]) {
			if(dfs(out)) {
				return true;
			}
		}
		processed[curr] = true;
		return false;
	}
	
	static class State {
		public int x,y;

		public State(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	public static int readInt() {
		return Integer.parseInt(nextToken());
	}

	public static long readLong() {
		return Long.parseLong(nextToken());
	}

	public static double readDouble() {
		return Double.parseDouble(nextToken());
	}

	public static String nextToken() {
		while(st == null || !st.hasMoreTokens())	{
			try {
				if(!br.ready())	{
					pw.close();
					System.exit(0);
				}
				st = new StringTokenizer(br.readLine());
			}
			catch(IOException e) {
				System.err.println(e);
				System.exit(1);
			}
		}
		return st.nextToken();
	}

	public static String readLine()	{
		st = null;
		try {
			return br.readLine();
		}
		catch(IOException e) {
			System.err.println(e);
			System.exit(1);
			return null;
		}
	}

}
