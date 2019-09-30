package codejam15;

import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class c {
	private static final int[][] mul = { { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 }, { 4, 3, -2, -1 } };

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader(new File("c.in")));
		PrintWriter pw = new PrintWriter("c.out");

		int c = 0;
		int tc = sc.nextInt();
		for (int t = 1; t <= tc; t++) {

			int l = sc.nextInt();
			long x = sc.nextLong();
			sc.nextLine();
			String s = sc.nextLine();

			boolean ans = find(l, x, cnv(s));
			if (ans)
				c++;
			pw.printf("Case #%d: %s\n", t, ans ? "YES" : "NO");
		}
		System.out.println(c);
		sc.close();
		pw.close();
	}

	private static int[] cnv(String s) {
		int r[] = new int[s.length()];
		for (int i = 0; i < s.length(); i++)
			r[i] = s.charAt(i) - 'i' + 2;
		return r;
	}

	private static boolean find(int l, long x, int[] s) {
		int p = 1;
		for (int z : s) {
			p = mul(p, z);
		}
		p = pow(p, x);
		if (p != -1)
			return false;
		long mini = findz(s, 2);
		if (mini == 0)
			return false;
		int r[] = new int[s.length];
		for (int i = 0; i < s.length; i++)
			r[s.length - 1 - i] = s[i];
		long mink = findz(r, 4);
		if (mink == 0)
			return false;
		return mini + mink < x * l;
	}

	private static int pow(int p, long x) {
		if (x == 1) {
			return p;
		}
		int q = pow(p, x / 2);
		q = mul(q, q);
		if (x % 2 == 1)
			q = mul(q, p);
		return q;
	}

	private static long findz(int[] s, int c) {
		int m[] = new int[s.length];
		m[0] = s[0];
		if (m[0] == c)
			return 1;
		for (int i = 1; i < s.length; i++) {
			m[i] = c == 2 ? mul(m[i - 1], s[i]) : mul(s[i], m[i - 1]);
			if (m[i] == c) {
				return i + 1;
			}
		}
		int r = m[m.length - 1];
		for (int q = 0; q < 3; q++)
			for (int i = 0; i < m.length; i++) {
				m[i] = c == 2 ? mul(r, m[i]) : mul(m[i], r);
				if (m[i] == c) {
					return (q + 1) * s.length + i + 1;
				}
			}
		return 0;
	}

	private static int mul(int i, int j) {
		return (int) Math.signum(i) * (int) Math.signum(j) * mul[Math.abs(i) - 1][Math.abs(j) - 1];
	}
}
