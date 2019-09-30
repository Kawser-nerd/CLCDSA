import java.io.IOException;
import java.util.HashMap;
import java.util.NoSuchElementException;



public class Main{
	
	
	
	public static void main(String args[])throws Exception{
		
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		String S = sc.next();
		String A = S.substring(0,N);
		String B = S.substring(N);
		HashMap<String,Integer> map1 = new HashMap<String,Integer>();
		HashMap<String,Integer> map2 = new HashMap<String,Integer>();
		for(int i=0;i<(1<<N);i++){
			String P = "";
			String Q = "";
			for(int j=0;j<N;j++){
				if((i>>j)%2==0){
					P += A.charAt(j);
				}else{
					Q += A.charAt(j);
				}
			}
			String R = P + "|" + Q;
			if(map1.containsKey(R)){
				map1.put(R,map1.get(R)+1);
			}else{
				map1.put(R,1);
			}
			
		}
		for(int i=0;i<(1<<N);i++){
			String P = "";
			String Q = "";
			for(int j=0;j<N;j++){
				if((i>>j)%2==0){
					P += B.charAt(N-j-1);
				}else{
					Q += B.charAt(N-j-1);
				}
			}
			String R = P + "|" + Q;
			if(map2.containsKey(R)){
				map2.put(R,map2.get(R)+1);
			}else{
				map2.put(R,1);
			}
			
		}
		long ans = 0;
		for(String ST:map1.keySet()){
			if(map2.containsKey(ST)){
				long a = map1.get(ST);
				long b = map2.get(ST);
				ans += a * b;
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