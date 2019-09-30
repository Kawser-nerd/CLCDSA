import java.util.*;
import java.io.*;

class Main {
	public static void main(String... args) {
		int N = IN.nextInt();
		int M = IN.nextInt();
		int Q = IN.nextInt();

		int[][] A = new int[N + 1][N + 1];
		for (int i = 0; i < M; i++) {
			int l = IN.nextInt();
			int r = IN.nextInt();
			A[l][r] += 1;
		}
		
		for (int i = 1; i <= N; i++) {
			for (int j = i; j < N; j++) {
				A[i][j + 1] += A[i][j];
			}
		}

		for (int j = N; j >= 2; j--) {
			for (int i = j; i >= 2; i--) {
				A[i - 1][j] += A[i][j];
			}
		}

		for (int i = 0; i < Q; i++) {
			int pi = IN.nextInt();
			int qi = IN.nextInt();
			puts(A[pi][qi]);
		}
		flush();
	}
	static final Scanner IN = new Scanner(System.in);
	static final PrintWriter OUT = new PrintWriter(System.out);
	static <T> void puts(T arg) { OUT.println(arg); }
	static void flush() { OUT.flush(); }
}