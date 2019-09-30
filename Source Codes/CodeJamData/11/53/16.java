import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	long M = 1000003;
	
	String DIR = "|-/\\";
	int[] dx = {-1, 1, 0, 0, -1, 1, -1, 1}, dy = {0, 0, -1, 1, 1, -1, -1, 1};
	
	void solve() {
		int R = sc.nextInt(), C = sc.nextInt();
		char[][] cs = new char[R][C];
		for (int i = 0; i < R; i++) {
			cs[i] = sc.next().toCharArray();
		}
		int res = 0;
		for (int i = 0; i < 1 << (R * C); i++) {
			int[][] in = new int[R][C];
			for (int x = 0; x < R; x++) {
				for (int y = 0; y < C; y++) {
					int d = DIR.indexOf(cs[x][y]);
					int k = (i >> (x * C + y) & 1);
					int x2 = (x + dx[d * 2 + k] + R) % R, y2 = (y + dy[d * 2 + k] + C) % C;
					in[x2][y2]++;
				}
			}
			boolean ok = true;
			for (int x = 0; x < R; x++) {
				for (int y = 0; y < C; y++) {
					if (in[x][y] != 1) {
						ok = false;
					}
				}
			}
			if (ok) res++;
		}
		System.out.println(res % M);
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (C.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new C().run();
	}
}
