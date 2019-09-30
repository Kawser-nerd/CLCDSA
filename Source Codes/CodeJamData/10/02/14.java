import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class B {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(new File("b.in"));
		PrintWriter cout = new PrintWriter("b.out");
		
		int tests = cin.nextInt();
		
		for (int test = 1; test <= tests; test++)
		{
			int N;
			N = cin.nextInt();
			BigInteger x = cin.nextBigInteger();
			BigInteger r = BigInteger.ZERO;
			for (int i = 0; i < N - 1; i++)
			{
				BigInteger y = cin.nextBigInteger();
				BigInteger z = x.subtract(y).abs();
				r = r.gcd(z);
			}
			x = x.mod(r);
			if (x.compareTo(BigInteger.ZERO) > 0) x = r.subtract(x);
			r = x;
			cout.println("Case #" + test + ": " + r);
		}
		
		cout.close();
	}

}
