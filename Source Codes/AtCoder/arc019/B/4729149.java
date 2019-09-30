import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.StringTokenizer;
class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		String s=sc.next();
		if(s.length()==1) {
			pl(0);
		}
		else {
			long sum=0;
			if(s.length()%2==0) {
				long humming_dist=0;
				int r=s.length()/2;
				int l=s.length()/2-1;
				for(int i=0; i<s.length()/2; i++) {
					if(s.charAt(l)!=s.charAt(r)) {
						humming_dist++;
					}
					l--;
					r++;
				}
				if(humming_dist==1) {
					sum=s.length()*25-2;
				}
				else {
					sum=s.length()*25;
				}
				pl(sum);
			}
			else if(s.length()%2==1) {
				long humming_dist=0;
				int l=(s.length()-1)/2-1;
				int r=(s.length()-1)/2+1;
				for(int i=0; i<s.length()/2; i++) {
					if(s.charAt(l)!=s.charAt(r)) {
						humming_dist++;
					}
					l--;
					r++;
				}
				if(humming_dist==0) {
					sum=(s.length()-1)*25;
				}
				else if(humming_dist==1) {
					sum=(s.length()-1)*25-2;
					sum+=25;
				}
				else {
					sum=s.length()*25;
				}
				pl(sum);
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