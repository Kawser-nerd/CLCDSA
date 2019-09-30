import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	int N, X;
	int[] S;
	
	void read() {
		N = sc.nextInt();
		X = sc.nextInt();
		S = new int[N];
		for (int i = 0; i < N; i++) S[i] = sc.nextInt();
	}
	
	void solve() {
		boolean[] used = new boolean[N];
		int num = 0;
		sort(S);
		for (int i = 0; i < N; i++) if (!used[i]) {
			used[i] = true;
			for (int j = N - 1; j >= 0; j--) if (!used[j] && S[i] + S[j] <= X) {
				used[i] = used[j] = true;
				break;
			}
			num++;
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
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (A.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new A().run();
	}
}
