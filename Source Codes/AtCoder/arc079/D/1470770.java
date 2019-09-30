import java.math.BigInteger;
import java.security.cert.CollectionCertStoreParameters;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	int[] f;
	boolean[] cycle;
	ArrayList<Integer>[] g;
	int n;
	int[] p;

	public void run() {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		p = new int[n];
		g = new ArrayList[n];
		cycle = new boolean[n];
		f = new int[n];
		for (int i = 0; i < n; ++i) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; ++i) {
			p[i] = sc.nextInt();
			--p[i];
			g[p[i]].add(i);
		}

		int v = 0;
		for (int i = 0; i < n; ++i) {
			v = p[v];
		}
		for (int i = 0; i < n; ++i) {
			cycle[v] = true;
			v = p[v];
		}
		Arrays.fill(f, -1);
		for (int i = 0; i < n; ++i) {
			if (!cycle[i] && f[i] == -1) {
				dfs(i);
			}
		}

		boolean ans = false;
		ArrayList<Integer> lis = new ArrayList<>();
		for (int dst : g[v]) {
			if (f[dst] != -1)
				lis.add(f[dst]);
		}
		ans |= solve(v, fgrundy(lis));
		ans |= solve(v, sgrundy(lis));
		System.out.println(ans ? "POSSIBLE" : "IMPOSSIBLE");
	}

	boolean solve(int v, int val) {
		int[] h = Arrays.copyOf(f, n);
		h[v] = val;
		for (int u = p[v]; u != v; u = p[u]) {
			ArrayList<Integer> lis = new ArrayList<>();
			for (int dst : g[u]) {
				lis.add(h[dst]);
			}
			h[u] = fgrundy(lis);
		}
		ArrayList<Integer> lis = new ArrayList<>();
		for (int d : g[v]) {
			lis.add(h[d]);
		}
		return fgrundy(lis) == val;
	}

	int sgrundy(ArrayList<Integer> lis) {
		lis.add(fgrundy(lis));
		return fgrundy(lis);
	}

	int fgrundy(ArrayList<Integer> lis) {
		Collections.sort(lis);
		if (lis.isEmpty() || lis.get(0) != 0)
			return 0;
		else {
			for (int i = 1; i < lis.size(); ++i) {
				if (lis.get(i - 1) + 1 < lis.get(i)) {
					return lis.get(i - 1) + 1;
				}
			}
			return lis.get(lis.size() - 1) + 1;
		}
	}

	void dfs(int cur) {
		ArrayList<Integer> lis = new ArrayList<>();
		for (int dst : g[cur]) {
			if (f[dst] == -1)
				dfs(dst);
			lis.add(f[dst]);
		}
		f[cur] = fgrundy(lis);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.