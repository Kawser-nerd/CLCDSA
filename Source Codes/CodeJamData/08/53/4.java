import java.io.*;
import java.util.*;

/**
 * @author Mikhail Dvorkin
 */
public class C implements Runnable {
	private Scanner in;
	private PrintWriter out;
	
	int n;
	ArrayList<Integer>[] e;
	int[] even;
	int[] pair;
	boolean[] mark;
	
	boolean dfs(int v) {
		if (v < 0 || v >= n)
			System.out.println("ERROR");
		if (mark[v])
			return false;
		mark[v] = true;
		if (even[v] != 0)
			System.out.println("ERROR");
		for (int i : e[v]) {
			if (even[i] != 1)
				System.out.println("ERROR");
			if (pair[i] == -1) {
				pair[i] = v;
				return true;
			}
			if (dfs(pair[i])) {
				pair[i] = v;
				return true;
			}
		}
		return false;
	}

	private void solve(int testCase) {
		int hei = in.nextInt();
		int wid = in.nextInt();
		n = hei * wid;
		e = new ArrayList[n];
		mark = new boolean[n];
		even = new int[n];
		pair = new int[n];
		Arrays.fill(pair, -1);
		Arrays.fill(even, 0);
		for (int i = 0; i < n; i++) {
			e[i] = new ArrayList<Integer>();
		}
		char[][] c = new char[hei][];
		int[][] num = new int[hei][wid];
		int ver = 0;
		for (int i = 0; i < hei; i++) {
			c[i] = in.next().toCharArray();
		}
		for (int i = 0; i < hei; i++) {
			for (int j = 0; j < wid; j++) {
				num[i][j] = wid * i + j;
				even[num[i][j]] = j % 2;
			}
		}
		for (int i = 0; i < hei; i++) {
			for (int j = 0; j < wid; j++) {
				if (c[i][j] == '.') {
					ver++;
					if (i > 0 && j > 0 && c[i - 1][j - 1] == '.') {
						e[num[i][j]].add(num[i - 1][j - 1]);
					}
					if (i > 0 && j + 1 < wid && c[i - 1][j + 1] == '.') {
						e[num[i][j]].add(num[i - 1][j + 1]);
					}
					if (j > 0 && c[i][j - 1] == '.') {
						e[num[i][j]].add(num[i][j - 1]);
					}
					if (j + 1 < wid && c[i][j + 1] == '.') {
						e[num[i][j]].add(num[i][j + 1]);
					}
					if (i + 1 < hei && j > 0 && c[i + 1][j - 1] == '.') {
						e[num[i][j]].add(num[i + 1][j - 1]);
					}
					if (i + 1 < hei && j + 1 < wid && c[i + 1][j + 1] == '.') {
						e[num[i][j]].add(num[i + 1][j + 1]);
					}
				} else if (c[i][j] != 'x')
					System.out.println("ERROR");
			}
		}
		for (int i = 0; i < n; i++) {
			if (even[i] == 1)
				continue;
			Arrays.fill(mark, false);
			if (dfs(i)) {
				ver--;
			}
		}
		out.println("Case #" + testCase + ": " + ver);
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
