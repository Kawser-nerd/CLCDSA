import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class Main {
	
	final boolean isDebug = false;
	String fileName = "input.txt";
	FastScanner sc;
	//PrintWriter out;
	final int MOD = 1000000007;
	
	/* solve */
	void solve(){
		int N = sc.nextInt();
		int Ma = sc.nextInt();
		int Mb = sc.nextInt();
		int[] a = new int[N+1];
		int[] b = new int[N+1];
		int[] c = new int[N+1];
		for(int i = 1; i <= N; i++){
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}
		int max = N * 10;
		
		int[][][] dp = new int[N+1][max+1][max+1];
		for(int i = 0; i <= N; i++){
			for(int j = 0; j <= max; j++){
				for(int k = 0; k <= max; k++){
					dp[i][j][k] = Integer.MAX_VALUE / 2;
				}
			}
		}
		dp[0][0][0] = 0;
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j <= max; j++){
				for(int k = 0; k <= max; k++){
					dp[i+1][j][k] = Math.min(dp[i+1][j][k], dp[i][j][k]);
					if(j+a[i+1] <= max && k+b[i+1] <= max){
						dp[i+1][j+a[i+1]][k+b[i+1]] = Math.min(dp[i+1][j+a[i+1]][k+b[i+1]], dp[i][j][k] + c[i+1]);
					}
				}
			}
		}
		
		int min = Integer.MAX_VALUE / 2;
		for(int i = 1 ;; i++){
			if(Ma * i > max || Mb * i > max) break;
			min = Math.min(min, dp[N][Ma*i][Mb*i]);
		}
		
		System.out.println((min == Integer.MAX_VALUE / 2) ? -1 : min);
	}
	/* end solve */
	
	/* main */
	public static void main(String[] args) throws IOException {
		new Main().m();
	}
	
	void m() throws IOException {
		long S = System.currentTimeMillis();
		sc = (isDebug) ? new FastScanner(new FileInputStream(fileName)) : new FastScanner(System.in);
		//out = new PrintWriter(System.out);
		solve();
		//out.flush();
		long G = System.currentTimeMillis();
		if(isDebug){
			System.out.println("---Debug---");
			System.out.printf("%7d ms", (G-S));
		}
	}
	/* end main */
}
/* end Main */

class FastScanner {
    private InputStream in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    public FastScanner(InputStream in) {
		this.in = in;
	}
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
    private int readByte() {
    	if (hasNextByte()) return buffer[ptr++];
    	else return -1;
    }
    private static boolean isPrintableChar(int c){
    	return 33 <= c && c <= 126;
    }
    public boolean hasNext() {
    	while(hasNextByte() && !isPrintableChar(buffer[ptr]))
    		ptr++; return hasNextByte();
    }
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
    public double nextDouble() {
    	return Double.parseDouble(next());
    }
}