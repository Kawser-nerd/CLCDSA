import java.io.*;
import java.util.*;

/**
 * @author Mikhail Dvorkin
 */
public class A implements Runnable {
	private Scanner in;
	private PrintWriter out;

	private void solve(int testCase) {
		int n = in.nextInt();
		int desired = in.nextInt();
		boolean[] and = new boolean[n + 1];
		boolean[] val = new boolean[n + 1];
		boolean[] ch = new boolean[n + 1];
		int inf = 1000000;
		int[][] ans = new int[n + 1][2];
		for (int i = 1; i <= n / 2; i++) {
			and[i] = (in.nextInt() == 1);
			ch[i] = (in.nextInt() == 1);
		}
		for (int i = n / 2 + 1; i <= n; i++) {
			int vv = in.nextInt();
			val[i] = (vv == 1);
			ans[i][vv] = 0;
			ans[i][1 - vv] = inf;
		}
		for (int i = n / 2; i >= 1; i--) {
			if (and[i]) {
				ans[i][1] = inf;
				ans[i][1] = Math.min(ans[i][1], ans[2 * i][1] + ans[2 * i + 1][1]);
				if (ch[i]) {
					ans[i][1] = Math.min(ans[i][1], ans[2 * i][1] + ans[2 * i + 1][0] + 1);
					ans[i][1] = Math.min(ans[i][1], ans[2 * i][0] + ans[2 * i + 1][1] + 1);
				}
				ans[i][0] = inf;
				ans[i][0] = Math.min(ans[i][0], ans[2 * i][0] + ans[2 * i + 1][0]);
				ans[i][0] = Math.min(ans[i][0], ans[2 * i][1] + ans[2 * i + 1][0]);
				ans[i][0] = Math.min(ans[i][0], ans[2 * i][0] + ans[2 * i + 1][1]);
			} else {
				ans[i][0] = inf;
				ans[i][0] = Math.min(ans[i][0], ans[2 * i][0] + ans[2 * i + 1][0]);
				if (ch[i]) {
					ans[i][0] = Math.min(ans[i][0], ans[2 * i][1] + ans[2 * i + 1][0] + 1);
					ans[i][0] = Math.min(ans[i][0], ans[2 * i][0] + ans[2 * i + 1][1] + 1);
				}
				ans[i][1] = inf;
				ans[i][1] = Math.min(ans[i][1], ans[2 * i][1] + ans[2 * i + 1][1]);
				ans[i][1] = Math.min(ans[i][1], ans[2 * i][1] + ans[2 * i + 1][0]);
				ans[i][1] = Math.min(ans[i][1], ans[2 * i][0] + ans[2 * i + 1][1]);
			}
		}
		out.println("Case #" + testCase + ": " + ((ans[1][desired] == inf) ? "IMPOSSIBLE" : ans[1][desired]));
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Thread(new A()).start();
	}

	public void run() {
		try {
			in = new Scanner(new FileReader("a.in"));
			out = new PrintWriter("a.out");
			int n = in.nextInt();
			for (int i = 1; i <= n; i++)
				solve(i);
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
