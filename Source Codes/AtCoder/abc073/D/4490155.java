import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static long[][] route;
	static int N;
	static int R;
	static int[] r;
	static long cost=3641145141919810L;
	public static void main (String[] args){
		SC sc=new SC(System.in);
		N=sc.nextInt();
		int M=sc.nextInt();
		R=sc.nextInt();
		r=new int[R];
		for(int i=0; i<R; i++) {
			r[i]=sc.nextInt()-1;
		}
		route=new long[N][N];
		long INF=1_145_141_919_810_364L;
		for(int i=0; i<N; i++) {
			Arrays.fill(route[i],INF);
		}
		for(int i=0; i<M; i++) {
			int from=sc.nextInt()-1;
			int to=sc.nextInt()-1;
			long cost=sc.nextLong();
			route[from][to]=cost;
			route[to][from]=cost;
		}
		Warshall_Floyd();
		permute(r,r.length);
		pl(cost);
	}
	public static void permute(int[] v, int n) {
		if (n == 1) {
			long tmp=0;
			for(int i=0; i<R-1; i++) {
				tmp+=route[r[i+1]][r[i]];
			}
			cost=Math.min(cost, tmp);
		}
		else {
			for (int i = 0; i < n; i++) {
				permute(v, n-1);
				if (n % 2 == 1) {
					swap(v, 0, n-1);
				} else {
					swap(v, i, n-1);
				}
			}
		}
	}
	public static void Warshall_Floyd() {
		for(int k=0; k<N; k++) {
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					route[i][j]=Math.min(route[i][j], route[i][k]+route[k][j]);
				}
			}
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
	private static void swap(int[] v, int i, int j) {
		int t = v[i]; v[i] = v[j]; v[j] = t;
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