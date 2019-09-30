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
		/*
		 * ??
		 * ??????????
		 * ???1?????1??????????????????
		 * DP????????????????
		 *
		 */
		int R=sc.nextInt();
		int C=sc.nextInt();
		int D=sc.nextInt();
		int[][] okane=new int[R][C];
		int[] dp=new int[R+C+1];
		Arrays.fill(dp,0);
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				okane[i][j]=sc.nextInt();
			}
		}
		dp[0]=okane[0][0];
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				int manhattan=i+j;	//??????????????????????????ABS?????????
				dp[manhattan]=Math.max(dp[manhattan],okane[i][j]);
			}
		}
		for(int i=2; i<=R+C; i+=2) {
			dp[i]=Math.max(dp[i], dp[i-2]);
		}
		for(int i=3; i<=R+C; i+=2) {
			dp[i]=Math.max(dp[i], dp[i-2]);
		}
		int max=0;
		if(D%2==0) {
			for(int i=0; i<=Math.min(D,R+C); i+=2) {
				max=Math.max(max, dp[i]);
			}
		}
		else if(D%2==1) {
			for(int i=1; i<=Math.min(D,R+C); i+=2) {
				max=Math.max(max, dp[i]);
			}
		}
		pl(max);
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