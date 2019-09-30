import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

public class Main {
	public static void main (String[] args) throws Exception {
		SC sc=new SC(System.in);
		int H=sc.nextInt();
		int W=sc.nextInt();
		int D=sc.nextInt();
		int[][] map=new int[H*W+1][2];
		int[][] ary=new int[H][W];
		int[][] ans=new int[D][H*W/D+2];
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				ary[i][j]=sc.nextInt();
				map[ary[i][j]][0]=i;
				map[ary[i][j]][1]=j;
			}
		}
		for(int i=0; i<D; i++) {
			for(int j=i; j<=H*W; j+=D) {
				if(j==i) {
					ans[i][0]=0;
				}
				else {
					ans[i][(j-i)/D]=Math.abs(map[j][0]-map[j-D][0])+Math.abs(map[j][1]-map[j-D][1]);
					ans[i][(j-i)/D]+=ans[i][(j-i)/D-1];
				}
			}
		}
		int Q=sc.nextInt();
		for(int i=0; i<Q; i++) {
			int from=sc.nextInt();
			int to=sc.nextInt();
			int mod=from%D;
			if(from<D) {
				pl(ans[mod][(to-mod)/D]);
			}
			else{
				pl(ans[mod][(to-mod)/D]-ans[mod][(from-mod)/D]);
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