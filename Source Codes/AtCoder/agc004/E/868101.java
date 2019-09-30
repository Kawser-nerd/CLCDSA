import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int h = nextInt();
		int w = nextInt();
		char[][] f = new char[h][];
		
		int ex = -1, ey = -1;
		
		for (int i = 0; i < h; i++) {
			f[i] = nextToken().toCharArray();
			for (int j = 0; j < w; j++) {
				if (f[i][j] == 'E') {
					ex = i;
					ey = j;
				}
			}
		}
		
		int[][] cumX = new int[h][w + 1];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cumX[i][j + 1] = cumX[i][j] + (f[i][j] == 'o' ? 1 : 0);
			}
		}
		
		int[][] cumY = new int[w][h + 1];
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				cumY[i][j + 1] = cumY[i][j] + (f[j][i] == 'o' ? 1 : 0);
			}
		}
		
		
		int segmH = h * (h + 1) / 2;
		int segmW = w * (w + 1) / 2;
		
		int[] hFrom = new int[segmH];
		int[] hTo = new int[segmH];
		int[][] hSegmId = new int[h][h];
		
		int ptr = 0;
		for (int len = 1; len <= h; len++)
			for (int i = 0; i + len <= h; i++) {
				hFrom[ptr] = i;
				hTo[ptr] = i + len - 1;
				hSegmId[i][i + len - 1] = ptr;
				ptr++;
			}
		
		int[] wFrom = new int[segmW];
		int[] wTo = new int[segmW];
		int[][] wSegmId = new int[w][w];
		
		ptr = 0;
		for (int len = 1; len <= w; len++)
			for (int i = 0; i + len <= w; i++) {
				wFrom[ptr] = i;
				wTo[ptr] = i + len - 1;
				wSegmId[i][i + len - 1] = ptr;
				ptr++;
			}
		
		int[][] dp = new int[segmH][segmW];
		for (int i = 0; i < segmH; i++) {
			
			int x1 = hFrom[i];
			int x2 = hTo[i];
			
			for (int j = 0; j < segmW; j++) {
				
				int val = 0;
				
				int y1 = wFrom[j];
				int y2 = wTo[j];
				
				
				
				int xTo = Math.min(ex + x1, x2);
				int yTo = Math.min(ey + y1, y2);
				int xFrom = Math.max(ex + (x2 - x1) - (h - 1) + x1, x1);
				int yFrom = Math.max(ey + (y2 - y1) - (w - 1) + y1, y1);
				
				// kill x1
				int bonus = 0;
				if (x1 >= xFrom && x1 <= xTo && yFrom <= yTo) {
					bonus = cumX[x1][yTo + 1] - cumX[x1][yFrom];
				}
				val = Math.max(val, bonus + (x1 == x2 ? 0 : dp[hSegmId[x1 + 1][x2]][j]));
				
				// kill y1
				bonus = 0;
				if (y1 >= yFrom && y1 <= yTo && xFrom <= xTo) {
					bonus = cumY[y1][xTo + 1] - cumY[y1][xFrom];
				}
				val = Math.max(val, bonus + (y1 == y2 ? 0 : dp[i][wSegmId[y1 + 1][y2]]));
				
				// kill x2
				bonus = 0;
				if (x2 >= xFrom && x2 <= xTo && yFrom <= yTo) {
					bonus = cumX[x2][yTo + 1] - cumX[x2][yFrom];
				}
				val = Math.max(val, bonus + (x1 == x2 ? 0 : dp[hSegmId[x1][x2 - 1]][j]));
				
				// kill y2
				bonus = 0;
				if (y2 >= yFrom && y2 <= yTo && xFrom <= xTo) {
					bonus = cumY[y2][xTo + 1] - cumY[y2][xFrom];
				}
				val = Math.max(val, bonus + (y1 == y2 ? 0 : dp[i][wSegmId[y1][y2 - 1]]));
				
//				System.err.println(x1 + " " + y1 + " " + x2 + " " + y2 + " " + val);
				dp[i][j] = val;
			}
		}
		
		out.println(dp[segmH - 1][segmW - 1]);
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}