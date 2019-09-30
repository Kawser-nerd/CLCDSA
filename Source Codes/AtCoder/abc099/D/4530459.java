import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String args[]) {
		FastScanner scanner = new FastScanner();
		int n=scanner.nextInt();
		int C=scanner.nextInt();
		int[][] d=new int[C][C];
		int[][] c=new int[n][n];
		for(int i=0;i<C;i++) {
			for(int j=0;j<C;j++) {
				d[i][j]=scanner.nextInt();
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				c[i][j]=scanner.nextInt()-1;
			}
		}
		int[][] cost=new int[3][C];
		for(int i=0;i<C;i++) {
			for(int x=0;x<n;x++) {
				for(int y=0;y<n;y++) {
					cost[(x+y)%3][i]+=d[c[x][y]][i];
				}
			}
		}
		int min=Integer.MAX_VALUE;
		for(int x=0;x<C;x++) {
			for(int y=0;y<C;y++) {
				for(int z=0;z<C;z++) {
					if(x==y||x==z||y==z)continue;
					int tmp=0;
					tmp+=cost[0][x];
					tmp+=cost[1][y];
					tmp+=cost[2][z];
					min=Math.min(min, tmp);
				}
			}
		}
		System.out.println(min);
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