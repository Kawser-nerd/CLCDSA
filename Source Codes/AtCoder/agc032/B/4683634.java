import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		/*
		 * ?????????? n(n+1)/2-??????
		 * ??????????????????
		 *
		 * ?????????????
		 * ?????????????????????????
		 *
		 */
		int N=sc.nextInt();
		if(N%2==0) {
			int kosu=0;
			boolean[][] list=new boolean[N][N];
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(i!=j) {
						list[i][j]=true;
					}
				}
			}
			for(int i=0; i<N; i++) {
				list[Math.abs(i)][Math.abs(N-1-i)]=false;
			}
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(list[i][j]) {
						kosu++;
					}
				}
			}
			pl(kosu/2);
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(i<j) {
						if(list[i][j]) {
							pl((i+1)+" "+(j+1));
						}
					}
				}
			}
		}
		else if(N%2==1) {
			int kosu=0;
			boolean[][] list=new boolean[N][N];
			for(int i=0; i<N-1; i++) {
				for(int j=0; j<N-1; j++) {
					if(i!=j) {
						list[i][j]=true;
					}
				}
			}
			for(int i=0; i<N-1; i++) {
				list[Math.abs(i)][Math.abs(N-2-i)]=false;
			}
			for(int i=0; i<N-1; i++) {
				list[N-1][i]=true;
				list[i][N-1]=true;
			}
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(list[i][j]) {
						kosu++;
					}
				}
			}
			pl(kosu/2);
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(i<j) {
						if(list[i][j]) {
							pl((i+1)+" "+(j+1));
						}
					}
				}
			}
		}
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