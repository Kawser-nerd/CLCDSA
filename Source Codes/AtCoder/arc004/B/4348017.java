import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;
public class Main {
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int N=sc.nextInt();
		long[] d=new long[N];
		for(int i=0; i<N; i++) {
			d[i]=sc.nextInt();
		}
		Arrays.sort(d);
		long longest=d[N-1];
		long sum=0;
		for(int i=0; i<N-1; i++) {
			sum+=d[i];
		}
		if(N==1) {
			pl(d[0]);
			pl(d[0]);
		}
		else if(N==2) {
			pl(d[0]+d[1]);
			pl(Math.abs(d[0]-d[1]));
		}
		else {
			pl(sum+longest);
			pl(Math.max(0,longest-sum));
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