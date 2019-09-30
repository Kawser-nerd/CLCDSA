import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class Main {
	
	final boolean isDebug = false;
	String fileName = "input.txt";
	FastScanner sc;
	//PrintWriter out;
	final int MOD = (int)1e9+7;
	final int INF = Integer.MAX_VALUE / 2;
	
	/* solve */
	void solve() throws Exception{
		int N = sc.nextInt();
		ArrayList<Pair> list = new ArrayList<Pair>();
		for(int i = 0; i < N; i++) list.add(new Pair(sc.nextInt(), sc.nextInt()));
		Collections.sort(list);
		
		//for(Pair p : list) System.out.println(p.w + " " + p.h);
		
		Pair[] dp = new Pair[N+1];
		Arrays.fill(dp, new Pair(Integer.MAX_VALUE, Integer.MAX_VALUE));
		dp[0] = new Pair(0, 0);
		
		for(Pair p : list){
			int ng = 0;
			int ok = N;
			while(ok - ng > 1){
				int mid = (ok + ng) / 2;
				if(dp[mid].h > p.h) ok = mid;
				else ng = mid;
			}
			if(dp[ok-1].h < p.h && p.h < dp[ok].h) dp[ok] = p;
		}
		
		for(int i = N; i >= 0; i--){
			if(dp[i].h != Integer.MAX_VALUE && dp[i].w != Integer.MAX_VALUE){
				System.out.println(i);
				return;
			}
		}
 	}
	
	/* end solve */
	
	/* main */
	public static void main(String[] args) throws Exception {
		new Main().m();
	}
	
	void m() throws Exception {
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

class Pair implements Comparable<Pair>{
	int w, h;
	public Pair(int w, int h){
		this.w = w;
		this.h = h;
	}
	
	@Override
	public boolean equals(Object o){
		Pair O = (Pair)o;
		if(this.w == O.w && this.h == O.h) return true;
		else return false;
	}
	
	@Override
	public int hashCode(){
		return Objects.hash(w, h);
	}
	
	@Override
	public int compareTo(Pair o) {
		if(this.equals(o)) return 0;
		else{
			if(this.w != o.w) return (this.w < o.w) ? -1 : 1;
			else return (this.h > o.h) ? -1 : 1;
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