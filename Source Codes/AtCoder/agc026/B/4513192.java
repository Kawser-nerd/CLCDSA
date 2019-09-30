import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		long []A = new long[T];
		long []B = new long[T];
		long []C = new long[T];
		long []D = new long[T];

		for(int i = 0; i < T; i++) {
			A[i] = scan.nextLong();
			B[i] = scan.nextLong();
			C[i] = scan.nextLong();
			D[i] = scan.nextLong();
		}
		scan.close();
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < T; i++) {
			if(B[i] > A[i] || B[i] > D[i]) {
				sb.append("No");
			}else if(C[i] >= B[i] - 1) {
				sb.append("Yes");
			}else {
				long g = gcd(B[i], D[i]);
				long l = A[i] - B[i] + 1;
				long r = A[i] - C[i] - 1;
				long q = 0;
				long k = (r - q + g) / g - (l - q + g - 1) / g;
				if(k > 0) {
					sb.append("No");
				}else {
					sb.append("Yes");
				}
			}
			sb.append("\n");
		}
		System.out.print(sb.toString());
	}
	static long gcd(long m, long n) {
		if(m < n) return gcd(n, m);
		if(n == 0) return m;
		return gcd(n, m % n);
	}
}