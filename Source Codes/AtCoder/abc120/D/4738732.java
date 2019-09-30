import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		/*
		 * ??????????????????????????
		 * ??????????????
		 * ???????????????????????????????
		 * UnionFnd????????????????????
		 */
		int N=sc.nextInt();
		int M=sc.nextInt();
		int[][] data=new int[M][2];
		long[] res=new long[M+1];
		long fumando=((long)N)*((long)N-1)/2L;
		res[0]=fumando;
		for(int i=M-1; i>=0; i--) {
			data[i][0]=sc.nextInt();
			data[i][1]=sc.nextInt();
		}
		UnionFind UFT=new UnionFind(N+1);
		for(int i=0; i<M; i++) {
			int AR=UFT.find(data[i][0]);
			int BR=UFT.find(data[i][1]);
			long a=(long)UFT.size(AR);
			long b=(long)UFT.size(BR);
			//pl(AR+" "+BR+" "+a+" "+b);
			UFT.union(data[i][0], data[i][1]);
			if(AR!=BR) {
				res[i+1]=res[i]-a*b;
			}
			else {
				res[i+1]=res[i];
			}
		}
		for(int i=M-1; i>=0; i--) {
			pl(res[i]);
		}
	}

	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void pl() {
		System.out.println();
	}
	public static void p(Object o) {
		System.out.print(o);
	}
	public static class UnionFind{
		int[] par; //
		public UnionFind(int n){
			par = new int[n];
			for(int i = 0; i < n; i++){ par[i] = -1; }
		}

		public int find(int x){
			if(par[x] < 0){
				return x;
			}else{
				return par[x] = find(par[x]);
			}
		}

		public boolean union(int x, int y){
			x = find(x);
			y = find(y);

			if(x != y){
				if(par[y] < par[x]) {  // ?????????????????.
					int tmp = x; x = y; y = tmp;
				}
				par[x] += par[y];
				par[y] = x;
				return true;
			}else{
				return false;
			}
		}

		public boolean same(int x, int y){
			return find(x) == find(y);
		}

		public int size(int x){
			return -par[find(x)];
		}
	}
	static class SC {
		private BufferedReader reader = null;
		private StringTokenizer tokenizer = null;
		public SC(InputStream in) {
			reader = new BufferedReader(new InputStreamReader(in));
		}
		public String next() {
			if (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new UncheckedIOException(e);
				}
			}
			return tokenizer.nextToken();
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new UncheckedIOException(e);
			}
		}
	}
}