import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int a=sc.nextInt();
		String[] aa=new String[a];
		for(int i=0; i<a; i++) {
			aa[i]=sc.next();
		}
		int sum=0;
		int last=0;
		for(int i=0; i<9; i++) {
			for(int j=0; j<a; j++) {
				if(aa[j].charAt(i)=='.') {
					last=0;
				}
				else if(aa[j].charAt(i)=='x') {
					sum++;
					last=0;
				}
				else if(aa[j].charAt(i)=='o') {
					if(last==0) {
						last=1;
						sum++;
					}
					else if(last==1) {
						//
					}
				}
			}
			last=0;
		}
		pl(sum);
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