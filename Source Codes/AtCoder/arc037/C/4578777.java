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
		int N=sc.nextInt();
		long K=sc.nextLong();
		long[] yoko=new long[N];
		for(int i=0; i<N; i++) {
			yoko[i]=sc.nextLong();
		}
		long[] tate=new long[N];
		for(int i=0; i<N; i++) {
			tate[i]=sc.nextLong();
		}
		Arrays.sort(yoko);
		Arrays.sort(tate);
		long min=yoko[0]*tate[0];
		long max=yoko[N-1]*tate[N-1];
		while(max-min>1) {
			long mid=(max+min)/2;
			long sum=0;
			for(int i=0; i<N; i++) {
				int tmp=lowerBound(yoko,mid/tate[i]+1);	//mid/tate[i]?????
				if(tmp==-1) {
					sum+=N;
				}
				else {
					sum+=tmp;
				}
			}
			if(sum>=K) {
				max=mid;
			}
			else{
				min=mid;
			}
		}
		long res=min;
		long tmpans=0;
		for(int i=0; i<N; i++) {
			int tmp=lowerBound(yoko,min/tate[i]+1);	//mid/tate[i]?????
			if(tmp==-1) {
				tmpans+=N;
			}
			else {
				tmpans+=tmp;
			}
		}
		if(tmpans>=K) {
			pl(res);
		}
		else {
			pl(max);
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
	public static final int lowerBound(final long[] arr, final long value) {
		int low = 0;
		int high = arr.length;
		int mid;
		while (low < high) {
			mid = (high+low)/2;
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