import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();
		long INF=1000000007L;
		/*
		 * ?????????
		 */
		long[][] time=new long[N][N];
		long[][] bus=new long[N][2];
		for(int i=0; i<N; i++) {
			bus[i][0]=0L;
			bus[i][1]=i+1;
		}
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				time[i][j]=INF;
			}
		}
		for(int i=0; i<M; i++) {
			int from=sc.nextInt()-1;
			int to=sc.nextInt()-1;
			long cost=sc.nextLong();
			time[from][to]=cost;
			time[to][from]=cost;
		}
		for(int k=0; k<N; k++) {
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					time[i][j]=Math.min(time[i][j], time[i][k]+time[k][j]);
				}
			}
		}
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(i!=j) {
					bus[i][0]=Math.max(bus[i][0], time[i][j]);
				}
			}
		}
		for(int i=0; i<N; i++) {
			//pl(bus[i][0]);
		}
		quick_sort(bus,0,N-1);
		pl(bus[0][0]);
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
	static void quick_sort(long[][] d, int left, int right) {
		if (left>=right) {
			return;
		}
		long p = d[(left+right)/2][0];
		int l = left, r = right;
		long tmp,tmp1,tmp2;
		while(l<=r) {
			while(d[l][0] < p) { l++; }
			while(d[r][0] > p) { r--; }
			if (l<=r) {
				tmp = d[l][0]; d[l][0] = d[r][0]; d[r][0] = tmp;
				tmp1=d[l][1]; tmp2=d[r][1]; d[l][1]=tmp2; d[r][1]=tmp1;
				l++; r--;
			}
		}
		quick_sort(d, left, r);
		quick_sort(d, l, right);
	}
}