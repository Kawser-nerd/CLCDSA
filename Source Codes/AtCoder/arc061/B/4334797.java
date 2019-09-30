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
	void solve(){
		int H = sc.nextInt();
		int W = sc.nextInt();
		int N = sc.nextInt();
		HashMap<Pair, Integer> map = new HashMap<>();
		int[] dx = {-2, -1, 0, -2, -1, 0, -2, -1, 0};
		int[] dy = {-2, -2, -2, -1, -1, -1, 0, 0, 0};
		
		for(int i = 0; i < N; i++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			for(int j = 0; j < 9; j++){
				int y = a + dy[j];
				int x = b + dx[j];
				if(x >= 1 && x + 2 <= W && y >= 1 && y + 2 <= H){
					//System.out.println(i + " " + y + " " + x);
					Pair p = new Pair(y, x);
					Integer count = map.get(p);
					if(count == null) count = 1;
					else count++;
					map.put(p, count);
				}
			}
		}
		
		long[] count = new long[10];
		count[0] = ((long)W - 2) * (H - 2);
		ArrayList<Entry<Pair, Integer>>	listEntries = new ArrayList<Entry<Pair, Integer>>(map.entrySet());
		for(Entry<Pair, Integer> e : listEntries){
			count[e.getValue()]++;
			count[0]--;
		}
		
		for(int i = 0; i <= 9; i++) System.out.println(count[i]);
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

class Pair{
	int y, x;
	public Pair(int y, int x){
		this.y = y;
		this.x = x;
	}
	
	@Override
	public boolean equals(Object o){
		Pair O = (Pair)o;
		if(this.y == O.y && this.x == O.x) return true;
		else return false;
	}
	
	@Override
	public int hashCode(){
		return Objects.hash(y, x);
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