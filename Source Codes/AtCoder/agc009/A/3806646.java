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
		int[][] sw=new int[N][2];
		long cnt=0;
		for(int i=0; i<N; i++) {
			sw[i][0]=sc.nextInt();
			sw[i][1]=sc.nextInt();
		}
		for(int i=N-1; i>=0; i--) {
			if((cnt+sw[i][0])%sw[i][1]==0) {
				//
			}
			else {
				cnt+=sw[i][1]-(cnt+sw[i][0])%sw[i][1];
			}
		}
		System.out.println(cnt);
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
}