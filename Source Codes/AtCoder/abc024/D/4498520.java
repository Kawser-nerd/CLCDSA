import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
public class Main {
	static final int MOD = 1000000007;
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		final long A = sc.nextLong();
		final long B = sc.nextLong();
		final long C = sc.nextLong();
		long div = getInverse(getMod(A*(B+C)-B*C));
		long c = getMod(getMod(B*(C-A))*div);
		long r = getMod(getMod(C*(B-A))*div);
		pl(r +" "+ c);
		/*
		 * A = r+c   C c
		 * B = r+c+1 C c
		 * C = r+c+1 C c+1
		 *
		 * ????
		 *
		 * B/A = (c+r+1)/(r+1)  *1
		 * C/A = (c+r+1)/(c+1)  *2
		 *
		 * *1,*2???2???????????????r???c????????????????
		 * (C/A)*(1-A/B) = c/(c+1)
		 * ????
		 * 1 - (C/A)*(1-A/B) = 1/(c+1)
		 *
		 * ??? (C*B-C*A)/(A*B-C*B+C*A)
		 * ?MOD????????????????????????????
		 *
		 * A/B=C?????? A*(B^-1)?????
		 *
		 * ????
		 * c = (C*B-C*A) * (A*B-C*B+C*A)??????
		 * ????
		 *
		 * ???r?????
		 *
		 * r = (B*C - A*C) / (A*B-B*C+A*C)???
		 *
		 * r = (A*C-A*C) * (A*B-B*C+A*C)??????
		 * ???
		 */
	}
	static long getPower(long a, int n) {		//???????
		if(n == 0){
			return 1;
		}else if(n % 2 == 0){
			return getPower(getMod(a*a), n/2);
		}else{
			return getMod(a*getPower(a,n-1));
		}
	}
	static long getInverse(long a) {
		return getPower(a, MOD-2);
	}
	static long getMod(long a){
		if(a >= 0){
			return a%MOD;
		}
		else{
			return MOD + a%MOD;
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
}