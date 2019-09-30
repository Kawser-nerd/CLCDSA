import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

class Main{
	static int[][] dp1,dp2,dp3,dp4;
	static int[] x_vec= {0,1,0,-1};
	static int[] y_vec= {1,0,-1,0};
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int R=sc.nextInt();
		int C=sc.nextInt();
		int K=sc.nextInt();
		dp1=new int[R][C];
		dp2=new int[R][C];
		dp3=new int[R][C];
		dp4=new int[R][C];
		int[][] kabe=new int[R][C];
		String s="";
		for(int i=0; i<R; i++) {
			s=sc.next();
			for(int j=0; j<C; j++) {
				if(s.charAt(j)=='x') {
					kabe[i][j]=1;
					dp1[i][j]=0;//??????
					dp2[i][j]=0;//??????
					dp3[i][j]=0;//??????
					dp4[i][j]=0;//??????
				}
				else {
					kabe[i][j]=0;
					dp1[i][j]=-1;	//?????? 0????????????????-1???????????????????????0???????
					dp2[i][j]=-1;//??????
					dp3[i][j]=-1;	//?????? 0????????????????-1???????????????????????0???????
					dp4[i][j]=-1;//??????
				}
			}
		}
		for(int i=0; i<C; i++) {
			if(kabe[0][i]==0) {
				dp1[0][i]=1;	//????????????????1?????????????
				dp2[0][i]=1;
				dp3[0][i]=1;
				dp4[0][i]=1;
			}
			if(kabe[R-1][i]==0) {
				dp1[R-1][i]=1;	//????????????????1?????????????
				dp2[R-1][i]=1;
				dp3[R-1][i]=1;
				dp4[R-1][i]=1;
			}
		}
		for(int i=0; i<R; i++) {
			if(kabe[i][0]==0) {
				dp1[i][0]=1;
				dp2[i][0]=1;
				dp3[i][0]=1;
				dp4[i][0]=1;
			}
			if(kabe[i][C-1]==0) {
				dp1[i][C-1]=1;
				dp2[i][C-1]=1;
				dp3[i][C-1]=1;
				dp4[i][C-1]=1;
			}
		}
		for(int i=1; i<R-1; i++) {
			for(int j=1; j<C-1; j++) {
				if(kabe[i][j]==0) {
					dp1(i,j);
				}
			}
		}
		for(int i=R-2; i>=1; i--) {
			for(int j=1; j<C-1; j++) {
				if(kabe[i][j]==0) {
					dp2(i,j);
				}
			}
		}
		for(int i=1; i<R-1; i++) {
			for(int j=C-2; j>=1; j--) {
				if(kabe[i][j]==0) {
					dp3(i,j);
				}
			}
		}
		for(int i=R-2; i>=1; i--) {
			for(int j=C-2; j>=1; j--) {
				if(kabe[i][j]==0) {
					dp4(i,j);
				}
			}
		}
		int counter=0;
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				if(Math.min(Math.min(dp1[i][j], dp2[i][j]), Math.min(dp3[i][j], dp4[i][j]))>=K) {
					counter++;
				}
			}
		}
		pl(counter);
	}
	static void dp1(int i,int j) {
		int min=1200;
		for(int p=0; p<4; p++) {
			if(dp1[i+y_vec[p]][j+x_vec[p]]>=0) {
				min=Math.min(min, dp1[i+y_vec[p]][j+x_vec[p]]);
			}
		}
		dp1[i][j]=min+1;
	}
	static void dp2(int i,int j) {
		int min=1200;
		for(int p=0; p<4; p++) {
			if(dp2[i+y_vec[p]][j+x_vec[p]]>=0) {
				min=Math.min(min, dp2[i+y_vec[p]][j+x_vec[p]]);
			}
		}
		dp2[i][j]=min+1;
	}
	static void dp3(int i,int j) {
		int min=1200;
		for(int p=0; p<4; p++) {
			if(dp3[i+y_vec[p]][j+x_vec[p]]>=0) {
				min=Math.min(min, dp3[i+y_vec[p]][j+x_vec[p]]);
			}
		}
		dp3[i][j]=min+1;
	}
	static void dp4(int i,int j) {
		int min=1200;
		for(int p=0; p<4; p++) {
			if(dp4[i+y_vec[p]][j+x_vec[p]]>=0) {
				min=Math.min(min, dp4[i+y_vec[p]][j+x_vec[p]]);
			}
		}
		dp4[i][j]=min+1;
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
	}
}