import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;


public class Solution implements Runnable {
	
	
	int[] dc = new int[] {1, -1, 1, -1};
	int[] dr = new int[] {0, 0, -1, -1};
	
	private ArrayList<ArrayList<Integer>> e;
	private boolean[] w;
	private int[] r2l;
	void solve() throws Exception {
		int tc = nextInt();
		for (int tt = 0; tt < tc; tt++) {
			out.print("Case #" + (tt + 1) + ": ");
			int m = nextInt();
			int n = nextInt();
			boolean[][] broken = new boolean[m][n];
			int vc = n * m;
			for (int i = 0; i < m; i++) {
				String s = nextToken();
				for (int j = 0; j < n; j++) {
					if (s.charAt(j) == 'x') {
						broken[i][j] = true;
						vc--;
					}
				}
			}
			int[][] num = new int[m][n];
			int cnt1 = 0;
			int cnt2 = 0;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (broken[i][j]) {
						continue;
					}
					if (j % 2 == 0) {
						num[i][j] = cnt1++;
					} else {
						num[i][j] = cnt2++;
					}
				}
			}
			e = new ArrayList<ArrayList<Integer>>();
			for (int i = 0; i < cnt1; i++) {
				e.add(new ArrayList<Integer>());
			}
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (broken[i][j]) {
						continue;
					}
					if (j % 2 == 0) {
						for (int k = 0; k < dr.length; k++) {
							int ni = i + dr[k];
							int nj = j + dc[k];
							if (0 <= ni && ni < m && 0 <= nj && nj < n) {
								if (broken[ni][nj]) {
									continue;
								}
								e.get(num[i][j]).add(num[ni][nj]);
							}
						}
					} else {
						for (int k = 0; k < dr.length; k++) {
							int ni = i + dr[k];
							int nj = j + dc[k];
							if (0 <= ni && ni < m && 0 <= nj && nj < n) {
								if (broken[ni][nj]) {
									continue;
								}
								e.get(num[ni][nj]).add(num[i][j]);
							}
						}
						
					}
				}
			}
			int size = 0;
			r2l = new int[cnt2];
			Arrays.fill(r2l, -1);
			for (int i = 0; i < cnt1; i++) {
				w = new boolean[cnt1];
				if (go(i)) {
					size++;
				}
			}
//			System.out.println(tc);
			out.println(vc - size);
		}
	}
	
	boolean go(int x) {
		if (w[x]) {
			return false;
		}
		w[x] = true;
		for (int y : e.get(x)) {
			if (r2l[y] == -1 || go(r2l[y])) {
				r2l[y] = x;
				return true;
			}
		}
		return false;
	}
	
	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new Thread(new Solution("c")).start();
	}

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	public Solution(String fname) throws IOException {
		in = new BufferedReader(new FileReader(fname + ".in"));
		st = new StringTokenizer("");
		out = new PrintWriter(new FileWriter(fname + ".out"));
	}
	
	
	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	
	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}
	
	public void run() {
		try {
			solve();
		} catch (Exception e) {
			apstenu(e);
		} finally {
			out.close();
		}
	}

	private void apstenu(Exception e) {
		e.printStackTrace();
		System.exit(1);
	}
	
}
