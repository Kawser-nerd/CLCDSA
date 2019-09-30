import java.util.*;
import java.io.*;

public class D {
	
	int n;
	int[] t;
	ArrayList<Integer>[] inside;
	boolean[][] graph;
	boolean[][] hasInside;
	
	private void solve() throws Exception {
		int k = nextInt();
		n = nextInt();
		//k = 1;
		//n = 200;
		int[] keyCounts = new int[200];
		for (int i = 0; i < k; ++i) {
			++keyCounts[nextInt() - 1];
			//++keyCounts[199];
		}
		t = new int[n];
		inside = new ArrayList[n];
		hasInside = new boolean[n][200];
		for (int i = 0; i < n; ++i) {
			/*t[i] = i;
			inside[i] = new ArrayList<>();
			inside[i].add((i - 1 + 200) % 200);*/
			t[i] = nextInt() - 1;
			inside[i] = new ArrayList<>();
			for (int j = nextInt(); j > 0; --j) {
				inside[i].add(nextInt() - 1);
			}
			for (int a : inside[i]) {
				hasInside[i][a] = true;
			}
		}
		graph = new boolean[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				graph[i][j] = hasInside[i][t[j]];
			}
		}
		boolean[] isOpen = new boolean[n];
		if (!canWin(isOpen.clone(), keyCounts.clone())) {
			out.println("IMPOSSIBLE");
			return;
		}
		for (int it = 0; it < n; ++it) {
			for (int i = 0; i < n; ++i) {
				if (!isOpen[i] && keyCounts[t[i]] > 0) {
					open(i, isOpen, keyCounts);
					if (canWin(isOpen.clone(), keyCounts.clone())) {
						out.print((i + 1) + " ");
						break;
					}
					close(i, isOpen, keyCounts);
				}
			}
		}
		out.println();
	}

	private boolean canWin(boolean[] isOpen, int[] keyCounts) {
		int closeCount = 0;
		for (boolean o : isOpen) {
			if (!o) {
				++closeCount;
			}
		}
		boolean[] visited = new boolean[n];
		outer: for (int it = 0; it < closeCount; ++it) {
			for (int i = 0; i < n; ++i) {
				if (isOpen[i] || keyCounts[t[i]] == 0) {
					continue;
				}
				Arrays.fill(visited, false);
				if (canReach(i, t[i], isOpen, visited)) {
					open(i, isOpen, keyCounts);
					continue outer;
				}
				int cnt = 1;
				for (int j = i + 1; j < n; ++j) {
					if (!isOpen[j] && t[j] == t[i]) {
						++cnt;
					}
				}
				if (cnt <= keyCounts[t[i]]) {
					open(i, isOpen, keyCounts);
					continue outer;
				}
			}
			return false;
		}
		return true;
	}

	private boolean canReach(int v, int type, boolean[] isOpen, boolean[] visited) {
		if (hasInside[v][type]) {
			return true;
		}
		visited[v] = true;
		for (int i = 0; i < n; ++i) {
			if (graph[v][i] && !isOpen[i] && !visited[i]) {
				if (canReach(i, type, isOpen, visited)) {
					return true;
				}
			}
		}
		return false;
	}

	Map<Integer, Boolean> canWin;

	private void open(int ind, boolean[] isOpen, int[] keyCounts) {
		if (keyCounts[t[ind]] <= 0) {
			throw new RuntimeException();
		}
		isOpen[ind] = true;
		--keyCounts[t[ind]];
		for (int a : inside[ind]) {
			++keyCounts[a];
		}
	}
	private void close(int ind, boolean[] isOpen, int[] keyCounts) {
		for (int a : inside[ind]) {
			if (keyCounts[a] <= 0) {
				throw new RuntimeException();
			}
			--keyCounts[a];
		}
		isOpen[ind] = false;
		++keyCounts[t[ind]];
	}

	public void run() {
		try {
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private D(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		new D("D").run();
		System.err.println("Done in " + (System.currentTimeMillis() - start) + "ms");
	}
}
