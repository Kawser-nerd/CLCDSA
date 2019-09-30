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
			boolean[][] arr = new boolean[100][100];
			int n = sc.nextInt();
			for (int i = 0; i < n; i++) {
				int x1 = sc.nextInt();
				int y1 = sc.nextInt();
				int x2 = sc.nextInt();
				int y2 = sc.nextInt();
				for (int x = x1; x <= x2; x++)
					for (int y = y1; y <= y2; y++)
						arr[x - 1][y - 1] = true;
			}
			int res = 0;
			while (true) {
				res++;
				boolean ok = false;
				for (int i = 99; i >= 0; i--)
					for (int j = 99; j >= 0; j--) {
						if (i == 0 || j == 0)
							arr[i][j] = false;
						else if (arr[i][j]
								&& (!arr[i - 1][j] && !arr[i][j - 1]))
							arr[i][j] = false;
						else if (!arr[i][j] && (arr[i - 1][j] && arr[i][j - 1]))
							arr[i][j] = true;
						ok |= arr[i][j];
					}
				if (!ok)
					break;
			}
			pw.printf("Case #%d: %d\n", tn, res);
		}
		pw.close();
	}
}