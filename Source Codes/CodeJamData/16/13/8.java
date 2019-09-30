import java.io.*;
import java.util.*;

public class C {

	int solveOne(Scanner in) {
		int n = in.nextInt();
		int f[] = new int[1 + n];
		for (int i = 1; i <= n; i++) {
			f[i] = in.nextInt();
		}
		boolean inPair[] = new boolean[1 + n];
		for (int i = 1; i <= n; i++) {
			if (f[f[i]] == i) {
				inPair[i] = true;
			}
		}
		int chainLen[] = new int[1 + n];
		boolean used[] = new boolean[1 + n];
		int maxCircleLen = 0;
		for (int first = 1; first <= n; first++) {
			if (inPair[first]) {
				continue;
			}
			Arrays.fill(used, false);
			used[first] = true;
			int cur = first;
			int len = 1;
			while (true) {
				int next = f[cur];
				if (inPair[next]) {
					chainLen[next] = Math.max(chainLen[next], len);
					break;
				}
				if (next == first) {
					maxCircleLen = Math.max(maxCircleLen, len);
					break;
				}
				if (used[next]) {
					break;
				}
				used[next] = true;
				len++;
				cur = next;
			}
		}
		int joinLen = 0;
		for (int i = 1; i <= n; i++) {
			if (inPair[i]) {
				joinLen += 1 + chainLen[i];
			}
		}
		return Math.max(maxCircleLen, joinLen);
	}
	
	void solve(Scanner in, PrintWriter out) {
		int nTests = in.nextInt();
		for (int iTest = 1; iTest <= nTests; iTest++) {
			out.printf("Case #%d: %d%n", iTest, solveOne(in));
		}
	}
	
	void run() {
		try (
			Scanner in = new Scanner(System.in);
			PrintWriter out = new PrintWriter(System.out);
	   	) {
	   		solve(in, out);
	   	}
	}


	public static void main(String args[]) {
		new C().run();
	}
}
