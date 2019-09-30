import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	char[] PRS = "PRS".toCharArray();
	
	int N;
	int[] num;
	
	void read() {
		N = sc.nextInt();
		num = new int[3];
		num[1] = sc.nextInt();
		num[0] = sc.nextInt();
		num[2] = sc.nextInt();
	}
	
	String rec(int N, int i) {
		if (N == 0) return "" + PRS[i];
		String a = rec(N - 1, i), b = rec(N - 1, (i + 2) % 3);
		if (a.compareTo(b) > 0) return b + a;
		return a + b;
	}
	
	void solve() {
		String res = null;
		for (int i = 0; i < 3; i++) {
			String tmp = rec(N, i);
			int[] count = new int[256];
			for (char c : tmp.toCharArray()) count[c]++;
			boolean ok = true;
			for (int j = 0; j < 3; j++) ok &= count[PRS[j]] == num[j];
			if (ok && (res == null || res.compareTo(tmp) > 0)) res = tmp;
		}
		if (res != null) System.out.println(res);
		else System.out.println("IMPOSSIBLE");
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
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (A.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new A().run();
	}
}
