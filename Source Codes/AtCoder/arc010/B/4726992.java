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
		int[] day= {0,31,29,31,30,31,30,31,31,30,31,30,31};
		int[] accum= {0,31,60,91,121,152,182,213,244,274,305,335,366};
		int[] days=new int[367];
		int d=0;
		int max=0;
		int tmp=0;
		for(int i=1; i<=366; i++) {
			if(d==6 || d==0) {
				days[i]=1;
			}
			else {
				days[i]=0;
			}
			d++;
			d%=7;
		}
		int N=sc.nextInt();
		int[] ds=new int[N];
		for(int i=0; i<N; i++) {
			String s=sc.next();
			String[] a=s.split("/");
			ds[i]=accum[(Integer.parseInt(a[0])-1)]+Integer.parseInt(a[1]);
		}
		Arrays.sort(ds);
		for(int i=0; i<N; i++) {
			int dd=ds[i];
			if(days[dd]>0) {
				int td=1;
				while(true) {
					if(dd+td<=366) {
						if(days[dd+td]==0) {
							days[dd+td]++;
							break;
						}
						else {
							//
						}
					}
					else {
						break;
					}
					td++;
				}
			}
			else {
				days[dd]++;
			}
		}
		for(int i=0; i<=366; i++) {
			if(days[i]>0) {
				tmp++;
				max=Math.max(max, tmp);
			}
			else if(days[i]==0) {
				tmp=0;
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