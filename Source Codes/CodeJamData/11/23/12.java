import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Comparator;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Locale;
import java.util.Queue;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.Map.Entry;

public class Solution implements Runnable {

	public static void main(String[] args) {
		(new Thread(new Solution())).start();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	BigInteger nextBigInt() throws IOException {
		return new BigInteger(nextToken());
	}
	
	int[][] edges = new int[20][20];
	boolean[][] w = new boolean[20][20];
	int[] l = new int[20];
	boolean[][] mat = new boolean[20][20];
	int n;
	
	int[] nextEdge(int[] a) {
		int[] res = new int[2];
		res[0] = (a[0] + edges[a[0]][a[1]]) % n;
		res[1] = (Arrays.binarySearch(edges[res[0]], 0, l[res[0]], n - edges[a[0]][a[1]]) + n - 1) % n;
		return res;
	}
	
	int[] res = new int[20];
	int gr;
	
	boolean rek(int q, int ans) {
		if (q == n) {
			for (int i = 0; i < gr; i++) {
				boolean[] w = new boolean[ans];
				for (int j = 0; j < n; j++) {
					if (mat[i][j]) {
						w[res[j]] = true;
					}
				}
				for (int qq = 0; qq < ans; qq++) {
					if (!w[qq]) return false;
				}
			}
			return true;
		} else {
			for (int i = 0; i < ans; i++) {
				res[q] = i;
				if (rek(q + 1, ans)) return true;
			}
		}
		return false;
	}

	void solve() throws IOException {
		for (boolean[] i : w) Arrays.fill(i, false);
		for (boolean[] i : mat) Arrays.fill(i, false);
		Arrays.fill(l, 0);
		n = nextInt();
		int m = nextInt();
		int[] u = new int[m];
		for (int i = 0; i < m; i++) u[i] = nextInt() - 1;
		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			edges[u[i]][l[u[i]]++] = (n + v - u[i]) % n;
			edges[v][l[v]++] = (n + u[i] - v) % n;
		}
		for (int i = 0; i < n; i++) {
			edges[i][l[i]++] = 1;
			edges[i][l[i]++] = n - 1;
		}
		for (int i = 0; i < n; i++) {
			Arrays.sort(edges[i], 0, l[i]);
		}
		gr = 0;
		int ans = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < l[i]; j++) {
				if (!w[i][j] && edges[i][j] < n - 1) {
					int cnt = 1;
					w[i][j] = true;
					mat[gr][i] = true;
					int[] q = nextEdge(new int[] {i, j});
					while (q[0] != i) {
						w[q[0]][q[1]] = true;
						mat[gr][q[0]] = true;
						cnt++;
						q = nextEdge(q);
					}
					ans = Math.min(ans, cnt);
					gr++;
				}
			}
		}
		out.println(ans);
		rek(0, ans);
		for (int i = 0; i < n; i++) out.print((res[i] + 1) + " ");
		out.println();
	}
	
	public void run() {
		Locale.setDefault(Locale.UK);
		try {
			in = new BufferedReader(new FileReader(new File("input.txt")));
			out = new PrintWriter(new FileWriter(new File("output.txt")));
			int t = nextInt();
			for (int nn = 1; nn <= t; nn++) {
				out.print("Case #" + nn + ": ");
				solve();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		out.flush();
	}

}
