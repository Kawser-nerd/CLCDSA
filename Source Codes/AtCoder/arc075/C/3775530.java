import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.NoSuchElementException;
import java.util.Objects;
 

 
public class Main{
	
	static int[] bit;
	static int N;

	public static void main(String args[])throws Exception{
		
		FastScanner sc = new FastScanner();
		N = sc.nextInt();
		int K = sc.nextInt();
		long[] a = new long[N];
		long[] b = new long[N+1];
		long[] c = new long[N+1];
		b[0] = 0;
		for(int i=0;i<N;i++){
			a[i] = sc.nextInt()-K;
			b[i+1] = b[i] + a[i];
			c[i+1] = b[i+1];
		}
		
		Arrays.sort(c);
		HashMap<Long,Integer> map = new HashMap<Long,Integer>();
		int pos = 0;
		for(int i=0;i<N+1;i++){
			if(!map.containsKey(c[i])){
				map.put(c[i],pos);
				pos++;
			}
		}
		int[] d = new int[N+1];
		for(int i=0;i<N+1;i++){
			d[i] = map.get(b[i]) + 1;
		}
		
		bit = new int[N+2];
		long ans = 0;
		for(int i=0;i<N+1;i++){
			ans += sum(d[i]);
			add(d[i],1);
			
		}
		System.out.println(ans);
		
	}
	private static void add(int i, int j) {
		while(i <= N+1){
			bit[i] += j;
			i += i & (-i);
			
		}
	}
	private static long sum(int i) {
		int s = 0;
		while(i>0){
			s += bit[i];
			i -= i & (-i);
			
		}
		return s;
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