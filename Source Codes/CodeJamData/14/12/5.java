import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class ProblemB {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int T = in.nextInt();
		for (int cn = 1 ; cn <= T ; cn++) {
			int N = in.nextInt();
			int[][] edges = new int[N-1][2];
			for (int i = 0 ; i < N-1 ; i++) {
				edges[i][0] = in.nextInt()-1;
				edges[i][1] = in.nextInt()-1;
			}
			out.println(String.format("Case #%d: %d", cn, solve(edges)));
		}
		out.flush();
	}
	
	private static int solve(int[][] edges) {
		int N = edges.length+1;
		int max = Integer.MAX_VALUE;

		List<Integer>[] graph = new List[N];
		for (int i = 0 ; i < N ; i++) {
			graph[i] = new ArrayList<Integer>();
		}
		for (int i = 0 ; i < N-1 ; i++) {
			int a = edges[i][0];
			int b = edges[i][1];
			graph[a].add(b);
			graph[b].add(a);
		}

		_graph = graph;
		childCount = new int[N];
		for (int i = 0 ; i < N ; i++) {
			Arrays.fill(childCount, -1);
			childCount(i, -1);
			
			max = Math.min(max, dfs(i, -1));
		}
		return max;
	}
	

	static List<Integer>[] _graph;
	
	static int[] childCount;
	
	public static int childCount(int now, int parent) {
		if (childCount[now] != -1) {
			return childCount[now];
		}
		childCount[now] = 0;
		for (int to : _graph[now]) {
			if (to != parent) {
				childCount[now] += childCount(to, now) + 1;
			}
		}
		return childCount[now];
	}

	private static int dfs(int now, int parent) {
		List<Integer> dec = new ArrayList<Integer>();
		int total = childCount[now];
		for (int to : _graph[now]) {
			if (to != parent) {
				int make = dfs(to, now);
				dec.add(make - (childCount[to]+1));
			}
		}
		Collections.sort(dec);
		if (dec.size() >= 2) {
			total += dec.get(0);
			total += dec.get(1);
		}
		return total;
	}

	public static void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}
}
