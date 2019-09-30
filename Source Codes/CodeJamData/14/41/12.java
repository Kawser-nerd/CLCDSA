package gcj.R2_2014.A;

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
//		if (true) { filename = "A-small-attempt1.in"; }
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
		int TNO = sc.nextInt();
		for (int tno = 0; tno < TNO; tno++) {
			fout.write(String.format("Case #%d: ", (tno + 1)));
			obj.solve(sc, fout);
			fout.flush();
		}
		fout.flush();
		fout.close();

		long end = System.currentTimeMillis();
		tr((end - start) + "ms");
	}

	void solve(Scanner sc, PrintWriter fout) {
		int n = sc.nextInt();
		int S = sc.nextInt();
		int[] a = new int[n];
		boolean[] done = new boolean[n];
		for (int i = 0; i < n; i++) a[i] = sc.nextInt();
		Arrays.sort(a);

		int res = 0;

		for (int k = n - 1; k >= 0; k--) if (!done[k]) {
			int pi = -1;
			for (int p = k - 1; p >= 0; p--) if (!done[p] && a[p] + a[k] <= S) {
				pi = p;
				break;
			}
			if (pi != -1) {
				done[pi] = true;
			}
			done[k] = true;
			res++;
		}


		fout.println(res);
	}
}
