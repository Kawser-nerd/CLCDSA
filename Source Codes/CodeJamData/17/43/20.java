import java.io.*;
import java.util.*;

/*

1
2 3
/.\
-#.

1
3 2
|\
#.
|/


*/
public class c {
	static final int STDIO = 0, SMALL = 1, LARGE = 2;
	static int inType = STDIO;
	static int outType = LARGE;
	static int[][] ds = new int[][] {
		{0,1},{0,-1},
		{1,0},{-1,0}
	};

	public static void main(String[] args) throws IOException {
		Scanner in = getScanner();
		PrintWriter out = getPrintWriter();
		int maxT = in.nextInt();
		test: for (int curT = 1; curT <= maxT; curT++) {
			
			int r = in.nextInt(), c = in.nextInt();
			TwoSAT ts = new TwoSAT(r*c);
			char[][] grid = new char[r][c];
			for(int i=0;i<r;i++) {
				String line = in.next();
				grid[i] = line.toCharArray();
				for(int j=0;j<c;j++) {
					if(grid[i][j] == '-' || grid[i][j] == '|')
						grid[i][j] = '+';
				}
			}
			
			out.printf("Case #%d: ", curT);
			ArrayList<Integer>[] ors = new ArrayList[r*c];
			ArrayList<Boolean>[] negs = new ArrayList[r*c];
			for(int i=0;i<r*c;i++) {
				ors[i] = new ArrayList<Integer>();
				negs[i] = new ArrayList<Boolean>();
			}
			for(int i=0;i<r;i++) {
				for(int j=0;j<c;j++) {
					if(grid[i][j] != '+') continue;
					ArrayList<Integer>[] locs = new ArrayList[2];
					for(int a=0;a<2;a++)
						locs[a] = new ArrayList<Integer>();
					boolean[] valid = new boolean[2];
					Arrays.fill(valid, true);
					for(int d1=0;d1<4;d1++) {
						int ci = i;
						int cj = j;
						int d = d1;
						boolean first = true;
						while(ci >= 0 && ci < r && cj >= 0 && cj < c) {
							if(grid[ci][cj] == '#') break;
							if(!first && grid[ci][cj] == '+') {
								valid[d1/2] = false;
							}
							first = false;
							locs[d1/2].add(ci*c+cj);
							if(grid[ci][cj] == '/') {
								if(d == 0) {
									d = 3;
								} else if(d == 1) {
									d = 2;
								} else if(d == 2) {
									d = 1;
								} else if(d == 3) {
									d = 0;
								}
							} else {
								if(grid[ci][cj] == '\\') {
									if(d == 0) {
										d = 2;
									} else if(d == 1) {
										d = 3;
									} else if(d == 2) {
										d = 0;
									} else if(d == 3) {
										d = 1;
									}
								}
							}
							ci += ds[d][0];
							cj += ds[d][1];
							
						}
					}
					if(!valid[0] && !valid[1]) {
						out.println("IMPOSSIBLE");
						
						if (inType != STDIO)
							System.out.println(curT + "/" + maxT);
						continue test;
					}
					if(!valid[0]) {
						ts.addForce(i*c+j, true);
					} else {
						for(int a : locs[0]) {
							ors[a].add(i*c+j);
							negs[a].add(false);
						}
					}
					if(!valid[1]) {
						ts.addForce(i*c+j, false);
					} else {
						for(int a : locs[1]) {
							ors[a].add(i*c+j);
							negs[a].add(true);
						}
					}
				}
			}
			for(int i=0;i<r;i++) {
				for(int j=0;j<c;j++) {
					if(grid[i][j] != '.') continue;
					int id = i*c+j;
					if(ors[id].size() == 0) {
						out.println("IMPOSSIBLE");
						
						if (inType != STDIO)
							System.out.println(curT + "/" + maxT);
						continue test;
					}
					if(ors[id].size() == 1) {
						ts.addForce(ors[id].get(0), negs[id].get(0));
					} else {
						ts.addOr(ors[id].get(0), negs[id].get(0),
								ors[id].get(1), negs[id].get(1));
					}
					if(ors[id].size() > 2) System.out.println(1/0);
				}
			}
			if(!ts.solve()) {
				out.println("IMPOSSIBLE");
			} else {
				out.println("POSSIBLE");
				for(int i=0;i<r;i++) {
					for(int j=0;j<c;j++) {
						if(grid[i][j] == '+') {
							int val = ts.vals[2*(i*c+j)];
							grid[i][j] = val == 0 ? '-' : '|';
						}
					}
				}
				for(int i=0;i<r;i++) {
					for(int j=0;j<c;j++) {
						out.print(grid[i][j]);
					}
					out.println();
				}
			}
			//// OUTPUT

			if (inType != STDIO)
				System.out.println(curT + "/" + maxT);
		}

		out.close();
	}

	static class TwoSAT {
		int n, n2;  int[] vals, cvals;  SCC scc;
		
		public TwoSAT(int nn) {  n2 = 2 * (n = nn);  scc = new SCC(n2);  vals = new int[n2];  }

		void addImpl(int a, boolean va, int b, boolean vb) {
			a *= 2; b *= 2;  if (!va) a++;  if (!vb) b++;
			scc.add(a, b);  scc.add(b ^ 1, a ^ 1);
		}

		//# Add (a NAND b)
		void addNand(int a, boolean va, int b, boolean vb) {
			addImpl(a, va, b, !vb);
		}//$

		//# Add (a OR b) where va and vb represent whether a and b are inverted
		public void addOr(int a, boolean va, int b, boolean vb) {
			addImpl(a, !va, b, vb); // ~a -> b
		}//$

		//# Add (a XOR b) where va and vb represent whether a and b are inverted
		public void addXor(int a, boolean va, int b, boolean vb) {
			addImpl(a, !va, b, vb); // ~a -> b
			addImpl(a, va, b, !vb); // a -> ~b
		}//$

		//# Forces a to have whatever value va is
		public void addForce(int a, boolean va) {
			addOr(a, va, a, va);
		}//$

		boolean solve() {
			ArrayList<ArrayList<Integer>> comps = scc.go();
			int[] id2c = new int[scc.n];  SCC graph = scc.compressSCC(id2c);
			cvals = new int[graph.adj.length];  Arrays.fill(cvals, -1);
			for(int i = 0; i < n; i++)  if(id2c[2*i] == id2c[2*i+1]) return false;

			int[] deg = new int[graph.adj.length];
			for(int u = 0; u < graph.adj.length; u++) for(int v : graph.adj[u]) deg[v]++;

			ArrayDeque<Integer> q = new ArrayDeque<Integer>();
			for(int i = 0; i < graph.adj.length; i++) if(deg[i] == 0) q.offer(i);

			while (!q.isEmpty()) {
				int u = q.poll();  ArrayList<Integer> comp = comps.get(u);
				if (cvals[u] == -1) {
					cvals[u] = 0;
					for(int i = 0; i < comp.size(); i++)
						cvals[id2c[comp.get(i) ^ 1]] = 1;
				}
				for(int v : graph.adj[u]) if((--deg[v]) == 0) q.offer(v);
			}
			for(int i = 0; i < comps.size(); i++) for(int v : comps.get(i)) vals[v] = cvals[i];

			return true;
		}
	}
	//Tarjan Strongly Connected Components O(V + E)
	static class SCC {
	  ArrayList<Integer>[] adj;
	  int n;
	  @SuppressWarnings("unchecked")
	  SCC(int n) {
	    this.n = n;
	    adj = new ArrayList[n];
	    for (int curr = 0; curr < n; ++curr)
	      adj[curr] = new ArrayList<Integer>();
	  }

	  void add(int v1, int v2) {
	    adj[v1].add(v2);
	  }

	  int index;
	  boolean[] visited;
	  int[] indices;
	  int[] lowlink;
	  ArrayDeque<Integer> stack;
	  ArrayList<ArrayList<Integer>> components;
	  ArrayList<ArrayList<Integer>> go() {
	    index = 1;
	    indices = new int[n];
	    lowlink = new int[n];
	    visited = new boolean[n];
	    components = new ArrayList<ArrayList<Integer>>();
	    stack = new ArrayDeque<Integer>();

	    for (int curr = 0; curr < n; ++curr)
	      if (indices[curr] == 0)
	        dfs(curr);

	    return components;
	  }

	  void dfs(int node) {
	    indices[node] = lowlink[node] = index++;
	    stack.push(node);
	    visited[node] = true;

	    for (int next : adj[node]) {
	      if (indices[next] == 0) {
	        dfs(next);
	        lowlink[node] = Math.min(lowlink[node], lowlink[next]);
	      } else if (visited[next]) {
	        lowlink[node] = Math.min(lowlink[node], indices[next]);
	      }
	    }

	    if (lowlink[node] == indices[node]) {
	      ArrayList<Integer> component = new ArrayList<Integer>();
	      int next;
	      do {
	        next = stack.pop();
	        visited[next] = false;
	        component.add(next);
	      } while (next != node);
	      components.add(component);
	    }
	  }

	  //#
	  public class StackState {
	    int node, child;
	    boolean beforeDFS;
	    StackState(int n) {
	      node = n;
	      child = 0;
	      beforeDFS = true;
	    }
	    void setChild(int c) {
	      child = c;
	      beforeDFS = true;
	    }
	  }

	  void dfsItr(int start) {
	    ArrayDeque<StackState> s = new ArrayDeque<StackState>();
	    s.push(new StackState(start));

	    while (!s.isEmpty()) {
	      StackState st = s.pop();
	      if (indices[st.node] == 0) {
	        indices[st.node] = lowlink[st.node] = index++;
	        stack.push(st.node);
	        visited[st.node] = true;
	      }
	      if (st.child == adj[st.node].size()) {
	        if (lowlink[st.node] == indices[st.node]) {
	          ArrayList<Integer> component = new ArrayList<Integer>();
	          int next;
	          do {
	            next = stack.pop();
	            visited[next] = false;
	            component.add(next);
	          } while (next != st.node);
	          components.add(component);
	        }
	      } else {
	        int next = adj[st.node].get(st.child);
	        if (st.beforeDFS) {
	          if (indices[next] == 0) {
	            st.beforeDFS = false;
	            s.push(st);
	            s.push(new StackState(next));
	          } else if (visited[next]) {
	            lowlink[st.node] = Math.min(lowlink[st.node], indices[next]);
	            st.setChild(st.child + 1);
	            s.push(st);
	          } else {
	            st.setChild(st.child + 1);
	            s.push(st);
	          }
	        } else {
	          lowlink[st.node] = Math.min(lowlink[st.node], lowlink[next]);
	          st.setChild(st.child + 1);
	          s.push(st);
	        }
	      }
	    }
	  }
	  //$

	  //# Make sure to call go() before calling this function.
	  // Function returns a new graph such that all SCCs are
	  // compressed into one node and only the edges connecting
	  // two components are in the new graph.
	  // nodeMapping is an integer array that will store the mapping
	  // for each node in the old graph into the new graph.//$
	  SCC compressSCC(int[] nodeMapping) {
	    for (int i = 0; i < components.size(); ++i) {
	      ArrayList<Integer> component = components.get(i);
	      for (int node : component)
	        nodeMapping[node] = i;
	    }
	    SCC g = new SCC(components.size());
	    int[] added = new int[components.size()];
	    Arrays.fill(added, -1);
	    for (int i = 0; i < components.size(); ++i) {
	      ArrayList<Integer> component = components.get(i);
	      for (int node : component) {
	        for (int next : adj[node]) {
	          int comp = nodeMapping[next];
	          if (comp != i && added[comp] != i) {
	            g.add(i, comp);
	            added[comp] = i;
	          }
	        }
	      }
	    }
	    return g;
	  }
	}
	
	static final String PROBLEM_LETTER = "C";

	static Scanner getScanner() throws IOException {
		if (outType != STDIO)
			inType = outType;
		if (inType == SMALL)
			return new Scanner(new File(PROBLEM_LETTER + "-small-attempt0.in"));
		else if (inType == LARGE)
			return new Scanner(new File(PROBLEM_LETTER + "-large.in"));
		return new Scanner(System.in);
	}

	static PrintWriter getPrintWriter() throws IOException {
		if (outType == SMALL) {
			System.out.println("WRITING TO " + PROBLEM_LETTER + "-SMALL");
			try {
				Thread.sleep(3000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			return new PrintWriter(new File(PROBLEM_LETTER + "-small.out"));
		} else if (outType == LARGE) {
			System.out.println("WRITING TO " + PROBLEM_LETTER + "-LARGE");
			try {
				Thread.sleep(3000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			return new PrintWriter(new File(PROBLEM_LETTER + "-large.out"));
		}
		return new PrintWriter(System.out);
	}
}
