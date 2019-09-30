import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		long N=sc.nextLong();
		long X=sc.nextLong();
		long sum=0;
		if(X>N/2) {
			X=N-X;
		}
		long big=N-X;
		long mini=X;
		sum=N;
		while(true) {
			if(big%mini!=0) {
				sum+=mini*2*(big/mini);
				long tmp=mini;
				mini=big%mini;
				big=tmp;
			}
			else {
				sum+=mini*((big/mini)*2-1);
				break;
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