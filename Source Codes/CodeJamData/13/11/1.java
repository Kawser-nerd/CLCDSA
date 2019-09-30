import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	long r, t;
	
	void read() {
		r = sc.nextLong();
		t = sc.nextLong();
	}
	
	void solve() {
		long left = 0, right = 1L << 40;
		while (right - left > 1) {
			long n = (left + right) / 2;
			if ((double)(2 * r + 1) * n + 2.0 * n * (n - 1) > 1.5 * t) {
				right = n;
			} else if ((2 * r + 1) * n + 2 * n * (n - 1) > t) {
				right = n;
			} else {
				left = n;
			}
		}
		System.out.println(left);
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
		new A().run();
	}
}
