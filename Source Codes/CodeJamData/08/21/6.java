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
		long a = in.nextInt();
		long b = in.nextInt();
		long c = in.nextInt();
		long d = in.nextInt();
		long x = in.nextInt();
		long y = in.nextInt();
		long m = in.nextInt();
		long[][] p = new long[3][3];
		p[(int) (x % 3)][(int) (y % 3)]++;
		for (int i = 1; i < n; i++) {
			x = ((a * x + b) % m);
			y = ((c * y + d) % m);
			p[(int) (x % 3)][(int) (y % 3)]++;
		}
		long ans = 0;
		for (int k1 = 0; k1 < 9; k1++)
			for (int k2 = k1; k2 < 9; k2++)
				for (int k3 = k2; k3 < 9; k3++) {
					int i1 = k1 / 3;
					int j1 = k1 % 3;
					int i2 = k2 / 3;
					int j2 = k2 % 3;
					int i3 = k3 / 3;
					int j3 = k3 % 3;
					if ((i1 + i2 + i3) % 3 != 0)
						continue;
					if ((j1 + j2 + j3) % 3 != 0)
						continue;
					if (k1 < k2 && k2 < k3) {
						ans += p[i1][j1] * p[i2][j2] * p[i3][j3];
					} else if (k1 == k2 && k2 == k3) {
						ans += p[i1][j1] * (p[i1][j1] - 1) * (p[i1][j1] - 2) / 6;
					} else {
						System.out.println("ERROR");
					}
				}
		out.println("Case #" + testCase + ": " + ans);
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
