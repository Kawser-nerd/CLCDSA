import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
class Main{
	static int[][] cases;
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int N=sc.nextInt();
		cases=new int[N][3];
		for(int i=0; i<N; i++) {
			cases[i][0]=sc.nextInt();
			cases[i][1]=sc.nextInt();
			cases[i][2]=sc.nextInt();
			sort(i);
		}
		int a=0;
		int b=0;
		int c=0;
		for(int i=0; i<N; i++) {
			a=Math.max(a, cases[i][0]);
			b=Math.max(b, cases[i][1]);
			c=Math.max(c, cases[i][2]);
		}
		pl(a*b*c);
	}
	public static void sort(int p) {
		int sm=cases[p][0]+cases[p][1]+cases[p][2];
		int mx=Math.max(cases[p][0], Math.max(cases[p][1], cases[p][2]));
		int mn=Math.min(cases[p][0], Math.min(cases[p][1], cases[p][2]));
		int md=sm-mx-mn;
		cases[p][0]=mn;
		cases[p][1]=md;
		cases[p][2]=mx;
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