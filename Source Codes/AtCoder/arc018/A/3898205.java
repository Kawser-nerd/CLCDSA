import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		double he=sc.nextDouble()/100;
		double BMI=sc.nextDouble();
		pl(BMI*he*he);
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
	public static void p(Object o) {
		System.out.print(o);
	}
	public static boolean isPrime(int a) {
		if(a<4) {
			if(a==2 || a==3) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			for(int j=2; j*j<=a; j++) {
				if(a%j==0) {
					return false;
				}
				if(a%j!=0 && (j+1)*(j+1)>a) {
					return true;
				}
		}
		return true;
		}
	}
}