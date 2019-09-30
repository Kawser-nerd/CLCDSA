import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int N = sc.nextInt();
		int[] A = new int[N];
		int[] B = new int[N];
		Value[] vs = new Value[2 * N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
			vs[i * 2] = new Value(A[i], i, 0);
			vs[i * 2 + 1] = new Value(B[i], i, 1);
		}
		Arrays.sort(vs);
		boolean[][] use = new boolean[2][N];
		long sum = 0;
		for (int i = 0; i < N; i++) {
			use[vs[i].d][vs[i].i] = true;
			sum += vs[i].v;
		}
		int c0 = 0;
		for (int i = 0; i < N; i++) {
			if (use[0][i] && use[1][i]) {
				System.out.println(sum);
				return;
			}
			if (use[0][i]) ++c0;
		}
		if (c0 == N || c0 == 0) {
			System.out.println(sum);
			return;
		}
		int[] maxF = new int[N + 1];
		int[] maxB = new int[N + 1];
		for (int i = 0; i < N; i++) {
			maxF[i + 1] = Math.max(maxF[i], use[0][i] ? A[i] : B[i]);
			maxB[N - i - 1] = Math.max(maxB[N - i], use[0][N - i - 1] ? A[N - i - 1] : B[N - i - 1]);
		}
		long ans = Long.MAX_VALUE;
		for (int i = 0; i < N; i++) {
			long cur = sum + (use[0][i] ? B[i] : A[i]);
			cur -= Math.max(maxF[i], maxB[i + 1]);
			ans = Math.min(ans, cur);
		}

		System.out.println(ans);
	}

	static class Value implements Comparable<Value> {
		int v, i, d;

		public Value(int v, int i, int d) {
			this.v = v;
			this.i = i;
			this.d = d;
		}

		@Override
		public int compareTo(Value o) {
			return Integer.compare(this.v, o.v);
		}
	}

}