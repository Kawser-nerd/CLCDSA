import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class A_Round1A {

	static BigInteger sumEven(BigInteger v) {
		// 2+4+...+v
		v = v.divide(BigInteger.valueOf(2));
		return v.multiply(v.add(BigInteger.ONE));
	}

	static BigInteger sumOdd(BigInteger v) {
		// 1+3+4+...+v
		v = v.add(BigInteger.ONE).divide(BigInteger.valueOf(2));
		return v.multiply(v);
	}

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("A-large.in"));
		PrintWriter pw = new PrintWriter(new File("A-large3.out"));
		int n;
		n = sc.nextInt();
		for (int tt = 0; tt < n; ++tt) {
			pw.print("Case #" + (tt + 1 ) + ": ");
			BigInteger r, t;
			r = sc.nextBigInteger();
			t = sc.nextBigInteger();

			BigInteger low = BigInteger.ZERO, hi = BigInteger.valueOf(80710678000000l);
			while (low.compareTo(hi) < 0) {
				BigInteger mid = low.add((hi.subtract(low).add(BigInteger.ONE).divide(BigInteger.valueOf(2))));
				BigInteger sum = BigInteger.ZERO;
				if (r.and(BigInteger.ONE).compareTo(BigInteger.ONE) < 0)
					sum = sumEven(r.add(mid.multiply(BigInteger.valueOf(2)))).subtract(sumEven(r.subtract(BigInteger.valueOf(2))));
				else
					sum = sumOdd(r.add(mid.multiply(BigInteger.valueOf(2)))).subtract(sumOdd(r.subtract(BigInteger.valueOf(2))));
//				cout << mid << " " << sum ;
				sum = (sum.multiply(BigInteger.valueOf(2)).add(mid.add(BigInteger.ONE)));
//				cout << " " << sum << endl;
				if (sum.compareTo(t) > 0)
					hi = mid.subtract(BigInteger.ONE);
				else
					low = mid;
			}
//			while(1) {
//				ll nv = 2 * r + 1;
//				cout << cnt << " " << nv << endl;
//				if (t < nv)
//					break;
//				cnt++;
//				t -= nv;
//						r += 2;
//			}
			pw.println(low.add(BigInteger.ONE));
		}
		pw.close();
	}
}
