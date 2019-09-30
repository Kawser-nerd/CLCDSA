import java.util.*;
import java.io.*;
import java.math.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	public void solve() throws Exception {
		int tests = sc.nextInt();
		outer:
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			int n = sc.nextInt();
			char s[][] = new char[n][];
			for (int i = 0; i < n; i++) {
				s[i] = in.readLine().toCharArray();
			}
			ArrayList<Integer> counts [] = new ArrayList [n];
			ArrayList<Character> chars [] = new ArrayList [n];
			
			for (int i = 0; i < n; i++) {
				counts[i] = new ArrayList<>();
				chars[i] = new ArrayList<>();
				char c = s[i][0];
				int cnt = 1;
				for (int j = 1; j < s[i].length; j++) {
					if (s[i][j] == s[i][j - 1]) {
						cnt++;
					} else {
						counts[i].add(cnt);
						chars[i].add(c);
						c = s[i][j];
						cnt = 1;
					}
				}
				counts[i].add(cnt);
				chars[i].add(c);
			}
			
			for (int i = 1; i < n; i++) {
				if (chars[i].size() != chars[i - 1].size()) {
					out.println("Fegla Won");
					continue outer;
				}
			}
			
			int result = 0;
			
			for (int j = 0; j < chars[0].size(); j++) {
				int best = Integer.MAX_VALUE / 2;
				int cnt[] = new int [101];
				for (int i = 1; i < n; i++) {
					if (chars[i].get(j) != chars[i - 1].get(j)) {
						out.println("Fegla Won");
						continue outer;
					}
				}
				for (int i = 0; i < n; i++) {
					cnt[counts[i].get(j)]++;
				}
				for (int brute = 0; brute <= 100; brute++) {
					int current = 0;
					for (int i = 0; i <= 100; i++) {
						if (i == brute) continue;
						current += abs(i - brute) * cnt[i];
					}
					best = min(best, current);
				}
				result += best;
			}
			
			out.println(result);
			
		}
	}


	static Throwable t;

	BufferedReader in;
	FastScanner sc;
	PrintWriter out;

	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter(new FileWriter("output.txt"));
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(System.out);
			sc = new FastScanner(in);
			solve();
		} catch (Throwable t) {
			Solution.t = t;
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) throws Throwable {
		Thread thread = new Thread(null, new Solution(), "", 1 << 26);
		thread.start();
		thread.join();
		if (Solution.t != null)
			throw t;
	}

}

class FastScanner {

	BufferedReader in;
	StringTokenizer st;

	public FastScanner(BufferedReader in) {
		this.in = in;
	}

	public String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	public int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

}