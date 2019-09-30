import java.math.*;
import java.io.*;
import java.util.*;

public class A {
	
	static Scanner in;

	static BigInteger check(BigInteger n, BigInteger r) {
		return n.multiply(r.add(r).subtract(BigInteger.valueOf(3))).add(n.multiply(n.add(BigInteger.ONE).multiply(BigInteger.valueOf(2))));		
	}

	static BigInteger solve() {
		BigInteger r, t;
		r = in.nextBigInteger();
		t = in.nextBigInteger();
		BigInteger L = BigInteger.ONE;
		BigInteger R = BigInteger.valueOf(10).pow(100);
		while (L.compareTo(R) < 0) {
			BigInteger m = L.add(R.add(BigInteger.ONE)).divide(BigInteger.valueOf(2));
			if (check(m, r).compareTo(t) <= 0)
				L = m;
			else
				R = m.subtract(BigInteger.ONE);					
		}
		return L;
	}

	public static void main(String[] args) {
		in = new Scanner(System.in);
		int tt;
		tt = in.nextInt();
		for(int i = 0; i < tt; i++) {
			System.out.println("Case #" + (i+1) + ": " + solve());
		}
	}
}                                