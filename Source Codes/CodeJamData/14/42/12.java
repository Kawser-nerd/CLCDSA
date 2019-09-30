package gcj.R2_2014.B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
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
		int N = sc.nextInt();
		int[] a = new int[N];

		for (int i = 0; i < N; i++) a[i] = sc.nextInt();
		a = normalize(a);

		int[] pos = new int[N];
		for (int i = 0; i < N; i++) pos[a[i]] = i;

//		tr(a);
//		tr(pos);

		int res = 0;
		for (int i = 0; i < N; i++) {
			int left = 0, right = 0;
			for (int j = pos[i] - 1; j >= 0; j--) if (a[j] > i) left++;
			for (int j = pos[i] + 1; j < N; j++) if (a[j] > i) right++;
			int cur = Math.min(left, right);
//			tr(i, cur);
			res += cur;
		}

		fout.println(res);
	}

	int[] normalize(int[] v) {
		int[] res = new int[v.length];
		int[][] t = new int[v.length][2];
		for (int i = 0; i < v.length; i++) {
			t[i][0] = v[i];
			t[i][1] = i;
		}
		Arrays.sort(t, 0, t.length, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				if (a[0] != b[0]) return a[0] < b[0] ? -1 : 1;
				return 0;
			}
		});

		int r = 0;
		for (int i = 0; i < v.length; i++) {
			r += (i > 0 && t[i - 1][0] != t[i][0]) ? 1 : 0;
			res[(int)t[i][1]] = r;
		}
		return res;
	}
}
