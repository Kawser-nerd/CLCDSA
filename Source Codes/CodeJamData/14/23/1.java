import java.io.*;
import java.util.*;

public class BoredTSP {

	FastScanner in;
	PrintWriter out;

	List<Integer>[] graph;

	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		final int[] code = new int[n];
		for (int i = 0; i < n; i++) {
			code[i] = in.nextInt();
		}

		graph = new List[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int from = in.nextInt() - 1, to = in.nextInt() - 1;
			graph[from].add(to);
			graph[to].add(from);
		}
		Comparator<Integer> codeComp = new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return Integer.compare(code[o1], code[o2]);
			}
		};

		for (int i = 0; i < n; i++) {
			Collections.sort(graph[i], codeComp);
		}

		int[] best = null;
		for (int start = 0; start < n; start++) {
			int[] cur = new int[n];
			List<Integer> stack = new ArrayList<>();
			boolean[] vis = new boolean[n];

			vis[start] = true;
			stack.add(start);
			cur[0] = start;
			
			boolean ok = true;

			for (int pos = 1; pos < n; pos++) {
				List<Integer> neighbors = new ArrayList<>();

				for (int i : stack) {
					for (int j : graph[i]) {
						if (!vis[j]) {
							neighbors.add(j);
						}
					}
				}

				Collections.sort(neighbors, codeComp);
				
				boolean can = false;

				for (int i : neighbors) {
					List<Integer> newStack = new ArrayList<>(stack);

					while (!graph[newStack.get(newStack.size() - 1)].contains(i)) {
						newStack.remove(newStack.size() - 1);
					}
				
					
					newStack.add(i);
					
					boolean[] newVis = vis.clone();
					newVis[i] = true;
					
					if (can(newStack, newVis)) {
						vis = newVis;
						stack = newStack;
						cur[pos] = i;
						can = true;
						break;
					}
				}
				if (!can) {
					ok = false;
					break;
				}
			}
			
			if (ok) {
				if (best == null) {
					best = cur;
				} else {
					for (int i = 0; i < n; i++) {
						if (code[best[i]] < code[cur[i]]) {
							break;
						} else if (code[best[i]] > code[cur[i]]) {
							best = cur;
							break;
						}
					}
				}
			}
		}
		for (int i : best) {
			out.print(code[i]);
		}
		out.println();
	}
	
	
	boolean[] curVis;

	private boolean can(List<Integer> newStack, boolean[] newVis) {
		this.curVis = newVis.clone();
		for (int i : newStack) {
			go(i);
		}
		
		for (int i = 0; i < graph.length; i++) {
			if (!curVis[i]) {
				return false;
			}
		}
		return true;
	}
	
	void go(int u) {
		curVis[u] = true;
		for (int v : graph[u]) {
			if (!curVis[v]) {
				go(v);
			}
		}
	}

	void run() {
		try {
			in = new FastScanner("input.txt");
			out = new PrintWriter("output.txt");
			int T = in.nextInt();
			for (int i = 1; i <= T; i++) {
				long time = System.currentTimeMillis();
				out.printf("Case #%d: ", i);
				solve();
				System.err.println("Test #" + i + " done in " + (System.currentTimeMillis() - time)
						+ " ms");
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
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
	}

	public static void main(String[] args) {
		new BoredTSP().run();
	}
}
