import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main implements Runnable {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new Thread(new Main()).start();
	}

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			run1();
		} catch (IOException e) {
			throw new RuntimeException();
		}
	}

	int nextInt(StreamTokenizer st) throws IOException {
		st.nextToken();
		return (int) st.nval;
	}

	private List<Integer> kmp(String x, String a) {
		String s = a + "$" + x;
		int[] oppa = new int[s.length()];
		oppa[0] = 0;
		int tmp = 0;
		List<Integer> res = new ArrayList<Integer>();
		for (int i = 1; i < s.length(); i++) {
			while (tmp != 0 && s.charAt(tmp) != s.charAt(i)) {
				// System.out.println(i + " " + tmp);
				tmp = oppa[tmp - 1];
			}
			if (s.charAt(tmp) == s.charAt(i))
				tmp++;
			oppa[i] = tmp;
			if (tmp == a.length()) {
				res.add(i - a.length() - a.length());
			}
		}
		return res;
	}

	double nextDouble(StreamTokenizer st) throws IOException {
		st.nextToken();
		return st.nval;
	}

	String nextLine(StreamTokenizer st) throws IOException {
		st.nextToken();
		return st.sval;
	}

	public void run1() throws IOException {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int tN = sc.nextInt();
		for (int tn = 1; tn <= tN; tn++) {
			long l = sc.nextLong();
			int n = sc.nextInt();
			int[] arr = new int[n];
			int d = 0;
			for (int i = 0; i < n; i++) {
				arr[i] = sc.nextInt();
				d = gcd(d, arr[i]);
			}
			if (l % d != 0) {
				pw.printf("Case #%d: IMPOSSIBLE\n", tn);
				continue;
			}
			Arrays.sort(arr);
			int m = arr[n - 1] * arr[n - 1];
			long[] dist = new long[m];
			Arrays.fill(dist, 1000000000000000001l);
			boolean[] was = new boolean[m];
			dist[0] = 0;
			while (true) {
				int u = -1;
				for (int i = 0; i < m; i++)
					if (!was[i] && (u == -1 || dist[u] > dist[i]))
						u = i;
				if (u == -1)
					break;
				was[u] = true;
				for (int i = 0; i < n; i++) {
					if (arr[i] + u < m)
						dist[arr[i] + u] = Math.min(dist[arr[i] + u],
								dist[u] + 1);
				}
			}
			long res = 1000000000000000001l;
			for (int a = (int) (l % arr[n - 1]); a < m; a += arr[n - 1]) {
				res = Math.min(res, dist[a] + (l - a) / arr[n - 1]);
			}
			pw.printf("Case #%d: %d\n", tn, res);
		}
		pw.close();
	}

	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
}