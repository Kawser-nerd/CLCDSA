import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;
class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int N=sc.nextInt();
		int K=sc.nextInt();
		int[] ary=new int[N];
		int[] dp=new int[N];
		Arrays.fill(dp,0);
		int sum=0;
		for(int i=0; i<N; i++) {
			ary[i]=sc.nextInt();
		}
		dp[0]=1;
		for(int i=1; i<N; i++) {
			if(ary[i]>ary[i-1]) {
				dp[i]=dp[i-1]+1;
			}
			else {
				dp[i]=1;
			}
		}
		for(int i=0; i<N; i++) {
			if(dp[i]>=K) {
				sum++;
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
}