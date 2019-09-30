import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
class Main{
	static int[] cases;
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();
		int have=0;
		cases=new int[N+1];
		for(int i=0; i<=N; i++) {
			cases[i]=i-1;
		}
		for(int i=0; i<M; i++) {
			int s=sc.nextInt();
			swap(have,s);
			have=s;
		}
		int[] seiretu=new int[N];
		for(int i=0; i<=N; i++) {
			if(cases[i]==-1) {
				//
			}
			else {
				seiretu[cases[i]]=i;
			}
		}
		for(int i=0; i<N; i++) {
			pl(seiretu[i]);
		}
	}
	static void swap(int p,int q) {
		int a=cases[p];
		cases[p]=cases[q];
		cases[q]=a;
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