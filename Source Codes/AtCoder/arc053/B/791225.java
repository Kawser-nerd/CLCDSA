import java.io.*;
import java.math.*;
import java.util.*;


class Main {
	static int[] vy = {1,0,-1,0};
	static int[] vx = {0,1,0,-1};
	static long mod = 1000000007;
	static HashMap<String,Boolean> map = new HashMap<String,Boolean>();
	public static void main(String[] args) {	
		FastScanner sc = new FastScanner();
		//Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		char[] S = sc.next().toCharArray();
		int[] count = new int[26];
		for(int i = 0; i < S.length; i++) {
			count[S[i] - 'a']++;
		}
		int a = 0;
		int b = 0;
		for(int i = 0; i < 26; i++) {
			if(count[i] % 2 == 0) {
				b += count[i];
			}
			else {
				a++;
				b += count[i]-1;
			}
		}
		if(a == 0) System.out.println(b);
		else {
			int[] len = new int[a];
			for(int i = 0; i < len.length; i++) {
				len[i] = 1;
			}
			while(b != 0) {
				for(int i = 0; i < len.length; i++) {
					if(b == 0) break;
					len[i] += 2;
					b -= 2;
				}
			}
			int MIN = len[0];
			for(int i = 0; i < len.length; i++) {
				MIN = Math.min(MIN, len[i]);
			}
			System.out.println(MIN);
		}
	}
	
	static class FastScanner {
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
	                return minus ? -n : n;
	            }else{
	                throw new NumberFormatException();
	            }
	            b = readByte();
	        }
	    }
	    public int nextInt() {
	        if (!hasNext()) throw new NoSuchElementException();
	        int n = 0;
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
	}
}