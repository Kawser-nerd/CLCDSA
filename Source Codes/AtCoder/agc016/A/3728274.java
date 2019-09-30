import java.util.Map.Entry;
import java.io.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws IOException {
		FastScanner sc = new FastScanner(System.in);
		
		String s = sc.next();
		char[] p = "abcdefghijklmnopqrstuvwxyz".toCharArray();
		int ans = 101;
		for(int i = 0; i < p.length; i++){
			char c = p[i];
			char[] prev = s.toCharArray();
			int count = 0;
			
			boolean tf = true;
			for(int j = 0; j < prev.length; j++)
				if(prev[j] != c){
					tf = false;
					break;
				}
			if(tf){
				System.out.println(0);
				return;
			}
			
			while(true){
				count++;
				char[] next = new char[prev.length-1];
				boolean isAll = true;
				for(int j = 0; j < next.length; j++){
					if(prev[j] == c || prev[j+1] == c) next[j] = c;
					else{
						next[j] = prev[j];
						isAll = false;
					}
				}
				
				if(isAll) break;
				prev = next;
			}
			
			ans = Math.min(ans, count);
		}
		System.out.println(ans);
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