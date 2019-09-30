import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();
		int[][] a=new int[N][2];

		for(int i=0; i<N; i++) {
			a[i][0]=1000000+(i+1);
			a[i][1]=(i+1);
		}
		for(int i=0; i<M; i++) {
			a[sc.nextInt()-1][0]=1000000-(i+1);
		}
		quick_sort(a,0,N-1);
		for(int i=0; i<N; i++) {
			System.out.println(a[i][1]);
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
	static void quick_sort(int[][] d, int left, int right) {
		if (left>=right) {
			return;
		}
		int p = d[(left+right)/2][0];
		int l = left, r = right;
		int tmp,tmp1,tmp2;
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