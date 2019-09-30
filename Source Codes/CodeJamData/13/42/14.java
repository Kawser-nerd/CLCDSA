import java.util.Scanner;

public class B {

	static Scanner sc = new Scanner(System.in);
	static int N;
	static long P;

	public static void main(String[] args) throws Exception {
		int T = sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			N = sc.nextInt();
			P = sc.nextLong();
			System.out.println("Case #" + t + ": " + (solveGuarantee(1L << N, P) - 1) + " " + (solveCould(1L << N, P) - 1));
		}
	}

	static long solveGuarantee(long n, long p) {
		if (p == n) return n;
		if (p <= n / 2) return 1;
		return solveGuarantee(n / 2, p - n / 2) * 2 + 1;
	}

	static long solveCould(long n, long p) {
		if (p == n) return n;
		if (p >= n / 2) return n - 1;
		// (p < n / 2) 
		long c = solveCould(n / 2, p);
		return c + c - 1;
	}

}