import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
 
public class Main {
	InputStream is;
 
	int __t__ = 1;
	int __f__ = 0;
	int __FILE_DEBUG_FLAG__ = __f__;
	String __DEBUG_FILE_NAME__ = "src/B3";
 
	FastScanner in;
	PrintWriter out;
	
	class UnionFindTree {
		int[] parent;
		int[] size;
		
		public UnionFindTree(int n) {
			parent = new int[n];
			size = new int[n];
			init();
		}
		
		public void init() {
			for (int i = 0; i < parent.length; i++) {
				parent[i] = i;
				size[i] = 1;
			}
		}
		
		public int find(int x) {
			if (parent[x] == x) return x;
			return parent[x] = find(parent[x]);
		}
		
		public boolean same(int x, int y) {
			return find(x) == find(y);
		}
		
		public void unite(int x, int y) {
			int xx = find(x), yy = find(y);
			if (xx == yy) return;
			parent[xx] = yy;
			size[yy] += size[xx];
		}
 
		public int getSize(int x) {
			return size[find(x)];
		}
		
		public String toString() {
			String res = "";
			res += Arrays.toString(parent) + "\n";
			res += Arrays.toString(size);
			return res;
		}
	}
 
	public void solve() {
		int n = in.nextInt(), m = in.nextInt(), S = in.nextInt() - 1;
		
		ArrayList<Integer>[] g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<Integer>();
		
		for (int i = 0; i < m; i++) {
			int a = in.nextInt() - 1, b = in.nextInt() - 1;
			g[a].add(b);
			g[b].add(a);
		}
		
		UnionFindTree uft = new UnionFindTree(n);
		List<Integer> ans = new ArrayList<>();
		for (int u = n - 1; u >= 0; u--) {
			for (int v : g[u]) 
				if (v > u)
					uft.unite(u, v);
			
			if (uft.same(u, S)) {
				ans.add(u + 1);
			}
		}
		for (int idx = ans.size() - 1; idx >= 0; idx--)
			out.println(ans.get(idx));
		out.close();
	}
 
	public void run() {
		if (__FILE_DEBUG_FLAG__ == __t__) {
			try {
				is = new FileInputStream(__DEBUG_FILE_NAME__);
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
			System.out.println("FILE_INPUT!");
		} else {
			is = System.in;
		}
		in = new FastScanner(is);
		out = new PrintWriter(System.out);
 
		Thread t = new Thread(null, new Runnable() {
			
			@Override
			public void run() {
				solve();
			}
		}, "lul", 1 << 27);
		t.start();
	}
 
	public static void main(String[] args) {
		new Main().run();
	}
 
	public void mapDebug(int[][] a) {
		System.out.println("--------map display---------");
 
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				System.out.printf("%3d ", a[i][j]);
			}
			System.out.println();
		}
 
		System.out.println("----------------------------");
		System.out.println();
	}
 
	public void debug(Object... obj) {
		System.out.println(Arrays.deepToString(obj));
	}
 
	class FastScanner {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
 
		public FastScanner(InputStream stream) {
			this.stream = stream;
			//stream = new FileInputStream(new File("dec.in"));
 
		}
 
		int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}
 
		boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
 
		boolean isEndline(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
 
		int nextInt() {
			return Integer.parseInt(next());
		}
 
		int[] nextIntArray(int n) {
			int[] array = new int[n];
			for (int i = 0; i < n; i++)
				array[i] = nextInt();
 
			return array;
		}
 
		int[][] nextIntMap(int n, int m) {
			int[][] map = new int[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextIntArray(m);
			}
			return map;
		}
 
		long nextLong() {
			return Long.parseLong(next());
		}
 
		long[] nextLongArray(int n) {
			long[] array = new long[n];
			for (int i = 0; i < n; i++)
				array[i] = nextLong();
 
			return array;
		}
 
		long[][] nextLongMap(int n, int m) {
			long[][] map = new long[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextLongArray(m);
			}
			return map;
		}
 
		double nextDouble() {
			return Double.parseDouble(next());
		}
 
		double[] nextDoubleArray(int n) {
			double[] array = new double[n];
			for (int i = 0; i < n; i++)
				array[i] = nextDouble();
 
			return array;
		}
 
		double[][] nextDoubleMap(int n, int m) {
			double[][] map = new double[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextDoubleArray(m);
			}
			return map;
		}
 
		String next() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}
 
		String[] nextStringArray(int n) {
			String[] array = new String[n];
			for (int i = 0; i < n; i++)
				array[i] = next();
 
			return array;
		}
 
		String nextLine() {
			int c = read();
			while (isEndline(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndline(c));
			return res.toString();
		}
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.