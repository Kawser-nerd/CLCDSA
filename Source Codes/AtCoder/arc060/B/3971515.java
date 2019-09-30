import java.io.IOException;
import java.util.NoSuchElementException;



public class Main{



	public static void main(String args[])throws Exception{

		FastScanner sc = new FastScanner();
		long N= sc.nextLong();
		long S =sc.nextLong();
		long ans = 1000000000;
		ans *= ans;
		long ank = ans;
		if(N<S){
			System.out.println(-1);
		}else if(N==S){
			System.out.println(N+1);
		}else{
			for(long i=1;i*i<=N-S;i++){
				if((N-S)%i==0){
					if(judge(i+1,N,S)){
						ans = Math.min(ans,i+1);
					}

					if(judge(((N-S)/i)+1,N,S)){
						ans = Math.min(ans,(N-S)/i+1);

					}
				}
			}
			if(ans==ank){
				System.out.println(-1);
			}else{
				System.out.println(ans);
			}
		}
		
	}

	private static boolean judge(long i, long n, long s) {
		while(n>0){

			s -= n%i;
			n /= i;
		}
		
		if(s==0){
			return true;
		}else{
			return false;
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