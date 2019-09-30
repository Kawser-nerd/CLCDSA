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
		Cake[] list = new Cake[N];
		for(int i = 0; i < N; i++){
			list[i] = new Cake(sc.nextLong(), sc.nextLong(), sc.nextLong());
		}
		
		long max = 0;
		long sum;
		
		sum = 0;
		Arrays.sort(list, (c1, c2)->c2.compPPP(c1));
		for(int i = 0; i < M; i++) sum += list[i].x + list[i].y + list[i].z;
		max = Math.max(max, sum);
		
		sum = 0;
		Arrays.sort(list, (c1, c2)->c2.compMPP(c1));
		for(int i = 0; i < M; i++) sum += -list[i].x + list[i].y + list[i].z;
		max = Math.max(max, sum);
		
		sum = 0;
		Arrays.sort(list, (c1, c2)->c2.compPMP(c1));
		for(int i = 0; i < M; i++) sum += list[i].x + -list[i].y + list[i].z;
		max = Math.max(max, sum);
		
		sum = 0;
		Arrays.sort(list, (c1, c2)->c2.compPPM(c1));
		for(int i = 0; i < M; i++) sum += list[i].x + list[i].y + -list[i].z;
		max = Math.max(max, sum);
		
		sum = 0;
		Arrays.sort(list, (c1, c2)->c2.compPMM(c1));
		for(int i = 0; i < M; i++) sum += list[i].x + -list[i].y + -list[i].z;
		max = Math.max(max, sum);
		
		sum = 0;
		Arrays.sort(list, (c1, c2)->c2.compMPM(c1));
		for(int i = 0; i < M; i++) sum += -list[i].x + list[i].y + -list[i].z;
		max = Math.max(max, sum);
		
		sum = 0;
		Arrays.sort(list, (c1, c2)->c2.compMMP(c1));
		for(int i = 0; i < M; i++) sum += -list[i].x + -list[i].y + list[i].z;
		max = Math.max(max, sum);
		
		sum = 0;
		Arrays.sort(list, (c1, c2)->c2.compMMM(c1));
		for(int i = 0; i < M; i++) sum += -list[i].x + -list[i].y + -list[i].z;
		max = Math.max(max, sum);
		
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
	
	public int compPPP(Cake c){
		long sum = (this.x + this.y + this.z) - (c.x + c.y + c.z);
		return (sum == 0) ? 0 : (sum > 0) ? 1 : -1;
	}
	
	public int compMPP(Cake c){
		long sum = (-this.x + this.y + this.z) - (-c.x + c.y + c.z);
		return (sum == 0) ? 0 : (sum > 0) ? 1 : -1;
	}
	
	public int compPMP(Cake c){
		long sum = (this.x + -this.y + this.z) - (c.x + -c.y + c.z);
		return (sum == 0) ? 0 : (sum > 0) ? 1 : -1;
	}
	
	public int compPPM(Cake c){
		long sum = (this.x + this.y + -this.z) - (c.x + c.y + -c.z);
		return (sum == 0) ? 0 : (sum > 0) ? 1 : -1;
	}
	
	public int compPMM(Cake c){
		long sum = (this.x + -this.y + -this.z) - (c.x + -c.y + -c.z);
		return (sum == 0) ? 0 : (sum > 0) ? 1 : -1;
	}
	
	public int compMPM(Cake c){
		long sum = (-this.x + this.y + -this.z) - (-c.x + c.y + -c.z);
		return (sum == 0) ? 0 : (sum > 0) ? 1 : -1;
	}
	
	public int compMMP(Cake c){
		long sum = (-this.x + -this.y + this.z) - (-c.x + -c.y + c.z);
		return (sum == 0) ? 0 : (sum > 0) ? 1 : -1;
	}
	
	public int compMMM(Cake c){
		long sum = (-this.x + -this.y + -this.z) - (-c.x + -c.y + -c.z);
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