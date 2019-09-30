import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {

	static PrintWriter out;
	static InputReader ir;
	static int[][][][] dp;
	static int[] x,y,cx,cy;

	static void solve() {
		int w=ir.nextInt();
		int h=ir.nextInt();
		int n=ir.nextInt();
		x=new int[n+2];
		y=new int[n+2];
		x[n+1]=w+1;
		y[n+1]=h+1;
		for(int i=0;i<n;i++){
			x[i+1]=ir.nextInt();
			y[i+1]=ir.nextInt();
		}
		cx=compress(x);
		cy=compress(y);
		Arrays.sort(x);
		Arrays.sort(y);
		dp=new int[n+2][n+2][n+2][n+2];
		out.println(dfs(0,0,n+1,n+1));
	}

	static int dfs(int lx,int ly,int rx,int ry){
		if(dp[lx][ly][rx][ry]>0)
			return dp[lx][ly][rx][ry];
		int ret=0;
		boolean f=false;
		for(int i=0;i<dp.length;i++){
			if(cx[i]>lx&&cx[i]<rx&&cy[i]>ly&&cy[i]<ry){
				ret=Math.max(ret,dfs(lx,ly,cx[i],cy[i])+dfs(lx,cy[i],cx[i],ry)+dfs(cx[i],ly,rx,cy[i])+dfs(cx[i],cy[i],rx,ry));
				f=true;
			}
		}
		if(f)
			ret+=x[rx]+y[ry]-x[lx]-y[ly]-3;
		return dp[lx][ly][rx][ry]=ret;
	}

	public static int[] compress(int[] a) {
		int n = a.length;
		int[] r=a.clone();
		Arrays.sort(r);
		int[] ret = new int[n];
		for (int i = 0; i < n; i++)
			ret[i] =lower_bound(r,0,n-1,a[i]);
		return ret;
	}

	public static int lower_bound(int[] a, int fromIndex, int toIndex, int val) {
		if (val > a[toIndex])
			return toIndex + 1;
		if (val <= a[fromIndex])
			return fromIndex;
		int lb = fromIndex - 1, ub = toIndex;
		while (ub - lb > 1) {
			int mid = (ub - lb)/2+lb;
			if (a[mid] >= val) {
				ub = mid;
			} else {
				lb = mid;
			}
		}
		return ub;
	}

	public static void main(String[] args) throws Exception {
		ir = new InputReader(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.flush();
	}

	static class InputReader {

		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int curbuf;
		private int lenbuf;

		public InputReader(InputStream in) {
			this.in = in;
			this.curbuf = this.lenbuf = 0;
		}

		public boolean hasNextByte() {
			if (curbuf >= lenbuf) {
				curbuf = 0;
				try {
					lenbuf = in.read(buffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return false;
			}
			return true;
		}

		private int readByte() {
			if (hasNextByte())
				return buffer[curbuf++];
			else
				return -1;
		}

		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}

		private void skip() {
			while (hasNextByte() && isSpaceChar(buffer[curbuf]))
				curbuf++;
		}

		public boolean hasNext() {
			skip();
			return hasNextByte();
		}

		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isSpaceChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}

		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}

		public char[][] nextCharMap(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}
}