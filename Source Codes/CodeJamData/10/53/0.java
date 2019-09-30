import java.io.*;
import java.util.*;

public class Solution {
	
	final String f = "C-large";
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	static class Segment {
		int l, r;
		
		Segment(int l, int r) {
			this.l = l;
			this.r = r;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[2000001];
		for (int i = 0; i < n; ++i) {
			a[nextInt() + 1000000] += nextInt();
		}
		ArrayList<Integer> st = new ArrayList<Integer>();
		st.add(1000000000);
		boolean one = false;
		int count = 0;
		long ans = 0;
		for (int i = 0; i < a.length + 200000; ++i) {
			if (i < a.length) {
				count += a[i];
			}
//			if (count != 0) {
//				System.out.println();
//			}
			int t = count;
			count = 0;
			while (t > 1) {
				count++;
				if (one) {
					t--;
					int v = st.remove(st.size() - 1);
					int u = st.remove(st.size() - 1);
					ans += v + 1;
					if (v == 1) {
						if (u == 1) {
							st.add(st.remove(st.size() - 1) + 1);
							st.add(1);
						} else {
							st.add(u - 1);
							st.add(1);
							st.add(1);
						}
						one = false;
					} else {
						if (u == 1) {
							st.add(st.remove(st.size() - 1) + 1);
							st.add(1);
							st.add(v - 1);
						} else {
							st.add(u - 1);
							st.add(1);
							st.add(1);
							st.add(v - 1);
						}
					}
				} else {
					ans++;
					t -= 2;
					int u = st.remove(st.size() - 1);
					if (u == 1) {
						st.add(st.remove(st.size() - 1) + 1);
					} else {
						st.add(u - 1);
						st.add(1);
					}
					one = true;
				}
			}
			if (t == 0) {
				if (one) {
					st.add(1);
					one = false;
				} else {
					st.add(st.remove(st.size() - 1) + 1);
				}
			} else {
				if (!one) {
					st.add(1);
					one = true;
				} else {
					st.add(st.remove(st.size() - 1) + 1);
				}
			}
		}
		out.println(ans);
	}

	Solution() throws IOException {
		in = new BufferedReader(new FileReader(f + ".in"));
		out = new PrintWriter(f + ".out");
		
		eat("");
		
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			System.out.println("Test #" + (test + 1));
			out.print("Case #" + (test + 1) + ": ");
			solve();
		}
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws IOException {
		new Solution();
	}
}
