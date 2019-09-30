import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.solveE();
	}

	private void solveC() {
		Scanner sc = new Scanner(System.in);
		long X = sc.nextLong();
		long Y = sc.nextLong();
		int ans = 0;
		while (X <= Y) {
			X *= 2;
			ans++;
		}
		System.out.println(ans);
	}

	private void solveD() {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		int N = S.length();
		int ans;
		Character prev = null;
		for (ans = N / 2 + 1; ans <= N; ans++) {
			char right = S.charAt(ans - 1);
			char left = S.charAt(N - ans);
			if (left != right || (prev != null && prev != right)) {
				break;
			}
			prev = right;
		}
		System.out.println(ans - 1);
	}

	private void solveE() {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		int N = S.length();
		char[] array = S.toCharArray();
		Map<Character, Integer> map = new HashMap<>();
		for (int i = 0; i < N; i++) {
			char asc = array[i];
			if (!map.containsKey(asc)) {
				map.put(asc, 0);
			}
			map.put(asc, map.get(asc) + 1);
		}
		int oddNum = 0;
		int[] target = new int[N];
		Map<Character, List<Integer>> count = new HashMap<>();
		int left = 0;
		for (int i = 0; i < N; i++) {
			char asc = array[i];
			if (!count.containsKey(asc)) {
				count.put(asc, new ArrayList<>());
			}
			List<Integer> list = count.get(asc);
			int num = map.get(asc);
			if (list.size() < num / 2) {
				target[i] = left++;
			} else if (num % 2 == 1 && list.size() == (num - 1) / 2) {
				if (++oddNum > 1) {
					System.out.println(-1);
					return;
				}
				target[i] = N / 2;
			} else {
				target[i] = N - list.get(num - list.size() - 1) - 1;
			}
			list.add(target[i]);
		}
		BinaryIndexedTree bit = new BinaryIndexedTree(262144);
		long sum = 0;
		for (int i = 0; i < N; i++) {
			long tmp = bit.getSum(N - target[i] - 1);
			sum += tmp;
			bit.add(N - target[i] - 1, 1);
		}
		System.out.println(sum);
	}

	class BinaryIndexedTree {
		long[] array;
		int size;
		public BinaryIndexedTree(int size) {
			this.size = size;
			array = new long[size];
		}
		public void add(int index, long value) {
			int p = size;
			int d = size / 2;
			while (d > 0) {
				if (p - d > index) {
					array[p - 1] += value;
					p -= d;
				}
				d /= 2;
			}
			array[p - 1] += value;
		}
		public long getSum(int index) {
			int p = index + 1;
			long ret = array[p - 1];
			int a = 2;
			while (p - a / 2 - 1 >= 0) {
				if (p % a > 0) {
					p -= a / 2;
					ret += array[p - 1];
				}
				a *= 2;
			}
			return ret;
		}
		@Override
		public String toString() {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < size; i++) {
				sb.append(String.format("%3d", array[i]));
			}
			return sb.toString();
		}
	}

	private int countGreater(int[][] maxList, int level, int left, int base, int right, int[] pow) {
		int sum = 0;
		if (maxList[level][left] > base) {
			if (level == 0) {
				return 1;
			}
			if (pow[level - 1] * left * 2 < right) {
				sum += countGreater(maxList, level - 1, left * 2, base, right, pow);
			}
			if (pow[level - 1] * (left * 2 + 1) < right) {
				sum += countGreater(maxList, level - 1, left * 2 + 1, base, right, pow);
			}
		}
		return sum;
	}

	private void solveF() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		System.out.println(N);
	}

	interface Graph {
		void link(int from, int to, int cost);
		Optional<Integer> getCost(int from, int to);
		int getVertexNum();
	}

	interface FlowResolver {
		int maxFlow(int from, int to);
	}

	/**
	 * ???????????
	 * ??????????????MLE?????
	 */
	class ArrayGraph implements Graph {
		private Integer[][] costArray;
		private int vertexNum;

		public ArrayGraph(int n) {
			costArray = new Integer[n][];
			for (int i = 0; i < n; i++) {
				costArray[i] = new Integer[n];
			}
			vertexNum = n;
		}

		@Override
		public void link(int from, int to, int cost) {
			costArray[from][to] = new Integer(cost);
		}

		@Override
		public Optional<Integer> getCost(int from, int to) {
			return Optional.ofNullable(costArray[from][to]);
		}

		@Override
		public int getVertexNum() {
			return vertexNum;
		}
	}

	/**
	 * DFS(??????)?????
	 * ????O(E*MaxFlow)??? (E:???, MaxFlow:?????)
	 */
	class DfsFlowResolver implements FlowResolver {
		private Graph graph;
		public DfsFlowResolver(Graph graph) {
			this.graph = graph;
		}

		/**
		 * ?????(?????)????
		 * @param from ??(source)?ID
		 * @param to ??(target)?ID
		 * @return ?????(?????)
		 */
		public int maxFlow(int from, int to) {
			int sum = 0;
			int currentFlow;
			do {
				currentFlow = flow(from, to,Integer.MAX_VALUE / 3, new boolean[graph.getVertexNum()]);
				sum += currentFlow;
			} while (currentFlow > 0);
			return sum;
		}

		/**
		 * ?????? ?????????
		 * @param from ???????ID
		 * @param to ??(target)?ID
		 * @param current_flow ???????
		 * @param passed ?????????????????
		 * @return ??(target)??????/?????????
		 */
		private int flow(int from, int to, int current_flow, boolean[] passed) {
			passed[from] = true;
			if (from == to) {
				return current_flow;
			}
			for (int id = 0; id < graph.getVertexNum(); id++) {
				if (passed[id]) {
					continue;
				}
				Optional<Integer> cost = graph.getCost(from, id);
				if (cost.orElse(0) > 0) {
					int nextFlow = current_flow < cost.get() ? current_flow : cost.get();
					int returnFlow = flow(id, to, nextFlow, passed);
					if (returnFlow > 0) {
						graph.link(from, id, cost.get() - returnFlow);
						graph.link(id, from, graph.getCost(id, from).orElse(0) + returnFlow);
						return returnFlow;
					}
				}
			}
			return 0;
		}
	}
}