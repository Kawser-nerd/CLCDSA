import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

class Main{
	static boolean[][] nakama=new boolean[13][13];
	static boolean[] zoku=new boolean[13];
	static int N;
	static int M;
	static int p=0;
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		N=sc.nextInt();
		M=sc.nextInt();
		for(int i=0; i<M; i++) {
			int f=sc.nextInt();
			int t=sc.nextInt();
			nakama[f][t]=true;
			nakama[t][f]=true;
		}
		int t=1;
		for(int i=0; i<N; i++) {
			t*=2;
		}
		for(int i=1; i<=t; i++) {
			int tmp=i;
			for(int j=1; j<=N; j++) {
				if(tmp%2==0) {
					zoku[j]=false;
				}
				else if(tmp%2==1) {
					zoku[j]=true;
				}
				tmp/=2;
			}
			if(nakama()) {
				int tmmp=0;
				for(int ii=0; ii<=N; ii++) {
					if(zoku[ii]) {
						tmmp++;
					}
				}
				p=Math.max(p, tmmp);
			}
		}
		pl(p);
	}
	public static boolean nakama() {
		for(int i=1; i<=N; i++) {
			if(zoku[i]) {
				for(int j=1; j<=N; j++) {
					if(i!=j) {
						if(zoku[j]) {
							if(!nakama[i][j]) {
								return false;
							}
						}
					}
				}
			}
		}
		return true;
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