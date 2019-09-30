import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String args[]) {
		FastScanner scanner = new FastScanner();
		int n=scanner.nextInt();
		int m=scanner.nextInt();
		long[][] s=new long[3][n];
		for(int i=0;i<n;i++){
			s[0][i]=scanner.nextLong();
			s[1][i]=scanner.nextLong();
			s[2][i]=scanner.nextLong();
		}
		long max=Long.MIN_VALUE;
		for(int i=0;i<8;i++){
			long[][] t=new long[3][n];
			for(int r=0;r<3;r++){
				t[r]=deep_copy(s[r]);
			}
			for(int j=0;j<3;j++){
				if(((i>>j)&1)==0){
					for(int a=0;a<n;a++){
						t[j][a]=-s[j][a];
					}
				}
			}
			long[] tmp=new long[n];
			for(int x=0;x<n;x++){
				for(int y=0;y<3;y++){
					tmp[x]+=t[y][x];
				}
			}
			Arrays.sort(tmp);
			long sc=0;
			for(int z=n-1;z>=n-m;z--){
				sc+=tmp[z];
			}
			max=Math.max(max, sc);
		}
		System.out.println(max);
	}
	private static long[] deep_copy(long[] array) {
		long[] newArray = new long[array.length];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
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