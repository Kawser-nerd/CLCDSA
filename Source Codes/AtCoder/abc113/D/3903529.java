import java.util.Map.Entry;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	static int MOD = 1000000007;
	static int H;
	static int W;
	static int K;
	static ArrayList<Integer> okBit;
	
	
	public static void main(String[] args) throws IOException {
		FastScanner sc = new FastScanner(System.in);
		
		H = sc.nextInt();
		W = sc.nextInt();
		K = sc.nextInt();
		
		if(W == 1){
			if(K == 1) System.out.println(1);
			else System.out.println(0);
			return;
		}
		
		okBit = new ArrayList<Integer>();
		OkBit();
		
		int[][] dp = new int[H+1][W+1];
		dp[0][1] = 1;
		
		for(int i = 0; i < H; i++){
			for(int bit : okBit){
				int[] slide = new int[W+1];
				for(int d = 0; d < W-1; d++){
					int left = d + 1;
					int right = d + 2;
					if(((bit>>d) & 1) == 1){
						slide[left] = 1;
						slide[right] = -1;
					}
				}
				
				for(int num = 1; num <= W; num++){
					dp[i+1][num+slide[num]] = (dp[i+1][num+slide[num]] + dp[i][num]) % MOD;
				}
			}
		}
		
		System.out.println(dp[H][K]);
	}
	
	public static void OkBit(){
		for(int bit = 0; bit < 1<<(W-1); bit++){
			boolean isOk = true;
			boolean ren = false;
			for(int d = 0; d < W-1; d++){
				if(((bit>>d) & 1) == 1){
					if(ren){
						isOk = false;
						break;
					}
					else{
						ren = true;
					}
				}else{
					ren = false;
				}
			}
			
			if(isOk){
				okBit.add(bit);
			}
		}
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