import java.io.IOException;
import java.util.NoSuchElementException;

 
public class Main{

	
	static long mod = 1000000007;
	public static void main(String args[])throws Exception{
		FastScanner sc = new FastScanner();
		
		int N = sc.nextInt();
		
		long[] a = new long[N+1];

		for(int i=1;i<=N;i++){
			a[i] = sc.nextInt();
		}
		
		long[] rev = new long[N+1];
		long[] revs = new long[N+1]; 
		for(int i=1;i<=N;i++){
			rev[i] = revq(i);
		}
		for(int i=1;i<=N;i++){
			revs[i] = (revs[i-1] + rev[i])%mod;
		}
		
		long ans = 0;
		for(int i=1;i<=N;i++){
			ans += a[i] * (revs[i] + revs[N-i+1] -1)%mod;
			ans %= mod;
		}
		for(int i=1;i<=N;i++){
			ans *= i;
			ans %= mod;
		}
		System.out.println(ans);
	}
	private static long revq(int i) {
		long sisu = mod-2;
		long I = i;
		return pow(I,sisu);
	}
	private static long pow(long i, long sisu) {
		if(sisu==1){
			return i;
		}
		if(sisu%2==0){
			long val = pow(i,sisu/2);
			return val * val % mod;
		}else{
			return pow(i,sisu-1) * i % mod;
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