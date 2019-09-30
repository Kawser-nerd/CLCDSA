import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int sq=sc.nextInt();
		String s="";
		int t=0; int a=0;
		for(int i=0; i<sq; i++) {
			s=sc.next();
			for(int j=0; j<sq; j++) {
				if(s.charAt(j)=='R') {
					t++;
				}
				else if(s.charAt(j)=='B') {
					a++;
				}
			}
		}
		if(a==t) {
			System.out.println("DRAW");
		}
		else if(a>t) {
			System.out.println("AOKI");
		}
		else if(a<t) {
			System.out.println("TAKAHASHI");
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