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
		String s=sc.next();
		char[] shortcut= {'X','Y','A','B'};
		int[] dp=new int[N+1];
		int min=114514;
		int INF=114514;
		for(int i=0; i<16; i++) {
			for(int j=0; j<16; j++) {
				if(i!=j) {
					for(int k=1; k<=N; k++) {
						dp[k]=INF;
					}
					dp[0]=0;
					dp[1]=1;
					for(int k=1; k<N; k++) {
						if(s.charAt(k)==shortcut[i/4] && s.charAt(k-1)==shortcut[i%4]) {
							dp[k+1]=Math.min(dp[k]+1, dp[k-1]+1);
						}
						else if(s.charAt(k)==shortcut[j/4] && s.charAt(k-1)==shortcut[j%4]) {
							dp[k+1]=Math.min(dp[k]+1, dp[k-1]+1);
						}
						else {
							dp[k+1]=dp[k]+1;
						}
					}
					min=Math.min(min, dp[N]);
				}
				else if(i==j) {
					continue;
				}
			}
		}
		pl(min);
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