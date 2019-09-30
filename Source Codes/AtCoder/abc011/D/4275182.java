import java.io.IOException;
import java.util.NoSuchElementException;

public class Main{
	
	public static void main(String[] args){
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		int D = sc.nextInt();
		int X = Math.abs(sc.nextInt());
		int Y = Math.abs(sc.nextInt());
		double[] logfac = new double[4000];
		for(int i=1;i<4000;i++){
			logfac[i] = logfac[i-1] + Math.log10(i);
		}
		if(X%D==0&&Y%D==0){
			int a = X/D;
			int b = Y/D;
			int c = 0;
			int d = 0;
			double anss = 0;
			if(a+b<=N&&(N-(a+b))%2==0){
				for(int i=0;i<=(N-(a+b))/2;i++){
					double ans = 0;
					int p = a+i;
					int q = b+(N-(a+b))/2-i;
					int r = i;
					int s = (N-(a+b))/2-i;
					//System.out.println(p + " " + q + " " + r + " " + s);
					ans += logfac[N];
					ans -= logfac[p];
					ans -= logfac[q];
					ans -= logfac[r];
					ans -= logfac[s];
					ans -= N * Math.log10(4);
					anss += Math.pow(10,ans);
					
				}

				System.out.println(anss);
			}else{
				System.out.println(0);
			}
			
		}else{
			System.out.println(0);
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