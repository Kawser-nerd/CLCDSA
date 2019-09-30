import java.io.IOException;
import java.util.NoSuchElementException;

 
public class Main{
	
	public static void main(String args[])throws Exception{
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		int[] t = new int[N];
		int[] v = new int[N];
		int alltime = 0;
		for(int i=0;i<N;i++){
			t[i] = sc.nextInt();
			alltime += t[i];
		}
		
		for(int i=0;i<N;i++){
			v[i] = sc.nextInt();
		}
		
		int[] timetable = new int[alltime*2+1];
		
		int pos = 0;
		for(int i=0;i<N;i++){
			int put = t[i];
			for(int j=0;j<put*2;j++){
				timetable[pos] = v[i];
				pos++;
			}
		}
		pos = 1;
		
		for(int i=0;i<N;i++){
			int put = t[i];
			for(int j=0;j<put*2;j++){
				timetable[pos] = Math.min(timetable[pos], v[i]);
				pos++;
			}
		}
		int[][] dp = new int[alltime*2+1][201];
		for(int i=0;i<=alltime*2;i++){
			for(int j=0;j<=200;j++){
				dp[i][j] = -1;
			}
		}
		dp[0][0] = 0;
		for(int i=1;i<=alltime*2;i++){
			for(int j=0;j<=200;j++){
				if(j<=timetable[i]*2){
					if(j-1>=0){
						if(dp[i-1][j-1]>=0){
							dp[i][j] = Math.max(dp[i][j], dp[i-1][j-1] + 2*j-1);
						}
					}
					if(dp[i-1][j]>=0){
						dp[i][j] = Math.max(dp[i][j], dp[i-1][j]+2*j);
					}
					if(j+1<=200){
						if(dp[i-1][j]>=0){
							dp[i][j] = Math.max(dp[i][j], dp[i-1][j+1] + 2*j+1);
						}
					}
				}
			}
		}
		

		System.out.println((double)dp[alltime*2][0]/8.0);
		
		
		
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