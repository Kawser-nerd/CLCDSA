import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;
class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();
		int[] namep=new int[26];
		int[] seal=new int[26];
		Arrays.fill(namep,0);
		Arrays.fill(seal,0);
		String name=sc.next();
		for(int i=0; i<N; i++) {
			namep[name.charAt(i)-'A']++;
		}
		String kit=sc.next();
		for(int i=0; i<M; i++) {
			seal[kit.charAt(i)-'A']++;
		}
		int max=1;
		for(int i=0; i<26; i++) {
			if(namep[i]>0) {
				if(seal[i]==0) {
					pl(-1);
					System.exit(0);
				}
				else if(seal[i]>0) {
					max=Math.max(max,(namep[i]+seal[i]-1)/seal[i] );
				}
			}
		}
		pl(max);
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