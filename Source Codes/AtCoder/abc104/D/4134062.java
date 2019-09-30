import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

class Main{
	static final long MOD=1000000007;
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		String s=sc.next();
		int len=s.length();
		long[][] dp=new long[len+1][4];
		for(int i=0; i<=len; i++) {
			for(int j=0; j<4; j++) {
				dp[i][j]=0;
			}
		}
		dp[0][0]=1;dp[0][1]=0;dp[0][2]=0;dp[0][3]=0;
		for(int i=1; i<=len; i++) {
			if(s.charAt(i-1)=='A') {
				dp[i][0]=dp[i-1][0];
				dp[i][1]=(dp[i-1][1]+dp[i-1][0])%MOD;
				dp[i][2]=dp[i-1][2];
				dp[i][3]=dp[i-1][3];
			}
			else if(s.charAt(i-1)=='B') {
				dp[i][0]=dp[i-1][0];
				dp[i][1]=dp[i-1][1];
				dp[i][2]=(dp[i-1][2]+dp[i-1][1])%MOD;
				dp[i][3]=dp[i-1][3];
			}
			else if(s.charAt(i-1)=='C') {
				dp[i][0]=dp[i-1][0];
				dp[i][1]=dp[i-1][1];
				dp[i][2]=dp[i-1][2];
				dp[i][3]=(dp[i-1][3]+dp[i-1][2])%MOD;
			}
			else{
				dp[i][3]=(dp[i-1][3]*3+dp[i-1][2])%MOD;
				dp[i][2]=(dp[i-1][2]*3+dp[i-1][1])%MOD;
				dp[i][1]=(dp[i-1][1]*3+dp[i-1][0])%MOD;
				dp[i][0]=(dp[i-1][0]*3)%MOD;
			}
		}
		pl(dp[len][3]);
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