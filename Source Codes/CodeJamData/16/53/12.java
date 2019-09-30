import java.io.*;
import java.util.*;

public class _2016Round3qB {

	static int x[], y[], z[];
	
	public static void main(String args[]) throws Exception {
		InputReader in;
		PrintWriter w;
		boolean online = true;
		String fileName = "C-small-attempt0";

		if (online) {
			in = new InputReader(
					new FileInputStream(new File(fileName + ".in")));
			w = new PrintWriter(new FileWriter(fileName + "out.txt"));
		} else {
			in = new InputReader(System.in);
			w = new PrintWriter(System.out);
		}

		int T = in.nextInt();

		for (int t = 1; t <= T; t++) {
			w.print("Case #" + t + ": ");
			
			int n = in.nextInt();
			int s = in.nextInt();
			
			x = new int[n];
			y = new int[n];
			z = new int[n];
			
			for (int i = 0; i < n; i++) {
				x[i] = in.nextInt();
				y[i] = in.nextInt();
				z[i] = in.nextInt();
				in.nextInt();	in.nextInt();	in.nextInt();
			}
			
			long dist[] = new long[n * (n - 1) / 2];
			for (int i = 0, k = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++, k++) {
					dist[k] = d(i, j);
				}
			}
			
			Arrays.sort(dist);
			
			int start = 0, end = dist.length;
			int ans = -1;
			
			while(start < end) {
				int mid = (start + end) >> 1;
				DisjointSet ds = new DisjointSet(n);
				long M = dist[mid];
				for (int i = 0; i < n; i++){
					for (int j = i + 1; j < n; j++){
						long di = d(i, j);
						if (di <= M) {
							ds.merge(i, j);
						}
					}
				}
				if(ds.find(0) == ds.find(1)) {
					ans = mid;
					end = mid;
				}
				else
					start = mid + 1;
			}
			
			
			w.println(Math.sqrt(dist[ans]));
			
		}

		w.close();
	}
	
	static long d(int i, int j){
		long a = x[i] - x[j];
		long b = y[i] - y[j];
		long c = z[i] - z[j];
		return a * a + b * b + c * c;
	}
	
	static public class DisjointSet {

		public int rank[],parent[],size[];
		public int n,comp;
		
		public DisjointSet(int n){
		    this.n = n;
			makeSet();
		}
		
		public void makeSet(){
			rank = new int[n];
			parent = new int[n];
			for(int i=0;i<n;i++)
				parent[i] = i;
			size = new int[n];
			Arrays.fill(size, 1);
			comp = n;
		}
		
		public int find(int x){
			if(parent[x] != x)
				parent[x] = find(parent[x]);
			return parent[x];
		}
		
		public void merge(int x,int y){
			int xRoot = find(x);
			int yRoot = find(y);
			
			if(xRoot == yRoot)	return;
			
			size[xRoot] = size[yRoot] = size[xRoot] + size[yRoot];
			
			if(rank[xRoot] < rank[yRoot])
				parent[xRoot] = yRoot;
			else{
				parent[yRoot] = xRoot;
				if(rank[xRoot] == rank[yRoot]) rank[xRoot]++;
			}
			
			comp--;
		}
		
	}

	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar, snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}
