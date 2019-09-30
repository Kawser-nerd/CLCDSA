import java.util.*;
import java.io.*;
public class Main {
	static IO io = new IO();
	public static void main(String[] args) {
		int n = io.nextInt();	// 1..50
		int d[][] = new int[n][n];
		for (int j=0; j<n; j++) {
			for (int i=0; i<n; i++) {
				d[i][j] = io.nextInt();
			}
		}
		
		int q = io.nextInt();	// 1..n^2
		int p[] = new int[q];
		for (int i=0; i<q; i++) p[i] = io.nextInt();
		
		// ???????????(i,j)???????????dp????????
		int dp[][] = new int[n+1][n+1];
		dp[n-1][n-1] = d[n-1][n-1];
		for (int i=n-2; i>=0; i--) dp[i][n-1] = d[i][n-1] + dp[i+1][n-1];	// ?????
		for (int i=n-2; i>=0; i--) dp[n-1][i] = d[n-1][i] + dp[n-1][i+1];	// ?????
		for (int j=n-2; j>=0; j--) {
			for (int i=n-2; i>=0; i--) {
				dp[i][j] = dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1] + d[i][j];
			}
		}
		
		for (int a=0; a<q; a++) {
			
			int ans = 0;
				
			// ?????????
			int lim = p[a];
			Deque<int[]> que = new ArrayDeque<int[]>();
			// ??????????????????????
			int from = 1;
			root: for (int y=n; y>=Math.sqrt(p[a])-1; y--) {
				for (int x=from; x<=n; x++) {
					if (x*y>lim) {
						from = x;
						continue root;
					}
					else {
						que.offer(new int[] {y,x});
						if (x!=y) que.offer(new int[] {x,y});
					}
				}
			}
			
			while (!que.isEmpty()) {
				int poll[] = que.poll();
				int x = poll[0];
				int y = poll[1];
				for (int yy=0; yy<n-y+1; yy++) {
					for (int xx=0; xx<n-x+1; xx++) {
							int tmp = 0;
							tmp = dp[xx][yy] - dp[xx+x][yy] - dp[xx][yy+y] + dp[xx+x][yy+y];
							ans = Math.max(ans, tmp);
						}
					}	
				}
				
			System.out.println(ans);
		}
			
	}
	
	static class IO extends PrintWriter {
		private final InputStream in;
		private final byte[] buffer = new byte[1024];
		private int ptr = 0;
		private int buflen = 0;

		public IO() { this(System.in);}
		public IO(InputStream source) { super(System.out); this.in = source;}
		private boolean hasNextByte() {
			if (ptr < buflen) {
				return true;
			}else{
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
		private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
		private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
		private static boolean isNewLine(int c) { return c == '\n' || c == '\r';}
		private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
		private void skipNewLine() { while(hasNextByte() && isNewLine(buffer[ptr])) ptr++;}
		public boolean hasNext() { skipUnprintable(); return hasNextByte();}
		public boolean hasNextLine() { skipNewLine(); return hasNextByte();}
		public String next() {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while(isPrintableChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
		public char[] nextCharArray(int len) {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
			char[] s = new char[len];
			int i = 0;
			int b = readByte();
			while(isPrintableChar(b)) {
				if (i == len) {
					throw new InputMismatchException();
				}
				s[i++] = (char) b;
				b = readByte();
			}
			return s;
		}
		public String nextLine() {
			if (!hasNextLine()) {
				throw new NoSuchElementException();
			}
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while(!isNewLine(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
		public long nextLong() {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
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
			while(true){
				if ('0' <= b && b <= '9') {
					n *= 10;
					n += b - '0';
				}else if(b == -1 || !isPrintableChar(b)){
					return minus ? -n : n;
				}else{
					throw new NumberFormatException();
				}
				b = readByte();
			}
		}
		public int nextInt() {
			long nl = nextLong();
			if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
				throw new NumberFormatException();
			}
			return (int) nl;
		}
		public char nextChar() {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
			return (char) readByte();
		}
		public double nextDouble() { return Double.parseDouble(next());}
		public int[] arrayInt(int n) { int[] a = new int[n]; for(int i=0;i<n;i++) a[i] = nextInt(); return a;}
		public long[] arrayLong(int n) { long[] a = new long[n]; for(int i=0;i<n;i++) a[i] = nextLong(); return a;}
		public double[] arrayDouble(int n) { double[] a = new double[n]; for(int i=0;i<n;i++) a[i] = nextDouble(); return a;}
		public void arrayInt(int[]... a) {for(int i=0;i<a[0].length;i++) for(int j=0;j<a.length;j++) a[j][i] = nextInt();}
		public int[][] matrixInt(int n,int m) { int[][] a = new int[n][]; for(int i=0;i<n;i++) a[i] = arrayInt(m); return a;}
		public char[][] charMap(int n,int m) { char[][] a = new char[n][]; for(int i=0;i<n;i++) a[i] = nextCharArray(m); return a;}
		public void close() {
			super.close();
			try {
				in.close();
			} catch (IOException e) {}
		}
	}
}