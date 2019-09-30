import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(System.in);
		BigInteger TWO = BigInteger.valueOf(2);
		BigInteger FOUR = BigInteger.valueOf(4);
		int cases = scan.nextInt();
		BigInteger r, t, res;
		PrintStream outfile = new PrintStream("C-large.out.txt");
		for (int c = 1; c <= cases; c++) {
			r = scan.nextBigInteger();
			t = scan.nextBigInteger();
			res = r.multiply(r).subtract(r);
			res = res.add(t.multiply(TWO));
			res = res.multiply(FOUR).add(BigInteger.ONE);
			res = bigIntSqRootFloor(res);
			res = res.subtract(r.mod(TWO).equals(BigInteger.ZERO) ? BigInteger.valueOf(3) : BigInteger.valueOf(5));
			res = res.divide(FOUR);
			res = res.subtract(r.divide(TWO)).add(BigInteger.ONE);
			outfile.println("Case #" + c + ": " + res.toString());
		}
	}

	/**
	 * Computes ceil(sqrt(x))
	 * Refernce used:
	 * http://stackoverflow.com/questions/4407839/how-can-i-find-the-square-root-of-a-java-biginteger
	 */

	public static BigInteger bigIntSqRootFloor(BigInteger x)
	        throws IllegalArgumentException {
	    if (x.compareTo(BigInteger.ZERO) < 0) {
	        throw new IllegalArgumentException("Negative argument.");
	    }
	    // square roots of 0 and 1 are trivial and
	    // y == 0 will cause a divide-by-zero exception
	    if (x == BigInteger.ZERO || x == BigInteger.ONE) {
	        return x;
	    } // end if
	    BigInteger two = BigInteger.valueOf(2L);
	    BigInteger y;
	    // starting with y = x / 2 avoids magnitude issues with x squared
	    for (y = x.divide(two);
	            y.compareTo(x.divide(y)) > 0;
	            y = ((x.divide(y)).add(y)).divide(two));
	    return y;
	} // end bigIntSqRootFloor
}
