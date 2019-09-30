import java.io.IOException;
import java.io.InputStream;
import java.util.*;

public class Main {
	
    public static void main(String[] args) {
    	FastScanner sc = new FastScanner();
    	
    	int c11 = sc.nextInt();
    	int c12 = sc.nextInt();
    	int c13 = sc.nextInt();
    	int c21 = sc.nextInt();
    	int c22 = sc.nextInt();
    	int c23 = sc.nextInt();
    	int c31 = sc.nextInt();
    	int c32 = sc.nextInt();
    	int c33 = sc.nextInt();
    	
    	int b1 = c11;
    	int b2 = c12;
    	int b3 = c13;
    	int a2 = c21 - b1;
    	int a3 = c31 - b1;
    	
    	boolean can = true;
    	
    	if(c22!=a2+b2 || c23!= a2+b3 || c32!= a3+b2 || c33!= a3+b3){
    		can = false;
    	}
    	
    	if(can){
        	System.out.println("Yes");
    	}
    	else{
        	System.out.println("No");
    	}
    }
    
}


class FastScanner {
    private final InputStream in = System.in;
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
    public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
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
    public double nextDouble() { return Double.parseDouble(next());}
}