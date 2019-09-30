import java.math.BigInteger;
import java.util.*;

public class Main {
	Scanner in = new Scanner(System.in);
	BigInteger[] data;

	BigInteger solve() {
		int N = in.nextInt();
		for (int i = 0; i < N; i++)
			data[i] = in.nextBigInteger();

		Arrays.sort(data, 0, N);
		BigInteger g = data[1].subtract(data[0]);
		for (int i = 2; i < N; i++)
			g = g.gcd(data[i].subtract(data[i - 1]));

		return g.subtract(data[0].remainder(g)).remainder(g);
	}

	void cases() {
		data = new BigInteger[1000];
		int T = in.nextInt();
		for (int c = 1; c <= T; c++)
			System.out.println("Case #" + c + ": " + solve());
	}

	public static void main(String[] args) throws Exception {
		(new Main()).cases();
	}
}