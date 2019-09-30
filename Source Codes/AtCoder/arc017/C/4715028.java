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
		long[] one;
		long[] two;
		int N=sc.nextInt();
		long X=sc.nextLong();
		long[] W=new long[N];
		for(int i=0; i<N; i++) {
			W[i]=sc.nextLong();
		}
		if(N%2==0) {
			int mono=1;
			for(int i=0; i<N/2; i++) {
				mono*=2;
			}
			one=new long[mono];
			two=new long[mono];
			for(int i=0; i<mono; i++) {
				int tmp=i;
				one[i]=0;
				two[i]=0;
				for(int j=0; j<N/2; j++) {
					if(tmp%2==1) {
						one[i]+=W[j];
						two[i]+=W[j+N/2];
					}
					tmp/=2;
				}
			}
		}
		else{
			int mono=1;
			for(int i=0; i<N/2+1; i++) {
				mono*=2;
			}
			one=new long[mono];
			two=new long[mono/2];
			for(int i=0; i<mono; i++) {
				int tmp=i;
				if(i<mono/2) {
					one[i]=0;
					two[i]=0;
					for(int j=0; j<N/2; j++) {
						if(tmp%2==1) {
							one[i]+=W[j];
							two[i]+=W[j+N/2+1];
						}
						tmp/=2;
					}
				}
				else {
					one[i]=0;
					for(int j=0; j<N/2+1; j++) {
						if(tmp%2==1) {
							one[i]+=W[j];
						}
						tmp/=2;
					}
				}
			}
		}
		/*
		pl(one.length+" "+two.length);
		for(int i=0; i<one.length; i++) {
			pl(one[i]);
		}
		pl();
		for(int i=0; i<two.length; i++) {
			pl(two[i]);
		}
		*/
		Arrays.sort(one);
		Arrays.sort(two);
		long ans=0;
		for(int i=0; i<one.length; i++) {
			long res=X-one[i];
			if(res<0) {
				//
			}
			else {
				int l=lowerBound(two,res);
				if(l==-1) {
					//
				}
				else {
					if(two[l]==res) {
						int r=lowerBound(two,res+1);
						if(r==-1) {
							ans+=two.length-l;
						}
						else {
							ans+=r-l;
						}
					}
					else {
						//
					}
				}
			}
		}
		pl(ans);
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
	public static final int lowerBound(final long[] arr, final long value) {
		int low = 0;
		int high = arr.length;
		int mid;
		while (low < high) {
			mid = ((high - low) >>> 1) + low;    //(low + high) / 2 (?????????)
			if (arr[mid] < value) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		if(low<arr.length) {
			return low;
		}
		else {
			return -1;
		}
	}
}