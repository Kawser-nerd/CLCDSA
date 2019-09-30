import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;

public class Main{
	
	public static void main(String args[])throws Exception{
		
		FastScanner sc= new FastScanner();
		int N = sc.nextInt();
		long K = sc.nextLong();
		long[] maxdel = new long[N];
		long inf = 100000000000L;
		
		
		for(int i=0;i<N;i++){
			maxdel[i] = -1 * inf;
		}
		PriorityQueue<Long> Q = new PriorityQueue<Long>(Comparator.reverseOrder());
		for(int i=0;i<N;i++){
			int t = sc.nextInt()-1;
			long d = sc.nextLong();
			if(maxdel[t]<=d){
				Q.add(maxdel[t]);
				maxdel[t] = d;
			}else{
				Q.add(d);
			}
		}
		Arrays.sort(maxdel);
		long sum = 0;
		long max = 0;
		for(int i=0;i<K;i++){
			sum += maxdel[N-1-i];
		}
		max = sum + K * K ;
		for(long i=K-1;i>0;i--){
			sum -= maxdel[N-1-(int)i];
			sum += Q.poll();
			max = Math.max(sum + i * i, max);
		}
		System.out.println(max);
		
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