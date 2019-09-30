import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;

public class Main {
	static int MOD = 1000000007;
	static int[][] ary;
	static int[][] ans;
	static int H,W;
	public static void main(String[] args) {
		SC sc = new SC(System.in);
		H=sc.nextInt();
		W=sc.nextInt();
		ary=new int[H][W];
		ans=new int[H][W];
		int res=0;
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				ary[i][j]=sc.nextInt();
				ans[i][j]=0;
			}
		}
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				if(ans[i][j]==0) {
					memo(i,j,-1);
				}
				res+=ans[i][j];
				res%=MOD;
			}
		}
		pl(res);
	}
	public static int memo(int i,int j,int value) {
		if(i<0 || i>=H || j<0 || j>=W) {
			return 0;
		}
		if(ary[i][j]<=value) {
			return 0;
		}
		if(ans[i][j]>0) {
			return ans[i][j];
		}
		int tmp=0;
		tmp = memo(i - 1, j, ary[i][j]);	//????
		tmp %= MOD;
		tmp +=memo(i, j - 1, ary[i][j]);		//????
		tmp %= MOD;
		tmp += memo(i + 1, j, ary[i][j]);		//????
		tmp %= MOD;
		tmp += memo(i, j + 1,ary[i][j]);		//????
		tmp %= MOD;
		tmp+=1;		//????????
		tmp%=MOD;
		ans[i][j] =tmp;
		return tmp;
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