import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class Main {
		
	public static void main(String[] args) throws IOException {
		FastScanner sc = new FastScanner(System.in);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] A = new int[N+1];
		int[][] sum = new int[N+1][3];
		for(int i = 1; i <= N; i++){
			A[i] = sc.nextInt();
			sum[i][0] = i;
			sum[i][1] = (sum[i-1][1] + A[i]) % M;
			sum[i][2] = (sum[i-1][2] + A[i]);
		}
		
		Arrays.sort(sum, new Comparator<int[]>() {
            public int compare(int[] obj1, int[] obj2) {
                if(obj1[1] != obj2[1]){
                	return obj2[1] - obj1[1];
                }else{
                	return obj2[0] - obj1[0];
                }
            }
        });
		
		/*
		for(int[] a : sum){
			System.out.println(a[0] + " " + a[1] + " " + a[2]);
		}
		*/
		
		long ans = 0;
		int mod = M-1;
		int dist = 0;
		for(int i = N; i >= 0; i--){
			if(sum[i][1] != mod){
				mod = sum[i][1];
				dist = 1;
			}else{
				ans += dist;
				dist++;
			}
		}
		System.out.println(ans);
		
	}//end main
	
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