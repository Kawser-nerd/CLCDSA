import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		/*
		 * ?????????
		 */
		int H=sc.nextInt();
		int W=sc.nextInt();
		long[][] cost=new long[10][10];
		for(int i=0; i<10; i++) {
			for(int j=0; j<10; j++) {
				cost[i][j]=sc.nextLong();
			}
		}
		for(int k=0; k<10; k++) {
			for(int i=0; i<10; i++) {
				for(int j=0; j<10; j++) {
					cost[i][j]=Math.min(cost[i][j], cost[i][k]+cost[k][j]);
				}
			}
		}
		int[][] moji=new int[H][W];
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				moji[i][j]=sc.nextInt();
			}
		}
		long sum=0;
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				if(moji[i][j]!=-1) {
					sum+=cost[moji[i][j]][1];
				}
			}
		}
		pl(sum);
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