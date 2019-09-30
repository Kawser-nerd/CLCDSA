import java.util.*;
import java.math.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		BigInteger A = new BigInteger(a);
		BigInteger L = A.multiply(A);
		BigInteger C = A.add(BigInteger.ONE);
		BigInteger U = C.multiply(C).subtract(BigInteger.ONE);
		BigInteger DIV = BigInteger.TEN.pow(2);
		BigInteger ADD = BigInteger.valueOf(99L);

		for(;;) {
			BigInteger tL = L.add(ADD).divide(DIV);
			BigInteger tU = U.divide(DIV);

			if(tL.compareTo(tU) <= 0) {
				L = tL;
				U = tU;
			} else {
				break;
			}
		}
		System.out.println(L.toString());
	}
}