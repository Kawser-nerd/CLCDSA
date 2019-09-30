import java.io.*;
import java.util.*;

public class AIWar {

	ArrayList[] graph ;
	
	int ans1;
	int ans2;
	boolean[] used;
	int[] th;
	int n;
	
	void dfs(int k, int d) {
		if (k == 1) {
			int cur2 = 0;
			for (int i = 0; i < n; i++) {
				if (th[i] > 0 && !used[i])
					cur2++;
			}			
			if (d < ans1 || (d == ans1 && cur2 > ans2)) {
				ans1 = d;
				ans2 = cur2;
			}
			return;
		}
		if (d >= ans1)
			return;
		
		used[k] = true;
		for (Object i : graph[k])
			th[(Integer) i]++;
		
		for (Object i : graph[k]) {
			int j = (Integer) i;
			if (!used[j]) {
				dfs(j, d + 1);
			}
		}
		
		for (Object i : graph[k])
			th[(Integer) i]--;
		used[k] = false;
	}
	
	void solve() throws Exception {
		n = nextInt();
		int m = nextInt();
		graph = new ArrayList[n];
		for (int i = 0; i < n; i++)
			graph[i] = new ArrayList<Integer>();
		for (int i = 0; i < m; i++) {
			String s = nextToken();
			StringTokenizer st = new StringTokenizer(s, ", ");
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			graph[x].add(y);
			graph[y].add(x);
		}
		ans1 = Integer.MAX_VALUE;
		ans2 = Integer.MIN_VALUE;
		used = new boolean[n];
		th = new int[n];
		dfs(0, -1);	
		out.println(ans1 + " " + ans2);
	}

	void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			int tests = nextInt();
			for (int i = 0; i < tests; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;
	final String filename = new String("AIWar").toLowerCase();

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new AIWar().run();
	}

}
