import java.io.*;
import java.util.*;

public class C {

	void dfs(int v, int[] was1, int[] was2) {
		if (was2[v] == 2 || was1[v] == 1) {
			return;
		}
		was1[v] = 1;
		for (int i = 0; i<n; i++) {
			if (a[v][i] == 1) {
				dfs(i,was1,was2);
			}
		}
	}
	int n;
	int[][] a;
	
	void solve() throws IOException {
		n = nextInt();
		int m = nextInt();
		a = new int[n][n];
		final int[] val = new int[n];
		for (int i = 0; i < n; i++) {
			val[i] = nextInt();
		}
		for (int i = 0; i < m; i++) {
			int st = nextInt() - 1;
			int en = nextInt() - 1;
			a[st][en] = a[en][st] = 1;
		}

		Integer[] que = new Integer[n];
		for (int i = 0; i < n; i++) {
			que[i] = i;
		}
		Arrays.sort(que,new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return val[o1] - val[o2];
			}
		});
		
		int[] was = new int[n];
		int[] stack = new int[n];
		int tl = 0;
		int start = que[0];
		stack[tl++] = start;
		was[start] = 1;

		for (int i = 0; i < n; i++) {
			out.print(val[stack[tl-1]]);
			for (int j : que) {
				if (was[j] == 0) {
					int[] oldwas = was.clone();
					int[] oldstack = stack.clone();
					int oldtl = tl;
					while (tl > 0 && a[stack[tl - 1]][j] == 0) {
						was[stack[tl-1]] = 2;
						tl--;
					}
					if (tl == 0) {
						was = oldwas;
						stack = oldstack;
						tl = oldtl;
						continue;
					}
					was[j] = 1;
					stack[tl++] = j;
					int[] dfswas = new int[n];
					for (int k = 0; k<n; k++) {
						if (was[k] == 1) {
							dfs(k,dfswas,was);
						}
					}
					boolean fl = true;
					for (int k = 0; k<n; k++) {
						if (dfswas[k] == 0 && was[k] == 0) {
							fl = false;
						}
					}
					if (fl) { 
						break;
					} else {
						was = oldwas;
						stack = oldstack;
						tl = oldtl;
					}
				}
			}
		}
		out.println();
	}

	void run() throws IOException {
		in = new BufferedReader(new FileReader("C.in"));
		out = new PrintWriter("C.out");
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println(i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
		}

	public static void main(String[] args) throws IOException {
		new C().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String temp = in.readLine();
			if (temp == null) {
				return null;
			}
			st = new StringTokenizer(temp);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

}
