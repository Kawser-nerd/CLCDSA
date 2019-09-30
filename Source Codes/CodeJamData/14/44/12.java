package gcj.R2_2014.D;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class GCJ {

	public static void tr(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	static final long MOD = 1000000007;

	public static void main(String[] args) throws Throwable {
		long start = System.currentTimeMillis();

		String pkg = new Object(){}.getClass().getEnclosingClass().getPackage().getName().replace('.', '/');
		String dir = "src/" + pkg;

		String filename = "";

//		if (true) { filename = "sample.in"; }
		if (true) { filename = "D-small-attempt0.in"; }
//		if (true) { filename = "A-large-practice.in"; }

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

	int N, M;
	String[] ss;
	void solve(Scanner sc, PrintWriter fout) {
		M = sc.nextInt();
		N = sc.nextInt();
		ss = new String[M];
		for (int i = 0; i < M; i++) {
			String s = sc.next();
			ss[i] = s;
		}
		assign = new int[M];

		maxScore = 0;
		maxCount = 0;
		rec(0);

		maxCount %= MOD;
		fout.println(maxScore + " " + maxCount);
	}

	int maxScore;
	int maxCount;
	int[] assign;
	void rec(int d) {
		if (d == assign.length) {
//			tr(assign);
			int score = count(assign);
			if (score == maxScore) {
				++maxCount;
			} else if (score > maxScore) {
				maxScore = score;
				maxCount = 1;
			}
			return;
		}
		for (int i = 0; i < N; i++) {
			assign[d] = i;
			rec(d+1);
		}
	}

	class SetString extends HashSet<String> {

	}

	int count(int[] as) {
		SetString st[] = new SetString[N];
		for (int i = 0; i < N; i++) st[i] = new SetString();

		for (int i = 0; i < ss.length; i++) {
			String s = ss[i];
			for (int len = 0; len <= s.length(); len++) {
				st[as[i]].add(s.substring(0, len));
			}
		}
		int res = 0;
		for (int i = 0; i < N; i++) {
			res += st[i].size();
		}
		return res;
	}
}
