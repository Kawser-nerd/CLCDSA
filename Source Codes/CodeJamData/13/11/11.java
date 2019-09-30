import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws Exception {
		String path = "D:\\A-large";
		Scanner sc = new Scanner(new File(path + ".in"));
		PrintWriter pw = new PrintWriter(path + ".out");
		int testCases = sc.nextInt();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			long r = sc.nextLong();
			long t = sc.nextLong();

			long lo = 0;
			long hi = (long) 1e17;
			while (hi - lo > 1) {
				long n = (lo + hi) / 2;

				BigInteger x = BigInteger.valueOf(n).multiply(BigInteger.valueOf(2 * r + 1 + 2 * (n - 1)));

				if (x.compareTo(BigInteger.valueOf(t)) <= 0) {
					lo = n;
				} else {
					hi = n;
				}
			}

			long res = lo;

			pw.println("Case #" + testCase + ": " + res);
			pw.flush();
		}
		pw.close();
	}
}
