import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Edge {
		final int to;
		Edge pair;
		int capacity;
		
		Edge(int to, int capacity) {
			this.to = to;
			this.capacity = capacity;
		}
		
		void addFlow(int flow) {
			if ((capacity -= flow) < 0 || (pair.capacity += flow) < 0) {
//				throw new AssertionError();
			}
		}
		
		void addNonreversibleFlow(int flow) {
			if ((capacity -= flow) < 0) {
//				throw new AssertionError();
			}
		}
	}
	
	static Edge createEdge(List<Edge> net[], int a, int b, int forwardCapacity, int reverseCapacity) {
		Edge ea = new Edge(b, forwardCapacity);
		Edge eb = new Edge(a, reverseCapacity);
		ea.pair = eb;
		eb.pair = ea;
		net[a].add(ea);
		net[b].add(eb);
		return ea;
	}
	
	static int pushFlow(List<Edge> net[], boolean seen[], boolean terminal[], int cur, int flow) {
		if (seen[cur]) {
			return 0;
		}
		seen[cur] = true;
		if (terminal[cur]) {
			return flow;
		}
		for (Edge e: net[cur]) {
			int newFlow;
			if (flow < 0) {
				newFlow = max(flow, -e.pair.capacity);
			} else {
				newFlow = min(flow, e.capacity);
			}
			if (newFlow == 0) {
				continue;
			}
			newFlow = pushFlow(net, seen, terminal, e.to, newFlow);
			if (newFlow != 0) {
				e.addFlow(newFlow);
				return newFlow;
			}
		}
		return 0;
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		boolean leaves[] = new boolean[n];
		int ids[] = new int[n];
		int idcnt = 0;
		int freecnt = 0;
		Map<Integer, Integer> idmap = new HashMap<>();
		for (int i = 0; i < n; i++) {
			boolean leave = next().charAt(0) != 'E';
			leaves[i] = leave;
			int id = nextInt();
			if (id == 0) {
				ids[i] = -1;
				++freecnt;
			} else {
				if (idmap.containsKey(id)) {
					ids[i] = idmap.get(id);
				} else {
					idmap.put(id, ids[i] = idcnt++);
				}
			}
		}
		final int eventI = 0;
		final int freeI = eventI + n;
		final int personI = freeI + freecnt;
		final int sourceI = personI + idcnt * freecnt;
		final int sinkI = sourceI + 1;
		List<Edge> net[] = new List[sinkI + 1];
		for (int i = 0; i < net.length; i++) {
			net[i] = new ArrayList<>();
		}
		int lastEvent[] = new int[idcnt];
		int lastFree = sourceI;
		fill(lastEvent, sourceI);
		Edge eventEdges[] = new Edge[n];
		for (int i = 0, j = 0; i < n; i++) {
			if (ids[i] < 0) {
				for (int id = 0; id < idcnt; id++) {
					int peid = personI + id * freecnt + j;
					createEdge(net, lastEvent[id], peid, 1, 0);
					lastEvent[id] = peid;
					createEdge(net, eventI + i, peid, leaves[i] ? 0 : 1, leaves[i] ? 1 : 0);
				}
				createEdge(net, lastFree, freeI + j, n, 0);
				lastFree = freeI + j;
				createEdge(net, eventI + i, freeI + j, leaves[i] ? 0 : 1, leaves[i] ? 1 : 0);
				++j;
			} else {
				createEdge(net, lastEvent[ids[i]], eventI + i, 1, 0);
				lastEvent[ids[i]] = eventI + i;
			}
			if (leaves[i]) {
				eventEdges[i] = createEdge(net, eventI + i, sinkI, 1, 0);
			} else {
				eventEdges[i] = createEdge(net, sourceI, eventI + i, 1, 0);
			}
		}
		Edge peopleEdges[] = new Edge[idcnt];
		for (int id = 0; id < idcnt; id++) {
			peopleEdges[id] = createEdge(net, lastEvent[id], sinkI, 1, 0);
		}
		Edge freeEdge = createEdge(net, lastFree, sinkI, n, 0);
		boolean terminal[] = new boolean[net.length];
		boolean seen[] = new boolean[net.length];
		terminal[sourceI] = true;
		terminal[sinkI] = true;
		for (int i = 0; i < n; i++) {
			if (eventEdges[i].capacity > 0) {
				seen[sourceI] = false;
				seen[sinkI] = false;
				if (pushFlow(net, seen, terminal, eventI + i, leaves[i] ? -1 : 1) == 0) {
					fill(seen, false);
					if (pushFlow(net, seen, terminal, eventI + i, leaves[i] ? -1 : 1) == 0) {
						printCase();
						out.println("CRIME TIME");
						return;
					}
				}
				eventEdges[i].addNonreversibleFlow(1);
			} else {
				eventEdges[i].pair.addNonreversibleFlow(1);
			}
		}
		terminal[sinkI] = false;
		while (true) {
			seen[sourceI] = false;
			seen[sinkI] = false;
			if (pushFlow(net, seen, terminal, sinkI, n) == 0) {
				fill(seen, false);
				if (pushFlow(net, seen, terminal, sinkI, n) == 0) {
					break;
				}
			}
		}
		int ans = n - freeEdge.capacity;
		for (Edge e: peopleEdges) {
			if (e.capacity == 0) {
				++ans;
			}
		}
		printCase();
		out.println(ans);
	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
				System.err.println("Test " + test + " done");
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}