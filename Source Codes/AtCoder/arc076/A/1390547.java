import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Main main = new Main();
		main.solveC();
	}

	private void solveC() {
		Scanner sc = new Scanner(System.in);

		final long MOD = 1000000007;
		long N = sc.nextInt();
		long M = sc.nextInt();

		if (N - M > 1 || M - N > 1) {
			System.out.println(0);
		} else {
			if (N == M) {
				System.out.println(2 * perm(N, MOD) * perm(N, MOD) % MOD);
			} else {
				System.out.println(perm(N, MOD) * perm(M, MOD) % MOD);
			}
		}
	}

	private long perm(long N, long mod) {
		long mul = 1L;
		for (; N > 0; N--) {
			mul = (mul * N) % mod;
		}
		return mul;
	}
}