import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Locale;
import java.util.Queue;
import java.util.Scanner;

public class ProblemC2 {

	public static void solve(Scanner sc) {
		int N = sc.nextInt();
		ArrayList<Node> nodes = new ArrayList<>();
		HashMap<String, Node> wordNodesIn = new HashMap<>();
		HashMap<String, Node> wordNodesOut = new HashMap<>();
		sc.nextLine();
		for (int i = 0; i < N; i++) {
			Node curr = new Node(i + "");
			nodes.add(curr);
			String sentence = sc.nextLine();
			String[] words = sentence.split(" ");
			for (String word : words) {
				if (wordNodesIn.get(word) == null) {
					Node in = new Node(word + "-in");
					Node out = new Node(word + "-out");
					Edge e1 = new Edge(in, out, 1);
					Edge e2 = new Edge(out, in, 0);
					e1.dual = e2;
					e2.dual = e1;
					in.edges.add(e1);
					out.edges.add(e2);
					wordNodesIn.put(word, in);
					wordNodesOut.put(word, out);
				}
				// edge to word-in
				Node tar = wordNodesIn.get(word);
				Edge e1 = new Edge(curr, tar, 1);
				Edge e2 = new Edge(tar, curr, 0);
				e1.dual = e2;
				e2.dual = e1;
				curr.edges.add(e1);
				tar.edges.add(e2);

				// edge from word-out
				Node src = wordNodesOut.get(word);
				Edge e3 = new Edge(src, curr, 1);
				Edge e4 = new Edge(curr, src, 0);
				e3.dual = e4;
				e4.dual = e3;
				src.edges.add(e3);
				curr.edges.add(e4);
			}
		}
		
		nodes.addAll(wordNodesIn.values());
		nodes.addAll(wordNodesOut.values());
		System.out.println(PushRelabel.getMaxFlow(nodes, nodes.get(0),
				nodes.get(1)));
	}

	public static void main(String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner(new File("C-practice.in"));
//		 Scanner sc = new Scanner(new File("C-small-attempt1.in"));
		 Scanner sc = new Scanner(new File("C-large (1).in"));
		// sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
	}

	static class PushRelabel {
		static void push(Edge e) {
			int send = Math.min(e.start.excess, e.capacity - e.flow);
			e.flow += send;
			e.dual.flow -= send;
			e.start.excess -= send;
			e.end.excess += send;
		}

		static void relabel(Node u, int[] count) {
			count[u.height]--;
			int min_height = Integer.MAX_VALUE;
			for (Edge e : u.edges) {
				if (e.capacity - e.flow > 0) {
					min_height = Math.min(min_height, e.end.height);
				}
			}
			u.height = min_height + 1;
			count[u.height]++;
		}

		static void gap(int h, Collection<Node> graph, int[] count) {
			int nodes = graph.size();
			for (Node v : graph) {
				if (v.height < h || v.height >= nodes)
					continue;
				count[v.height]--;
				v.height = nodes + 1;
				count[v.height]++;
			}
		}

		/**
		 * assumes that no zero edges or self loops are present.
		 * 
		 * @param graph
		 * @param source
		 * @param sink
		 * @return
		 */
		static int getMaxFlow(Collection<Node> graph, Node source, Node sink) {
			int nodes = graph.size();
			int[] count = new int[2 * nodes];

			count[nodes] = 1;
			count[0] = 1;

			source.height = nodes;
			source.excess = Integer.MAX_VALUE;

			// BFS for initial heights
			Node[] bfsQueue = new Node[nodes];
			int first = 0;
			int last = 1;
			bfsQueue[0] = sink;
			sink.active = true;
			while (first != last) {
				Node v = bfsQueue[first++];
				for (Edge e : v.edges) {
					Node w = e.end;
					if (w != source && !w.active) {
						w.height = v.height + 1;
						count[w.height]++;
						w.active = true;
						bfsQueue[last++] = w;
					}
				}
			}

			// determine active nodes
			Queue<Node> activeNodes = new LinkedList<>();
			// reset active
			for (Node n : graph) {
				n.active = false;
			}
			// hack so that they will never be added to the queue
			source.active = sink.active = true;

			for (Edge e : source.edges) {
				push(e);
				if (!e.end.active) {
					activeNodes.add(e.end);
					e.end.active = true;
				}
			}

			// work on active nodes
			while (!activeNodes.isEmpty()) {
				Node v = activeNodes.poll();
				v.active = false;

				// discharge
				if (v.it == null) {
					v.it = v.edges.listIterator();
				} else {
					// consider last edge again, might not be fully pushed
					v.it.previous();
				}
				while (v.excess > 0) {
					if (v.it.hasNext()) {
						Edge e = v.it.next();
						Node w = e.end;
						if ((e.capacity - e.flow > 0) && (v.height > w.height)) {
							push(e);
							if (!w.active) {
								w.active = true;
								activeNodes.add(w);
							}
						}
					} else {
						if (v.height > 0 && v.height < nodes && count[v.height] == 1)
							gap(v.height, graph, count);
						else
							relabel(v, count);
						v.it = v.edges.listIterator();
					}
				}
			}
			return sink.excess;
		}

	}

	static class Node {
		LinkedList<Edge> edges = new LinkedList<>();
		ListIterator<Edge> it = null;

		String id;
		int excess;
		int height;

		// for initial bfs as "visited", later as "is an active node"
		boolean active;

		Node(String id) {
			this.id = id;
		}

		@Override
		public String toString() {
			return id + ": excess " + excess + ", height " + height;
		}
	}

	static class Edge {
		Node start;
		Node end;
		int capacity;
		int flow;
		Edge dual;

		public Edge(Node start, Node end, int capacity) {
			this.start = start;
			this.end = end;
			this.capacity = capacity;
		}
		
		@Override
		public String toString() {
			return "From: " + start + "\nTo: " + end + "\nCap: " + capacity;
		}
	}
}
