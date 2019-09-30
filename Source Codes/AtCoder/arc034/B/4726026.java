import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		/*
		 * ??
		 *
		 * N????10^18??2^60?????
		 * N????????????
		 * ????????????????????
		 * ???????0-9??????????????10*18?180??????????????
		 * ???0?????????????????????
		 *
		 * ???
		 * ?????N?????????x>>f(x)????
		 * ???f(x)?1-162???????????????
		 * f(x)???????????
		 */
		int kazu=0;
		long N=sc.nextLong();
		boolean[] ans=new boolean[163];
		for(long i=1; i<=162; i++) {
			long zan=N-i;
			if(ketawa(zan)==i) {
				ans[(int)i]=true;
				kazu++;
			}
		}
		pl(kazu);
		for(int i=162; i>0; i--) {
			if(ans[i]) {
				pl(N-((long)i));
			}
		}
	}
	public static long ketawa(long a) {
		long sum=0;
		while(a>0) {
			sum+=a%10;
			a/=10;
		}
		return sum;
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