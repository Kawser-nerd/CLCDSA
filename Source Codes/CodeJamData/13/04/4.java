import static java.lang.System.currentTimeMillis;

import java.io.*;
import java.util.*;

public class D {

	static void solveMultiTest() throws IOException {
		int testCases = nextInt();
		for (int testCase = 1; testCase <= testCases; testCase++) {
			out.print("Case #" + testCase + ": ");
			long time = currentTimeMillis();
			solveOneTest();
			time = currentTimeMillis() - time;
			System.err.print("solved "+testCase+"/"+testCases);
			if (time > 1000) {
				System.err.print(" time: "+time);
			}
			System.err.println();
		}
	}

	static void addAll(Map<Integer, Integer> keyId, int[] array) {
		for (int element : array) {
			if (!keyId.containsKey(element)) {
				keyId.put(element, keyId.size());
			}
		}
	}

	static void solveOneTest() throws IOException {
		int numberOfKeysWeHave = nextInt();
		int numberOfChests = nextInt();
		int[] keysHaveInitially = new int[numberOfKeysWeHave];
		for (int i = 0; i < numberOfKeysWeHave; i++) {
			keysHaveInitially[i] = nextInt();
		}
		int[] chestRequires = new int[numberOfChests];
		int[][] chestContains = new int[numberOfChests][];
		for (int i = 0; i < numberOfChests; i++) {
			chestRequires[i] = nextInt();
			chestContains[i] = new int[nextInt()];
			for (int j = 0; j < chestContains[i].length; j++) {
				chestContains[i][j] = nextInt();
			}
		}
		Map<Integer, Integer> keyId = new HashMap<>();
		addAll(keyId, keysHaveInitially);
		addAll(keyId, chestRequires);
		for (int[] arr : chestContains) {
			addAll(keyId, arr);
		}
		int[] keyCountHaveInitially = new int[keyId.size()];
		for (int key : keysHaveInitially) {
			++keyCountHaveInitially[keyId.get(key)];
		}
		for (int i = 0; i < chestRequires.length; i++) {
			chestRequires[i] = keyId.get(chestRequires[i]);
		}
		for (int i = 0; i < chestContains.length; i++) {
			int[] count = new int[keyId.size()];
			for (int key : chestContains[i]) {
				++count[keyId.get(key)];
			}
			chestContains[i] = count;
		}

		boolean[] opened = new boolean[numberOfChests];

		if (!canOpenAllChests(keyCountHaveInitially.clone(), chestRequires,
				chestContains, opened.clone())) {
			out.println("IMPOSSIBLE");
			return;
		}

		int[] answer = new int[numberOfChests];
		System.err.println("TEST");

		for (int openedChests = 0; openedChests < numberOfChests; openedChests++) {
			boolean foundChest = false;
			for (int chest = 0; chest < numberOfChests; chest++) {
				if (opened[chest]
						|| keyCountHaveInitially[chestRequires[chest]] == 0) {
					continue;
				}
				boolean[] newOpened = opened.clone();
				newOpened[chest] = true;
				int[] newKeyCount = keyCountHaveInitially.clone();
				--newKeyCount[chestRequires[chest]];
				add(newKeyCount, chestContains[chest]);
				boolean stillOK = canOpenAllChests(newKeyCount, chestRequires,
						chestContains, newOpened);
				if (stillOK) {
					// System.err.println("open chest "+chest);
					answer[openedChests] = chest;
					--keyCountHaveInitially[chestRequires[chest]];
					add(keyCountHaveInitially, chestContains[chest]);
					opened[chest] = true;
					foundChest = true;
					break;
				}
			}
			if (!foundChest) {
				throw new AssertionError();
			}
		}
		for (int i = 0; i < numberOfChests; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(answer[i] + 1);
		}
		out.println();
	}

	private static boolean canOpenAllChests(int[] keyCountHaveInitially,
			int[] chestRequires, int[][] chestContains, boolean[] opened) {
		while (!allOpened(opened)) {
			int chests = chestRequires.length;
			boolean[][] graph = new boolean[chests][chests];
			for (int i = 0; i < chests; i++) {
				for (int j = 0; j < chests; j++) {
					if (!opened[i] && !opened[j]) {
						graph[i][j] = chestContains[i][chestRequires[j]] > 0;
					}
				}
			}
			StronglyConnectedComponentsFinder.graph = graph;
			int[] component = new int[chests];
			int componentsCount = StronglyConnectedComponentsFinder
					.findComponents(graph, component);
			boolean[] useless = new boolean[componentsCount];
			for (int i = 0; i < chests; i++) {
				if (opened[i]) {
					useless[component[i]] = true;
				}
			}
			boolean[] hasIncomingEdge = calculateHasIncomingEdge(component,
					componentsCount, graph);
			boolean[] canEat = new boolean[componentsCount];

			for (int i = 0; i < chests; i++) {
				if (opened[i]) {
					continue;
				}
				if (keyCountHaveInitially[chestRequires[i]] > 0) {
					canEat[component[i]] = true;
				}
			}
			for (int i = 0; i < componentsCount; i++) {
				if (useless[i]) {
					continue;
				}
				if (hasIncomingEdge[i]) {
					continue;
				}
				if (!canEat[i]) {
					return false;
				}
			}
			for (int i = 0; i < chests; i++) {
				if (opened[i]) {
					continue;
				}
				if (!hasIncomingEdge[component[i]] && keyCountHaveInitially[chestRequires[i]] > 0) {
					add(keyCountHaveInitially, chestContains[i]);
					--keyCountHaveInitially[chestRequires[i]];
					opened[i] = true;
					hasIncomingEdge[component[i]] = true;
				}
			}
		}
		return true;
	}

	private static boolean allOpened(boolean[] opened) {
		for (int i = 0; i < opened.length; i++) {
			if (!opened[i]) {
				return false;
			}
		}
		return true;
	}

	private static void add(int[] keyCountHaveInitially, int[] is) {
		for (int i = 0; i < keyCountHaveInitially.length; i++) {
			keyCountHaveInitially[i] += is[i];
		}
	}

	private static boolean[] calculateHasIncomingEdge(
			int[] stronglyConnectedComponent, int componentsCount,
			boolean[][] graph) {
		boolean[] hasIncomingEdge = new boolean[componentsCount];
		int n = graph.length;
		for (int i = 0; i < n; i++) {
			int u = stronglyConnectedComponent[i];
			if (hasIncomingEdge[u]) {
				continue;
			}
			for (int j = 0; j < n; j++) {
				if (graph[j][i] && stronglyConnectedComponent[j] != u) {
					hasIncomingEdge[u] = true;
					break;
				}
			}
		}
		return hasIncomingEdge;
	}

	static class StronglyConnectedComponentsFinder {
		static boolean[][] graph;
		static boolean[] visited;
		static int[] order;
		static int[] component;
		static int n;

		static int findComponents(boolean[][] graph,
				int[] stronglyConnectedComponent) {
			StronglyConnectedComponentsFinder.graph = graph;
			StronglyConnectedComponentsFinder.component = stronglyConnectedComponent;
			n = stronglyConnectedComponent.length;
			order = new int[n];
			visited = new boolean[n];

			time = 0;
			for (int i = 0; i < n; i++) {
				if (!visited[i]) {
					dfs1(i);
				}
			}

			Arrays.fill(visited, false);
			time = 0;

			for (int i = n - 1; i >= 0; --i) {
				int u = order[i];
				if (!visited[u]) {
					dfs2(u);
					time++;
				}
			}
			return time;
		}

		private static void dfs2(int u) {
			visited[u] = true;
			component[u] = time;
			for (int v = 0; v < n; v++) {
				if (!graph[v][u] || visited[v]) {
					continue;
				}
				dfs2(v);
			}
		}

		static int time;

		private static void dfs1(int u) {
			visited[u] = true;
			for (int v = 0; v < n; v++) {
				if (!graph[u][v] || visited[v]) {
					continue;
				}
				dfs1(v);
			}
			order[time++] = u;
		}

	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("d.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream(new File("d.out"));
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solveMultiTest();
		out.close();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
}
