import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		FastScanner sc = new FastScanner(System.in);
		
		int h1 = sc.nextInt();
		int w1 = sc.nextInt();
		int h2 = sc.nextInt();
		int w2 = sc.nextInt();
		if(h1 == h2 || h1 == w2 || h2 == w1 || w1 == w2)
			System.out.println("YES");
		else
			System.out.println("NO");
				
	}//end main
	
	/*
	 * ??????????????????????????(E*2^V)
	 * bitDP
	 * dp[S]:??S????????????S?G?????
	 * ???i???j????????? and ?j????????i??????????
            dp[i?j??????] += dp[i]
	 */
	public static long countTopoogicalSort(ArrayList<ArrayList<Integer>> G){
		//???????
		int n = G.size();
		//
		long[] dp = new long[1<<n];
		dp[0] = 1;
		
		for(int i = 0; i < (1<<n); i++){
			for(int j = 0; j < n; j++){
				if(((i>>j) & 1) == 1) continue;
				
				boolean tf = true;
				for(int to : G.get(j)){
					if(((i>>to) & 1) == 1){
						tf = false;
						break;
					}
				}
				if(!tf) continue;
				
				dp[i | (1<<j)] += dp[i];				
			}
		}
		
		return dp[(1<<n)-1];
	}
	
}//end Main

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