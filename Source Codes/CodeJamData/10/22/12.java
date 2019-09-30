import java.io.*;
import java.math.*;
import java.util.*;

public class B {

	final static int INF = 1000000000;

	static int N, K, B, T;
	static int[] X;
	static int[] V;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		for (int cas = 1; cas <= tests; cas++) {
			N = sc.nextInt();
			K = sc.nextInt();
			B = sc.nextInt();
			T = sc.nextInt();
			X = new int[N];
			for (int i = 0; i < N; i++)
				X[i] = sc.nextInt();
			V = new int[N];
			for (int i = 0; i < N; i++)
				V[i] = sc.nextInt();
			boolean[] can = new boolean[N];
			for (int i = 0; i < N; i++)
				can[i] = X[i] + V[i] * T >= B;
			int arrives = 0;
			int swaps = 0;
			for (int i = N - 1; i >= 0; i--) {
				if (arrives >= K)
					break;
				if (can[i]) {
					arrives ++;
				} else {
					swaps += K - arrives;
				}
			}
			if (arrives >= K) {
				System.out.println("Case #" + cas + ": " + swaps);
			} else {
				System.out.println("Case #" + cas + ": IMPOSSIBLE");
			}
		}
	}
}
