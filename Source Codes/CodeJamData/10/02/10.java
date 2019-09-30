import java.io.*;
import java.util.*;
import java.math.*;
public class qualB {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new InputStreamReader(System.in));
		int C = sc.nextInt();
		for (int c=1; c<=C; c++) {
			System.out.printf("Case #%d: ",c);
			int N = sc.nextInt();
			BigInteger firstnum = new BigInteger(sc.next());
			BigInteger gcd = null;
			for (int i=1; i<N; i++) {
				BigInteger next = new BigInteger(sc.next());
				BigInteger diff = next.subtract(firstnum).abs();
				if (gcd==null) gcd = diff;
				else gcd = gcd.gcd(diff);
			}
			BigInteger numtogo = firstnum.mod(gcd);
			if (numtogo.equals(BigInteger.ZERO)) System.out.println(0);
			else System.out.println(gcd.subtract(numtogo));
		}
	}
}