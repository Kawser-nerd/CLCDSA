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
		int C=sc.nextInt();
		int[][] iwakan=new int[C][C];
		for(int i=0; i<C; i++) {
			for(int j=0; j<C; j++) {
				iwakan[i][j]=sc.nextInt();
			}
		}
		int[] iwa_min=new int[C];
		for(int i=0; i<C; i++) {
			iwa_min[i]=Integer.MAX_VALUE;
			for(int j=0; j<C; j++) {
				if(i!=j) {
					iwa_min[i]=Math.min(iwa_min[i], iwakan[i][j]);
				}
			}
			//pl(i+" "+iwa_min[i]);
		}
		int[][] color=new int[N][N];
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				color[i][j]=sc.nextInt()-1;
			}
		}
		int[] mod0_color=new int[C];
		int[] mod1_color=new int[C];
		int[] mod2_color=new int[C];
		for(int i=0; i<C; i++) {
			mod0_color[i]=0;
			mod1_color[i]=0;
			mod2_color[i]=0;
		}
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if((i+j)%3==0) {
					mod0_color[color[i][j]]++;
				}
				else if((i+j)%3==1) {
					mod1_color[color[i][j]]++;
				}
				else if((i+j)%3==2) {
					mod2_color[color[i][j]]++;
				}
			}
		}
		//mod 0 ??
		long sum_iwa=Long.MAX_VALUE;
		long tmp_iwa=0;
/*		for(int i=0; i<C; i++) {		//???????
			tmp_iwa=0;
			for(int j=0; j<C; j++) {
				if(i!=j) {
					tmp_iwa+=mod0_color[j]*iwakan[j][i];
					pl(mod0_color[j]*iwakan[j][i]+" i!=j");
				}
				else if(i==j) {
					tmp_iwa+=(mod1_color[j]+mod2_color[j])*iwa_min[i];
					pl((mod1_color[j]+mod2_color[j])*iwa_min[i]+" i==j");
				}
			}
			pl("sum_iwa"+tmp_iwa);
			sum_iwa=Math.min(sum_iwa, tmp_iwa);
		}*/

		for(int i=0; i<C; i++) {		//mod 0??
			for(int j=0; j<C; j++) {	//mod 1??
				for(int k=0; k<C; k++) {//mod 2??
					tmp_iwa=0;
					if(i!=j && j!=k && k!=i) {
						for(int l=0; l<C; l++) {
							if(i!=l) {
								tmp_iwa+=mod0_color[l]*iwakan[l][i];
							}
						}
						for(int l=0; l<C; l++) {
							if(j!=l) {
								tmp_iwa+=mod1_color[l]*iwakan[l][j];
							}
						}
						for(int l=0; l<C; l++) {
							if(k!=l) {
								tmp_iwa+=mod2_color[l]*iwakan[l][k];
							}
						}
						sum_iwa=Math.min(tmp_iwa, sum_iwa);
					}
				}
			}
		}
		pl(sum_iwa);
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
	public static void p(Object o) {
		System.out.print(o);
	}
}