import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class D {
	
	static final int INF = 1 << 28, MAX = 4;
	static final double EPS = 1E-9;
	
	static int R, C;
	static boolean[][] b = new boolean[MAX][MAX];
	static boolean[][][] seen = new boolean[1<<16][MAX][MAX];
	static boolean[][][] memo = new boolean[1<<16][MAX][MAX];
	static boolean go(int mask, int r, int c) {
		if (seen[mask][r][c])
			return memo[mask][r][c];
		boolean[][] can = new boolean[R][C];
		int i, j, rr, cc;
		for (i = 0; i < R; i++)
			for (j = 0; j < C; j++)
				can[i][j] = b[i][j] && (mask & (1 << pos(i,j))) == 0;
		seen[mask][r][c] = true;
		boolean win = false;
		for (int dr = -1; dr <= 1; dr++)
			for (int dc = -1; dc <= 1; dc++) {
				rr = r + dr;
				cc = c + dc;
				if (rr >= 0 && cc >= 0 && rr < R && cc < C && can[rr][cc])
					win |= !go(mask | (1<<pos(rr,cc)), rr, cc);
			}
		return memo[mask][r][c] = win;
	}
	static int pos(int r, int c) {
		return r*C + c;
	}
	
	static void solve() {
		int i, j, k;
		Scanner scan = new Scanner(in);
		int T = scan.nextInt();
		String s;
		int kr, kc;
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");
			for (i = 0; i < 1<<16; i++)
				for (j = 0; j < MAX; j++)
					Arrays.fill(seen[i][j], false);
			R = scan.nextInt();
			C = scan.nextInt();
			kr = kc = -1;
			for (i = 0; i < R; i++) {
				s = scan.next();
				for (j = 0; j < C; j++) {
					b[i][j] = s.charAt(j) != '#';
					if (s.charAt(j) == 'K') {
						kr = i;
						kc = j;
					}
				}
			}
			out.println(go(1<<pos(kr, kc), kr, kc)? "A" : "B");
		}
	}
	
	static String read() {
		try { return in.readLine(); } catch (IOException e) { return null; }
	}
	public static void main(String[] args) throws IOException {
		/*in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new BufferedOutputStream(System.out));*/
		String file = "D-small";
		in = new BufferedReader( new FileReader(file + ".in") );
		out = new PrintWriter( new FileOutputStream(file + "_" + System.currentTimeMillis() + ".out") );
		solve(); out.flush();
	}
	static BufferedReader in; static PrintWriter out;
}
