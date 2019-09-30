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
		int[] ary=new int[N];
		for(int i=0; i<N; i++) {
			ary[i]=sc.nextInt();
		}
		int[] ths=new int[N];
		int[] aok=new int[N];
		for(int i=0; i<N; i++) {
			ths[i]=114514;
			aok[i]=-114514;
		}
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(i!=j) {
					int tkhs=calc_kisu(Math.min(i, j),Math.max(i, j),ary);
					int aoki=calc_gusu(Math.min(i, j),Math.max(i, j),ary);
					if(aoki>aok[i]) {
						aok[i]=aoki;
						ths[i]=tkhs;
					}
					/*else if(aoki==aok[i] && ths[i]>tkhs) {
						aok[i]=aoki;
						ths[i]=tkhs;
					}*/
				}
			}
		}
		int tkhsp=-114514;
		for(int i=0; i<N; i++) {
			tkhsp=Math.max(tkhsp, ths[i]);
		}
		pl(tkhsp);

	}
	public static int calc_kisu(int s,int g,int[] a) {
		int sum=0;
		for(int i=s; i<=g; i+=2) {
			sum+=a[i];
		}
		return sum;
	}

	public static int calc_gusu(int s,int g,int[] a) {
		int sum=0;
		for(int i=s+1; i<=g; i+=2) {
			sum+=a[i];
		}
		return sum;
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