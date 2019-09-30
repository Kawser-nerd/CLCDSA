import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	int N;
	int[] A;
	
	void read() {
		N = sc.nextInt();
		A = new int[N];
		for (int i = 0; i < N; i++) A[i] = sc.nextInt();
	}
	
	void solve() {
		int num = 0;
		for (int i = 0; i < N; i++) {
			int p = 0;
			for (int j = 0; j < N - i; j++) if (A[p] > A[j]) {
				p = j;
			}
			num += min(p, N - i - 1 - p);
			for (int j = p; j < N - i - 1; j++) A[j] = A[j + 1];
		}
		System.out.println(num);
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
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (B.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new B().run();
	}
}
