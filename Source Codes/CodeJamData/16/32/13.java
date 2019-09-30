import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class R1CQ2 {

	public static void main(String[] args) {
		try {
			String fileName = "B-small-attempt0";
			Scanner in = new Scanner(new File(fileName + ".in"));
			PrintWriter out = new PrintWriter(fileName + ".out");
			int numberOfTestCases = Integer.parseInt(in.nextLine());
			for (int caseNum = 1; caseNum <= numberOfTestCases; caseNum++) {
				String str = in.nextLine();
				int B = Integer.parseInt(str.substring(0, str.indexOf(" ")));
				int M = Integer.parseInt(str.substring(str.indexOf(" ") + 1));
				boolean[][] result = iterateAllGraphs(B, M);
				if (result == null) {
					out.println("Case #" + caseNum + ": IMPOSSIBLE");
				} else {
					out.println("Case #" + caseNum + ": POSSIBLE");
					for (int i = 0; i < result.length; i++) {
						String line = "";
						for (int j = 0; j < result.length; j++) {
							if (result[i][j]) {
								line += "1";
							} else {
								line += "0";
							}
						}
						out.println(line);
					}
				}
			}
			in.close();
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

	public static boolean[][] iterateAllGraphs(int nodeCount, int paths) {
		int n = (int) Math.pow((nodeCount - 1), 2);
		for (int a = 0; a < Math.pow(2, n); a++) {
			String bin = Integer.toBinaryString(a);
			while (bin.length() < n)
				bin = "0" + bin;
			char[] chars = bin.toCharArray();
			boolean[] boolArray = new boolean[n];
			for (int b = 0; b < chars.length; b++) {
				boolArray[b] = chars[b] == '0' ? true : false;
			}
			boolean[][] graph = new boolean[nodeCount][nodeCount];
			int counter = 0;
			for (int i = 0; i < graph.length - 1; i++) {
				for (int j = 1; j < graph.length; j++) {
					graph[i][j] = boolArray[counter];
					counter++;
				}
			}
			//System.out.println(Arrays.deepToString(graph));
			if (isAcylic(graph) && countPaths(graph) == paths) {
				return graph;
			}
		}
		return null;
	}

	public static boolean isAcylic(boolean[][] graph) {
		final boolean[][] copy = new boolean[graph.length][];
		for (int i = 0; i < graph.length; i++) {
			copy[i] = Arrays.copyOf(graph[i], graph[i].length);
		}
		Stack<Integer> nodesNoIncoming = new Stack<>();
		for (int j = 0; j < copy.length; j++) {
			if (noIncoming(copy, j)) {
				nodesNoIncoming.add(j);
			}
		}
		while (!nodesNoIncoming.isEmpty()) {
			int node = nodesNoIncoming.pop();
			for (int j = 0; j < copy.length; j++) {
				if (copy[node][j]) {
					copy[node][j] = false;
					if (noIncoming(copy, j)) {
						nodesNoIncoming.push(j);
					}
				}
			}
		}
		for (int i = 0; i < copy.length; i++) {
			for (int j = 0; j < copy.length; j++) {
				if (copy[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

	private static boolean noIncoming(boolean[][] graph, int node) {
		for (int i = 0; i < graph.length; i++) {
			if (graph[i][node]) {
				return false;
			}
		}
		return true;
	}

	public static int countPaths(boolean[][] graph) {
		int[] pathCount = new int[graph.length];
		for (int i = 0; i < pathCount.length; i++) {
			pathCount[i] = -1;
		}
		return dfs(0, graph.length - 1, graph, pathCount);
	}

	private static int dfs(int start, int target, boolean[][]graph, int[] pathCount) {
		if (start == target) {
			return 1;
		}
		if (pathCount[start] < 0) {
			pathCount[start] = 0;
			for (int i = 0; i < graph[start].length; i++) {
				if (graph[start][i]) {
					pathCount[start] += dfs(i, target, graph, pathCount);
				}
			}
		}
		return pathCount[start];
	}

}
