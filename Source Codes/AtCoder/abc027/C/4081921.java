import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int depth=0;
		long N=sc.nextLong();
		long calcdep=N;
		while(calcdep>0) {
			calcdep/=2;
			depth++;
		}
		if(depth%2==0) {//?????????????????
			for(long i=depth-2; i>=0; i--) {
				if((depth-i)%2==0) {
					if(((N>>i)&1)==1) {
						pl("Takahashi");
						System.exit(0);
					}
				}
				else {
					if(((N>>i)&1)==0) {
						pl("Aoki");
						System.exit(0);
					}
				}
			}
			pl("Takahashi");
		}
		else {
			for(long i=depth-2; i>=0; i--) {
				if((depth-i)%2==1) {
					if(((N>>i)&1)==1) {
						pl("Aoki");
						System.exit(0);
					}
				}
				else {
					if(((N>>i)&1)==0) {
						pl("Takahashi");
						System.exit(0);
					}
				}
			}
			pl("Aoki");
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