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
		int N=sc.nextInt();
		int M=sc.nextInt();
		long[] ary=new long[M+2];
		Arrays.fill(ary, 0);
		long sum=0;
		for(int i=0; i<N; i++) {
			int from=sc.nextInt();
			int to=sc.nextInt();
			long score=sc.nextLong();
			ary[from]+=score;
			ary[to+1]-=score;
			sum+=score;
		}
		for(int i=1; i<=M+1; i++) {
			ary[i]=ary[i]+ary[i-1];
		}
		long min=Long.MAX_VALUE;
		for(int i=1; i<=M; i++) {
			min=Math.min(min, ary[i]);
		}
		pl(sum-min);
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