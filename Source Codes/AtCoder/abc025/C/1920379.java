import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {

	static PrintWriter out;
	static InputReader ir;

	static void solve() {
		int[][] b=new int[2][];
		for(int i=0;i<2;i++)
			b[i]=ir.nextIntArray(3);
		int[][] c=new int[3][];
		for(int i=0;i<3;i++)
			c[i]=ir.nextIntArray(2);
		int[][] a=new int[3][3];
		int[] ret=dfs(0,a,b,c);
		out.println(ret[0]);
		out.println(ret[1]);
	}

	public static int[] dfs(int turn,int[][] a,int[][] b,int[][] c){
		if(turn==8){
			int p=-1,q=-1;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(a[i][j]==0){
						a[i][j]=1;
						p=i;
						q=j;
					}
				}
			}
			int[] ret=new int[2];
			for(int i=0;i<2;i++){
				for(int j=0;j<3;j++){
					ret[Math.abs((a[i][j]-a[i+1][j]))>>>1]+=b[i][j];
				}
			}
			for(int i=0;i<3;i++){
				for(int j=0;j<2;j++){
					ret[Math.abs((a[i][j]-a[i][j+1]))>>>1]+=c[i][j];
				}
			}
			a[p][q]=0;
			return ret;
		}
		int ma=0,r=(int)1e9;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(a[i][j]==0){
					a[i][j]=(int)Math.pow(-1,turn&1);
					int[] t=dfs(turn+1,a,b,c);
					if(ma<t[turn&1]){
						ma=t[turn&1];
						r=t[(turn&1)^1];
					}
					if(ma==t[turn&1]&&r>t[(turn&1)^1]){
						r=t[(turn&1)^1];
					}
					a[i][j]=0;
				}
			}
		}
		int[] ret=new int[2];
		ret[turn&1]=ma;
		ret[(turn&1)^1]=r;
		return ret;
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