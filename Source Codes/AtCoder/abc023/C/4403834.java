import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int R,C,K,N;
	static int[][] mono;
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		R=sc.nextInt();
		C=sc.nextInt();
		K=sc.nextInt();
		N=sc.nextInt();
		int[] Gyo=new int[R];
		int[] Ret=new int[C];
		Arrays.fill(Gyo,0);
		Arrays.fill(Ret,0);
		int[][] ame=new int[N][2];
		for(int i=0; i<N; i++) {
			ame[i][0]=sc.nextInt()-1;
			ame[i][1]=sc.nextInt()-1;
			Gyo[ame[i][0]]++;
			Ret[ame[i][1]]++;
		}
		long motoK=0;
		long siteK=0;
		long siteK1=0;

		for(int i=0; i<N; i++) {
			if(Gyo[ame[i][0]]+Ret[ame[i][1]]==K) {
				siteK++;
			}
			else if(Gyo[ame[i][0]]+Ret[ame[i][1]]==K+1) {
				siteK1++;
			}
		}
		int[] gy=new int[100001];
		int[] rt=new int[100001];
		Arrays.fill(gy, 0);
		Arrays.fill(rt, 0);
		for(int i=0; i<R; i++) {
			gy[Gyo[i]]++;
		}
		for(int i=0; i<C; i++) {
			rt[Ret[i]]++;
		}
		for(int i=0; i<=K; i++) {
			motoK+=(rt[i])*(gy[K-i]);
		}
		pl(motoK-siteK+siteK1);
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