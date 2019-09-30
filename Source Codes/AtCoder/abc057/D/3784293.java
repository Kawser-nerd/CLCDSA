import java.io.IOException;
import java.util.Arrays;
import java.util.NoSuchElementException;
 

 
public class Main{
	
	static long[][] comb = new long[60][60];
	
	public static void main(String args[])throws Exception{
		
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		
		
		long[] v = new long[N];
		for(int i=0;i<N;i++){
			v[i] = sc.nextLong();
		}
		Arrays.sort(v);
		long max = v[N-1];
		long min = 0;
		double sum = 0;
		for(int i=0;i<A;i++){
			min = v[N-1-i];
			sum += min;
		}
		
		for(int i=0;i<60;i++){
			comb[i][i] = 1;
			comb[i][0] = 1;
		}
		int minum = 0;
		int minumcon = 0;
		for(int i=0;i<N;i++){
			if (min == v[i]){
				minum++;
			}
		}
		for(int i=0;i<A;i++){
			if(min==v[N-1-i]){
				minumcon++;
			}
		}
		long ans = 0;
		
		
		if(min==max){
			for(int i=minumcon;i<=Math.min(minum,B);i++){
				ans += combcal(minum,i);
				
			}
		}else{
			ans = combcal(minum,minumcon);
		}
		System.out.println(String.format("%.6f", sum / (double)A));
		System.out.println(ans);
	}

	private static long combcal(int i, int j) {
		if(comb[i][j]==0){
			return comb[i][j] = combcal(i-1,j-1) + combcal(i-1,j);
		}else{
			return comb[i][j];
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