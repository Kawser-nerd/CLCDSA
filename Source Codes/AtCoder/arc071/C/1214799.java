import java.io.IOException;
import java.io.InputStream;
import java.util.*;
 
public class Main{
	public static void main(String[] args){
		FastScanner sc = new FastScanner();
		String s = sc.next();
		String t = sc.next();
		int q = sc.nextInt();
		
		int[] as = new int[s.length()+1];
		int[] at = new int[t.length()+1];
		
		for(int i=0; i<s.length(); i++){
			if(s.charAt(i)=='A'){
				as[i+1] = as[i]+1;
			}else{
				as[i+1] = as[i]+2;
			}
		}
		for(int i=0; i<t.length(); i++){
			if(t.charAt(i)=='A'){
				at[i+1] = at[i]+1;
			}else{
				at[i+1] = at[i]+2;
			}
		}
		
		for(int i=1; i<=q; i++){
			if( (as[sc.nextInt()-1]*-1 + as[sc.nextInt()])%3 == (at[sc.nextInt()-1]*-1 + at[sc.nextInt()])%3 ){
				System.out.println("YES");
			}else{
				System.out.println("NO");
			}
		}
		return;
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