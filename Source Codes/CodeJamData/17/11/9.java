package gcj2017.a1.a;

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
//		if (true) { filename = "A-small-attempt0.in"; }
		if (true) { filename = "A-large.in"; }

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
			fout.write(String.format("Case #%d:\n", (t + 1)));
			obj.solve(sc, fout);
			fout.flush();
		}
		fout.flush();
		fout.close();
		long end = System.currentTimeMillis();
		tr((end - start) + "ms");
	}
	
	void solve(Scanner sc, PrintWriter out) {
		int R = sc.nextInt();
		int C = sc.nextInt();
		tr(R, C);
		char[][] s = new char[R][];
		for (int r = 0; r < R; r++) {
			s[r] = sc.next().toCharArray();
		}
		for (int r = 0; r < R; r++) {
			char cur = '?';
			for (int c = 0; c < C; c++) {
				if (s[r][c] == '?') {
					s[r][c] = cur;
				} else {
					cur = s[r][c];
				}
			}
			for (int c = C - 1; c >= 0; c--) {
				if (s[r][c] == '?') {
					s[r][c] = cur;
				} else {
					cur = s[r][c];
				}
			}
		}
		
		for (int c = 0; c < C; c++) {
			char cur = '?';
			for (int r = 0; r < R; r++) {
				if (s[r][c] == '?') {
					s[r][c] = cur;
				} else {
					cur = s[r][c];
				}
			}
			for (int r = R - 1; r >= 0; r--) {
				if (s[r][c] == '?') {
					s[r][c] = cur;
				} else {
					cur = s[r][c];
				}
			}
		}
		
		for (int r = 0; r < R; r++)
			out.println(new String(s[r]));
	}
	
}
