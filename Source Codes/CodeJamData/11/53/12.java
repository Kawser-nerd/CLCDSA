import java.io.*;
import java.util.*;

public class BaiC {
	
	
	class Graph {

		final int MAX = 22000;
		
			int N;
			ArrayList<Integer>[] ke;
			boolean[] gt, dt;
			boolean satisfy;
			// queue
			int[] q;
			int le, ri;
			boolean[] inq;
			
			void init(int n) {
				N = n;
				ke = new ArrayList[MAX];
				for(int i=0;i<MAX;++i) ke[i] = new ArrayList<Integer>();
				gt = new boolean[MAX];
				dt = new boolean[MAX];
				q = new int[MAX];
				inq = new boolean[MAX];
				satisfy = true;
			}
			
			void add_edge( int a, int b) {
				ke[a].add(b);
			}
			
			int doi(int x) {
				return N+1 - x;
			}
			
			boolean gan(int i) {
				
				for(int t=0;t<=ri;++t) inq[q[t]] = false;
				
				q[le=ri=0] = i;
				inq[i] = true;
				while(le<=ri) {
					int u = q[le++];
					for(int k=0;k<ke[u].size();++k) {
						int v = ke[u].get(k);
						if(dt[v] && !gt[v]) return false;
						if(v==doi(i)) return false;
						if((!inq[v]) && !dt[v]) {
							q[++ri] = v;
							inq[v] = true;
						}
					}
				}
				for(int k=0;k<=ri;++k) {
					int u = q[k];
					gt[u] = dt[u] = dt[doi(u)] = true;
					gt[doi(u)] = false;
				}
				return true;
			}

		void process() {	
			int[] hv = new int[N/2];
			
			for(int i=0;i<N/2;++i) hv[i] = i+1;
			
			Random ran = new Random();
			
			for(int k=0;k<10000;++k) {
				int u = ran.nextInt(N/2);
				int v = ran.nextInt(N/2);
				int t = hv[u]; hv[u] = hv[v]; hv[v] = t;
			}
			
			
			for(int k=0;k<N/2;++k) {	
				int i = hv[k];
				if(!dt[i]) {
					boolean t = ran.nextBoolean();
					if(t) {
						if( (!gan(i) ) && !gan(doi(i))) {
							satisfy = false;
							return;
						}
					}
					else if((!gan(doi(i))) && !gan(i)) {
						satisfy = false;
						return;
					}
				}
			}
		}

		
	}
	
	int[] dx = new int[]{-1, 0, -1, -1};
	int[] dy = new int[]{0, -1, 1, -1};
	
	int m, n;
	int[][] a;
	
	int nc, nd;
	boolean[] vs;
	ArrayList<Integer>[] ke;
	
	void dfs(int i) {
		vs[i] = true;
		++nd;
		for(int j : ke[i]) {
			++nc;
			if(!vs[j]) dfs(j);
		}
	}
	
	int solve(char[][] aa) {
		
		m = aa.length;
		n = aa[0].length;
		a = new int[m][n];
		for(int i=0;i<m;++i) {
			for(int j=0;j<n;++j) {
				if(aa[i][j] == '|') this.a[i][j] = 0;
				else if(aa[i][j] == '-') this.a[i][j] = 1;
				else if(aa[i][j] == '/') this.a[i][j] = 2;
				else this.a[i][j] = 3;
			}
		}
		
		TreeSet<Integer> edges = new TreeSet<Integer>();
		
		Graph graph = new Graph();
		graph.init(m * n * 2);
		
		for(int i=0;i<m;++i) {
			for(int j=0;j<n;++j) {
				
				for(int zx=-2;zx<=2;++zx) {
					for(int zy=-2;zy<=2;++zy) {
						int u = i + zx;
						int v = j + zy;
						u = (u % m + m) % m;
						v = (v % n + n) % n;
						
						if(u == i && v == j) continue;
						
						for(int s1=-1;s1<=1;s1+=2) {
							for(int s2=-1;s2<=1;s2+=2) {
								int x1 = i + dx[a[i][j]] * s1;
								int y1 = j + dy[a[i][j]] * s1;
								int x2 = u + dx[a[u][v]] * s2;
								int y2 = v + dy[a[u][v]] * s2;
								
								x1 = (x1 % m + m) % m;
								x2 = (x2 % m + m) % m;
								y1 = (y1 % n + n) % n;
								y2 = (y2 % n + n) % n;
								
								if(x1 == x2 && y1 == y2) {
									
									int uu = i * n + j;
									int vv = u * n + v;
									
									uu++; vv++;
									
									if(s1 == 1) uu = 2 * m * n + 1 - uu;
									if(s2 == 1) vv = 2 * m * n + 1 - vv;
									
									graph.add_edge(uu, 2 * m * n + 1 - vv);
									graph.add_edge(vv, 2 * m * n + 1 - uu);
									
									// System.out.println(i + " " + j + " " + u + " " + v);
									edges.add(i * n*m*n + j * m * n + u * n + v);
									edges.remove(u * n*m*n + v * m*n + i * n + j);
								}
							}
						}
					}
				}
				
			}
		}
		
		graph.process();
		
		if(!graph.satisfy) return 0;
		
		ke = new ArrayList[m * n];
		for(int i=0;i<m*n;++i) ke[i] = new ArrayList<Integer>();
		
		for(int z : edges) {
			int u = z % (m*n);
			int v = z / (m*n);
			ke[u].add(v);
			ke[v].add(u);
			// System.out.println("add " + u + " " + v);
		}
		
		vs = new boolean[m * n];
		int res = 1;
		int mod = 1000003;
		for(int i=0;i<m*n;++i) if(!vs[i]) {
			nd = nc = 0;
			dfs(i);
			
			nc /= 2;
			
			res = res * 2;
			res %= mod;
		}
		
		return res;
	}
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		// PrintWriter pw = new PrintWriter(System.out);
		PrintWriter pw = new PrintWriter(new FileWriter("Clarge.out"));
		
		int ntest = sc.nextInt();
		for(int test=1;test<=ntest;++test) {
			
			
			int m = sc.nextInt();
			int n = sc.nextInt();
			
			char[][] a = new char[m][n];
			for(int i=0;i<m;++i)
				a[i] = sc.next().toCharArray();
			
			int res = new BaiC().solve(a);
			
			pw.print("Case #" + test + ": ");
			pw.print(res);
			pw.println();
			
		}
		
		sc.close();
		pw.close();
	}
}
