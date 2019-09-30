import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
class Main{
	static int[] junjo;
	static int[][] convert;
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		junjo=new int[10];
		for(int i=0; i<10; i++) {
			junjo[sc.nextInt()]=i;
		}
		int N=sc.nextInt();
		convert=new int[N][2];
		for(int i=0; i<N; i++) {
			int a=sc.nextInt();
			convert[i][1]=a;
			convert[i][0]=cnv(a);
		}
		quick_sort(convert,0,N-1);
		for(int i=0; i<N; i++) {
			pl(convert[i][1]);
		}
	}
	public static int cnv(int num) {
		int ret=0;
		int con=1_000_000_000;
		for(int i=0; i<=9; i++) {
			int tmp=num/con;
			ret+=con*junjo[tmp];
			num%=con;
			con/=10;
		}
		//pl(num+" "+ret);
		return ret;
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
	static void quick_sort(int[][] d, int left, int right) {
		if (left>=right) {
			return;
		}
		int p = d[(left+right)/2][0];
		int l = left, r = right;
		int tmp,tmp1,tmp2;
		while(l<=r) {
			while(d[l][0] < p) { l++; }
			while(d[r][0] > p) { r--; }
			if (l<=r) {
				tmp = d[l][0]; d[l][0] = d[r][0]; d[r][0] = tmp;
				tmp1=d[l][1]; tmp2=d[r][1]; d[l][1]=tmp2; d[r][1]=tmp1;
				l++; r--;
			}
		}
		quick_sort(d, left, r);
		quick_sort(d, l, right);
	}
}