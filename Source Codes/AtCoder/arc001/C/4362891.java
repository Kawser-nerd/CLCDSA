import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		int[] dp=new int[51];
		int mae=sc.nextInt();
		int ato=sc.nextInt();
		int INF=1000000007;
		Arrays.fill(dp, INF);
		dp[0]=0;
		dp[1]=1;
		dp[2]=2;
		dp[3]=3;
		dp[4]=2;
		dp[5]=1;
		dp[6]=2;
		dp[7]=3;
		dp[8]=3;
		dp[9]=2;
		dp[10]=1;
		for(int i=11; i<=50; i++) {
			dp[i]=i/10+dp[i%10];
		}
		pl(dp[Math.abs(mae-ato)]);
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