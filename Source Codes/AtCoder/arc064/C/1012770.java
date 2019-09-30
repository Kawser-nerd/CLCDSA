import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.NoSuchElementException;

public class Main {
	public static class Node {
		int before;
		double cost;
		public Node() {
			this.before = -1;
			this.cost = Double.MAX_VALUE;
		}
	}

	public static Node[] dijkstra(int n, int start, double[][] matrix) {
		boolean[] defnode = new boolean[n];
		Node[] cost = new Node[n];
		for(int i=0; i<n; i++) {
			defnode[i] = false;
			cost[i] = new Node();
		}
		cost[start].cost = 0;
		int node = start;
		int counter = 0;
		while(true) {
			counter++;
			if(counter == n || node == Integer.MAX_VALUE) return cost;
			defnode[node] = true;
			for(int i=0; i<n; i++) {
				if(defnode[i]) continue;
				if(matrix[node][i] == Double.MAX_VALUE) continue;
				if((cost[node].cost + matrix[node][i]) < cost[i].cost) {
					cost[i].cost = cost[node].cost + matrix[node][i];
					cost[i].before = node;
				}
			}
			int minnode = Integer.MAX_VALUE;
			Double mincost = Double.MAX_VALUE;
			for(int i=0; i<n; i++) {
				if(defnode[i]) continue;
				if(cost[i].cost < mincost) {
					minnode = i;
					mincost = cost[i].cost;
				}
			}
			node = minnode;
		}
	}

	public static void main(String[] args) {
		FS fs = new FS();
		// start
		int xs = fs.nextInt();
		int ys = fs.nextInt();
		// goal
		int xt = fs.nextInt();
		int yt = fs.nextInt();
		// num of barrier
		int N = fs.nextInt();
		double[][] matrix = new double[N+2][N+2];
		int[] x = new int[N+2];
		int[] y = new int[N+2];
		int[] r = new int[N+2];
		x[0] = xs;
		y[0] = ys;
		r[0] = 0;
		x[N+1] = xt;
		y[N+1] = yt;
		r[N+1] = 0;
		for(int i=0; i<N; i++) {
			x[i+1] = fs.nextInt();
			y[i+1] = fs.nextInt();
			r[i+1] = fs.nextInt();
		}
		for(int i=0; i<N+2; i++) {
			matrix[i][i] = Double.MAX_VALUE;
		}

		// calculate cost
		for(int i=0; i<N+1; i++) {
			for(int j=i+1; j<N+2; j++) {
				double xi = (double)x[i];
				double xj = (double)x[j];
				double yi = (double)y[i];
				double yj = (double)y[j];
				double ri = (double)r[i];
				double rj = (double)r[j];
				double l = Math.max(0.0, Math.sqrt(Math.pow(xi-xj, 2.0)+Math.pow(yi-yj, 2.0))-ri-rj);
				matrix[i][j] = l;
				matrix[j][i] = l;
			}
		}

		Node[] cost = dijkstra(N+2, 0, matrix);
		System.out.println(cost[N+1].cost);
	}

	// Read Class
	static class FS {
		private final InputStream in = System.in;
		private final byte[] buffer = new byte[1024];
		private int ptr = 0;
		private int buflen = 0;
		private boolean hasNextByte() {
			if (ptr < buflen) {
				return true;
			} else {
				ptr = 0;
				try {
					buflen = in.read(buffer);
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (buflen <= 0) {
					return false;
				}
			}
			return true;
		}

		private int readByte() { return hasNextByte() ? buffer[ptr++] : -1;}
		private boolean isPrintableChar(int c) {return 33 <= c && c <= 126;}
		private void skipUnprintable() {while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}

		public boolean hasNext() { skipUnprintable(); return hasNextByte();}
		public String next() {
			if (!hasNext()) throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while(isPrintableChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
		public int nextInt() {
			return (int)nextLong();
		}
		public long nextLong() {
			if (!hasNext()) throw new NoSuchElementException();
			long n = 0;
			boolean minus = false;
			int b = readByte();
			if (b == '-') {
				minus = true;
				b = readByte();
			}
			if (b < '0' || '9' < b) {
				throw new NumberFormatException();
			}
			while(true) {
				if ('0' <= b && b <= '9') {
					n *= 10;
					n += b - '0';
				} else if(b == -1 || !isPrintableChar(b)) {
					return minus ? -n : n;
				} else {
					throw new NumberFormatException();
				}
				b = readByte();
			}
		}
	}
}