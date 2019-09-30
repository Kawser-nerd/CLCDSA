import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class D {
	Scanner sc = new Scanner(System.in);
	
	void solve() {
		char[] cs = sc.next().toCharArray();
		int m = 0;
		for (char c : cs) if (c == '?') m++;
		for (int i = 0; i < 1 << m; i++) {
			char[] ds = cs.clone();
			int p = 0;
			for (int j = 0; j < cs.length; j++) if (cs[j] == '?') {
				ds[j] = (char)('0' + (i >> p & 1));
				p++;
			}
			long v = 0;
			for (char c : ds) v = v * 2 + c - '0';
			long a = (long)sqrt(v);
			while (a * a < v) a++;
			while (a * a > v) a--;
			if (a * a == v) {
				System.out.println(Long.toBinaryString(v));
				return;
			}
		}
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
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
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (D.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new D().run();
	}
}
