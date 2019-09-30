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

public class Main2 implements Runnable {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new Thread(new Main2()).start();
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
			System.out.println(tn);
			int n = sc.nextInt();
			int m = 2 * n - 1;
			int[][] arr = new int[m][m];
			for (int i = 0; i < m; i++) {
				int cur = Math.abs(n - 1 - i);
				for (int j = 0; j < n - Math.abs(n - 1 - i); j++) {
					arr[i][cur] = sc.nextInt();
					cur += 2;
				}
			}
			boolean[] simm1 = new boolean[m];
			boolean[] simm2 = new boolean[m];
			Arrays.fill(simm1, true);
			Arrays.fill(simm2, true);
			for (int i = 0; i < m; i++)
				for (int j1 = 0; j1 < m; j1++)
					for (int j2 = j1 + 2; j2 < m; j2 += 2) {
						if (Math.abs(n - 1 - i) + Math.abs(n - 1 - j1) < n
								&& Math.abs(n - 1 - i) + Math.abs(n - 1 - j2) < n
								&& arr[i][j1] != arr[i][j2]) {
							simm1[(j1 + j2) / 2] = false;
						}
					}
			for (int j = 0; j < m; j++)
				for (int i1 = 0; i1 < m; i1++)
					for (int i2 = i1 + 2; i2 < m; i2 += 2) {
						if (Math.abs(n - 1 - i1) + Math.abs(n - 1 - j) < n
								&& Math.abs(n - 1 - i2) + Math.abs(n - 1 - j) < n
								&& arr[i1][j] != arr[i2][j])
							simm2[(i1 + i2) / 2] = false;
					}
			// for (int i = 0; i < m; i++) {
			// System.out.print(simm1[i] + " ");
			// }
			// System.out.println();
			// for (int i = 0; i < m; i++) {
			// System.out.print(simm2[i] + " ");
			// }
			// System.out.println();
			long res = 1000000;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < m; j++) {
					if (simm1[i] && simm2[j]) {
						res = Math.min(res, Math.abs(n - 1 - i)
								+ Math.abs(n - 1 - j));
					}
				}
			res += n;
			pw.printf("Case #%d: %d\n", tn, res * res - n * n);
		}
		pw.close();
	}
}