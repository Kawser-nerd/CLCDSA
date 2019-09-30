import java.io.*;
import java.util.*;

/**
 * @author Mikhail Dvorkin
 */
public class B implements Runnable {
	private Scanner in;
	private PrintWriter out;
	
	int[] dsu;
	int sets;
	
	int get(int x) {
		if (dsu[x] == x)
			return x;
		dsu[x] = get(dsu[x]);
		return dsu[x];
	}
	
	void merge(int x, int y) {
//		System.out.println(x + " " + y);
		x = get(x);
		y = get(y);
		if (x == y)
			return;
		if (Math.random() < 0.5)
			dsu[x] = y;
		else
			dsu[y] = x;
		sets--;
	}

	private void solve(int testCase) {
		long a = in.nextLong();
		long b = in.nextLong();
		long p = in.nextLong();
		int max = (int) (b - a + 1);
		dsu = new int[max];
		sets = max;
		for (int i = 0; i < max; i++) {
			dsu[i] = i;
		}
		boolean[] prime = new boolean[max];
		Arrays.fill(prime, true);
		for (int i = 2; i < max; i++) {
			if (!prime[i])
				continue;
			for (int j = 2 * i; j < max; j += i)
				prime[j] = false;
		}
		for (long q = p; q < max; q++) {
			if (!prime[(int) q])
				continue;
			long d = a - a % q;
			if (d < a)
				d += q;
			while (d + q <= b) {
				merge((int) (d - a), (int) (d + q - a));
				d += q;
			}
		}
		out.println("Case #" + testCase + ": " + sets);
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
