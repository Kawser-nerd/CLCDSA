import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;


public class C {
	Scanner in;
	PrintWriter out;
	
	long GCD(long a, long b) {
		while (b != 0) {
			a %= b;
			long tmp = a;
			a = b;
			b = tmp;
		}
		return a;
	}
	
	void solve() {
		long AAA = -1;
		int n = in.nextInt();
		long l = in.nextLong();
		long h = in.nextLong();
		long a[] = new long[n];
		for (int i = 0; i < n; ++i) a[i] = in.nextLong();
		Arrays.sort(a);
		long gcd_all[] = new long[n];
		gcd_all[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; --i) gcd_all[i] = GCD(gcd_all[i + 1], a[i]);
		long nok = 1;
//		for (int i = 0; i < n; ++i) out.print(gcd_all[i] + " ");
//		out.println();
		for (int i = 0; i < n; ++i) {
//			out.println(nok + " " + gcd_all[i]);
			//x is divisible by gcd_all[i]
			//x divides NOK of all numbers <a[i]
			if (nok <= gcd_all[i] && gcd_all[i] % nok == 0) {
				long y = gcd_all[i] / nok;
				for (long q = 1; q * q <= y; ++q) if (y % q == 0)
					for (int u = 0; u < 2; ++u) {
						long mult;
						if (u == 0) mult = q; else mult = y / q;
						long ans = nok * mult;
						if (ans >= l && ans <= h) {
							if (AAA == -1 || AAA > ans)
								AAA = ans;
						}
					}
					
			}
			BigInteger _nok = BigInteger.valueOf(nok);
			BigInteger _a = BigInteger.valueOf(a[i]);
			BigInteger new_nok = _nok.multiply(_a.divide(_a.gcd(_nok)));
//			out.println("nn = " + new_nok);
			if (new_nok.compareTo(BigInteger.valueOf(h)) > 0) {
				nok = h + 1;
				break;
			} else
				nok = new_nok.longValue();
		}
		if (nok < h) {
			long mult = (l - 1) / nok + 1;
			long ans = mult * nok;
			if (ans >= l && ans <= h) {
				if (AAA == -1 || AAA > ans)
					AAA = ans;
			}
		}
		if (AAA == -1)
			out.println("NO");
		else
			out.println(AAA);
	}
	
	void doit() throws FileNotFoundException {
		in = new Scanner(new FileInputStream("input.txt"));
		out = new PrintWriter(new FileOutputStream("output.txt"));
		int t = in.nextInt();
		for (int i = 0; i < t; ++i) {
			System.err.println("Case #" + (i + 1));
			out.print("Case #" + (i + 1) + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws FileNotFoundException {
		new C().doit();
	}

}
