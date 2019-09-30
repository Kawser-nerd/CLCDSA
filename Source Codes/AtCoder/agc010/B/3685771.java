import java.io.IOException;
import java.util.NoSuchElementException;

 
public class Main{

	
	public static void main(String args[])throws Exception{
		FastScanner sc = new FastScanner();
		
		int N = sc.nextInt();
		long n = N;
		long[] a = new long[N];
		long sum = 0;
		long once = 0;
		long[] sabun = new long[N];
		for(int i=0;i<N;i++){
			a[i] = sc.nextInt();
			once += i+1;
			sum += a[i];
			
		}
		if(sum%once!=0){
			System.out.println("NO");
			return;
		}
		long time = sum/once;
		sabun[0] = a[N-1] - a[0];
		for(int i=1;i<N;i++){
			sabun[i] = a[i-1] - a[i];
		}
		for(int i=0;i<N;i++){
			sabun[i] += time; 
		}
		long does = 0;
		for(int i=0;i<N;i++){
			if(sabun[i]%N!=0){
				System.out.println("NO");
				return;
			}else{
				if(sabun[i]<0){
					System.out.println("NO");
					return;
				}else{
					does += sabun[i]/N;
				}
			}
		}
		if(does==time){
			System.out.println("YES");
		}else{
			System.out.println("NO");
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