import java.io.*;
import java.util.*;

/**
 * @author Mikhail Dvorkin
 */
public class D implements Runnable {
	private Scanner in;
	private PrintWriter out;
	final int mod = 10007;
	
	class Stone implements Comparable<Stone> {
		int x, y;

		public Stone(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public int compareTo(Stone o) {
			return x + y - o.x - o.y;
		}
	}

	private void solve(int testCase) {
		int hei = in.nextInt() - 1;
		int wid = in.nextInt() - 1;
		int r = in.nextInt();
		int[] x = new int[r];
		int[] y = new int[r];
		for (int i = 0; i < r; i++) {
			x[i] = in.nextInt() - 1;
			y[i] = in.nextInt() - 1;
		}
		ArrayList<Stone> s = new ArrayList<Stone>();
		int ans = 0;
		for (int mask = 0; mask < (1 << r); mask++) {
			s.clear();
			s.add(new Stone(0, 0));
			s.add(new Stone(hei, wid));
			int stones = 0;
			for (int i = 0; i < r; i++) {
				if ((mask & (1 << i)) == 0)
					continue;
				stones++;
				s.add(new Stone(x[i], y[i]));
			}
			int ways = solve(s);
			if (stones % 2 == 0)
				ans += ways;
			else
				ans += mod - ways;
			ans %= mod;
		}
		out.println("Case #" + testCase + ": " + ans);
	}

	private int solve(ArrayList<Stone> s) {
		Collections.sort(s);
		int ways = 1;
		for (int i = 0; i < s.size() - 1; i++) {
			int x = s.get(i + 1).x - s.get(i).x;
			int y = s.get(i + 1).y - s.get(i).y;
//			if (x == 0 && y == 0)
//				System.out.println("ERROR");
			if (x == 0 && y == 0)
				continue;
			if (x < 0 || y < 0)
				return 0;
			if (x > 2 * y || y > 2 * x)
				return 0;
			if ((x + y) % 3 != 0)
				return 0;
			int steps = (x + y) / 3;
			int up = y - steps;
			if (up < 0 || up > steps)
				System.out.println("ERROR");
			ways *= cnk(steps, up);
			ways %= mod;
		}
		return ways;
	}
	
	static int max = 100000010;
	static short[] p = new short[max];
	int[] rev = new int[mod];
	
	int full(int n) {
		int res = 0;
		do {
			n /= mod;
			res += n;
		} while (n > 0);
		return res;
	}
	
	{
		p[1] = p[0] = 1;
		int pp = 1;
		for (int i = 1; i < mod; i++) {
			for (int j = 1; j < mod; j++) {
				if (((i * j) % mod) == 1)
					rev[i] = j;
			}
		}
		for (int i = 2; i < max; i++) {
			if (i % 1000000 == 0)
				System.out.println(i);
			int j = i;
			while (j % mod == 0)
				j /= mod;
			j %= mod;
			pp = (pp * j) % mod;
			p[i] = (short) pp;
		}
	}

	private int cnk(int n, int k) {
		int f = full(n) - full(k) - full(n - k);
		if (f < 0)
			System.out.println("ERROR");
		if (f > 0)
			return 0;
		int res = p[n];
		res = (res * rev[p[k]]) % mod;
		res = (res * rev[p[n - k]]) % mod;
		return res;
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Thread(new D()).start();
	}

	public void run() {
		try {
			in = new Scanner(new FileReader("d.in"));
			out = new PrintWriter("d.out");
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
