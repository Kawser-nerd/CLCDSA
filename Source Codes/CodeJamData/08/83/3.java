import java.util.*;
import java.io.*;
import java.math.*;

public class ProblemC {
	int n, k;
	boolean[][] adj;
	long res = 1;
	long MOD = 1000000009;

	int deg(int v) {
		int res=0;
		for (int i=0; i < n; i++)
			if (adj[v][i]) res++;
		return res;
	}

	void go(int v, int p) {
		if (p == -1) {
			int d = deg(v);
			for (long x = k; x > k - d; x--)
				res = (res * x) % MOD;
		} else {
			int taken = deg(p);
			int need = deg(v) - 1;
			for (long x = k - taken; x > k - taken - need; x--)
				res = (res * x) % MOD;
		}
		for (int i=0; i < n; i++)
			if (adj[v][i] && i != p)
				go(i, v);
	}

	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			pw.print("Case #" + caseNum + ":");
			n = sc.nextInt();
			k = sc.nextInt();
			adj = new boolean[n][n];
			for (int i=0; i + 1 < n; i++) {
				int a = sc.nextInt();
				int b = sc.nextInt();
				adj[a-1][b-1] = adj[b-1][a-1] = true;
			}
			res = 1;
			go(0, -1);
			pw.println(" "+res);
		}
		pw.flush();
		pw.close();
		sc.close();
	}

	public static void main(String[] args) throws Exception {
		(new ProblemC()).doMain();
	}
}