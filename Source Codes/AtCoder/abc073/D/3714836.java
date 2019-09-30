import java.io.IOException;
import java.util.NoSuchElementException;

 
public class Main{
	static int R;
	static int[] r;
	static long ans;
	static long[][] dp;
	static int m;
	public static void main(String args[])throws Exception{
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		int M = sc.nextInt();
		R = sc.nextInt();
		r = new int[R];
		for(int i=0;i<R;i++){
			r[i] = sc.nextInt();
		}
		dp = new long[N+1][N+1];
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				dp[i][j] = 1000000000;
			}
		}
		
		for(int i=0;i<M;i++){
			int A = sc.nextInt();
			int B = sc.nextInt();
			int C = sc.nextInt();
			dp[A][B] = C;
			dp[B][A] = C;
		}
		for(int i=1;i<=N;i++){
			dp[i][i] = 0;
		}
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				for(int k=1;k<=N;k++){
					dp[j][k] = Math.min(dp[j][k], dp[j][i] + dp[i][k]);
				}
			}
		}
		m = 1;
		for(int i=0;i<R;i++){
			m *= 2;
		}
		m--;
		ans = 1000000000;
		for(int i=0;i<R;i++){
			dfs(i,1<<i,0);
		}
	
		System.out.println(ans);
		
	}

	private static void dfs(int p,int v,long l) {
		if(v==m){
			ans = Math.min(ans,l);
			return;
		}
		for(int i=0;i<R;i++){
			if(((v>>i)&1)==0){
				dfs(i,v|(1<<i),l+dp[r[p]][r[i]]);
			}
		}
	}
}









class FastScanner {
    private final java.io.InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
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
    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
    private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
    public boolean hasNext() { skipUnprintable(); return hasNextByte();}
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
                return (minus ? -n : n);
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
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
                return (int) (minus ? -n : n);
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
}