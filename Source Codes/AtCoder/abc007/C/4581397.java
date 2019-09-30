import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

	public static int[] dirX = {0, 1, 0, -1};
	public static int[] dirY = {1, 0, -1, 0};

	public static char[][] map;
	public static int[][] dist;

	public static int tempX;
	public static int tempY;

	public static void main(String[] args) {
		FastScanner fs = new FastScanner(System.in);

		int R = fs.nextInt();
		int C = fs.nextInt();

		int sy = fs.nextInt() - 1;
		int sx = fs.nextInt() - 1;
		int gy = fs.nextInt() - 1;
		int gx = fs.nextInt() - 1;

		map = new char[R][];
		dist = new int[R][C];

		for (int i = 0; i < R; i++) {
			map[i] = fs.nextLine().toCharArray();
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				dist[i][j] = -1;
			}
		}

		Deque<Point> deq = new ArrayDeque<Point>();

		Point Start = new Point(sx, sy);
		Point Goal = new Point(gx, gy);

		deq.offerLast(Start);
		dist[sy][sx] = 0;

		while (deq.size() > 0) {
			Point point = deq.pollFirst();
			if (point.y == gy && point.x == gx) break;

			for (int i = 0; i < 4; i++) {
				tempY = point.y + dirY[i];
				tempX = point.x + dirX[i];

				if (tempY < 0 || tempY >= R || tempX < 0 || tempX >= C) {
					continue;
				}

				if ((map[tempY][tempX] == '#') || (dist[tempY][tempX] != -1)) {
					continue;
				}

				deq.offerLast(new Point(tempX, tempY));
				dist[tempY][tempX] = dist[point.y][point.x]+ 1;
			}
		}


		System.out.println(dist[gy][gx]);
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

class Point {
	public int x;
	public int y;

	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
}