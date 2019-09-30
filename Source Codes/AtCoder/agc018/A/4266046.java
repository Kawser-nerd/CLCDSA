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
		int K=sc.nextInt();
		int[] A=new int[N];
		for(int i=0; i<N; i++) {
			A[i]=sc.nextInt();
		}
		long gcd=A[0];
		for(int i=1; i<N; i++){
			gcd=gcd(gcd,A[i]);
		}
		//pl(gcd);
		boolean ans=false;
		for(int i=0; i<N; i++) {
			if(A[i]>K) {
				if((A[i]-K)%gcd==0) {
					ans=true;
				}
			}
			else if(A[i]==K) {
				ans=true;
			}
		}
		if(ans) {
			pl("POSSIBLE");
		}
		else {
			pl("IMPOSSIBLE");
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
	public static long lcm(long m, long n) {
		return m / gcd(m, n)*n;
	}
	public static long gcd(long m, long n) {
		if(m < n) return gcd(n, m);
		if(n == 0) return m;
		return gcd(n, m % n);
	}
}