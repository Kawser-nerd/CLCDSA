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
		 * ??
		 * ????????????????????
		 * ????????????????????????O(1)??????????????????
		 * ?????????????2???????????
		 * ?????????O(N^4)???????????O(N^6)???????
		 */
		int H=sc.nextInt();
		int W=sc.nextInt();
		int[][] Bl=new int[H+1][W+1];
		int[][] Wh=new int[H+1][W+1];
		for(int i=0; i<=H; i++) {
			for(int j=0; j<=W; j++) {
				Bl[i][j]=0;
				Wh[i][j]=0;
			}
		}
		for(int i=1; i<=H; i++) {
			for(int j=1; j<=W; j++) {
				if(((i-1)+(j-1))%2==0) {	//?
					Bl[i][j]=sc.nextInt();
				}
				else {
					Wh[i][j]=sc.nextInt();
				}
			}
		}
		for(int i=0; i<=H; i++) {
			for(int j=1; j<=W; j++) {
				Bl[i][j]=Bl[i][j]+Bl[i][j-1];
				Wh[i][j]=Wh[i][j]+Wh[i][j-1];
			}
		}
		for(int i=0; i<=W; i++) {
			for(int j=1; j<=H; j++) {
				Bl[j][i]=Bl[j][i]+Bl[j-1][i];
				Wh[j][i]=Wh[j][i]+Wh[j-1][i];
			}
		}
		int max=0;
		for(int i=0; i<=H; i++) {
			for(int j=0; j<=W; j++) {	//??
				for(int k=1; k<=H-i; k++) {
					for(int l=1; l<=W-j; l++) {
						int sum_B=Bl[k+i][l+j]+Bl[k-1][l-1]-Bl[k-1][l+j]-Bl[k+i][l-1];
						int sum_W=Wh[k+i][l+j]+Wh[k-1][l-1]-Wh[k-1][l+j]-Wh[k+i][l-1];
						if(sum_B==sum_W) {
							max=Math.max(max, (i+1)*(j+1));
						}
						//pl((i+1)*(j*1));
					}
				}
			}
		}
		pl(max);
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