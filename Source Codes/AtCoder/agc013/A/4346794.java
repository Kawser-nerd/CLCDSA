import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		int N=sc.nextInt();
		int[] ary=new int[N];
		for(int i=0; i<N; i++) {
			ary[i]=sc.nextInt();
		}
		int zougen=0;
		int counter=0;
		int now=ary[0];
		for(int i=1; i<N; i++) {
			if(now==ary[i]) {
				//???????????
			}
			else {
				if(zougen==0) {	//????????
					if(now>ary[i]) {//??
						zougen=-1;
						now=ary[i];
					}
					else if(now<ary[i]) {//??
						zougen=1;
						now=ary[i];
					}
				}
				else if(zougen==1) {	//????
					if(now>ary[i]) {//????????
						zougen=0;
						counter++;
						now=ary[i];
					}
					else if(now<=ary[i]) {//??
						zougen=1;
						now=ary[i];
					}
				}
				else if(zougen==-1) {	//????
					if(now>ary[i]) {//????????
						now=ary[i];
					}
					else if(now<=ary[i]) {//?????????
						zougen=0;
						counter++;
						now=ary[i];
					}
				}
			}
		}
		counter++;
		pl(counter);
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