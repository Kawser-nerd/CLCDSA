import java.util.*;
import java.math.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		BigInteger A = new BigInteger(a);
		BigInteger B = A.multiply(A);
		BigInteger C = A.add(BigInteger.ONE);
		BigInteger D = C.multiply(C);

		int x = -(B.toString().length() - 1);
		if(x % 2 != 0) {
			++x;
		}
		for(int t = x; ; t += 2) {
			BigInteger tB, tD;
			BigInteger div = BigInteger.TEN.pow(-t);
			BigInteger add = div.subtract(BigInteger.ONE);
			tB = B.add(add).divide(div);
			tD = D.add(add).divide(div);
			// System.out.printf("%s %s\n", tB.toString(), tD.toString());
			if(tB.compareTo(tD) < 0) {
				System.out.println(tB.toString());
				return;
			}
		}
	}
}