import java.io.IOException;
import java.io.PrintWriter;
import java.util.NoSuchElementException;



public class Main{
	
	public static void main(String args[])throws Exception{

		FastScanner sc = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int Q = sc.nextInt();
		int[][][] B = new int[N+1][M+1][3];
		
		for(int i=1;i<=N;i++) {
			String S = sc.next();
			for(int j=1;j<=M;j++) {
				B[i][j][0] = S.charAt(j-1)-'0';
			}
		}
		for(int i=1;i<=N;i++) {
			for(int j=2;j<=M;j++) {
				if(B[i][j-1][0]*B[i][j][0]==1) {
					B[i][j][1] = 1;
				}
			}
		}
		
		for(int i=2;i<=N;i++) {
			for(int j=1;j<=M;j++) {
				if(B[i-1][j][0]*B[i][j][0]==1) {
					B[i][j][2] = 1;
				}
			}
		}

		for(int i=1;i<=N;i++) {
			for(int j=1;j<=M;j++) {
				for(int k=0;k<3;k++) {
					B[i][j][k] += B[i][j-1][k] + B[i-1][j][k] - B[i-1][j-1][k];
				}
			}
		}		
		for(int i=0;i<Q;i++) {
			int x1 = sc.nextInt();
			int y1 = sc.nextInt();
			int x2 = sc.nextInt();
			int y2 = sc.nextInt();
			int num = B[x2][y2][0]-B[x1-1][y2][0]-B[x2][y1-1][0]+B[x1-1][y1-1][0];
			int yoko = B[x2][y2][1]-B[x1-1][y2][1]-B[x2][y1][1]+B[x1-1][y1][1];
			int tate = B[x2][y2][2]-B[x1][y2][2]-B[x2][y1-1][2]+B[x1][y1-1][2];

			out.println(num-yoko-tate);
		}
		out.flush();
		
	
	
	
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