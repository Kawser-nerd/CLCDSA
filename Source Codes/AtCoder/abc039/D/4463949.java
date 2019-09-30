import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		int H=sc.nextInt();
		int W=sc.nextInt();
		int[][] moto=new int[H][W];
		int[][] hensyu=new int[H][W];
		int[][] res=new int[H][W];
		for(int i=0; i<H; i++) {
			String S=sc.next();
			for(int j=0; j<W; j++) {
				if(S.charAt(j)=='#') {
					moto[i][j]=1;
					hensyu[i][j]=1;
				}
				else {
					moto[i][j]=0;
					hensyu[i][j]=0;
				}
				res[i][j]=0;
			}
		}
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				int base=moto[i][j];
				for(int k=-1; k<=1; k++) {
					for(int l=-1; l<=1; l++) {
						if(i+k>=0 && i+k<H) {
							if(j+l>=0 && j+l<W) {
								if(base==0) {
									hensyu[i+k][j+l]=0;
								}
							}
						}
					}
				}
			}
		}
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				if(hensyu[i][j]==1) {
					for(int k=-1; k<=1; k++) {
						for(int l=-1; l<=1; l++) {
							if(i+k>=0 && i+k<H) {
								if(j+l>=0 && j+l<W) {
									res[i+k][j+l]=1;
								}
							}
						}
					}
				}
			}
		}
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				if(res[i][j]!=moto[i][j]) {
					pl("impossible");
					System.exit(0);
				}
			}
		}
		pl("possible");
		for(int i=0; i<H; i++) {
			StringBuilder sb=new StringBuilder();
			for(int j=0; j<W; j++) {
				if(hensyu[i][j]==1) {
					sb.append('#');
				}
				else {
					sb.append('.');
				}
			}
			pl(sb.toString());
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