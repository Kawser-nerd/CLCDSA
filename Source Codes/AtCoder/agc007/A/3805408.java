import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Iterator;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) {
		SC sc=new SC(System.in);
		int H=sc.nextInt();
		int W=sc.nextInt();
		long[] tasizan=new long[64];
		long tmp=1;
		tasizan[0]=1;
		for(int i=1; i<64; i++) {
			tasizan[i]=tasizan[i-1]*2;
		}
		long ans=0;
		String a="";
		for(int i=0; i<H; i++) {
			a=a+sc.next();
		}
		String bb="";
		for(int i=0; i<a.length(); i++) {
			if(a.charAt(i)=='#') {
				ans+=tasizan[i];
			}
		}
		int N=H+W-2;
		int R=H-1;
		int[][] test=new int[H][W];
		for(long l:new Combination(N,R)) {
			String aa="%"+N+"s";
			String b= String.format(aa, Long.toBinaryString(l)).replace(' ', '0');
			//System.out.println(b);
			long temp=0;
			int x=0; int y=0;

			for(int j=0; j<H; j++) {
				for(int k=0; k<W; k++) {
					test[j][k]=0;
				}
			}
			test[0][0]=1;
			for(int j=0; j<N; j++) {
				if(b.charAt(j)=='0') {
					test[y][x+1]=1;
					x++;
				}
				else if(b.charAt(j)=='1') {
					test[y+1][x]=1;
					y++;
				}
			}
			for(int j=0; j<H; j++) {
				for(int k=0; k<W; k++) {
					temp+=test[j][k]*tasizan[j*W+k];
				}
			}
			if(temp==ans) {
				System.out.println("Possible");
				System.exit(0);
			}
		}
		System.out.println("Impossible");
		System.exit(0);
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
	private static class Combination implements Iterable<Long> {
		private final int max;
		private final int select;
		public Combination(int max, int select) {
			if (max < 1 || 62 < max) {
				throw new IllegalArgumentException();
			}
			this.max = max;
			this.select = select;
		}
		public Iterator<Long> iterator() {
			return new CombinationIterator(max, select);
		}
	}
	private static class CombinationIterator implements Iterator<Long> {
		private long value;
		private final long max;

		public CombinationIterator(int max, int select) {
			this.value = (1L << select) - 1L;
			this.max = 1L << max;
		}
		public boolean hasNext() {
			return value < max;
		}
		public Long next() {
			long stock = value;
			value = next(value);
			return stock;
		}
		public void remove() {
			throw new UnsupportedOperationException();
		}
		private long next(long source) {
			long param1 = smallestBitOf(source);
			long param2 = param1 + source;
			long param3 = smallestBitOf(param2);
			long param5 = (param3 / param1) >>> 1;
			return param5 - 1 + param2;
		}
		private long smallestBitOf(long source) {
			long result = 1L;
			while (source % 2 == 0) {
				source >>>= 1;
				result <<= 1;
			}
			return result;
		}
	}
}