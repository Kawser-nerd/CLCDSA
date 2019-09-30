import java.io.*;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJC implements Runnable {

	private PrintWriter out;
	
	final String file = "C-large";
	Random rnd = new Random(42);

    static class Edge {
        int id;
        int u, v;
        int a, b;

        Edge(int id, int u, int v, int a, int b) {
            this.id = id;
            this.u = u;
            this.v = v;
            this.a = a;
            this.b = b;
        }
    }

    static class Node implements Comparable<Node> {
        int i, dist;

        Node(int i, int dist) {
            this.i = i;
            this.dist = dist;
        }

        @Override
        public int compareTo(Node o) {
            return dist - o.dist;
        }
    }

    static final int INF = 2000000001;

	static class InputData {

        List<Edge>[] edges;
        int[] p0;

		InputData(FastReader in) throws IOException {
            int n = in.nextInt();
            int m = in.nextInt();
            int p = in.nextInt();
            edges = new List[n];
            for (int i = 0; i < n; ++i) {
                edges[i] = new ArrayList<Edge>();
            }
            for (int i = 0; i < m; ++i) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                int a = in.nextInt();
                int b = in.nextInt();
                edges[u].add(new Edge(i, u, v, a, b));
            }
            p0 = new int[p];
            for (int i = 0; i < p; ++i) {
                p0[i] = in.nextInt() - 1;
            }
		}
		
		void solve(PrintWriter out) {
            HashSet<Integer> small = new HashSet<Integer>();
            for (int it = 0; it < p0.length; ++it) {
                int[] dists = dists(small, p0[it]);
                Edge e = null;
                for (List<Edge> el : edges) {
                    for (Edge ee : el) {
                        if (ee.id == p0[it]) {
                            e = ee;
                        }
                    }
                }
//                System.err.println(Arrays.toString(dists) + " " + e.v + " " + (dists[e.u] + e.a));
                if (!dists2(e.v, dists[e.u] + e.a, dists)) {
                    out.println(e.id + 1);
                    return;
                }
                small.add(p0[it]);
            }
            out.println("Looks Good To Me");
		}

        private boolean dists2(int v0, int d0, int[] dists) {
            if (dists[v0] < d0) {
                return false;
            }
            int[] d = new int[edges.length];
            Arrays.fill(d, INF);
            PriorityQueue<Node> pq = new PriorityQueue<Node>();
            d[v0] = d0;
            pq.add(new Node(v0, d0));
            while (!pq.isEmpty()) {
                Node n = pq.poll();
                if (d[n.i] < n.dist) {
                    continue;
                }
                if (n.i == 1) {
                    return true;
                }
                for (Edge e : edges[n.i]) {
                    int len = e.a;
                    if (d[e.v] > d[e.u] + len && d[e.u] + len <= dists[e.v]) {
                        d[e.v] = d[e.u] + len;
                        pq.add(new Node(e.v, d[e.v]));
                    }
                }
            }
            return false;
        }

        private int[] dists(HashSet<Integer> small, int ignore) {
            int[] d = new int[edges.length];
            Arrays.fill(d, INF);
            PriorityQueue<Node> pq = new PriorityQueue<Node>();
            d[0] = 0;
            pq.add(new Node(0, 0));
            while (!pq.isEmpty()) {
                Node n = pq.poll();
                if (d[n.i] < n.dist) {
                    continue;
                }
                for (Edge e : edges[n.i]) {
                    if (e.id == ignore) {
                        continue;
                    }
                    int len = small.contains(e.id) ? e.a : e.b;
                    if (d[e.v] > d[e.u] + len) {
                        d[e.v] = d[e.u] + len;
                        pq.add(new Node(e.v, d[e.v]));
                    }
                }
            }
            return d;
        }
    }
	
	static class Solver implements Callable<String> {

		InputData data;
		
		Solver(InputData data) {
			this.data = data;
		}

		@Override
		public String call() throws Exception {
			StringWriter out = new StringWriter();
			data.solve(new PrintWriter(out));
			return out.toString();
		}
		
	}

	public void run() {
		try {
			FastReader in = new FastReader(new BufferedReader(new FileReader(file + ".in")));
			out = new PrintWriter(file + ".out");
			
			ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(7);
			
			int tests = in.nextInt();
			Future<String>[] ts = new Future[tests];
			for (int test = 0; test < tests; ++test) {
				ts[test] = service.submit(new Solver(new InputData(in)));
			}
			for (int test = 0; test < tests; ++test) {
				while (!ts[test].isDone()) {
					Thread.sleep(500);
				}
				System.err.println("Test " + test);
				out.print("Case #" + (test + 1) + ": ");
				out.print(ts[test].get());
			}
			service.shutdown();
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	static class FastReader {
		public FastReader(BufferedReader in) {
			this.in = in;
			eat("");
		}
		
		private StringTokenizer st;
		private BufferedReader in;
		
		void eat(String s) {
			st = new StringTokenizer(s);
		}
		
		String next() throws IOException {
			while (!st.hasMoreTokens()) {
				String line = in.readLine();
				if (line == null) {
					return null;
				}
				eat(line);
			}
			return st.nextToken();
		}
		
		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
		
		long nextLong() throws IOException {
			return Long.parseLong(next());
		}
		
		double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new GCJC().run();
	}
	
}
