import java.io.IOException;
import java.util.NoSuchElementException;

public class Main{
	
	public static void main(String[] args){
		FastScanner sc = new FastScanner();
		int x1 = sc.nextInt(); 
		int y1 = sc.nextInt();
		int r = sc.nextInt();
		int x2 = sc.nextInt(); 
		int y2 = sc.nextInt(); 
		int x3 = sc.nextInt(); 
		int y3 = sc.nextInt();
		if(x1-r<x2||x1+r>x3||y1-r<y2||y1+r>y3){
			System.out.println("YES");
		}else{
			System.out.println("NO");
		}
		if((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1) > r * r || (x3-x1) * (x3-x1) + (y2-y1) * (y2-y1) > r * r ||(x2-x1) * (x2-x1) + (y3-y1) * (y3-y1) > r * r ||(x3-x1) * (x3-x1) + (y3-y1) * (y3-y1) > r * r ){
			System.out.println("YES");
		}else{
			System.out.println("NO");
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