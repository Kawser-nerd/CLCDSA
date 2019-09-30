import java.io.*;
import java.util.*;

public class Main {
	
	final boolean isDebug = false;
	String fileName = "input.txt";
	FastScanner sc;
	//PrintWriter out;
	final int MOD = (int)1e9+7;
	final int INF = Integer.MAX_VALUE / 2;
	
	/* solve */
	void solve(){
		int N = sc.nextInt();
		int M = sc.nextInt();
		Cake[][][][] list = new Cake[2][2][2][N];
		int[] d = {1, -1};
		for(int n = 0; n < N; n++){
			long x = sc.nextLong(), y = sc.nextLong(), z = sc.nextLong();
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 2; j++){
					for(int k = 0; k < 2; k++){
						list[i][j][k][n] = new Cake(x * d[i], y * d[j], z * d[k]);
					}
				}
			}
		}
		
		long max = 0;
		long sum;
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				for(int k = 0; k < 2; k++){
					Arrays.sort(list[i][j][k], (c1, c2)->c2.comp(c1));
					sum = 0;
					for(int n = 0; n < M; n++) sum += list[i][j][k][n].x + list[i][j][k][n].y + list[i][j][k][n].z;
					max = Math.max(max, sum);
				}
			}
		}
		
		System.out.println(max);
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

class Cake{
	long x, y, z;
	public Cake(long x, long y, long z){
		this.x = x;
		this.y = y;
		this.z = z;
	}
	
	public int comp(Cake c){
		long sum = (this.x + this.y + this.z) - (c.x + c.y + c.z);
		return (sum == 0) ? 0 : (sum > 0) ? 1 : -1;
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