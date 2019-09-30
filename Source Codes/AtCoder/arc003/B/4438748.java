import java.io.IOException;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.Stack;
public class Main{
	
	public static void main(String[] args){
		FastScanner sc = new FastScanner();
		
		int N = sc.nextInt();
		String[] S = new String[N];
		for(int i=0;i<N;i++){
			S[i] = "";
			String T = sc.next();
			Stack<Character> st = new Stack<Character>();
			for(int j=0;j<T.length();j++){
				st.push(T.charAt(j));
			}
			while(!st.isEmpty()){
				S[i] += st.pop();
			}
		}
		Arrays.sort(S);
		String[] U = new String[N];
		for(int i=0;i<N;i++){
			U[i] = "";
			Stack<Character> st = new Stack<Character>();
			for(int j=0;j<S[i].length();j++){
				st.push(S[i].charAt(j));
			}
			while(!st.isEmpty()){
				U[i] += st.pop();
			}
			System.out.println(U[i]);
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