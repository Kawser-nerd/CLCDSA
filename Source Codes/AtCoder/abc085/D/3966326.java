import java.io.*;
import java.util.*;

public class Main {
		
	public static void main(String[] args) throws IOException {
		FastScanner sc = new FastScanner(System.in);
		
		int N = sc.nextInt();
		int H = sc.nextInt();
		Pair[] ab = new Pair[N];
		for(int i = 0; i < N; i++){
			ab[i] = new Pair(sc.nextInt(), sc.nextInt());
		}
		Arrays.sort(ab, (e1, e2)->e2.compare(e1));
		
		int maxA = 0;
		for(int i = 0; i < N; i++){
			if(ab[i].a > maxA){
				maxA = ab[i].a;
			}
		}
		
		/*
		System.out.println(maxA);
		for(Pair p : ab){
			System.out.println(p.a + " " + p.b);
		}
		*/				
		
		int num = 0;
		for(int i = 0; i < N; i++){
			if(H <= 0) break;
			if(ab[i].b >= maxA){
				H -= ab[i].b;
				num++;
			}
		}
		
		if(H > 0){
			num += (int)Math.ceil(1.0 * H / maxA);
		}
		
		System.out.println(num);
		
	}//end main
	
}//end Main

class Pair{
	int a; int b;
	public Pair(int a, int b){this.a = a; this.b = b;}
	public int compare(Pair p){
		if(this.b != p.b){
			if(this.b > p.b) return 1;
			else return -1;
		}else{
			if(this.a > p.a) return 1;
			else if(this.a < p.a) return -1;
			else return 0;
		}
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