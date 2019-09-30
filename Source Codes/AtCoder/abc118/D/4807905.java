import java.io.InputStream;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	int[] q = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
	int[] a;

	int compare(String a, String b) {
		if (a == null) {
			a = "";
		}
		if (b == null) {
			b = "";
		}

		int result = Integer.compare(a.length(), b.length());
		if (result == 0) {
			result = a.compareTo(b);
		}
		return result;
	}

	String max(String s1, String s2) {
		if (compare(s1, s2) > 0) {
			return s1;
		} else {
			return s2;
		}
	}

	Map<Integer, String> memo = new HashMap<>();

	String dfs(int n) {
		if (n == 0) {
			return "";
		}

		String x = memo.get(n);
		if (x != null) {
			return x;
		}

		String ans = null;
		for (int i = 0; i < a.length; i++) {
			int newN = n - q[a[i]];

			if (newN < 0) {
				continue;
			}

			String tmp = dfs(newN);
			if (tmp == null) {
				continue;
			}

			ans = max(ans, a[i] + tmp);
		}

		memo.put(n, ans);

		return ans;

	}

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int N = sc.nextInt();
		int M = sc.nextInt();

		a = new int[M];
		for (int i = 0; i < M; i++) {
			a[i] = sc.nextInt();
		}

		out.println(dfs(N));

		sc.close();

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}