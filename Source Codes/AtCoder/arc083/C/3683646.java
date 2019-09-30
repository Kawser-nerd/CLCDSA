import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {

	static PrintWriter out;
	static InputReader ir;
	static boolean debug = false;
    static final int INF=(int)1e8;

	static void solve() {
        int n=ir.nextInt();
        Graph[] g=new Graph[n];
        for(int i=0;i<n;i++){
            g[i]=new Graph();
        }
        int[] p=ir.nextIntArray(n-1);
        for(int i=0;i<n-1;i++){
            p[i]--;
            g[p[i]].add(i+1);
        }
        int[] x=ir.nextIntArray(n);
        int[][] dep=new int[n][2];
        dfs(0,0,dep,g);
        Arrays.sort(dep,new Comparator<int[]>(){
            public int compare(int[] A,int[] B){
                return B[0]-A[0];
            }
        });
        int[] tdp=new int[n];
        for(int i=0;i<n;i++){
            int cur=dep[i][1];
            if(g[cur].size()==0){
                continue;
            }
            int[][] dp=new int[g[cur].size()+1][x[cur]+1];
            for(int j=0;j<g[cur].size();j++){
                Arrays.fill(dp[j],INF);
            }
            for(int j=g[cur].size()-1;j>=0;j--){
                int ch=g[cur].get(j);
                for(int k=0;k<=x[cur];k++){
                    if(k+x[ch]<=x[cur]){
                        dp[j][k]=Math.min(dp[j][k],dp[j+1][k+x[ch]]+tdp[ch]);
                    }
                    if(k+tdp[ch]<=x[cur]){
                        dp[j][k]=Math.min(dp[j][k],dp[j+1][k+tdp[ch]]+x[ch]);
                    }
                }
            }
            if(dp[0][0]>=INF){
                out.println("IMPOSSIBLE");
                return;
            }
            tdp[cur]=dp[0][0];
        }
        out.println("POSSIBLE");
	}

    static class Graph extends ArrayList<Integer>{}

    static void dfs(int cur,int d,int[][] dep,Graph[] g){
        dep[cur][0]=d;
        dep[cur][1]=cur;
        for(int i=0;i<g[cur].size();i++){
            dfs(g[cur].get(i),d+1,dep,g);
        }
    }

	public static void main(String[] args) {
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

	static void tr(Object... o) {
		if (debug)
			out.println(Arrays.deepToString(o));
	}
}