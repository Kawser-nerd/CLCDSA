import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class Solution implements Runnable {
	
	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private int[] solve(int n, int[] a, int[] b) {
		boolean[][] depend = prepareDepend(n, a, b);
		int current = 1;
		int[] answer = new int[n];
		for (int i = 0; i < n; i++) {
			answer[i] = -1;
		}
		boolean[] used = new boolean[n];
		for (int i = 0; i < n; i++) {
			current = go(i, depend, answer, current, used);
		}
		return answer;
	}
	
	private int go(int i, boolean[][] depend, int[] answer, int current, boolean[] used) {
		if (answer[i] != -1) {
			return current;
		}
		if (used[i]) {
			System.out.println("Botva!");
		}
		used[i] = true;
		for (int j = 0; j < depend[i].length; j++) {
			if (depend[i][j]) {
				current = go(j, depend, answer, current, used);
			}
		}
		answer[i] = current;
		current++;
		return current;
	}

	private boolean[][] prepareDepend(int n, int[] a, int[] b) {
		boolean[][] depend = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[j] >= a[i]) {
					depend[j][i] = true;
				}
			}
			int last = -1;
			for (int j = 0; j < i; j++) {
				if (a[j] + 1 == a[i]) {
					last = j;
				}
			}
			if (last != -1) {
				depend[i][last] = true;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; j > i; j--) {
				if (b[j] >= b[i]) {
					depend[j][i] = true;
				}
			}
			int first = -1;
			for (int j = n - 1; j > i; j--) {
				if (b[j] + 1 == b[i]) {
					first = j;
				}
			}
			if (first != -1) {
				depend[i][first] = true;
			}
		}
		return depend;
	}
	
	private void solve() throws IOException {
		int t = nextInt();
		for (int test = 1; test <= t; test++) {
			int n = nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			int[] b = new int[n];
			for (int i = 0; i < n; i++) {
				b[i] = nextInt();
			}
			int[] answer = solve(n, a, b);
			out.print("Case #" + test + ":");
			for (int i = 0; i < n; i++) {
				out.print(" " + answer[i]);
			}
			out.println();
		}
	}
	
	@Override
	public void run() {
		try {
			solve();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		} finally {
			out.close();
		}
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	private String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	public Solution(String filename) {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			st = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(filename + ".out"));
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Solution("data").run();
	}
}
