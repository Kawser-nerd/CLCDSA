import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

// 1 2 3 4 5
public class Main {
	// 0 - 1 BFS
	// Simple cool application
	// can be solved with two dimensional bfs


	public static boolean ok (int i,int j,int n,int m) {
		return i >= 0 && i < n && j >= 0 && j < m;
	}

	public static void main(String[]args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt();
		int dx[] = {0,-1,1,0};
		int dy[] = {1,0,0,-1};
		char grid[][] = new char[n][];
		for (int i = 0 ; i < n ; ++i) {
			grid[i] = sc.next().toCharArray();
		}
		Deque<Integer> dq = new LinkedList();
		int d[] = new int[n * m];
		for (int i = 0 ; i < n ; ++i) {
			for (int j = 0 ; j < m ; ++j) {
				if (grid[i][j] == 's') {
					dq.addFirst(i * m  + j);
				}
			}
		}
		Arrays.fill(d, 1 << 30);
		d[dq.getFirst()] = 0;
		while (!dq.isEmpty()) {
			int val = dq.pollFirst();
			if (d[val] > 2) {
				break;
			}
			int i = val / m, j = val % m;
			if (grid[i][j] == 'g') {
				System.out.println("YES");
				return;
			}
			for (int k = 0 ; k < 4 ; ++k) {
				int xc = dx[k] + i, yc = dy[k] + j;
				if (ok(xc,yc,n,m)) {
					int edgeCost = grid[xc][yc] == '#' ? 1 : 0;
					if (d[val] + edgeCost >= d[xc * m + yc]) {
						continue;
					}
					d[xc * m + yc] = d[val] + edgeCost;
					if (edgeCost == 0) {
						dq.addFirst(xc * m + yc);
					} else {
						dq.addLast(xc * m + yc);
					}
				}
			}

		}
		System.out.println("NO");
		
	}
	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(String s) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(new File(s)));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public boolean ready() throws IOException {
			return br.ready();
		}
	}


} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.