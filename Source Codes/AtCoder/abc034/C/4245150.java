import java.io.IOException;
import java.util.NoSuchElementException;

public class Main{
	static long[] fac;
	static int mod = 1000000007;
	public static void main(String[] args){
		FastScanner sc = new FastScanner();
		fac = new long[300000];
		fac[0] = 1;
		for(int i=1;i<=299999;i++){
			fac[i] = fac[i-1] * i;
			fac[i] %= mod;
		}
		int W = sc.nextInt();
		int H = sc.nextInt();
		System.out.println(comb(W+H-2,W-1));
		
		
	
		
	}
	
	
	private static long comb(int n, int k) {
		
		long ans = fac[n]%mod;
		long mot = rev(fac[n-k]) * rev(fac[k]) % mod;
		return ans * mot % mod;
	}

	private static long rev(long k) {
		return  pow(k,mod-2)%mod;
	}

	private static long pow(long k, int i) {
		if(i==0){
			return 1;
		}else{
			if(i%2==0){
				long vol = pow(k,i/2)%mod;
				return vol * vol % mod;
			}else{
				return k * pow(k,i-1) % mod;
			}
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