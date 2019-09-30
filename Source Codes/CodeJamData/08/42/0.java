import java.io.*;
import java.util.*;

/**
 * @author Mikhail Dvorkin
 */
public class B implements Runnable {
	private Scanner in;
	private PrintWriter out;

	private void solve(int testCase) {
		int n = in.nextInt();
		int m = in.nextInt();
		int a = in.nextInt();
		if (a > n * m) {
			out.println("Case #" + testCase + ": IMPOSSIBLE");
			return;
		}
		int p = a - a % n;
		if (p < a)
			p += n;
		int y3 = p / n;
		int x3 = p - a;
		out.println("Case #" + testCase + ": 0 0 " + n + " 1 " + x3 + " " + y3);
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Thread(new B()).start();
	}

	public void run() {
		try {
			in = new Scanner(new FileReader("b.in"));
			out = new PrintWriter("b.out");
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
