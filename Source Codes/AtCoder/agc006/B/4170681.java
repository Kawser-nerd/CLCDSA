import java.io.IOException;
import java.util.NoSuchElementException;



public class Main{


	public static void main(String args[])throws Exception{

		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		int x = sc.nextInt();
		int[] used = new int[2*N];
		if(x==1||x==2*N-1) {
			System.out.println("No");
		}else {
			System.out.println("Yes");
			if(N==2){
				System.out.println("1 2 3");
			}else{
				int[] a = new int[2*N-1];
				a[N-1] = x;
				a[N-2] = x-1;
				a[N] = x+1;
				used[x-1] = 1;
				used[x] = 1;
				used[x+1] = 1;
				if(x==2){
					a[N-3] = 4;
					used[4] = 1;
				}else{
					a[N+1] = x-2;
					used[x-2] = 1;
				}
				int numpos = 1;
				for(int i=0;i<2*N-1;i++){
					if(a[i]==0){
						while(used[numpos]==1){
							numpos++;
						}
						System.out.println(numpos);
						numpos++;
					}else{
						System.out.println(a[i]);
					}
				}
				
			}
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