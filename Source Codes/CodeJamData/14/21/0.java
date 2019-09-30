import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	int N;
	char[][] cs;
	
	void read() {
		N = sc.nextInt();
		cs = new char[N][];
		for (int i = 0; i < N; i++) cs[i] = sc.next().toCharArray();
	}
	
	String f(char[] cs) {
		String target = "";
		char last = 0;
		for (char c : cs) if (c != last) {
			target += c;
			last = c;
		}
		return target;
	}
	
	void solve() {
		String target = f(cs[0]);
		for (int i = 0; i < N; i++) if (!target.equals(f(cs[i]))) {
			System.out.println("Fegla Won");
			return;
		}
		int[] ps = new int[N];
		int res = 0;
		for (char c : target.toCharArray()) {
			int[] count = new int[N];
			for (int i = 0; i < N; i++) {
				while (ps[i] + count[i] < cs[i].length && cs[i][ps[i] + count[i]] == c) count[i]++;
				ps[i] += count[i];
			}
			int min = 1 << 29;
			for (int k = 1; k <= 200; k++) {
				int tmp = 0;
				for (int i = 0; i < N; i++) tmp += abs(count[i] - k);
				min = min(min, tmp);
			}
			res += min;
		}
		System.out.println(res);
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
