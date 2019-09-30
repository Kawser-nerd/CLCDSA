import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	int N;
	int[] A, B;
	
	void read() {
		N = sc.nextInt();
		A = new int[N];
		B = new int[N];
		for (int i = 0; i < N; i++) A[i] = sc.nextInt();
		for (int i = 0; i < N; i++) B[i] = sc.nextInt();
	}
	
	void solve() {
		g = new boolean[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (A[j] + 1 == A[i]) {
					g[j][i] = true;
					break;
				}
			}
			for (int j = 0; j < i; j++) {
				if (A[j] + 1 > A[i]) {
					g[i][j] = true;
				}
			}
		}
		for (int i = N - 1; i >= 0; i--) {
			for (int j = i + 1; j < N; j++) if (B[j] + 1 == B[i]) {
				g[j][i] = true;
				break;
			}
			for (int j = i + 1; j < N; j++) {
				if (B[j] + 1 > B[i]) {
					g[i][j] = true;
				}
			}
		}
//		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (g[i][j]) debug(i, j);
		for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) g[i][j] |= g[i][k] && g[k][j];
		int[] a = new int[N];
		for (int i = 0; i < N; i++) a[i] = i;
		int[] res = new int[N];
		f(a, res, 0, N);
		int[] seq = new int[N];
		for (int i = 0; i < N; i++) {
			if (i > 0) System.out.print(" ");
			for (int j = 0; j < N; j++) if (res[j] == i) {
				System.out.print(j + 1);
				seq[i] = j;
			}
		}
		System.out.println();
//		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
//			if (g[i][j] && seq[i] > seq[j]) throw null;
//		}
//		int[] A2 = new int[N];
//		for (int i = 0; i < N; i++) {
//			A2[i] = 1;
//			for (int j = 0; j < i; j++) if (seq[j] < seq[i]) A2[i] = max(A2[i], A2[j] + 1);
//		}
//		if (!Arrays.equals(A, A2)) {
//			debug(A);
//			debug(A2);
//		}
	}
	
	boolean[][] g;
	
	void f(int[] a, int[] res, int s, int t) {
		if (a.length == 0) return;
		int v = a[0], smallN = 0, largeN = 0;
		for (int i = 1; i < a.length; i++) if (g[a[i]][v]) smallN++;
		int[] small = new int[smallN], large = new int[a.length - 1 - smallN];
		smallN = 0;
		for (int i = 1; i < a.length; i++) {
			if (g[a[i]][v]) small[smallN++] = a[i];
			else large[largeN++] = a[i];
		}
		res[s + smallN] = v;
		f(small, res, s, s + smallN);
		f(large, res, s + smallN + 1, t);
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		try {
//			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (C.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new C().run();
	}
}
