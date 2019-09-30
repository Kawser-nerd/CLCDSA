import java.io.IOException;
import java.util.NoSuchElementException;

 
public class Main{
	
	public static void main(String args[])throws Exception{
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		long C = sc.nextLong();
		long[] x = new long[N+1];
		long[] v = new long[N+1];
		for(int i=1;i<=N;i++){
			x[i] = sc.nextLong();
			v[i] = sc.nextLong();
		}
		
		long[] rgr = new long[N+2];
		long[] drgr = new long[N+2];
		long[] lgr = new long[N+2];
		long[] dlgr = new long[N+2];
		
		long walk = 0;
		long val = 0;
		for(int i=1;i<=N;i++){
			walk = x[i];
			val += v[i];
			rgr[i] = Math.max(rgr[i-1], val-walk);
			drgr[i] = Math.max(drgr[i-1], val-walk*2);
			
		}
		walk = 0;
		val = 0;
		for(int i=N;i>0;i--){
			walk = C-x[i];
			val += v[i];
			lgr[i] = Math.max(lgr[i+1], val-walk); 
			dlgr[i] = Math.max(dlgr[i+1], val-walk*2); 
			
		}
		
		long ans = 0;
		for(int i=0;i<=N;i++){
			long max = Math.max(rgr[i]+dlgr[i+1], lgr[i+1]+drgr[i]);
			ans = Math.max(ans, max);
		}
		
		
		System.out.println(ans);
		
		
		
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