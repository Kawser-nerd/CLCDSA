import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	static final String filename = "A-large";
	
	static class Profile {
		int[] a;
		int dist;
		boolean stable, setStable;
		
		public int hashCode() {
			return Arrays.hashCode(a);
		}
		
		public boolean equals(Object obj) {
			Profile p = (Profile)obj;
			return Arrays.equals(a, p.a);
		}
		
		static int[] col = new int[12];

		public boolean isStable() {
			if (!setStable) {
				setStable = true;
				Arrays.fill(col, 0);
				boolean first = true;
				for (int i = 0; i < a.length; ++i) {
					for (int jj = a[i]; jj != 0; ) {
						int j = Integer.numberOfTrailingZeros(jj);
						jj ^= 1 << j;
						if (!get(col, i, j)) {
							if (first) {
								dfs(i, j);
								first = false;
							} else {
								return stable = false;
							}
						}
					}
				}
				stable = true;
			}
			return stable;
		}

		private void dfs(int i, int j) {
			if (!get(a, i, j) || get(col, i, j)) {
				return;
			}
			col[i] |= 1 << j;
			for (int d = 0; d < 4; ++d) {
				int x = i + dx[d];
				int y = j + dy[d];
				if (x >= 0 && x < a.length) {
					dfs(x, y);
				}
			}
		}
	}

	public void solve(int test) throws IOException {
		System.out.println("Case #" + test);
		out.print("Case #" + test + ": ");
		ArrayList<Profile> q = new ArrayList<Profile>();
		int n = nextInt();
		int m = nextInt();
		int[] f = new int[n];
		Profile p0 = new Profile(), target = new Profile();
		p0.a = new int[n];
		target.a = new int[n];
		for (int i = 0; i < n; ++i) {
			char[] tmp = next().toCharArray();
			for (int j = 0; j < m; ++j) {
				if (tmp[j] == '#') {
					f[i] |= 1 << j;
				} else if (tmp[j] == 'o') {
					p0.a[i] |= 1 << j;
				} else if (tmp[j] == 'x') {
					target.a[i] |= 1 << j;
				} else if (tmp[j] == 'w') {
					p0.a[i] |= 1 << j;
					target.a[i] |= 1 << j;
				}
			}
		}
		HashSet<Profile> col = new HashSet<Profile>();
		col.add(p0);
		q.add(p0);
		for (int it = 0; it < q.size(); ++it) {
			Profile p = q.get(it);
			if (p.equals(target)) {
				out.println(p.dist);
				return;
			}
			boolean stable = p.isStable();
			for (int i = 0; i < n; ++i) {
				for (int jj = p.a[i]; jj != 0; ) {
					int j = Integer.numberOfTrailingZeros(jj);
					jj ^= 1 << j;
					for (int d = 0; d < 4; ++d) {
						int x = i + dx[d];
						int y = j + dy[d];
						int xb = i - dx[d];
						int yb = j - dy[d];
						if (x < 0 || x >= n || y < 0 || y >= m || get(f, x, y) || get(p.a, x, y) ||
							xb < 0 || xb >= n || yb < 0 || yb >= m || get(f, xb, yb) || get(p.a, xb, yb)) {
							continue;
						}
						Profile pp = new Profile();
						pp.a = p.a.clone();
						pp.a[i] ^= 1 << j;
						pp.a[x] ^= 1 << y;
						if (!stable && !pp.isStable() || col.contains(pp)) {
							continue;
						}
						col.add(pp);
						q.add(pp);
						pp.dist = p.dist + 1;
					}
				}
			}
		}
		out.println(-1);
	}
	
	final static int[] dx = {-1, 1, 0, 0};
	final static int[] dy = {0, 0, -1, 1};

	private static boolean get(int[] p, int i, int j) {
		return (p[i] & (1 << j)) != 0;
	}
	
	public void run() {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new PrintWriter(filename + ".out");
			eat("");
			
			int tests = nextInt();
			for (int test = 0; test < tests; ++test) {
				solve(test + 1);
			}
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		} catch (OutOfMemoryError er) {
			List<int[]> x = new ArrayList<int[]>();
			while (true) {
				x.add(new int[100000]);
			}
		}
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
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
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Thread(new Solution()).start();
	}
	
}
