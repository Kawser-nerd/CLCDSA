import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class D {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FastScanner input = new FastScanner();
		int n2 = input.nextInt();
		for (int x = 0; x < n2; x++) {
			int n = input.nextInt();
			int pieces = input.nextInt();

			char[][] arr = new char[n][n];
			for (int a = 0; a < pieces; a++) {
				char tmp = input.next().toCharArray()[0];
				arr[input.nextInt() - 1][input.nextInt() - 1] = tmp;
			}

			boolean[][] rook = new boolean[n][n];
			for (int a = 0; a < n; a++) {
				for (int b = 0; b < n; b++) {
					rook[a][b] = ((arr[a][b] == 'o') || (arr[a][b] == 'x')) ? true : false;
				}
			}

			boolean[][] bishop = new boolean[n][n];
			for (int a = 0; a < n; a++) {
				for (int b = 0; b < n; b++) {
					bishop[a][b] = ((arr[a][b] == 'o') || (arr[a][b] == '+')) ? true : false;
				}
			}

			MaxFlowSolver rookSolver = new AhujaOrlin();
			Node rookSource = rookSolver.addNode();
			Node rookSink = rookSolver.addNode();

			Node[] rookRow = new Node[n];
			Node[] rookCol = new Node[n];

			for (int a = 0; a < n; a++) {
				boolean rowFill = false;
				for (int b = 0; b < n; b++) {
					rowFill |= rook[a][b];
				}
				rookRow[a] = rookSolver.addNode();
				rookSolver.link(rookSource, rookRow[a], rowFill ? 0 : 1);
			}
			for (int a = 0; a < n; a++) {
				boolean colFill = false;
				for (int b = 0; b < n; b++) {
					colFill |= rook[b][a];
				}
				rookCol[a] = rookSolver.addNode();
				rookSolver.link(rookCol[a], rookSink, colFill ? 0 : 1);
			}
			for (int a = 0; a < n; a++) {
				for (int b = 0; b < n; b++) {
					rookSolver.link(rookRow[a], rookCol[b], 1);
				}
			}
			long rookFlow = rookSolver.getMaxFlow(rookSource, rookSink);
			boolean[][] resultRook = new boolean[n][n];
			for (int a = 0; a < n; a++) {
				for (int b = 0; b < n; b++) {
					if (rookRow[a].edges.get(b + 1).flow > 0) {
						resultRook[a][b] = true;
					}
				}
			}

			MaxFlowSolver bishopSolver = new AhujaOrlin();
			Node[][] flowNodes = new Node[n][n];
			for (int a = 0; a < n; a++) {
				for (int b = 0; b < n; b++) {
					flowNodes[a][b] = bishopSolver.addNode();
				}
			}
			Node bishopSource = bishopSolver.addNode();
			Node bishopSink = bishopSolver.addNode();
			for (int leftDiag = 0; leftDiag < n * 2 - 1; leftDiag++) {
				boolean blocked = false;
				for (int a = 0; a < n; a++) {
					for (int b = 0; b < n; b++) {
						if (a + b == leftDiag) {
							blocked = blocked | bishop[a][b];
						}
					}
				}
				Node tmp = bishopSolver.addNode();
				bishopSolver.link(bishopSource, tmp, blocked ? 0 : 1);

				for (int a = 0; a < n; a++) {
					for (int b = 0; b < n; b++) {
						if (a + b == leftDiag) {
							bishopSolver.link(tmp, flowNodes[a][b], 1);
						}
					}
				}
			}
			for (int rightDiag = -n; rightDiag <= n; rightDiag++) {
				boolean blocked = false;
				for (int a = 0; a < n; a++) {
					for (int b = 0; b < n; b++) {
						if (a - b == rightDiag) {
							blocked = blocked | bishop[a][b];
						}
					}
				}
				Node tmp = bishopSolver.addNode();
				bishopSolver.link(tmp, bishopSink, blocked ? 0 : 1);
				for (int a = 0; a < n; a++) {
					for (int b = 0; b < n; b++) {
						if (a - b == rightDiag) {
							bishopSolver.link(flowNodes[a][b], tmp, 1);
						}
					}
				}
			}
			bishopSolver.getMaxFlow(bishopSource, bishopSink);
			
			boolean[][] resultBishop = new boolean[n][n];
			for (int a = 0; a < n; a++) {
				for (int b = 0; b < n; b++) {
					long flowTotal =0 ;
					for(Edge i: flowNodes[a][b].edges){
						flowTotal += Math.max(0, i.flow);
					}
					if(flowTotal >= 1){
						resultBishop[a][b] = true;
					}
				}
			}
			
			ArrayList<String> outputs = new ArrayList<String>();
			for(int a = 0; a < n; a++){
				for(int b = 0; b < n; b++){
					if(resultBishop[a][b] || resultRook[a][b]){
						boolean diag = resultBishop[a][b] || bishop[a][b];
						boolean rowCol = resultRook[a][b] || rook[a][b];
						if(diag && rowCol){
							outputs.add("o " + (a+1) + " " + (b+1));
						}
						else if(diag){
							outputs.add("+ " + (a+1) + " " + (b+1));
						} else if(rowCol){
							outputs.add("x " + (a+1) + " " + (b+1));							
						}
					}
				}
			}
			
			long points = 0;
			for(int a =0 ; a < n; a++){
				for(int b =0 ; b < n; b++){
					if(resultBishop[a][b] && bishop[a][b]){
						throw new Error();
					}
					if(resultRook[a][b] && rook[a][b]){
						throw new Error();
					}
					points += resultBishop[a][b]?1:0;
					points += resultRook[a][b]?1:0;
					points += bishop[a][b]?1:0;
					points += rook[a][b]?1:0;
				}
			}
			
			System.out.println("Case #" + (x + 1) + ": " + points + " " + outputs.size());
			for(String i:outputs){
				System.out.println(i);
			}
		}
	}

	public static class Node {
		// thou shall not create nodes except through addNode()
		private Node() {
		}

		List<Edge> edges = new ArrayList<Edge>();
		int index; // index in nodes array

		// The following fields are needed only if the respective solvers
		// are being used. We include them here for improved spatial locality.
		// To avoid unnecessary memory consumption, be sure to remove
		// those fields that aren't used by the solver you are using
		//
		int dist; // PushRelabel, Dinic, and AhujaOrlin.
		int mindj; // AhujaOrlin
		int currentarc; // AhujaOrlin
		long minCapacity; // FordFulkerson, AhujaOrlin
	}

	public static class Edge {
		boolean forward; // true: edge is in original graph
							// false: edge is a backward edge
		Node from, to; // nodes connected
		long flow; // current flow
		final long capacity;
		Edge dual; // reference to this edge's dual
		long cost; // only used for MinCost.

		// thou shall not create edges except through link()
		protected Edge(Node s, Node d, long c, boolean f) {
			forward = f;
			from = s;
			to = d;
			capacity = c;
		}

		// remaining capacity()
		long remaining() {
			return capacity - flow;
		}

		// increase flow and adjust dual
		void addFlow(long amount) {
			flow += amount;
			dual.flow -= amount;
		}
	}

	/* A Max Flow solver base class. */
	public static abstract class MaxFlowSolver {
		/* List of nodes, indexed. */
		List<Node> nodes = new ArrayList<Node>();

		/* Create an edge between nodes n1 and n2 */
		public void link(Node n1, Node n2, long capacity) {
			/*
			 * Only the EdmondsKarp solver takes cost into account during
			 * getMaxFlow(). Setting it to 1 for problems that do not involve
			 * cost means it uses a shortest path search when finding augmenting
			 * paths. In practice, this does not seem to make a difference.
			 */
			link(n1, n2, capacity, 1);
		}

		/* Create an edge between nodes n1 and n2 and assign cost */
		public void link(Node n1, Node n2, long capacity, long cost) {
			Edge e12 = new Edge(n1, n2, capacity, true);
			Edge e21 = new Edge(n2, n1, 0, false);
			e12.dual = e21;
			e21.dual = e12;
			n1.edges.add(e12);
			n2.edges.add(e21);
			e12.cost = cost;
			e21.cost = -cost;
		}

		/* Create an edge between nodes n1 and n2 */
		void link(int n1, int n2, long capacity) {
			link(nodes.get(n1), nodes.get(n2), capacity);
		}

		/* Create a graph with n nodes. */
		protected MaxFlowSolver(int n) {
			for (int i = 0; i < n; i++)
				addNode();
		}

		protected MaxFlowSolver() {
			this(0);
		}

		public abstract long getMaxFlow(Node src, Node snk);

		/* Add a new node. */
		public Node addNode() {
			Node n = new Node();
			n.index = nodes.size();
			nodes.add(n);
			return n;
		}
	}

	/**
	 * Implements Ahuja/Orlin.
	 *
	 * Ahuja/Orlin describe this as an optimized variant of the original
	 * Edmonds-Karp shortest augmenting path algorithm.
	 *
	 * Ahuja, R. K. and Orlin, J. B. (1991), Distance-directed augmenting path
	 * algorithms for maximum flow and parametric maximum flow problems. Naval
	 * Research Logistics, 38: 413–430. doi:10.1002/1520-6750(199106)38:3
	 * <413::AID-NAV3220380310>3.0.CO;2-J and parametric maximum flow problems.
	 * This is algorithm DD1 in the paper.
	 */
	static class AhujaOrlin extends MaxFlowSolver {
		/* Create a graph with n nodes. */
		AhujaOrlin() {
			this(0);
		}

		AhujaOrlin(int n) {
			super(n);
		}

		@Override
		public long getMaxFlow(Node src, Node snk) {
			/**
			 * INITIALIZE. Perform a (reverse) breadth-first search of the
			 * residual network starting from the sink node to compute distance
			 * labels d(i).
			 */
			final int n = nodes.size();
			long totalFlow = 0;
			for (Node u : nodes) {
				u.dist = -1;
				u.mindj = n; // tracks min dist of children for relabeling
				u.currentarc = 0; // current active arc
			}

			int[] count = new int[n + 1]; // count[i] number of nodes u with
											// u.dist == i
			count[0]++; // count is used to bail as soon as maxflow is found

			Node[] Q = new Node[n]; // (Q, head, tail) are used as BFS queue
			int head = 0, tail = 0;
			snk.dist = 0;
			Q[tail++] = snk;
			while (head < tail) {
				Node x = Q[head++];
				for (Edge e : x.edges) {
					if (e.to.dist == -1) {
						e.to.dist = e.from.dist + 1;
						count[e.to.dist]++;
						Q[tail++] = e.to;
					}
				}
			}

			if (src.dist == -1) // no flow if source is not reachable
				return 0;

			src.minCapacity = Long.MAX_VALUE;
			Edge[] pred = new Edge[n]; // current augmenting path
			Node i = src; // i is the 'tip' of the augmenting path as in paper

			advance: while (src.dist < n) { // If d(s) >= n, then STOP.
				/*
				 * If the residual network contains an admissible arc (i, j),
				 * then set pred(j) := i If j = t then go to AUGMENT; otherwise,
				 * replace i by j and repeat ADVANCE(i).
				 */
				boolean augment = false;

				for (; i.currentarc < i.edges.size(); i.currentarc++) {
					Edge e = i.edges.get(i.currentarc);
					if (e.remaining() == 0) {
						continue;
					}

					Node j = e.to;
					i.mindj = min(i.mindj, j.dist + 1);

					/*
					 * an admissible edge (i, j) is one for which d(i) = d(j) +
					 * 1
					 */
					if (i.dist == j.dist + 1) {
						pred[j.index] = e;
						j.minCapacity = min(i.minCapacity, e.remaining());
						if (j == snk) {
							augment = true;
							break;
						} else {
							i = j;
							continue advance;
						}
					}
				}
				// either ran out of admissible edges, or reached snk and thus
				// are ready to augment

				if (!augment) {
					/*
					 * RETREAT: Update d(i): = min{d(j) + 1: rij > 0 and (i, j)
					 * \in A(i)}. If d(s) >= n, then STOP. Otherwise, if i = s
					 * then go to ADVANCE(i); else replace i by pred(i) and go
					 * to ADVANCE(i).
					 */

					// check if maximum flow was already reached. This is
					// indicated
					// if a distance level is missing (a 'gap')
					if (--count[i.dist] == 0 && i.dist < src.dist)
						break;
					// TBD: i.dist describeds a min cut

					i.dist = i.mindj; // relabel
					count[i.dist]++;

					i.currentarc = 0; // reset current arc on node (i)
					i.mindj = n;

					if (i != src)
						i = pred[i.index].from;
				} else {
					/*
					 * AUGMENT. Let sigma: = min{ri: (i, j) \in P}. Augment
					 * sigma units of flow along P. Set i = s and go to
					 * ADVANCE(i).
					 */
					long addedFlow = snk.minCapacity;
					for (Edge edge = pred[snk.index]; edge != null; edge = pred[edge.dual.to.index]) {
						edge.addFlow(addedFlow);
					}
					totalFlow += addedFlow;
					i = src; // start over at source
				}
			}
			return totalFlow;
		}
	}

	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(Reader in) {
			br = new BufferedReader(in);
		}

		public FastScanner() {
			this(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String readNextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

		int[] readIntArray(int n) {
			int[] a = new int[n];
			for (int idx = 0; idx < n; idx++) {
				a[idx] = nextInt();
			}
			return a;
		}

		long[] readLongArray(int n) {
			long[] a = new long[n];
			for (int idx = 0; idx < n; idx++) {
				a[idx] = nextLong();
			}
			return a;
		}
	}
}
