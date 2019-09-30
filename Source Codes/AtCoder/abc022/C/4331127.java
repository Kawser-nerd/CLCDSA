import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) throws ClassNotFoundException, IOException {
		SC sc=new SC(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();
		long INF=1000000007;
		long[] gyouretu=new long[N*N];
		Arrays.fill(gyouretu, INF);
		for(int i=0; i<M; i++) {
			int f=sc.nextInt()-1;
			int t=sc.nextInt()-1;
			long c=sc.nextLong();
			gyouretu[f*N+t]=c;
			gyouretu[t*N+f]=c;
		}
		for(int i=1; i<N; i++) {
			for(int j=1; j<N; j++) {
				for(int k=1; k<N; k++) {
					gyouretu[j*N+k]=Math.min(gyouretu[j*N+k], gyouretu[j*N+i]+gyouretu[i*N+k]);
				}
			}
		}
		long min=1145141919810L;
		for(int i=1; i<N; i++) {
			for(int j=1; j<N; j++) {
				if(i<j) {
					min=Math.min(min, gyouretu[i]+gyouretu[i*N+j]+gyouretu[j]);
				}
			}
		}
		if(min>=INF) {
			pl(-1);
		}
		else {
			pl(min);
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