import java.io.*;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ2015R3D implements Runnable {

	private PrintWriter out;
	
	final String file = "D-small-attempt0";
	static Random rnd = new Random(42);

    static class Pair implements Comparable<Pair> {
        long v, c;

        public Pair(long v, long c) {
            this.v = v;
            this.c = c;
        }

        @Override
        public int compareTo(Pair o) {
            return Long.compare(v, o.v);
        }
    }

	static class InputData {

        int n;
        Pair[] ps;
		
		InputData(FastReader in) throws IOException {
            n = in.nextInt();
            ps = new Pair[n];
            for (int i = 0; i < n; ++i) {
                ps[i] = new Pair(in.nextLong(), -1);
            }
            for (int i = 0; i < n; ++i) {
                ps[i].c = in.nextLong();
            }
		}
		
		void solve(PrintWriter out) {
            Arrays.sort(ps);
            ArrayList<Long> ans = new ArrayList<>();
            long[] candidates = new long[n];
            for (int i = 0; i < n; ++i) {
                candidates[i] = ps[i].v;
                if (i > 0 && ps[i].v == ps[i - 1].v) {
                    throw new AssertionError();
                }
            }
            if (!rec(0, candidates, ps, ans)) {
                throw new AssertionError();
            }
            System.err.println(faults);
            Collections.reverse(ans);
            for (long x : ans) {
                out.print(x + " ");
            }
            out.println();
		}

        int faults = 0;

        private boolean rec(int u, long[] candidates, Pair[] ps, ArrayList<Long> ans) {
            if (ps.length == 1 && ps[0].c == 1) {
                return ps[0].v == 0;
            }
            loop: for (; u < candidates.length; ++u) {
                long d = candidates[u];
                ArrayList<Pair> ps1 = new ArrayList<>();
                if (d == 0) {
                    for (Pair p : ps) {
                        if (p.c % 2 == 1) {
                            continue loop;
                        }
                        ps1.add(new Pair(p.v, p.c / 2));
                    }
                } else if (d > 0) {
                    int jt = 0;
                    for (int it = 0; it < ps.length; ++it) {
                        Pair p = ps[it];
                        long nc = p.c;
                        if (jt < ps1.size() && ps1.get(jt).v == p.v - d) {
                            nc -= ps1.get(jt++).c;
                        }
                        if (nc < 0) {
                            continue loop;
                        }
                        if (nc > 0) {
                            ps1.add(new Pair(p.v, nc));
                        }
                    }
                    if (jt != ps1.size()) {
                        continue loop;
                    }
                } else {
                    int jt = 0;
                    for (int it = ps.length - 1; it >= 0; --it) {
                        Pair p = ps[it];
                        long nc = p.c;
                        if (jt < ps1.size() && ps1.get(jt).v == p.v - d) {
                            nc -= ps1.get(jt++).c;
                        }
                        if (nc < 0) {
                            continue loop;
                        }
                        if (nc > 0) {
                            ps1.add(new Pair(p.v, nc));
                        }
                    }
                    if (jt != ps1.size()) {
                        continue loop;
                    }
                    Collections.reverse(ps1);
                }
                if (rec(u, candidates, ps1.toArray(new Pair[ps1.size()]), ans)) {
                    ans.add(d);
                    return true;
                } else {
                    faults++;
                }
            }
            return false;
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
		new GCJ2015R3D().run();
	}
	
}
