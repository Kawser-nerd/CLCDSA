import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.NoSuchElementException;
import java.util.Objects;
 

 
public class Main{
	
	

	public static void main(String args[])throws Exception{
		
		FastScanner sc = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int Q = sc.nextInt();
		int [][] d = new int[N+10][N+10];
		for(int i=0;i<N+10;i++) {
			for(int j=0;j<N+10;j++) {
				d[i][j] = 0;
			}
		}
		int L = 0;
		int R = 0;
		int p = 0;
		int q = 0;
		for(int i=0;i<M;i++) {
			L = sc.nextInt();
			R = sc.nextInt();
			d[L][R] ++;
			
		}
		for(int i=1;i<=N;i++) {
			for(int j=i;j<=N;j++) {
				d[i][j] = d[i][j-1] + d[i][j];
			}
		}
		for(int i=1;i<=N;i++) {
			for(int j=i;j>=0;j--) {
				d[j][i] = d[j+1][i] + d[j][i];
			}
		}
		for(int i=0;i<Q;i++) {
			p = sc.nextInt();
			q = sc.nextInt();
			out.println(d[p][q]);
		}
		
		out.flush();
	}
	
	
}


class Pair {
	int a;
	int b;

	Pair(int p,int q){
		a = p;
		b = q;
	}
	
	public boolean equals(Object o){
		Pair O = (Pair) o;
		if(O.a==this.a&&O.b==this.b){
			return true;
		}else{
			return false;
		}
		
		
	}
	
	public int hashCode(){
		return Objects.hash(a,b);
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