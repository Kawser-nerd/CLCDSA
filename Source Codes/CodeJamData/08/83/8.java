import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemC {
	String input = "C-large.in";
	String output = input.substring(0, input.length() - 2) + "out";

	static long MOD = 1000000009L;

	int numCases;
	int n, k;
	boolean[][] a;
	long res;
	boolean[] visited;

	void dfs(int v, int lastCnt, int lvl) {
		visited[v] = true;
		int cc = 0;
		for (int i = 0; i < n; i++)
			if (a[v][i] && !visited[i]) {
				long choice = k - lastCnt - cc - 1;
				if (lvl < 2) choice++;
				if (choice < 0) choice = 0;
				res *= choice;
				res %= MOD;
				cc++;
			}
		for (int i = 0; i < n; i++)
			if (a[v][i] && !visited[i]) dfs(i, cc, lvl + 1);

	}

	void solve() throws FileNotFoundException {
		Scanner sc = new Scanner(new File(input));
		PrintWriter pw = new PrintWriter(output);
		numCases = Integer.parseInt(sc.nextLine());
		for (int cnum = 1; cnum <= numCases; cnum++) {
			n = sc.nextInt();
			k = sc.nextInt();
			a = new boolean[n][n];
			for (int i = 0; i < n - 1; i++) {
				int x = sc.nextInt() - 1;
				int y = sc.nextInt() - 1;
				a[x][y] = a[y][x] = true;
			}
			res = 1;
			visited = new boolean[n];
			dfs(0, 0, 0);
			pw.println("Case #" + cnum + ": " + res);
		}
		sc.close();
		pw.close();
	}

	public static void main(String[] args) throws FileNotFoundException {
		new ProblemC().solve();
	}
}
