import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

class Main implements Runnable {

	ArrayList<Integer>[] g;
	int[] deg;
	int n;
	int[] a, b;
	int A, B;

	public void run() {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		a = new int[n - 1];
		b = new int[n - 1];
		deg = new int[n];
		g = new ArrayList[n];
		for (int i = 0; i < n; ++i)
			g[i] = new ArrayList();
		for (int i = 0; i < n - 1; ++i) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			--a[i];
			--b[i];
			++deg[a[i]];
			++deg[b[i]];
			g[a[i]].add(b[i]);
			g[b[i]].add(a[i]);
		}
		A = 0;
		for (int i = 0; i < n; ++i) {
			if (deg[i] % 2 == 1)
				++A;
		}
		A /= 2;
		int ok = n - 1;
		int ng = 0;
		while (ok - ng > 1) {
			int middle = (ok + ng) / 2;
			if (check(middle)) {
				ok = middle;
			} else {
				ng = middle;
			}
		}
		System.out.println(A + " " + ok);
		sc.close();
	}

	boolean check(int B_) {
		int p = dfs(0, -1, B_);
		if (p <= B_)
			return true;
		else
			return false;
	}

	int dfs(int cur, int par, int B_) {
		ArrayList<Integer> pnd = new ArrayList<>();
		for (int dst : g[cur]) {
			if (dst == par)
				continue;
			int insert = dfs(dst, cur, B_);
			if (insert > B_)
				return insert;
			pnd.add(insert);
		}
		if (deg[cur] % 2 == 1)
			pnd.add(0);
		if (cur == 0)
			pnd.add(B_ - 1);
		Collections.sort(pnd);
		int ng = -1;
		int ok = pnd.size();
		loop1: while (ok - ng > 1) {
			int middle = (ok + ng) / 2;
			int s = 0;
			int t = pnd.size() - 1;
			if (s == middle)
				++s;
			if (t == middle)
				--t;
			while (t - s > 0) {
				if (pnd.get(s) + pnd.get(t) > B_) {
					ng = middle;
					continue loop1;
				}
				++s;
				--t;
				if (s == middle)
					++s;
				if (t == middle)
					--t;
			}
			ok = middle;
		}
		if (ok == pnd.size()) {
			return B_ + 1;
		}
		return pnd.get(ok) + 1;
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	public static void main(String[] args) throws FileNotFoundException {
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.