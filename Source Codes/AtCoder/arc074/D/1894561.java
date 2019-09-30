import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Optional;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static void main(String[] args){
		Main main = new Main();
		main.solveF();
	}

	private void solveF() {
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		sc.nextLine();
		final int SOURCE = 0;
		final int VERTEX_NUM = 2 + H + W;
		final int TARGET = VERTEX_NUM - 1;
		final int INF = Integer.MAX_VALUE / 3;
		// 1?H : ??????? H+1?H+W: ???????
		Graph graph = new ArrayGraph(VERTEX_NUM);
		for (int r = 0; r < H; r++) {
			String line = sc.nextLine();
			for (int c = 0; c < W; c++) {
				char asc = line.charAt(c);
				if (asc == 'o') {
					graph.link(r+1, H+1+c, 1);
					graph.link(H+1+c, r+1, 1);
				} else if (asc == 'S') {
					graph.link(SOURCE, r+1, INF);
					graph.link(SOURCE, H+1+c, INF);
				} else if (asc == 'T') {
					graph.link(r+1, TARGET, INF);
					graph.link(H+1+c, TARGET, INF);
				}
			}
		}
		FlowResolver fr = new BfsFlowResolver(graph);
		int ans = fr.maxFlow(SOURCE, TARGET);
		if (ans >= INF) {
			System.out.println(-1);
		} else {
			System.out.println(ans);
		}
	}

	private void solveC() {
		Scanner sc = new Scanner(System.in);
		long H = sc.nextLong();
		long W = sc.nextLong();
		long W_3 = W /3;
		long W_31 = W_3 + 1;
		long H_3 = H / 3;
		long H_31 = H_3 + 1;
		long W_2 = W / 2;
		long W_21 = W_2 + 1;
		long H_2 = H / 2;
		long H_21 = H_2 + 1;

		List<Long> areaList = new ArrayList<Long>();
		areaList.add(area(H * W_3, H * W_3, H * (W - 2 * W_3)));
		areaList.add(area(H * W_31, H * W_31, H * (W - 2 * W_31)));
		areaList.add(area(W * H_3, W * H_3, W * (H - 2 * H_3)));
		areaList.add(area(W * H_31, W * H_31, W * (H - 2 * H_31)));
		areaList.add(area(H * W_3, H_2 * (W - W_3), (H - H_2) * (W - W_3)));
		areaList.add(area(H * W_31, H_2 * (W - W_31), (H - H_2) * (W - W_31)));
		areaList.add(area(H * W_3, H_21 * (W - W_3), (H - H_21) * (W - W_3)));
		areaList.add(area(H * W_31, H_21 * (W - W_31), (H - H_21) * (W - W_31)));
		areaList.add(area(W * H_3, W_2 * (H - H_3), (W - W_2) * (H - H_3)));
		areaList.add(area(W * H_31, W_2 * (H - H_31), (W - W_2) * (H - H_31)));
		areaList.add(area(W * H_3, W_21 * (H - H_3), (W - W_21) * (H - H_3)));
		areaList.add(area(W * H_31, W_21 * (H - H_31), (W - W_21) * (H - H_31)));

		System.out.println(areaList.stream().min(Comparator.naturalOrder()).get());
	}

	private long area(long a, long b, long c) {
		if (a <= b && b <= c) {
			return c - a;
		}
		if (a <= c && c <= b) {
			return b - a;
		}
		if (b <= a && a <= c) {
			return c - b;
		}
		if (b <= c && c <= a) {
			return a - b;
		}
		if (c <= a && a <= b) {
			return b - c;
		}
		if (c <= b && b <= a) {
			return a - c;
		}
		return 0;
	}

	private void solveD() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		List<Long> list = new ArrayList<>();
		for (int i = 0; i < 3 * N; i++) {
			list.add(sc.nextLong());
		}

		List<Long> maxSumList = getSumList(list, new PriorityQueue<>(Comparator.naturalOrder()), N);
		Collections.reverse(list);
		List<Long> minSumList = getSumList(list, new PriorityQueue<>(Comparator.reverseOrder()), N);

		List<Long> scoreList = new ArrayList<>();
		for (int splitIndex = N; splitIndex <= 2 * N; splitIndex++) {
			scoreList.add(maxSumList.get(splitIndex - 1) - minSumList.get(3 * N - 1 - splitIndex));
		}
		System.out.println(scoreList.stream().max(Comparator.naturalOrder()).get());
	}

	private List<Long> getSumList(List<Long> list, PriorityQueue<Long> queue, int limitSize) {
		List<Long> sumList = new ArrayList<>();
		long sum = 0L;
		for (long value : list) {
			queue.add(value);
			sum += value;
			if (queue.size() > limitSize) {
				sum -= queue.remove();
			}
			sumList.add(sum);
		}
		return sumList;
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

	class BfsFlowResolver implements FlowResolver {
		private Graph graph;
		public BfsFlowResolver(Graph graph) {
			this.graph = graph;
		}
		public int maxFlow(int from, int to) {
			boolean finish = false;
			while (!finish) {
				Integer[] flows = new Integer[graph.getVertexNum()];
				flows[from] = Integer.MAX_VALUE / 3;
				Integer[] froms = new Integer[graph.getVertexNum()];
				boolean[] isPassed = new boolean[graph.getVertexNum()];
				finish = false;
				while (!finish) {
					finish = true;
					for (int id = 0; id < graph.getVertexNum(); id++) {
						if (flows[id] != null) {
							if (flow(id, flows, froms)) {
								finish = false;
							}
						}
					}
					if (flows[to] != null) {
						int to_i = to;
						while (froms[to_i] != null) {
							graph.link(froms[to_i], to_i, graph.getCost(froms[to_i], to_i).get() - flows[to]);
							graph.link(to_i, froms[to_i], graph.getCost(to_i, froms[to_i]).orElse(0) + flows[to]);
							to_i = froms[to_i];
						}
						finish = false;
						break;
					}
				}
			}
			int sum = 0;
			for (int id = 0; id < graph.getVertexNum(); id++) {
				sum += graph.getCost(to, id).orElse(0);
			}
			return sum;
		}
		public boolean flow(int from, Integer[] flows, Integer[] froms) {
			boolean change = false;
			for (int next = 0; next < graph.getVertexNum(); next++) {
				Optional<Integer> cost = graph.getCost(from, next);
				if (cost.orElse(0) > 0 && flows[next] == null) {
					int nextFlow = flows[from] < cost.get() ? flows[from] : cost.get();
					flows[next] = nextFlow;
					froms[next] = from;
					change = true;
				}
			}
			return change;
		}
	}

	/**
	 * IDDFS(??????????)?????
	 * ??????????2?????DFS(??????)?0????????
	 * ??Dinic????????O(E*V*V)??? (E:???, V:????)
	 */
	class IddfsFlowResolver implements FlowResolver {
		private Graph graph;
		public IddfsFlowResolver(Graph graph) {
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
			int limitDepth = 0;
			while (isExistFlow(from, to)) {
				int currentFlow = flow(from, to,Integer.MAX_VALUE / 3, 0, limitDepth);
				sum += currentFlow;
				if (currentFlow == 0) {
					limitDepth++;
				}
			}
			return sum;
		}

		/**
		 * ?????? ?????????
		 * @param from ???????ID
		 * @param to ??(target)?ID
		 * @param current_flow ???????
		 * @param depth ??(???)???
		 * @param limitDepth ????
		 * @return ??(target)??????/?????????
		 */
		private int flow(int from, int to, int current_flow, int depth, int limitDepth) {
			if (from == to) {
				return current_flow;
			}
			if (depth >= limitDepth) {
				return 0;
			}
			for (int id = 0; id < graph.getVertexNum(); id++) {
				Optional<Integer> cost = graph.getCost(from, id);
				if (cost.orElse(0) > 0) {
					int nextFlow = current_flow < cost.get() ? current_flow : cost.get();
					int returnFlow = flow(id, to, nextFlow, depth+1, limitDepth);
					if (returnFlow > 0) {
						graph.link(from, id, cost.get() - returnFlow);
						graph.link(id, from, graph.getCost(id, from).orElse(0) + returnFlow);
						return returnFlow;
					}
				}
			}
			return 0;
		}

		/**
		 * from??to?0?????????????
		 * @param from ??(source)?ID
		 * @param to ??(target)?ID
		 * @return 0??????true
		 */
		private boolean isExistFlow(int from, int to) {
			boolean[] passed = new boolean[graph.getVertexNum()];
			return search(from, to, passed);
		}

		/**
		 * ????????????????????DFS(??????)
		 * ??????O(V)??? (V:????)
		 * @param from ???????ID
		 * @param to ??(target)?ID
		 * @param passed ???????ID?true??????????
		 * @return to?0??????true
		 */
		private boolean search(int from, int to, boolean[] passed) {
			if (from == to) {
				return true;
			}
			passed[from] = true;
			for (int id = 0; id < graph.getVertexNum(); id++) {
				if (!passed[id] && graph.getCost(from, id).orElse(0) > 0 && search(id, to, passed)) {
					return true;
				}
			}
			return false;
		}
	}
}