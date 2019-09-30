import java.io.IOException;
import java.util.NoSuchElementException;
import java.util.Scanner;
public class Main{
	
	public static void main(String[] args){
		FastScanner sc = new FastScanner();
		Scanner scanner = new Scanner(System.in);
		int N = sc.nextInt();
		String S = sc.next();
		int min = N;
		min = Math.min(min,st("AA","AA",S));
		min = Math.min(min,st("AA","AB",S));
		min = Math.min(min,st("AA","AX",S));
		min = Math.min(min,st("AA","AY",S));
		min = Math.min(min,st("AA","BA",S));
		min = Math.min(min,st("AA","BB",S));
		min = Math.min(min,st("AA","BX",S));
		min = Math.min(min,st("AA","BY",S));
		min = Math.min(min,st("AA","XA",S));
		min = Math.min(min,st("AA","XB",S));
		min = Math.min(min,st("AA","XX",S));
		min = Math.min(min,st("AA","XY",S));
		min = Math.min(min,st("AA","YA",S));
		min = Math.min(min,st("AA","YB",S));
		min = Math.min(min,st("AA","YX",S));
		min = Math.min(min,st("AA","YY",S));
		
		min = Math.min(min,st("AB","AA",S));
		min = Math.min(min,st("AB","AB",S));
		min = Math.min(min,st("AB","AX",S));
		min = Math.min(min,st("AB","AY",S));
		min = Math.min(min,st("AB","BA",S));
		min = Math.min(min,st("AB","BB",S));
		min = Math.min(min,st("AB","BX",S));
		min = Math.min(min,st("AB","BY",S));
		min = Math.min(min,st("AB","XA",S));
		min = Math.min(min,st("AB","XB",S));
		min = Math.min(min,st("AB","XX",S));
		min = Math.min(min,st("AB","XY",S));
		min = Math.min(min,st("AB","YA",S));
		min = Math.min(min,st("AB","YB",S));
		min = Math.min(min,st("AB","YX",S));
		min = Math.min(min,st("AB","YY",S));
		
		min = Math.min(min,st("AX","AA",S));
		min = Math.min(min,st("AX","AB",S));
		min = Math.min(min,st("AX","AX",S));
		min = Math.min(min,st("AX","AY",S));
		min = Math.min(min,st("AX","BA",S));
		min = Math.min(min,st("AX","BB",S));
		min = Math.min(min,st("AX","BX",S));
		min = Math.min(min,st("AX","BY",S));
		min = Math.min(min,st("AX","XA",S));
		min = Math.min(min,st("AX","XB",S));
		min = Math.min(min,st("AX","XX",S));
		min = Math.min(min,st("AX","XY",S));
		min = Math.min(min,st("AX","YA",S));
		min = Math.min(min,st("AX","YB",S));
		min = Math.min(min,st("AX","YX",S));
		min = Math.min(min,st("AX","YY",S));
		
		min = Math.min(min,st("AY","AA",S));
		min = Math.min(min,st("AY","AB",S));
		min = Math.min(min,st("AY","AX",S));
		min = Math.min(min,st("AY","AY",S));
		min = Math.min(min,st("AY","BA",S));
		min = Math.min(min,st("AY","BB",S));
		min = Math.min(min,st("AY","BX",S));
		min = Math.min(min,st("AY","BY",S));
		min = Math.min(min,st("AY","XA",S));
		min = Math.min(min,st("AY","XB",S));
		min = Math.min(min,st("AY","XX",S));
		min = Math.min(min,st("AY","XY",S));
		min = Math.min(min,st("AY","YA",S));
		min = Math.min(min,st("AY","YB",S));
		min = Math.min(min,st("AY","YX",S));
		min = Math.min(min,st("AY","YY",S));
		
		min = Math.min(min,st("BA","AA",S));
		min = Math.min(min,st("BA","AB",S));
		min = Math.min(min,st("BA","AX",S));
		min = Math.min(min,st("BA","AY",S));
		min = Math.min(min,st("BA","BA",S));
		min = Math.min(min,st("BA","BB",S));
		min = Math.min(min,st("BA","BX",S));
		min = Math.min(min,st("BA","BY",S));
		min = Math.min(min,st("BA","XA",S));
		min = Math.min(min,st("BA","XB",S));
		min = Math.min(min,st("BA","XX",S));
		min = Math.min(min,st("BA","XY",S));
		min = Math.min(min,st("BA","YA",S));
		min = Math.min(min,st("BA","YB",S));
		min = Math.min(min,st("BA","YX",S));
		min = Math.min(min,st("BA","YY",S));
		
		min = Math.min(min,st("BB","AA",S));
		min = Math.min(min,st("BB","AB",S));
		min = Math.min(min,st("BB","AX",S));
		min = Math.min(min,st("BB","AY",S));
		min = Math.min(min,st("BB","BA",S));
		min = Math.min(min,st("BB","BB",S));
		min = Math.min(min,st("BB","BX",S));
		min = Math.min(min,st("BB","BY",S));
		min = Math.min(min,st("BB","XA",S));
		min = Math.min(min,st("BB","XB",S));
		min = Math.min(min,st("BB","XX",S));
		min = Math.min(min,st("BB","XY",S));
		min = Math.min(min,st("BB","YA",S));
		min = Math.min(min,st("BB","YB",S));
		min = Math.min(min,st("BB","YX",S));
		min = Math.min(min,st("BB","YY",S));
		
		min = Math.min(min,st("BX","AA",S));
		min = Math.min(min,st("BX","AB",S));
		min = Math.min(min,st("BX","AX",S));
		min = Math.min(min,st("BX","AY",S));
		min = Math.min(min,st("BX","BA",S));
		min = Math.min(min,st("BX","BB",S));
		min = Math.min(min,st("BX","BX",S));
		min = Math.min(min,st("BX","BY",S));
		min = Math.min(min,st("BX","XA",S));
		min = Math.min(min,st("BX","XB",S));
		min = Math.min(min,st("BX","XX",S));
		min = Math.min(min,st("BX","XY",S));
		min = Math.min(min,st("BX","YA",S));
		min = Math.min(min,st("BX","YB",S));
		min = Math.min(min,st("BX","YX",S));
		min = Math.min(min,st("BX","YY",S));
		
		min = Math.min(min,st("BY","AA",S));
		min = Math.min(min,st("BY","AB",S));
		min = Math.min(min,st("BY","AX",S));
		min = Math.min(min,st("BY","AY",S));
		min = Math.min(min,st("BY","BA",S));
		min = Math.min(min,st("BY","BB",S));
		min = Math.min(min,st("BY","BX",S));
		min = Math.min(min,st("BY","BY",S));
		min = Math.min(min,st("BY","XA",S));
		min = Math.min(min,st("BY","XB",S));
		min = Math.min(min,st("BY","XX",S));
		min = Math.min(min,st("BY","XY",S));
		min = Math.min(min,st("BY","YA",S));
		min = Math.min(min,st("BY","YB",S));
		min = Math.min(min,st("BY","YX",S));
		min = Math.min(min,st("BY","YY",S));
		
		min = Math.min(min,st("XA","AA",S));
		min = Math.min(min,st("XA","AB",S));
		min = Math.min(min,st("XA","AX",S));
		min = Math.min(min,st("XA","AY",S));
		min = Math.min(min,st("XA","BA",S));
		min = Math.min(min,st("XA","BB",S));
		min = Math.min(min,st("XA","BX",S));
		min = Math.min(min,st("XA","BY",S));
		min = Math.min(min,st("XA","XA",S));
		min = Math.min(min,st("XA","XB",S));
		min = Math.min(min,st("XA","XX",S));
		min = Math.min(min,st("XA","XY",S));
		min = Math.min(min,st("XA","YA",S));
		min = Math.min(min,st("XA","YB",S));
		min = Math.min(min,st("XA","YX",S));
		min = Math.min(min,st("XA","YY",S));
		
		min = Math.min(min,st("XB","AA",S));
		min = Math.min(min,st("XB","AB",S));
		min = Math.min(min,st("XB","AX",S));
		min = Math.min(min,st("XB","AY",S));
		min = Math.min(min,st("XB","BA",S));
		min = Math.min(min,st("XB","BB",S));
		min = Math.min(min,st("XB","BX",S));
		min = Math.min(min,st("XB","BY",S));
		min = Math.min(min,st("XB","XA",S));
		min = Math.min(min,st("XB","XB",S));
		min = Math.min(min,st("XB","XX",S));
		min = Math.min(min,st("XB","XY",S));
		min = Math.min(min,st("XB","YA",S));
		min = Math.min(min,st("XB","YB",S));
		min = Math.min(min,st("XB","YX",S));
		min = Math.min(min,st("XB","YY",S));
		
		min = Math.min(min,st("XX","AA",S));
		min = Math.min(min,st("XX","AB",S));
		min = Math.min(min,st("XX","AX",S));
		min = Math.min(min,st("XX","AY",S));
		min = Math.min(min,st("XX","BA",S));
		min = Math.min(min,st("XX","BB",S));
		min = Math.min(min,st("XX","BX",S));
		min = Math.min(min,st("XX","BY",S));
		min = Math.min(min,st("XX","XA",S));
		min = Math.min(min,st("XX","XB",S));
		min = Math.min(min,st("XX","XX",S));
		min = Math.min(min,st("XX","XY",S));
		min = Math.min(min,st("XX","YA",S));
		min = Math.min(min,st("XX","YB",S));
		min = Math.min(min,st("XX","YX",S));
		min = Math.min(min,st("XX","YY",S));
		
		min = Math.min(min,st("XY","AA",S));
		min = Math.min(min,st("XY","AB",S));
		min = Math.min(min,st("XY","AX",S));
		min = Math.min(min,st("XY","AY",S));
		min = Math.min(min,st("XY","BA",S));
		min = Math.min(min,st("XY","BB",S));
		min = Math.min(min,st("XY","BX",S));
		min = Math.min(min,st("XY","BY",S));
		min = Math.min(min,st("XY","XA",S));
		min = Math.min(min,st("XY","XB",S));
		min = Math.min(min,st("XY","XX",S));
		min = Math.min(min,st("XY","XY",S));
		min = Math.min(min,st("XY","YA",S));
		min = Math.min(min,st("XY","YB",S));
		min = Math.min(min,st("XY","YX",S));
		min = Math.min(min,st("XY","YY",S));
		
		min = Math.min(min,st("YA","AA",S));
		min = Math.min(min,st("YA","AB",S));
		min = Math.min(min,st("YA","AX",S));
		min = Math.min(min,st("YA","AY",S));
		min = Math.min(min,st("YA","BA",S));
		min = Math.min(min,st("YA","BB",S));
		min = Math.min(min,st("YA","BX",S));
		min = Math.min(min,st("YA","BY",S));
		min = Math.min(min,st("YA","XA",S));
		min = Math.min(min,st("YA","XB",S));
		min = Math.min(min,st("YA","XX",S));
		min = Math.min(min,st("YA","XY",S));
		min = Math.min(min,st("YA","YA",S));
		min = Math.min(min,st("YA","YB",S));
		min = Math.min(min,st("YA","YX",S));
		min = Math.min(min,st("YA","YY",S));
		
		min = Math.min(min,st("YB","AA",S));
		min = Math.min(min,st("YB","AB",S));
		min = Math.min(min,st("YB","AX",S));
		min = Math.min(min,st("YB","AY",S));
		min = Math.min(min,st("YB","BA",S));
		min = Math.min(min,st("YB","BB",S));
		min = Math.min(min,st("YB","BX",S));
		min = Math.min(min,st("YB","BY",S));
		min = Math.min(min,st("YB","XA",S));
		min = Math.min(min,st("YB","XB",S));
		min = Math.min(min,st("YB","XX",S));
		min = Math.min(min,st("YB","XY",S));
		min = Math.min(min,st("YB","YA",S));
		min = Math.min(min,st("YB","YB",S));
		min = Math.min(min,st("YB","YX",S));
		min = Math.min(min,st("YB","YY",S));
		
		min = Math.min(min,st("YX","AA",S));
		min = Math.min(min,st("YX","AB",S));
		min = Math.min(min,st("YX","AX",S));
		min = Math.min(min,st("YX","AY",S));
		min = Math.min(min,st("YX","BA",S));
		min = Math.min(min,st("YX","BB",S));
		min = Math.min(min,st("YX","BX",S));
		min = Math.min(min,st("YX","BY",S));
		min = Math.min(min,st("YX","XA",S));
		min = Math.min(min,st("YX","XB",S));
		min = Math.min(min,st("YX","XX",S));
		min = Math.min(min,st("YX","XY",S));
		min = Math.min(min,st("YX","YA",S));
		min = Math.min(min,st("YX","YB",S));
		min = Math.min(min,st("YX","YX",S));
		min = Math.min(min,st("YX","YY",S));
		
		min = Math.min(min,st("YY","AA",S));
		min = Math.min(min,st("YY","AB",S));
		min = Math.min(min,st("YY","AX",S));
		min = Math.min(min,st("YY","AY",S));
		min = Math.min(min,st("YY","BA",S));
		min = Math.min(min,st("YY","BB",S));
		min = Math.min(min,st("YY","BX",S));
		min = Math.min(min,st("YY","BY",S));
		min = Math.min(min,st("YY","XA",S));
		min = Math.min(min,st("YY","XB",S));
		min = Math.min(min,st("YY","XX",S));
		min = Math.min(min,st("YY","XY",S));
		min = Math.min(min,st("YY","YA",S));
		min = Math.min(min,st("YY","YB",S));
		min = Math.min(min,st("YY","YX",S));
		min = Math.min(min,st("YY","YY",S));
	
		
		System.out.println(min);
		
			
	}

	private static int st(String P, String Q, String s) {
		int N = s.length();
		int ans = 0;
		for(int i=0;i<N;i++){
			ans++;
			if(i<N-1){
				if(s.charAt(i)==P.charAt(0)&&s.charAt(i+1)==P.charAt(1)){
					i++;
				}else if(s.charAt(i)==Q.charAt(0)&&s.charAt(i+1)==Q.charAt(1)){
					i++;
				}
			}
		}
		return ans;
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