import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int s=sc.nextInt();
		int t=sc.nextInt();
		String a=sc.next();
		String b=sc.next();
		int gcdd=(int) gcd(a.length(),b.length());
		for(int i=0; i<gcdd; i++) {
			if(a.charAt(s/gcdd*i)!=b.charAt(t/gcdd*i)) {
				System.out.println(-1);
				System.exit(0);
			}
		}
		System.out.println(lcm(a.length(),b.length()));
	}
	public static long lcm(long m, long n) {
		return m / gcd(m, n)*n;
	}
	public static long gcd(long m, long n) {
		if(m < n) return gcd(n, m);
		if(n == 0) return m;
		return gcd(n, m % n);
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