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
		long[][] p=new long[N][2];
		for(int i=0; i<N; i++) {
			p[i][0]=sc.nextLong();
			p[i][1]=sc.nextLong();
		}
		int sum=0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<i; j++) {
				for(int k=0; k<j; k++) {
					long a1= p[i][0]-p[k][0];
					long a2= p[i][1]-p[k][1];
					long b1= p[j][0]-p[k][0];
					long b2= p[j][1]-p[k][1];
					if(Math.abs(a1*b2-a2*b1)%2==0 && Math.abs(a1*b2-a2*b1)>=1) {
						sum++;
					}
				}
			}
		}
		pl(sum);
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