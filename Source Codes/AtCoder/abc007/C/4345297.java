import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in Actual solution is at the top
 */

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}

	static class Task {
		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int R  = in.nextInt();
			int C  = in.nextInt();
			int sy = in.nextInt()-1;
			int sx = in.nextInt()-1;
			int gy = in.nextInt()-1;
			int gx = in.nextInt()-1;
			
			char[][] array = new char[R][C];
			for(int i = 0; i < R; i++) {
				String tmp = in.next();
				for(int j = 0; j < C; j++) {
					array[i][j] = tmp.charAt(j);
				}
			}

			Queue<Integer> y = new ArrayDeque<Integer>();
			Queue<Integer> x = new ArrayDeque<Integer>();
			y.add(sy);
			x.add(sx);
			array[sy][sx] = ' ';

			int[] vx = {0, 1, 0, -1};
			int[] vy = {1, 0, -1, 0};
			
			int[][] ans = new int[R][C];

			while(!x.isEmpty()) {
				int cy = y.poll();
				int cx = x.poll();
				for(int i = 0; i < 4; i++) {
					int ny = cy + vy[i];
					int nx = cx + vx[i];
					if(array[ny][nx] == '.') {
						y.add(ny);
						x.add(nx);
						ans[ny][nx] = ans[cy][cx] + 1;
						array[ny][nx] = ' ';
						if(ny == gy && nx == gx) {
							out.println(ans[gy][gx]);
						}
					}
				}
			}
		}
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}
}