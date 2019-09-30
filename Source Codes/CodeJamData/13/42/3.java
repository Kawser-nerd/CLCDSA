import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	int N;
	long P;
	
	void read() {
		N = sc.nextInt();
		P = sc.nextLong();
	}
	
	void solve() {
		if (P == 1L << N) {
			System.out.println((P - 1) + " " + (P - 1));
			return;
		}
		P--;
		long[] a = new long[N];
		for (int i = 0; i < N; i++) {
			a[N - i - 1] = P % 2;
			P /= 2;
		}
		int i1 = 0;
		while (a[i1] == 1) i1++;
		System.out.print((1L << (i1 + 1)) - 2);
		System.out.print(" ");
		int i0 = 0;
		while (i0 < N && a[i0] == 0) i0++;
		boolean b0 = true;
		for (int i = i0; i < N; i++) if (a[i] != 1) b0 = false;
		if (b0) {
			System.out.println((1L << N) - (1L << (i0)));
		} else {
			System.out.println((1L << N) - (1L << (i0 + 1)));
		}
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
//			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (B.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new B().run();
	}
}
