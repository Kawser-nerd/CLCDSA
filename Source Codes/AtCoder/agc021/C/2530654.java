import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	static final char[][] tres = {"<>^".toCharArray(),
			"^.v".toCharArray(),
			"v<>".toCharArray()};
	
	static char[][] ret;
	
	static void putV(int i, int j) {
		ret[i][j] = '^';
		ret[i+1][j] = 'v';
	}
	
	static void putH(int i, int j) {
		ret[i][j] = '<';
		ret[i][j+1] = '>';
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int N = sc.nextInt();
		int M = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		ret = new char[N][M];
		for (int i = 0; i < ret.length; i++) {
			Arrays.fill(ret[i], '.');
		}
		if (N % 2 == 1) {
			int to = M;
			if (M % 2 == 1 && N >= 3 && M >= 3) to -= 3;
			for (int j = 0; A > 0 && j + 1 < to; j+= 2) {
				A--;
				putH(N-1, j);
			}
		}
		if (M % 2 == 1) {
			int to = N;
			if (N % 2 == 1 && N >= 3 && M >= 3) to -= 3;
			for (int i = 0; B > 0 && i + 1 < to; i+= 2) {
				B--;
				putV(i, M - 1);
			}
		}
		boolean special = N%2 == 1 && M %2 == 1 && N >= 3 && M >= 3;
		for (int i = 0; i + 1 < N; i+=2) {
			for (int j = 0; j + 1 < M; j+=2) if (!special || i + 3 < N || j + 3 < M) {
				if (A > B) {
					putH(i,j);
					A--;
					if (A > 0) {
						putH(i+1,j);
						A--;
					}
				} else {
					if (B > 0) {
						putV(i,j);
						B--;
					}
					if (B > 0) {
						putV(i,j+1);
						B--;
					}
				}
			}
		}
		if (N%2 == 1 && M %2 == 1 && N >= 3 && M >= 3) {
			if (A == 2 && B == 2) {
				A = B = 0;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						ret[N - 3 + i][M - 3 + j] = tres[i][j];
					}
				}
			}
			if (A > 0) {
				putH(N-1, M-3);
				A--;
			}
			if (B > 0) {
				putV(N-3, M-1);
				B--;
			}
			if (A > 0) {
				putH(N-3, M-3);
				A--;
				if (A > 0) {
					putH(N-2, M-3);
					A--;
				}
			} else if (B > 0) {
				putV(N-3, M-3);
				B--;
				if (B > 0) {
					putV(N-3, M-2);
					B--;
				}
			}
		}
		
		if (A + B > 0) {
			System.out.println("NO");
		} else {
			System.out.println("YES");
			for (int i = 0; i < ret.length; i++) {
				System.out.println(new String(ret[i]));
			}
		}
	}
}