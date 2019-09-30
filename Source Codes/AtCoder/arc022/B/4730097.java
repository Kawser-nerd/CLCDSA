import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.StringTokenizer;
class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		/*
		 * ???????
		 * ???????????1???????????
		 * ??????????1?????????????????
		 * ???????????????????
		 * ????????
		 */
		int N=sc.nextInt();
		int[] array=new int[N];
		int[] taste=new int[100_001];
		int max_size=0;
		Arrays.fill(taste, 0);
		int l=0;
		int r=0;	//[l,r]??????
		for(int i=0; i<N; i++) {
			array[i]=sc.nextInt();
		}
		taste[array[0]]=1;
		max_size=1;
		while(!(l==N-1 && r==N-1)) {
			if(r<N-1) {
				r++;
				if(taste[array[r]]==0) {	//???????????
					taste[array[r]]++;
					max_size=Math.max(max_size,r-l+1);
					if(max_size==r-l+1) {
						//pl(l+" "+r);
					}
				}
				else {	//??2??????????????
					while(taste[array[r]]>0 && l<r) {
						taste[array[l]]--;
						l++;
					}
					taste[array[r]]++;
					max_size=Math.max(max_size,r-l+1);
				}
			}
			else {
				l++;
			}
		}
		pl(max_size);
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