import java.util.Map.Entry;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	
	static int MOD = 1000000007;
	static int H;
	static int W;
	static int[][] a;
	static int[][] f;
	static boolean[][] solved;
	
	public static void main(String[] args) throws IOException {
		FastScanner sc = new FastScanner(System.in);
		
		H = sc.nextInt();
		W = sc.nextInt();
		a = new int[H][W];
		f = new int[H][W];
		solved = new boolean[H][W];
		
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				a[i][j] = sc.nextInt();
			}
		}
		
		int ans = 0;
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				ans = (ans + f(i, j)) % MOD;
				//System.out.print(f(i, j) + " ");
			}
			//System.out.println();
		}
		System.out.println(ans);
	}
	
	public static int f(int i, int j){
		if(solved[i][j]) return f[i][j];
		
		int ans = 1;
		if(i+1 < H && a[i+1][j] > a[i][j]) ans = (ans + f(i+1, j)) % MOD;
		if(i-1 >= 0 && a[i-1][j] > a[i][j]) ans = (ans + f(i-1, j)) % MOD;
		if(j+1 < W && a[i][j+1] > a[i][j]) ans = (ans + f(i, j+1)) % MOD;
		if(j-1 >= 0 && a[i][j-1] > a[i][j]) ans = (ans + f(i, j-1)) % MOD;
		
		f[i][j] = ans;
		solved[i][j] = true;
		
		return f[i][j];
	}
}

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