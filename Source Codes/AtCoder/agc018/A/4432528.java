import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] A = new int[N];
		for(int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}
		sc.close();
		Arrays.sort(A);
		if(A[N - 1] < K) {
			System.out.println("IMPOSSIBLE");
			System.exit(0);
		}
		if(N == 1) {
			if(A[0] == K) {
				System.out.println("POSSIBLE");
			}else {
				System.out.println("IMPOSSIBLE");
			}
			System.exit(0);
		}
		int g  = gcd(A[0], A[1]);
		for(int i = 2; i < N; i++) {
			g = gcd(g, A[i]);
		}
		if(K % g == 0) {
			System.out.println("POSSIBLE");
		}else {
			System.out.println("IMPOSSIBLE");
		}
	}
	static int gcd(int m, int n) {
		if(m < n) return gcd(n, m);
		if(n == 0) return m;
		return gcd(n, m % n);
	}
}