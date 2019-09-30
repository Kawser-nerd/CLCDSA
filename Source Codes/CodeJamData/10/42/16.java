import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;

public class Main1 implements Runnable {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new Thread(new Main1()).start();
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
			int n = sc.nextInt();
			int[] oppa = new int[1 << n];
			for (int i = 0; i < oppa.length; i++)
				oppa[i] = sc.nextInt();
			int[] pr = new int[1 << n];
			for (int k = n - 1; k >= 0; k--) {
				for (int i = 0; i < (1 << k); i++)
					pr[i + (1 << k)] = sc.nextInt();
			}
			long[][] res = new long[n + 1][1 << (n + 1)];
			for (int m = (1 << (n + 1)) - 1; m >= 1; m--) {
				for (int k = 0; k <= n; k++) {
					if (m >= pr.length) {
						if (k > oppa[m - (1 << n)])
							res[k][m] = 100000000000000l;
						else
							res[k][m] = 0;
					} else {
						res[k][m] = pr[m] + res[k][m * 2] + res[k][m * 2 + 1];
						if (k < n)
							res[k][m] = Math.min(res[k][m], res[k + 1][m * 2]
									+ res[k + 1][m * 2 + 1]);
					}
					// System.out.println(m + " " + k + " " + res[k][m]);
				}
			}
			pw.printf("Case #%d: %d\n", tn, res[0][1]);
		}
		pw.close();
	}
}