import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		long N=sc.nextInt();
		long A=sc.nextInt();
		long B=sc.nextInt();
		long diff=0;
		long min=Integer.MAX_VALUE;
		long max=0;
		long sum=0;
		for(int i=0; i<N; i++) {
			int tmp=sc.nextInt();
			min=Math.min(tmp,min);
			max=Math.max(tmp, max);
			sum+=tmp;
		}
		diff=max-min;
		double comperss=B/((double)max-min);
		double hkn=((double)sum)/N*comperss;
		if(diff==0) {
			System.out.println(-1);
		}
		else {
			System.out.println(comperss+" "+(A-hkn));
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
	}
}