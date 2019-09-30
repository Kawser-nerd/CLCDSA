import java.io.*;
import java.util.*;
import java.math.*;

class Food implements Comparable<Food> {
	public BigInteger P;
	public BigInteger S;

	public int compareTo(Food other) {
		if(S.compareTo(other.S) == 0) return -P.compareTo(other.P); 
		else return S.compareTo(other.S);
	}
};

public class Main {
	static Food food[];
	static Food f[];
	static BigInteger M, F;
	static int N, NN;

	public static BigInteger calc(BigInteger M, BigInteger A, BigInteger B, BigInteger C, BigInteger U) {
		BigInteger k = M.divide(U.multiply(B).add(A));
		BigInteger res = BigInteger.ZERO;

		for(int d = -100; d <= 100; d++) {
			BigInteger K = k.add(new BigInteger(String.valueOf(d)));
			if(M.subtract(A.multiply(K)).compareTo(BigInteger.ZERO) < 0) continue;
			BigInteger v = M.subtract(A.multiply(K)).divide(B).add(C.multiply(K));
			BigInteger v2 = U.multiply(K).add(C.multiply(K));
			v = v.min(v2);
			res = res.max(v);
		}

		BigInteger K = M.divide(A);
		BigInteger v = M.subtract(A.multiply(K)).divide(B).add(C.multiply(K));
		BigInteger v2 = U.multiply(K).add(C.multiply(K));
		v = v.min(v2);
		res = res.max(v);

		return res;
	}

	public static void main(String args[]) throws IOException {
		Scanner cin = new Scanner(System.in);
		int ntest = cin.nextInt();
		for(int test = 1; test <= ntest; test++) {
			M = cin.nextBigInteger();
			F = cin.nextBigInteger();
			N = cin.nextInt();
			food = new Food[N];
			for(int i=0; i<N; i++) {
				food[i] = new Food();
				food[i].P = cin.nextBigInteger();
				food[i].S = cin.nextBigInteger();
			}
			Arrays.sort(food);
			NN = 0;

			f = new Food[N];

			for(int i=0; i<N; i++) {
				while(NN != 0 && f[NN-1].P.compareTo(food[i].P) >= 0) NN--;
				f[NN++] = food[i];
			}

			BigInteger total = BigInteger.ZERO;
			BigInteger many = BigInteger.ZERO;
			BigInteger ans = BigInteger.ZERO;

			for(int i=0; i<NN; i++) {
				BigInteger prize = f[i].P;
				BigInteger last = (i>0 ? f[i].S.subtract(f[i-1].S) : f[i].S.add(BigInteger.ONE));

				BigInteger res = calc(M, total.add(F), prize, many, last);

				ans = ans.max(res);

				total = total.add(last.multiply(f[i].P));
				many = many.add(last);
			}

			System.out.println("Case #" + test + ": " + ans.toString());
		}
		
	}
}
