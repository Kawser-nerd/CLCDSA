import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		String s=sc.next();
		int a=sc.nextInt();
		int b=sc.nextInt()+1;
		int c=sc.nextInt()+2;
		int d=sc.nextInt()+3;

		if(a!=0) {
			s=s.substring(0, a)+"\""+s.substring(a);
		}
		else if(a==0) {
			s="\""+s;
		}
		s=s.substring(0, b)+"\""+s.substring(b);
		s=s.substring(0, c)+"\""+s.substring(c);
		s=s.substring(0, d)+"\""+s.substring(d);
		System.out.println(s);
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