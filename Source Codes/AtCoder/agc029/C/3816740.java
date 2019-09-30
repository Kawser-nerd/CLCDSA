import java.io.IOException;
import java.util.NoSuchElementException;
 

 
public class Main{
	static int N;
	static int[] A;
	public static void main(String args[])throws Exception{
		
		FastScanner sc = new FastScanner();
		N = sc.nextInt();
		A = new int[N];
		int k = 0;
		for(int i=0;i<N;i++){
			A[i] = sc.nextInt();
			if(i>0){
				if(A[i-1]>=A[i]){
					k=1;
				}
			}
		}
		if(k==0){
			System.out.println(1);
			return;
		}
		int ok = 200001;
		int ng = 1;
		while(ok-ng>1){
			int mid = (ok+ng)/2;
			if(isOK(mid)){
				ok = mid;
			}else{
				ng = mid;
			}
		}
		System.out.println(ok);
	}
	private static boolean isOK(int mid) {
		int[] put = new int[21];
		int nowlook = 0;
		for(int i=0;i<N;i++){
			if(A[i]<=20){
			if(A[i]>nowlook){
				for(int j = nowlook+1;j<=A[i];j++){
					put[j] = 1;
				}
			}else{
				int putnext = A[i];
				while(put[putnext]==mid){
					putnext--;
					if(putnext==0){
						return false;
					}
				}
				put[putnext]++;
				for(int j=putnext+1;j<=20;j++){
					put[j] = 0;
				}
			}
			nowlook = A[i];
			}
		}
		if(put[1]>mid){
			return false;
		}else{
			return true;
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