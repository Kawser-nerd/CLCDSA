import java.util.Map.Entry;
import java.io.*;
import java.util.*;

public class Main {
	
	public static final long INF = Long.MAX_VALUE / 2 - 1;
	
	public static void main(String[] args) throws IOException {
		FastScanner sc = new FastScanner(System.in);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		int R = sc.nextInt();
		int[] r = new int[R];
		for(int i = 0; i < R; i++) r[i] = sc.nextInt()-1;
		Arrays.sort(r);
		int[][] dist = new int[N][N];
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++) dist[i][j] = (i == j) ? 0 : Integer.MAX_VALUE / 2 - 1;
		for(int i = 0; i < M; i++){
			int A = sc.nextInt()-1;
			int B = sc.nextInt()-1;
			int C = sc.nextInt();
			dist[A][B] = C;
			dist[B][A] = C;
		}
		
		for(int k = 0; k < N; k++){
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		
		int min = Integer.MAX_VALUE / 2 - 1;
		do{
			int sum = 0;
			for(int i = 0; i < r.length-1; i++)
				sum += dist[r[i]][r[i+1]];
			min = Math.min(min, sum);
		}while(nextPermutation(r));
		
		System.out.println(min);
	}
	
	//???
	public static boolean nextPermutation(int[] a){
		for(int i = a.length - 1; i > 0; --i){
			if(a[i - 1] < a[i]){
				int swapIndex = find(a[i - 1], a, i, a.length - 1);
				int temp = a[swapIndex];
				a[swapIndex] = a[i - 1];
				a[i - 1] = temp;
				Arrays.sort(a, i, a.length);
				return true;
			}
		}
		return false;
	}

	//dest??????????????????????????????
	private static int find(int dest, int[] a, int s, int e){
		if(s == e){
			return s;
		}
		int m = (s + e + 1) / 2;
		return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e);
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