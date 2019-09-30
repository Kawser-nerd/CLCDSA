import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;


public class Main {
	static class Pair{
		int a,b;
		public Pair(int a,int b){
			this.a = a;
			this.b = b;
		}
		
		public boolean large(Pair n){
			if (this.a == this.b){
				if (n.a < n.b) 
					return true;
				if (n.a > n.b)
					return false;
				return this.a > n.a;
			}
			if (this.a - this.b > 0)
				if (n.a - n.b <= 0){
					return true;
				} else {
					return this.b < n.b;
				}
			if (n.a - n.b >= 0){
				return false;
			}
			return this.a > n.a;
		}
		
		public boolean small(Pair n){
			if (this.a == this.b){
				if (n.a > n.b) 
					return true;
				if (n.a < n.b)
					return false;
				return this.a < n.a;
			}
			if (this.a - this.b > 0)
				if (n.a - n.b <= 0){
					return false;
				} else {
					return this.b > n.b;
				}
			if (n.a - n.b >= 0){
				return true;
			}
			return this.a < n.a;
		}
	}
	
	static void quicksort(Pair[] a, int st, int ed){
		if (st >= ed) return;
		int l = st;
		int r = ed;
		Pair mid = a[(l + r) / 2];
		while (l <= r) {
			while (l <= ed && a[l].small(mid)) l++;
			while (r >= st && a[r].large(mid)) r--;
			if (l <= r) {
				Pair temp = a[l];
				a[l] = a[r];
				a[r] = temp;
				l++;
				r--;
			}
		}
		
		if (st < r) {
			quicksort(a, st, r);
		}
		
		if (l < ed) {
			quicksort(a, l, ed);
		}
	}
	static int n;
	public static void main(String[] args) throws Exception{
		FastScanner fs = new FastScanner();
		long result = Integer.MIN_VALUE;
		n = fs.nextInt2();
		Pair[] a = new Pair[n];
		for (int i = 0; i < n; i++){
			a[i] = new Pair(fs.nextInt2(),fs.nextInt2());
		}
		quicksort(a,0,n - 1);
		long count = 0;
		for (int i = 0; i < n; i++){
			count += a[i].a;
			if (count > result){
				result = count;
			}
			count -= a[i].b;
		}
		StringBuilder sb = new StringBuilder();
		sb.append(result);
		System.out.println(sb.toString());
	}
}


class FastScanner {
	private final InputStream in = System.in;
	private final byte[] buffer = new byte[1024];
	private int ptr = 0;
	private int buflen = 0;
	
	private boolean hasNextByte() {
		if (ptr < buflen) {
			return true;
		} else {
			ptr = 0;
			try {
				buflen = in.read(buffer);
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (buflen <= 0) { return false; }
		}
		return true;
	}
	
	private int readByte() {
		if (hasNextByte()) {
			return buffer[ptr++];
		} else {
			return -1;
		}
	}
	
	private static boolean isPrintableChar(int c) {
		return '!' <= c && c <= '~';
	}
	
	private void skipUnprintable() {
		while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
			ptr++;
		}
	}
	
	public boolean hasNext() {
		skipUnprintable();
		return hasNextByte();
	}
	
	public String next() {
		if (!hasNext()) { throw new NoSuchElementException(); }
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while (isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	public int nextInt2() {
		return Integer.parseInt(next());
	}
	
	public int nextInt() {
		if (!hasNext()) { throw new NoSuchElementException(); }
		int n = 0;
		boolean minus = false;
		int b = readByte();
		if (b == '-') {
			minus = true;
			b = readByte();
		}
		if (b < '0' || '9' < b) { throw new NumberFormatException(); }
		while (true) {
			if ('0' <= b && b <= '9') {
				n *= 10;
				n += b - '0';
			} else if (b == -1 || !isPrintableChar(b)) {
				return minus ? -n : n;
			} else {
				throw new NumberFormatException();
			}
			b = readByte();
		}
	}
	
}