import java.util.*;
import java.io.*;

public class Tree implements Runnable {
	private final String problemID = getClass().getName();
	private final String problemType = "big";
	private BufferedReader in;
	private PrintWriter out;
	private int inf = Integer.MAX_VALUE / 4;
	
	private class TreeNode {
		public int value;
		public int op;
		public boolean changable;
		public int[] ans;
		public TreeNode left, right;

		public TreeNode(String descr, boolean isLeaf) {
			StringTokenizer st = new StringTokenizer(descr);
			ans = new int[2];
			ans[0] = ans[1] = inf;
			if (!isLeaf) {
				op = Integer.parseInt(st.nextToken());
				changable = (Integer.parseInt(st.nextToken()) == 1);
			} else {
				op = -1;
				changable = false;
				value = Integer.parseInt(st.nextToken());
			}
		}

		public void calc() {
			if (op == -1) {
				ans[value] = 0;
				ans[1 - value] = inf;
				return;
			}
			left.calc();
			right.calc();
			value = (op == 0) ? left.value | right.value : left.value & right.value;
			ans[value] = 0;
			
			for (int u = 0; u < 2; u++) {
				for (int v = 0; v < 2; v++) {
					int num = left.ans[u] + right.ans[v];
					if (num >= inf) {
						continue;
					}
					int cur = (op == 0) ? u | v : u & v;
					ans[cur] = Math.min(ans[cur], num);
				}
			}

			if (changable) {
				for (int u = 0; u < 2; u++) {
					for (int v = 0; v < 2; v++) {
						int num = left.ans[u] + right.ans[v] + 1;
						if (num >= inf) {
							continue;
						}
						int cur = (op == 1) ? u | v : u & v;
						ans[cur] = Math.min(ans[cur], num);
					}
				}
			}
		}
	}
	
	private void solveSingleTest(int testNumber) throws IOException {
		StringTokenizer st = new StringTokenizer(in.readLine());
		int m = Integer.parseInt(st.nextToken());
		int v = Integer.parseInt(st.nextToken());
		TreeNode[] nodes = new TreeNode[m + 1];
		for (int i = 1; i <= m; i++) {
			nodes[i] = new TreeNode(in.readLine(), i > (m - 1) / 2);
		}
		for (int i = 1; i <= (m - 1) / 2; i++) {
			nodes[i].left = nodes[2 * i];
			nodes[i].right = nodes[2 * i + 1];
		}
		nodes[1].calc();
		out.println("Case #" + testNumber + ": " + (nodes[1].ans[v] >= inf ? "IMPOSSIBLE" : "" + nodes[1].ans[v]));
	}
	
	public static void main(String[] args) {
		new Thread(new Tree()).start();
	}

	public void run() {
		try {
			solve();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	private void solve() throws IOException {
		in = new BufferedReader(new FileReader(new File(problemID + "_" + problemType + ".in")));
		out = new PrintWriter(new File(problemID + "_" + problemType + ".out"));
		
		int testsNumber = Integer.parseInt(in.readLine());
		for (int i = 0; i < testsNumber; i++) {
			solveSingleTest(i + 1);
		}
		
		in.close();
		out.close();
	}
}
