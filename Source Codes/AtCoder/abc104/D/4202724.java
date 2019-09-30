import java.io.*;
import java.util.*;

import javax.net.ssl.SSLContext;

public class Main {
	
	final boolean isDebug = false;
	String fileName = "input.txt";
	FastScanner sc;
	//PrintWriter out;
	final int MOD = 1000000007;
	final int INF = Integer.MAX_VALUE / 2;
	
	/* solve */
	void solve(){
		String S = sc.next();
		int[] sumA = new int[S.length()+1];
		int[] sumC = new int[S.length()+1];
		int[] sumQ = new int[S.length()+1];
		long[] pow3 = new long[S.length()+1];
		
		pow3[0] = 1;
		for(int i = 1; i <= S.length(); i++){
			pow3[i] = pow3[i-1] * 3;
			pow3[i] %= MOD;
		}
		
		for(int i = 1; i <= S.length(); i++){
			sumA[i] = sumA[i-1];
			sumC[i] = sumC[i-1];
			sumQ[i] = sumQ[i-1];
			if(S.charAt(i-1) == 'A') sumA[i]++;
			if(S.charAt(i-1) == 'C') sumC[i]++;
			if(S.charAt(i-1) == '?') sumQ[i]++;
		}
		
		long ans = 0;
		for(int i = 2; i <= S.length()-1; i++){
			if(S.charAt(i-1) == 'B'){
				long add;
				add = (sumA[i-1] - sumA[0]);
				add *= (sumC[S.length()] - sumC[i]);
				add %= MOD;
				add *= pow3[sumQ[S.length()]];
				add %= MOD;
				ans += add;
				ans %= MOD;
				
				if(sumQ[S.length()] >= 1){
					add = (sumA[i-1] - sumA[0]);
					add *= (sumQ[S.length()] - sumQ[i]);
					add %= MOD;
					add *= pow3[sumQ[S.length()] - 1];
					add %= MOD;
					ans += add;
					ans %= MOD;
					
					add = (sumQ[i-1] - sumQ[0]);
					add *= sumC[S.length()] - sumC[i];
					add %= MOD;
					add *= pow3[sumQ[S.length()] - 1];
					add %= MOD;
					ans += add;
					ans %= MOD;
				}
				
				if(sumQ[S.length()] >= 2){
					add = (sumQ[i-1] - sumQ[0]);
					add *= (sumQ[S.length()] - sumQ[i]);
					add %= MOD;
					add *= pow3[sumQ[S.length()] - 2];
					add %= MOD;
					ans += add;
					ans %= MOD;
				}
			}
			if(S.charAt(i-1) == '?'){
				long add;
				add = (sumA[i-1] - sumA[0]);
				add *= (sumC[S.length()] - sumC[i]);
				add %= MOD;
				add *= pow3[sumQ[S.length()] - 1];
				add %= MOD;
				ans += add;
				ans %= MOD;
				
				if(sumQ[S.length()] >= 2){
					add = (sumA[i-1] - sumA[0]);
					add *= (sumQ[S.length()] - sumQ[i]);
					add %= MOD;
					add *= pow3[sumQ[S.length()] - 2];
					add %= MOD;
					ans += add;
					ans %= MOD;
					
					add = (sumQ[i-1] - sumQ[0]);
					add *= (sumC[S.length()] - sumC[i]);
					add %= MOD;
					add *= pow3[sumQ[S.length()] - 2];
					add %= MOD;
					ans += add;
					ans %= MOD;
				}
				
				if(sumQ[S.length()] >= 3){
					add = (sumQ[i-1] - sumQ[0]);
					add *= (sumQ[S.length()] - sumQ[i]);
					add %= MOD;
					add *= pow3[sumQ[S.length()] - 3];
					add %= MOD;
					ans += add;
					ans %= MOD;
				}
			}
		}
		
		System.out.println(ans);
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
			System.out.printf("%8d ms", (G-S));
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