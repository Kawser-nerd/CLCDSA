import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	int n;
	char[] A, B;
	
	void read() {
		A = sc.next().toCharArray();
		B = sc.next().toCharArray();
		n = A.length;
	}
	
	String get(int i, char[] A, char c) {
		String res = "";
		for (int j = i; j < A.length; j++) {
			if (A[j] == '?') res += c;
			else res += A[j];
		}
		return res;
	}
	
	long min;
	String ra, rb;
	
	void update(String a, String b) {
		long diff = abs(Long.valueOf(a) - Long.valueOf(b));
		if (min > diff || min == diff && (ra.compareTo(a) > 0 || ra.compareTo(a) == 0 && rb.compareTo(b) > 0)) {
			min = diff;
			ra = a;
			rb = b;
		}
	}
	
	void solve() {
		min = Long.MAX_VALUE;
		String a = "", b = "";
		for (int i = 0; i <= n; i++) {
			if (i == n) {
				ra = a;
				rb = b;
				break;
			}
			if (A[i] == '?' && B[i] == '?') {
				update(a + "1" + get(i + 1, A, '0'), b + "0" + get(i + 1, B, '9'));
				update(a + "0" + get(i + 1, A, '9'), b + "1" + get(i + 1, B, '0'));
				a += "0";
				b += "0";
			} else if (A[i] == '?') {
				if (B[i] != '9') update(a + (char)(B[i] + 1) + get(i + 1, A, '0'), b + B[i] + get(i + 1, B, '9'));
				if (B[i] != '0') update(a + (char)(B[i] - 1) + get(i + 1, A, '9'), b + B[i] + get(i + 1, B, '0'));
				a += B[i];
				b += B[i];
			} else if (B[i] == '?') {
				if (A[i] != '9') update(a + A[i] + get(i + 1, A, '9'), b + (char)(A[i] + 1) + get(i + 1, B, '0'));
				if (A[i] != '0') update(a + A[i] + get(i + 1, A, '0'), b + (char)(A[i] - 1) + get(i + 1, B, '9'));
				a += A[i];
				b += A[i];
			} else if (A[i] < B[i]) {
				update(a + A[i] + get(i + 1, A, '9'), b + B[i] + get(i + 1, B, '0'));
				break;
			} else if (A[i] > B[i]) {
				update(a + A[i] + get(i + 1, A, '0'), b + B[i] + get(i + 1, B, '9'));
				break;
			} else {
				a += A[i];
				b += B[i];
			}
		}
		System.out.println(ra + " " + rb);
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
