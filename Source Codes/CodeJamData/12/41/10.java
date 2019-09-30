import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	int N;
	int[] d, len;
	
	void read() {
		N = sc.nextInt();
		d = new int[N + 1];
		len = new int[N + 1];
		for (int i = 0; i < N; i++) {
			d[i] = sc.nextInt();
			len[i] = sc.nextInt();
		}
		d[N] = sc.nextInt();
	}
	
	void solve() {
		int[] can = new int[N + 1];
		fill(can, -1);
		can[0] = d[0];
		boolean end = false;
		while (!end) {
			end = true;
			for (int i = 0; i < N; i++) if (can[i] > 0) {
				for (int j = 0; j <= N; j++) if (abs(d[i] - d[j]) <= can[i]) {
					int x = min(abs(d[i] - d[j]), len[j]);
					if (can[j] < x) {
						can[j] = x;
						end = false;
					}
				}
			}
		}
		System.out.println(can[N] >= 0 ? "YES" : "NO");
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
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
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (A.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new A().run();
	}
}
