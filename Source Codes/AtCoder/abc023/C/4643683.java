import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String args[]) {
		FastScanner scanner = new FastScanner();
		int R=scanner.nextInt();
		int C=scanner.nextInt();
		int k=scanner.nextInt();
		int n=scanner.nextInt();
		int[] r=new int[n];
		int[] c=new int[n];
		int[] sum_r = new int[R];
		int[] sum_c = new int[C];
		for( int i = 0; i < n; i++){
			r[i] = scanner.nextInt() - 1;
			c[i] = scanner.nextInt() - 1;
			sum_r[r[i]]++;
			sum_c[c[i]]++;
		}
		int[] rCnt=new int[100001];
		for( int i = 0; i < R; i++ ){
			rCnt[sum_r[i]]++;
		}
		int[] cCnt=new int[100001];
		for( int i = 0; i < C; i++ ){
			cCnt[sum_c[i]]++;
		}
		long ans=0;
		for(int i=0;i<=k;i++) {
			ans+=(long)rCnt[i]*cCnt[k-i];
		}
		for(int i=0;i<n;i++) {
			if(sum_r[r[i]]+sum_c[c[i]]==k) {
				ans--;
			}
			if(sum_r[r[i]]+sum_c[c[i]]==k+1) {
				ans++;
			}
		}
		System.out.println(ans);
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
        }else{
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
    public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() { return Double.parseDouble(next());}
}