import java.io.*;
import java.util.*;

public class gcj09round3_a implements Runnable {

//	String fileName = "E:/isinev/workspace/gcj09round3work/A-statement";
//	String fileName = "E:/isinev/workspace/gcj09round3work/A-small-attempt0";
//	String fileName = "E:/isinev/workspace/gcj09round3work/A-small-attempt1";
	String fileName = "E:/isinev/workspace/gcj09round3work/A-large";
	
	static int pn;
	
	static int[] dx = new int[] {-1, 0, 1, 0};
	static int[] dy = new int[] {0, 1, 0, -1};
	
	static class P {
		public P(int pn) {
			x = new int[pn];
			y = new int[pn];
		}
		int[] x;
		int[] y;
		int d;
		@Override
		public int hashCode() {
			final int prime = 10009;
			int result = 1;
			result = prime * result + Arrays.hashCode(x);
			result = prime * result + Arrays.hashCode(y);
			return result;
		}
		@Override
		public boolean equals(Object obj) {
//			if (this == obj)
//				return true;
//			if (obj == null)
//				return false;
//			if (getClass() != obj.getClass())
//				return false;
			P other = (P) obj;
			if (!Arrays.equals(x, other.x))
				return false;
			if (!Arrays.equals(y, other.y))
				return false;
			return true;
		}
		
		public void getNext() {
			P n = copy();
			int distn = dist.get(this);
			for (int i = 0; i < pn; i++) {
				for (int id = 0; id < 4; id++) {
					int nx = x[i] + dx[id];
					int ny = y[i] + dy[id];
					if (nx < 0 || r <= nx) {
						continue;
					}									
					if (ny < 0 || c <= ny) {
						continue;
					}
					
					
					n.x[i] = nx;
					n.y[i] = ny;
					int nd = n.checkStable(nx - 2 * dx[id], ny - 2 * dy[id]);
					if (nd == -1) {
						continue;
					}
					if (d == 1 && nd == 1) {
						continue;
					}
					P nc = n.copy().norm();
					
					if (dist.containsKey(nc)) {
						continue;
					}
					
//					if (Arrays.equals(nc.x, new int[] {1, 3, 3}) && Arrays.equals(nc.y, new int[] {2, 3, 4})) {
//						int ttt = 2;
//					}
//					if (Arrays.equals(nc.x, new int[] {2, 3, 3}) && Arrays.equals(nc.y, new int[] {2, 3, 4})) {
//						int ttt = 2;
//					}
					nc.prev = this;
					dist.put(nc, distn + 1);
					q.add(nc);
				}				
				n.x[i] = x[i];
				n.y[i] = y[i];
			}
		}
			
		private P norm() {
			for (int i1 = 0; i1 < pn; i1++) {
				for (int i2 = i1; i2 + 1 < pn; i2++) {
					int i3 = i2 + 1;
					if (this.x[i2] > this.x[i3] || (this.x[i2] == this.x[i3] && this.y[i2] > this.y[i3])) {
						int t = this.x[i2];
						this.x[i2] = this.x[i3];
						this.x[i3] = t;
						t = this.y[i2];
						this.y[i2] = this.y[i3];
						this.y[i3] = t;
					}
				}
			}
			return this;
		}
		@Override
		public String toString() {
			StringBuilder res = new StringBuilder();
			for (int i = 0; i < pn; i++) {
				res.append(String.format("(%d %d) ", x[i], y[i]));				
			}
			int[][] bi = new int[r][c];
			for (int i = 0; i < pn; i++) {
				bi[x[i]][y[i]]++;
			}
			for (int i = 0; i < r; i++) {
				res.append("\n");
				for (int j = 0; j < c; j++) {
					res.append(bi[i][j]);
				}
			}
			return res.toString();
		}
		
		private int checkStable(int px, int py) {
			int res = 0;
			if (px < 0 || r <= px) {
				res = -1;
			}									
			if (py < 0 || c <= py) {
				res = -1;
			}
			if (res == 0) {
				if (b[px][py]) {
					res = -1;
				}
			}
			
			for (int i = 0; i < pn; i++) {
				if (bd[x[i]][y[i]] || b[x[i]][y[i]] || (x[i] == px && y[i] == py)) {
					res = -1;
				}
				bd[x[i]][y[i]] = true;
			}			
			
			if (res == 0) {
				dfs(x[0], y[0]);
			}
			
			for (int i = 0; i < pn; i++) {
				bd[x[i]][y[i]] = false;
				if (!bu[x[i]][y[i]]) {
					if (res == 0) {
						res = 1;				
					}
				}
				bu[x[i]][y[i]] = false;
			}
			this.d = res;
			return res;
		}
		
		private void dfs(int x, int y) {
			if (bu[x][y]) {
				return;
			}
			bu[x][y] = true;
			for (int id = 0; id < 4; id++) {
				int nx = x + dx[id];
				if (nx < 0 || r <= nx) {
					continue;
				}
				int ny = y + dy[id];
				if (ny < 0 || c <= ny) {
					continue;
				}
				if (bd[nx][ny]) {
					dfs(nx, ny);
				}
			}
		}
		private P copy() {
			P r = getP();
			for (int i = 0; i < pn; i++) {
				r.x[i] = x[i];
				r.y[i] = y[i];
			}
			r.d = d;
			return r;
			
		}
		P prev = null;
//		public void printPrev() {
//			System.out.println(this);
//			if (prev != null) {
//				prev.printPrev();
//			}
//		}
	}
	
	static ArrayList<P> pstack = new ArrayList<P>();
	static P getP() {
		if (pstack.isEmpty()) {
			pstack.add(new P(pn));
		}
		return pstack.remove(pstack.size() - 1);
	}
	
	//	static void release(P p) { 
//		pstack.add(p);
//	}
	
	static Queue<P> q;
	static int r;
	static int c;
	
	class Solution {

		
		public int solve() throws Exception {
			pstack.clear();
			r = nextInt();			
			c = nextInt();
			b = new boolean[r][c];
			bd = new boolean[r][c];
			bu = new boolean[r][c];
			ArrayList<Integer> xs = new ArrayList<Integer>();
			ArrayList<Integer> ys = new ArrayList<Integer>();
			ArrayList<Integer> xt = new ArrayList<Integer>();
			ArrayList<Integer> yt = new ArrayList<Integer>();
			for (int i = 0; i < r; i++) {
				String ri = next();
				for (int j = 0; j < c; j++) {
					char h = ri.charAt(j);
					b[i][j] = (h == '#');
					if (h == 'o' || h == 'w') {
						xs.add(i);
						ys.add(j);
					}
					if (h == 'x' || h == 'w') {
						xt.add(i);
						yt.add(j);
					} 
				}
			}
			if (xs.size() != xt.size()) {
				return -1;
			}
			pstack.clear();
			pn = xs.size();
			P ps = getP();
			for (int i = 0; i < pn; i++) {
				ps.x[i] = xs.get(i);
				ps.y[i] = ys.get(i);
			}
			P pt = getP();
			for (int i = 0; i < pn; i++) {
				pt.x[i] = xt.get(i);
				pt.y[i] = yt.get(i);
			}
			dist.clear();
			q = new LinkedList<P>();
			q.add(ps);
			dist.put(ps, 0);
			while (!q.isEmpty()) {
				P cp = q.poll();
				cp.getNext();
			}
			
//			P o = getP();
//			o.x[0] = 3; o.y[0] = 3;
//			o.x[1] = 3; o.y[1] = 4;
			
			
			
//			P o = getP();
//			o.x[0] = 3; o.y[0] = 3;
//			o.x[1] = 3; o.y[1] = 4;
//			System.out.println(dist.get(o.norm()));
//
//			o.x[0] = 3; o.y[0] = 3;
//			o.x[1] = 3; o.y[1] = 4;
//			System.out.println(dist.get(o.norm()));
//			o.x[0] = 2; o.y[0] = 3;
//			o.x[1] = 3; o.y[1] = 4;
//			System.out.println(dist.get(o.norm()));
//			o.x[0] = 2; o.y[0] = 3;
//			o.x[1] = 2; o.y[1] = 4;
//			System.out.println(dist.get(o.norm()));
//			o.x[0] = 2; o.y[0] = 3;
//			o.x[1] = 1; o.y[1] = 4;
//			System.out.println(dist.get(o.norm()));
//			o.x[0] = 2; o.y[0] = 3;
//			o.x[1] = 1; o.y[1] = 3;
//			System.out.println(dist.get(o.norm()));
//			o.x[0] = 2; o.y[0] = 3;
//			o.x[1] = 1; o.y[1] = 2;
//			System.out.println(dist.get(o.norm()));
//			o.x[0] = 2; o.y[0] = 2;
//			o.x[1] = 1; o.y[1] = 2;
//			System.out.println(dist.get(o.norm()));
//			o.x[0] = 2; o.y[0] = 2;
//			o.x[1] = 1; o.y[1] = 1;
//			System.out.println(dist.get(o.norm()));
//			o.x[0] = 2; o.y[0] = 1;
//			o.x[1] = 1; o.y[1] = 1;
//			System.out.println(dist.get(o.norm()));
//			pt.norm();
//			System.out.println(pt);
//			for (P pi : dist.keySet()) {
//				if (pi.equals(pt)) {
//					pi.printPrev();
//				}
//			}
			
			return (dist.containsKey(pt) ? dist.get(pt) : -1);
		}
					
	}
	
	static HashMap<P, Integer> dist = new HashMap<P, Integer>();
	static boolean[][] b;

	static boolean[][] bd;
	static boolean[][] bu;
	
	@Override
	public void run() {
		try {
			int nt = nextInt();
			for (int it = 1; it <= nt; it++) {
//				System.out.println("Test " + it);
				out.format("Case #%d: %d\n", it, new Solution().solve());
//				System.out.println();
//				System.out.println();
			}
		} catch (Exception e) {			
			e.printStackTrace();
		} finally {
			out.close();
		}
	}
	
	static {
		Locale.setDefault(Locale.US);
	}		
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	public gcj09round3_a() throws FileNotFoundException {
		in = new BufferedReader(new FileReader(new File(fileName + ".in")));
		out = new PrintWriter(fileName + ".out");
		st = new StringTokenizer("");
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		new Thread(new gcj09round3_a()).start();	
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(next());
	}
	double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(next());
	}
	long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(next());
	}
}
