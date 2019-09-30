import java.io.*;
import java.util.*;

public class Main {
		
	public static void main(String[] args) throws IOException {
		FastScanner sc = new FastScanner(System.in);
		
		int N = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		
		int MAX = N+1;
		long[][] C = new long[MAX][MAX];
		C[0][0] = 1;
		for (int i = 1; i < C.length; ++i) {
			C[i][0] = 1;
			for (int j = 1; j < C[i].length; ++j) {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}
		long[] v = new long[N];
		for(int i = 0; i < N; i++){
			v[i] = sc.nextLong();
		}
		Arrays.sort(v);
		
		
		long maxSum = 0;
		int maxLen = A;
		boolean all = true;
		for(int i = 1; i <= maxLen; i++){
			maxSum += v[N-i];
			if(v[N-i] != v[N-1]) all = false;
		}
		
		double maxAvg = 1.0 * maxSum / A;
		System.out.println(maxAvg);
		
		long last = v[v.length-maxLen];
		int numAll = 0;
		int numSelect = 0;
		for(int i = 1; i <= N; i++){
			if(v[N-i] == last) numAll++;
			if(v[N-i] == last && i <= A) numSelect++;
		}
		
		if(!all){
			System.out.println(C[numAll][numSelect]);
		}else{
			long ans = 0;
			for(int i = A; i <= B; i++){
				if(v[N-i] != last) break;
				ans += C[numAll][i];
			}
			System.out.println(ans);
		}
		
	}//end main
	
	public static void comb(){
		int MAX = 51;
		long[][] C = new long[MAX][MAX];
		C[0][0] = 1;
		for (int i = 1; i < C.length; ++i) {
			C[i][0] = 1;
			for (int j = 1; j < C[i].length; ++j) {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}
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