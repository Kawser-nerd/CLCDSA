import java.io.IOException;
import java.util.NoSuchElementException;

 
public class Main{
	
	public static void main(String args[])throws Exception{
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[][] wf = new int[N+1][N+1];
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				wf[i][j] = 50000000;;
			}
		}
		for(int i=1;i<=N;i++){
			wf[i][i] = 0;
		}
		int[] a = new int[M];
		int[] b = new int[M];
		int[] c = new int[M];
		for(int i=0;i<M;i++){
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			c[i] = sc.nextInt();
			wf[a[i]][b[i]] = c[i];
			wf[b[i]][a[i]] = c[i];
			
		}
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				for(int k=1;k<=N;k++){
					wf[j][k] = Math.min(wf[j][k], wf[j][i] +wf[i][k]);
				}
			}
		}
		int ans = 0;
		for(int i = 0;i<M;i++){
			int e = 0;
			for(int j=1;j<=N;j++){
				for(int k=1;k<=N;k++){
					if(wf[j][k] == wf[j][a[i]] + c[i] + wf[b[i]][k]){
						e=1;
					}
				}
			}
			if(e==0){
				ans++;
			}
			
		}
		
		System.out.println(ans);
		
		
		
		
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