import java.io.IOException;
import java.io.InputStream;
import java.util.*;
 
public class Main{
	public static void main(String[] args){
		FastScanner sc = new FastScanner();
		int n = sc.nextInt();
		long[] num = new long[n];
		for(int i=0; i<n; i++){
			num[i] = sc.nextLong();
		}
		
		long ans1 = plusFirst(n,num);
		long ans2 = minusFirst(n,num);
		System.out.println(Math.min(ans1,ans2));		
		return;
	}
	
	public static long plusFirst(int n, long[] num){
		long sum = num[0];
		long ret = 0;
		if(sum <= 0){
			ret = 1-sum;
			sum = 1;
		}
		
		for(int i=1; i<n; i++){
			sum += num[i];
			if(i%2==1 && sum>=0){
				ret += sum+1;
				sum = -1;	
			}else if(i%2==0 && sum<=0){
				ret += 1-sum;
				sum = 1;
			}
		}
		return ret;
	}
	
	public static long minusFirst(int n, long[] num){
		long sum = num[0];
		long ret = 0;
		if(sum >= 0){
			ret = 1+sum;
			sum = -1;
		}
		
		for(int i=1; i<n; i++){
			sum += num[i];
			if(i%2==1 && sum<=0){
				ret += 1-sum;
				sum = 1;	
			}else if(i%2==0 && sum>=0){
				ret += 1+sum;
				sum = -1;
			}
		}
		return ret;
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