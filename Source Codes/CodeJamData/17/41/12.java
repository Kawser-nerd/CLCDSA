import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
public class A {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			pw.printf("Case #%d: ", casenum);
			int n = readInt();
			final int MOD = readInt();
			int[] init = new int[MOD-1];
			int inc = 0;
			while(n-- > 0) {
				int curr = readInt();
				if(curr%MOD == 0) {
					inc++;
				}
				else {
					init[(curr%MOD)-1]++;
				}
			}
			int ret = 0;
			Map<State, Integer> dp = new HashMap<State, Integer>();
			dp.put(new State(init, 0), 0);
			while(!dp.isEmpty()) {
				Map<State, Integer> next = new HashMap<State, Integer>();
				for(State out: dp.keySet()) {
					ret = Math.max(ret, dp.get(out));
					for(int i = 0; i < out.amt.length; i++) {
						if(out.amt[i] == 0) continue;
						int nV = dp.get(out);
						out.amt[i]--;
						int nH = (out.have);
						if(nH == 0) nV++;
						nH += i+1;
						nH %= MOD;
						State nK = new State(out.amt, nH);
						if(!next.containsKey(nK) || next.get(nK) < nV) {
							next.put(nK, nV);
						}
						out.amt[i]++;
					}
				}
				dp = next;
			}
			pw.println(ret + inc);
		}
		pw.close();
	}

	static class State {
		public int[] amt;
		public int have;
		public State(int[] b, int c) {
			amt = new int[b.length];
			for(int i = 0; i < amt.length; i++) {
				amt[i] = b[i];
			}
			have = c;
		}
		public int hashCode() {
			int ret = 0;
			for(int out: amt) {
				ret *= 3137;
				ret += out;
			}
			ret *= 3137;
			ret += have;
			return ret;
		}
		public boolean equals(Object o) {
			State s = (State)o;
			if(have != s.have) return false;
			for(int i = 0; i < amt.length; i++) {
				if(amt[i] != s.amt[i]) {
					return false;
				}
			}
			return true;
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
