import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

	public static int[] dirX = {-1, 0, 1, 0};
	public static int[] dirY = {0, 1, 0, -1};

	public static void main(String[] args) {
		FastScanner fs = new FastScanner(System.in);

		char[][] map = new char[10][];
		Set<Point> wc = null;
		int count = 0;

		for (int i = 0; i < 10; i++) {
			map[i] = fs.nextLine().toCharArray();
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (map[i][j] == 'o') count++;
			}
		}



		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				if (map[y][x] == 'x') {
					wc = new HashSet<Point>();
					map[y][x] = 'o';
					dfs(x, y, map, wc);
					if (wc.size() - 1 == count) {
						System.out.println("YES");
						return;
					}
					map[y][x] = 'x';
				} else {
					continue;
				}

			}
		}

		System.out.println("NO");

	}


	public static void dfs(int x, int y, char[][] map, Set<Point> wc) {
		if (map[y][x] == 'x') return;
		Point present = new Point(x, y);
		if (wc.contains(present)) return;
		wc.add(present);


		for (int i = 0; i < 4; i++) {
			if (x + dirX[i] < 0 || x + dirX[i] >=10 || y + dirY[i] < 0 || y + dirY[i] >= 10) continue;
			dfs(x + dirX[i], y + dirY[i], map, wc);
		}
	}




	static class FastScanner {

		private BufferedReader reader = null;
	    private StringTokenizer tokenizer = null;

	    public FastScanner(InputStream in) {
	        reader = new BufferedReader(new InputStreamReader(in));
	        tokenizer = null;
	    }

	    public String next() {
	        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
	            try {
	                tokenizer = new StringTokenizer(reader.readLine());
	            } catch (IOException e) {
	                throw new RuntimeException(e);
	            }
	        }
	        return tokenizer.nextToken();
	    }

	    public String nextLine() {
	        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
	            try {
	                return reader.readLine();
	            } catch (IOException e) {
	                throw new RuntimeException(e);
	            }
	        }

	        return tokenizer.nextToken("\n");
	    }

	    public long nextLong() {
	        return Long.parseLong(next());
	    }

	    public int nextInt() {
	        return Integer.parseInt(next());
	    }

	    public double nextDouble() {
	         return Double.parseDouble(next());
	     }

	    public int[] nextIntArray(int n) {
	        int[] a = new int[n];
	        for (int i = 0; i < n; i++)
	            a[i] = nextInt();
	        return a;
	    }

	    public long[] nextLongArray(int n) {
	        long[] a = new long[n];
	        for (int i = 0; i < n; i++)
	            a[i] = nextLong();
	        return a;
	    }

	}


}