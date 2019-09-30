import java.io.IOException;
import java.util.NoSuchElementException;
public class Main{

	public static void main(String[] args){
		FastScanner sc = new FastScanner();
		Mathplus mp = new Mathplus();
		mp.mod = 998244353;
		int N = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		long K = sc.nextLong();
		long ans = 0;
		for(long i=0;i<=N;i++){
			long rem = K - A*i;
			if(rem>=0&&rem%B==0){
				long num = rem/B;
				if(num<=N){
					ans += mp.comb(N, (int) i) * mp.comb(N, (int)num);
					ans %= mp.mod;
				}
			}
		}
		System.out.println(ans);
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

class Mathplus{
	int mod = 1000000007;
	long[] fac = new long[1000001];
	boolean isBuild = false;
	
	void buildFac(){
		fac[0] = 1;
		for(int i=1;i<=1000000;i++){
			fac[i] = (fac[i-1] * i)%mod;
		}
		isBuild = true;
	}
	
	long gcd(long a, long b){
		if(a<b){
			a^=b;
			b^=a;
			a^=b;
		}
		if(a%b==0){
			return b;
		}else{
			return gcd(b,a%b);
		}
	}
	
	long lcm(long a, long b){
		return a / gcd(a,b) * b;
	}
	
	public long comb(int a,int num){
		if(!isBuild){
			buildFac();
		}
		return fac[a] * (rev(fac[num])*rev(fac[a-num])%mod)%mod;
	}
	
	long rev(long l) {
		return pow(l,mod-2);
	}
	
	long pow(long l, int i) {
		if(i==0){
			return 1;
		}else{
			if(i%2==0){
				long val = pow(l,i/2);
				return val * val % mod;
			}else{
				return pow(l,i-1) * l % mod;
			}
		}
	}
	
	
}