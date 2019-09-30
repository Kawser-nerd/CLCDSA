import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String args[]) {
		FastScanner scanner = new FastScanner();
		int n=scanner.nextInt();
		int ma=scanner.nextInt();
		int mb=scanner.nextInt();
		int[] a=new int[n+1];
		int[] b=new int[n+1];
		int[] c=new int[n+1];
		for(int i=1;i<=n;i++) {
			a[i]=scanner.nextInt();
			b[i]=scanner.nextInt();
			c[i]=scanner.nextInt();
		}
		int[][][] dp=new int[n+1][401][401];
		for(int i=0;i<=n;i++) {
			for(int j=0;j<=400;j++) {
				for(int k=0;k<=400;k++) {
					dp[i][j][k]=Integer.MAX_VALUE/2;
				}
			}
		}
		dp[0][0][0]=0;
		for(int i=1;i<=n;i++) {
			for(int j=0;j<=400;j++) {
				for(int k=0;k<=400;k++) {
					if(j>=a[i]&&k>=b[i])
						dp[i][j][k]=Math.min(dp[i-1][j][k],dp[i-1][j-a[i]][k-b[i]]+c[i]);
					else
						dp[i][j][k]=dp[i-1][j][k];
				}
			}
		}
		int min=Integer.MAX_VALUE/2;
		for(int j=1;j<=400;j++) {
			for(int k=1;k<=400;k++) {
				if(j*mb==k*ma) {
					min=Math.min(min, dp[n][j][k]);
				}
			}
		}
		System.out.println(min==Integer.MAX_VALUE/2?-1:min);
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