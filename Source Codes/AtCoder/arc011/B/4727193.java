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
		int[] ary= {-1,1,1,2,-1,4,9,8,-1,3,8,5,7,9,-1,7,4,0,6,3,-1,5,2,6,-1,0};
		String[] nums=new String[N];
		int last=-1;
		for(int i=0; i<N; i++) {
			String s=sc.next();
			s=s.toLowerCase();
			nums[i]="";
			for(int j=0; j<s.length(); j++) {
				if(s.charAt(j)-'a'>=26 || s.charAt(j)-'a'<0) {
					//
				}
				else {
					if(ary[(s.charAt(j)-'a')]==-1) {
						//
					}
					else {
						nums[i]=nums[i]+""+ary[(s.charAt(j)-'a')];
					}
				}
			}
			if(nums[i].length()>0) {
				last=i;
			}
		}
		for(int i=0; i<N; i++) {
			if(nums[i].length()==0) {
				continue;
			}
			else {
				if(i!=last) {
					p(nums[i]+" ");
				}
				else {
					pl(nums[i]);
					break;
				}
			}
		}
		if(last==-1) {
			pl();
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