import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		FastScanner fs = new FastScanner(System.in);

		char[][] board = new char[8][8];
		for (int i = 0; i < 8; i++) {
			String temp = fs.nextLine();
			for (int j =0; j < 8; j++) {
				board[i][j] = temp.charAt(j);
			}
		}

		// ??
		if (dfs(0, 8, board)) {
			for (int i = 0; i < 8; i++) {
				for (int j =0; j < 8; j++) {
					System.out.print(board[i][j]);
				}
				System.out.println();
			}
		} else {
			System.out.println("No Answer");
		}

	}

	// ??????????true????
	static boolean dfs(int pos, int koma, char[][] board) {
		// ????????true????
		if (koma == 0) return true;
		// ???????????false????
		if (pos == 64) return false;

		// pos??x, y????
		int y = pos / 8;
		int x = pos % 8;

		// Q????????????????dfs?????
		if (board[y][x] == 'Q') {
			if (isPuttable(y, x, board) ) {
				if (dfs(pos+1, koma-1, board)) return true;
			}
			// ??????????false????????????
		} else {
			// ??????????dfs?????
			if (isPuttable(y, x, board)) {
				board[y][x] = 'Q';
				if (dfs(pos+1, koma -1, board)) return true;
				// ?????????
				board[y][x] = '.';
			}
			// ????????pos??????
			if (dfs(pos+1, koma, board)) return true;
		}

		return false;
	}

	static boolean isPuttable(int y, int x, char[][] board) {
		// 8?????
		for (int vy = -1; vy <= 1; vy++) {
			for (int vx = -1; vx <= 1; vx++) {
				if (vy == 0 && vx ==0 ) continue;
				int ty = y, tx = x;
				while(true) {
					// ???????false????
					// ?????????
					ty += vy; tx += vx;
					if (!ok(ty, tx)) break;
					if (board[ty][tx] == 'Q') return false;
				}
			}
		}
		return true;
	}

	// ??????
	static boolean ok(int y, int x) {
		return y >=0 && x >= 0 && y < 8 && x < 8;
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