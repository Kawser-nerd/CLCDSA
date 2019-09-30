import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.TreeMap;

public class BaiA {

	static int m, n;
	static char[][] a;

	static class Box implements Comparable<Box> {
		public int x, y;

		public Box clone() {
			return new Box(x, y);
		}

		public Box(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public int compareTo(Box b) {
			if (x == b.x)
				return y - b.y;
			else
				return x - b.x;
		}
	}

	static boolean ke(int x, int y, int u, int v) {
		return Math.abs(x - u) + Math.abs(y - v) == 1;
	}

	static boolean ke(Box a, Box b) {
		return ke(a.x, a.y, b.x, b.y);
	}

	static class State implements Comparable<State> {
		public Box[] a;
		public boolean ng;

		public void sort() {
			Arrays.sort(a);
		}

		public State clone() {
			State r = new State();
			r.a = new Box[a.length];
			r.ng = ng;
			for (int i = 0; i < a.length; ++i)
				r.a[i] = a[i].clone();
			return r;
		}

		public boolean isConnected() {
			boolean[] mark = new boolean[a.length];
			Queue<Integer> q = new LinkedList<Integer>();
			q.add(0);
			mark[0] = true;
			while (!q.isEmpty()) {
				int u = q.remove();
				for (int v = 0; v < mark.length; ++v)
					if (!mark[v] && ke(a[u], a[v])) {
						mark[v] = true;
						q.add(v);
					}
			}
			for (int i = 0; i < mark.length; ++i)
				if (!mark[i])
					return false;
			return true;
		}

		public int compareTo(State s) {
			for (int i = 0; i < a.length; ++i) {
				int t = a[i].compareTo(s.a[i]);
				if (t != 0)
					return t;
			}
			return 0;
		}
	}

	static int[] dx = new int[] { -1, 0, 1, 0 };
	static int[] dy = new int[] { 0, 1, 0, -1 };

	static boolean inside(int x, int y) {
		return 0 <= x && x < m && 0 <= y && y < n;
	}

	public static void main(String[] args) throws Exception {
		//Scanner sc = new Scanner(System.in);
		//PrintWriter pw = new PrintWriter(System.out);
		Scanner sc = new Scanner(new FileReader("A-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));
		int ntest = sc.nextInt();
		System.out.println(ntest);
		for (int test = 1; test <= ntest; ++test) {
			System.out.println(test);
			m = sc.nextInt();
			n = sc.nextInt();
			a = new char[m][];
			sc.nextLine();
			for (int i = 0; i < m; ++i) {
				a[i] = sc.nextLine().toCharArray();
			}

			int d = 0;
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j)
					if (a[i][j] == 'o' || a[i][j] == 'w')
						++d;
			}
			State st = new State();
			st.a = new Box[d];
			d = 0;
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j)
					if (a[i][j] == 'o' || a[i][j] == 'w')
						st.a[d++] = new Box(i, j);
			}
			d = 0;
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j)
					if (a[i][j] == 'x' || a[i][j] == 'w')
						++d;
			}
			State en = new State();
			en.a = new Box[d];
			d = 0;
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j)
					if (a[i][j] == 'x' || a[i][j] == 'w')
						en.a[d++] = new Box(i, j);
			}

			for (int i = 0; i < m; ++i)
				for (int j = 0; j < n; ++j)
					if (a[i][j] == 'x' || a[i][j] == 'w' || a[i][j] == 'o')
						a[i][j] = '.';

			st.sort();
			en.sort();

			Queue<State> q = new LinkedList<State>();
			TreeMap<State, Integer> map = new TreeMap<State, Integer>();
			q.add(st);
			map.put(st, 0);
			int res = -1;
			while (!q.isEmpty()) {
				State u = q.remove();
				int step = map.get(u);
				if (u.compareTo(en) == 0) {
					res = step;
					break;
				}
				boolean[][] mark = new boolean[m][n];
				for (int i = 0; i < u.a.length; ++i)
					mark[u.a[i].x][u.a[i].y] = true;
				for (int i = 0; i < u.a.length; ++i) {
					for (int h = 0; h < 4; ++h) {
						int x = u.a[i].x + dx[h];
						int y = u.a[i].y + dy[h];
						int uu = u.a[i].x - dx[h];
						int vv = u.a[i].y - dy[h];
						if (inside(x, y) && inside(uu, vv)) {
							if (!mark[x][y] && a[x][y] == '.' && !mark[uu][vv] && a[uu][vv] == '.') {
								State v = u.clone();
								v.a[i] = new Box(x, y);
								v.ng = !v.isConnected();
								v.sort();
								if (!(u.ng && v.ng) && !map.containsKey(v)) {
									map.put(v, step + 1);
									q.add(v);
								}
							}
						}
					}
				}
			}
			pw.println("Case #" + test + ": " + res);
		}
		pw.close();
		sc.close();
	}
}
