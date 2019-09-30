import java.io.*;
import java.util.*;

/**
 * @author Mikhail Dvorkin
 */
public class C implements Runnable {
	private Scanner in;
	private PrintWriter out;
	
	int two = 1048576;
	int[] s = new int[2 * two];

	private int[] deck(int n) {
		int[] a = new int[n + 1];
		Arrays.fill(s, 0);
		for (int i = 1; i <= n; i++) {
			s[two + i] = 1;
		}
		for (int i = two - 1; i > 0; i--) {
			s[i] = s[2 * i] + s[2 * i + 1];
		}
		int p = 1;
		int fr = n;
		for (int v = 1; v <= n; v++) {
			int u = (v - 1) % fr;
			int q = find(p, u);
			dec(q);
			fr--;
			a[q] = v;
			p = q;
			if (fr % 100000 == 999)
				System.out.println(fr);
		}
		return a;
	}

	private int find(int q, int u) {
		q += two;
		int big = sum(q, 2 * two - 1);
		if (u >= big) {
			return find(0, u - big);
		}
		int low = q - 1;
		int high = 2 * two - 1;
		while (low + 1 < high) {
			int m = (low + high) / 2;
			if (sum(q, m) >= u + 1) {
				high = m;
			} else {
				low = m;
			}
		}
		return high - two;
	}

	private int sum(int a, int b) {
		int ans = 0;
		while (a <= b) {
			if (a % 2 == 1) {
				ans += s[a];
				a++;
			}
			if (b % 2 == 0) {
				ans += s[b];
				b--;
			}
			a /= 2;
			b /= 2;
		}
		return ans;
	}

	private void dec(int q) {
		q += two;
		if (s[q] == 0) {
			System.out.println("ERROR");
		}
		while (q > 0) {
			s[q]--;
			q /= 2;
		}
	}

	private int get(NavigableSet<Integer> set, int index) {
		int low = set.first() - 1;
		int high = set.last();
		while (low + 1 < high) {
			int m = (low + high) / 2;
			if (set.headSet(m, true).size() > index)
				high = m;
			else
				low = m;
		}
		return high;
	}

	private void solve(int testCase) {
		int n = in.nextInt();
		int[] a = deck(n);
		
		out.print("Case #" + testCase + ":");
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			int pos = in.nextInt();
			out.print(" " + a[pos]);
		}
		out.println();
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Thread(new C()).start();
	}

	public void run() {
		try {
			in = new Scanner(new FileReader("c.in"));
			out = new PrintWriter("c.out");
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
