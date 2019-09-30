import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String args[]) {
		FastScanner scanner = new FastScanner();
		int n=scanner.nextInt();
		int[] l=new int[n];
		int[] r=new int[n];
		for(int i=0;i<n;i++){
			l[i]=scanner.nextInt();
			r[i]=scanner.nextInt();
		}
		sieve(100000);
		int[] cnt=new int[100001];
		for(int i=1;i<100001;i+=2){
			if(is_prime[i]&&is_prime[(i+1)/2]){
				cnt[i]++;
			}
		}
		for(int i=1;i<100001;i++){
			cnt[i]+=cnt[i-1];
		}
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<n;i++){
			sb.append(cnt[r[i]]-cnt[l[i]-1]+"\n");
		}
		System.out.println(sb);
	}
	
	static boolean[] is_prime;
	static private void sieve(int n) {
		is_prime = new boolean[n + 1];
		for (int i = 2; i <= n; i++) {
			is_prime[i] = true;
		}
		for (int i = 2; i <= n; i++) {
			if (is_prime[i]) {
				for (int j = i + i; j <= n; j += i) {
					is_prime[j] = false;
				}
			}
		}
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