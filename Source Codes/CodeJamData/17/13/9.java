package gcj2017.a1.c;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class GCJsmall {

	public static void tr(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	public static void main(String[] args) throws Throwable {
		long start = System.currentTimeMillis();

		String pkg = new Object(){}.getClass().getEnclosingClass().getPackage().getName().replace('.', '/');
		String dir = "src/" + pkg;

		String filename = "";

//		if (true) { filename = "sample.in"; }
		if (true) { filename = "C-small-attempt0.in"; }
//		if (true) { filename = "C-large.in"; }

		Scanner sc = null;
		try {
			sc = new Scanner(new File(dir + "/" + filename));
		} catch (FileNotFoundException e) {
			tr(e.getMessage());
			return;
		}
		PrintWriter fout = new PrintWriter(new File(dir + "/" + filename + ".res"));

		GCJsmall obj = new GCJsmall();
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
	
	class Sim {
		final long initial_Hd;
		long Hd;
		long Ad;
		long Hk;
		long Ak;
		long B;
		long D;
		public Sim(int hd, int ad, int hk, int ak, int b, int d) {
			initial_Hd = hd;
			Hd = hd;
			Ad = ad;
			Hk = hk;
			Ak = ak;
			B = b;
			D = d;
		}
		int run(int b, int d) {
			int turn = 0;
			long pb = -1;
			long pd = -1;
			long pHk = -1;
			long pHd = -1;
			for (; pb != b || pd != d || pHk != Hk || pHd != Hd; ) {
				pb = b;
				pd = d;
				pHk = Hk;
				pHd = Hd;
				++turn;
				if (d > 0) {
					if (Ak - D >= Hd) {
						Hd = initial_Hd;
					} else {
						d--;
						Ak -= D;
						if (Ak < 0) Ak = 0;
					}
				} else if (b > 0) {
					if (Ak >= Hd) {
						Hd = initial_Hd;
					} else {
						b--;
						Ad += B;
					}
				} else {
					if (Hk <= Ad) {
						Hk -= Ad;
					} else if (Ak >= Hd) {
						Hd = initial_Hd;
					} else {
						Hk -= Ad;
					}
				}
				
				
				if (Hk > 0) {
					Hd -= Ak;
				} else {
					return turn;
				}
				if (Hd <= 0) {
					return INF;
				}
			}
			return INF;
		}
	}
	
	final int INF = 1001001001;
	void solve(Scanner sc, PrintWriter out) {
		int Hd = sc.nextInt();
		int Ad = sc.nextInt();
		int Hk = sc.nextInt();
		int Ak = sc.nextInt();
		int B = sc.nextInt();
		int D = sc.nextInt();
		
		
		int ans = INF;
		for (int b = 0; b <= 100; b++) {
			for (int d = 0; d <= 100; d++) {
				Sim sim = new Sim(Hd, Ad, Hk, Ak, B, D);
				int here = sim.run(b, d);
				tr(b, d);
				if (ans > here) {
					ans = here;
				}
			}
		}
		
		if (ans == INF)
			out.println("IMPOSSIBLE");
		else
			out.println(ans);
	}
	
}
