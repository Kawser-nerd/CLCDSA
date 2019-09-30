package gcj2017.a1.b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class GCJ {

	public static void tr(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	public static void main(String[] args) throws Throwable {
		long start = System.currentTimeMillis();

		String pkg = new Object(){}.getClass().getEnclosingClass().getPackage().getName().replace('.', '/');
		String dir = "src/" + pkg;

		String filename = "";

//		if (true) { filename = "sample.in"; }
//		if (true) { filename = "B-small-attempt1.in"; }
		if (true) { filename = "B-large.in"; }

		Scanner sc = null;
		try {
			sc = new Scanner(new File(dir + "/" + filename));
		} catch (FileNotFoundException e) {
			tr(e.getMessage());
			return;
		}
		PrintWriter fout = new PrintWriter(new File(dir + "/" + filename + ".res"));

		GCJ obj = new GCJ();
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			fout.write(String.format("Case #%d: ", (t + 1)));
			obj.solve(sc, fout);
			fout.flush();
		}
		fout.flush();
		fout.close();
		long end = System.currentTimeMillis();
		tr((end - start) + "ms");
	}

	boolean can(long r, long q, long sz) {
		return r * 90 * sz <= q * 100 && q * 100 <= r * sz * 110;
	}
	void solve(Scanner sc, PrintWriter out) {
		int N = sc.nextInt();
		int P = sc.nextInt();
		long[] R = new long[N];
		for (int i = 0; i < N; i++) R[i] = sc.nextInt();
		long[][] Q = new long[N][P];
		for (int i = 0; i < N; i++) for (int j = 0; j < P; j++)
			Q[i][j] = sc.nextLong();
		for (int i = 0; i < N; i++)
			Arrays.sort(Q[i]);

		int ans = 0;
		int[] pt = new int[N];
		
		outer:
		for (long sz = 1; ; ) {
			for (int i = 0; i < N; i++) {
				while (pt[i] < P && R[i] * 90 * sz > Q[i][pt[i]] * 100)
					pt[i]++;
			}
			for (int i = 0; i < N; i++) 
				if (pt[i] >= P) 
					break outer;

			int ok = 0;
			for (int i = 0; i < N; i++) {
				if (pt[i] < P && can(R[i], Q[i][pt[i]], sz)) {
					ok++;
				} else {
					break;
				}
			}
			if (ok == N) {
				ans++;
				for (int i = 0; i < N; i++) pt[i]++;
			} else {
				sz++;
			}
		}
		out.println(ans);
	}
	
}
