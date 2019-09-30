import java.io.IOException;
import java.util.NoSuchElementException;



public class Main{
	static long[] fac = new long[200001];
	static long mod = 1000000007;
	public static void main(String args[])throws Exception{

		FastScanner sc = new FastScanner();
		long H = sc.nextLong();
		long W = sc.nextLong();
		long A = sc.nextLong();
		long B = sc.nextLong();
		
		fac[0] = 1;
		for(int i=1;i<=200000;i++) {
			fac[i] = (fac[i-1] * i)%mod;
		}
		long ans = 0;
		for(int i=0;i<W-B;i++) {
			ans += comb(W+H-A-2-i,H-A-1) * comb(A+i-1,A-1);
			ans %= mod;
		}
		System.out.println(ans);
		
		
		
	}
	
	private static long comb(long l, long m) {
		long ans = fac[(int) l];
		long under = (rev(fac[(int) m])*rev(fac[(int) (l-m)]))%mod;
		return (ans * under)%mod;
	}

	private static long rev(long l) {
		if(l==0) {
			return 1;
		}
		return pow(l,mod-2);
	}

	private static long pow(long l, long m) {
		if(m==0) {
			return 1;
		}
		if(m%2==0) {
			long val = pow(l,m/2);
			return (val * val)%mod;
		}else {
			return (pow(l,m-1) * l)%mod;
		}
	}	
}





class FastScanner {
    private final java.io.InputStream in = System.in;
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
    private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
    public boolean hasNext() { skipUnprintable(); return hasNextByte();}
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
                return (minus ? -n : n);
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
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
                return (int) (minus ? -n : n);
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
}