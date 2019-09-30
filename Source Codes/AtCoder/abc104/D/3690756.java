import java.io.IOException;
import java.util.NoSuchElementException;

 
public class Main{

	
	
	public static void main(String args[])throws Exception{
		FastScanner sc = new FastScanner();
		
		String S = sc.next();
		int L = S.length();
		long e = 1000000007;
		long t = 1;
		char[] s = new char[L+1];
		Long[] As = new Long[L+1];
		Long[] Bs = new Long[L+1];
		Long[] Cs = new Long[L+1];
		Long[] Qs = new Long[L+1];
		Long[] BCs = new Long[L+1];
		Long[] BQs = new Long[L+1];
		Long[] QCs = new Long[L+1];
		Long[] QQs = new Long[L+1];
		Long[] SBCs = new Long[L+1];
		Long[] SBQs = new Long[L+1];
		Long[] SQCs = new Long[L+1];
		Long[] SQQs = new Long[L+1];
		Long[] ABCs = new Long[L+1];
		Long[] ABQs = new Long[L+1];
		Long[] AQCs = new Long[L+1];
		Long[] AQQs = new Long[L+1];
		Long[] QBCs = new Long[L+1];
		Long[] QBQs = new Long[L+1];
		Long[] QQCs = new Long[L+1];
		Long[] QQQs = new Long[L+1];
		As[0] = (long) 0;
 		Bs[0] = (long) 0;
		Cs[0] = (long) 0;
		Qs[0] = (long) 0;
		BCs[0] = (long) 0;
		BQs[0] = (long) 0;
		QCs[0] = (long) 0;
		QQs[0] = (long) 0;
		SBCs[0] = (long) 0;
		SBQs[0] = (long) 0;
		SQCs[0] = (long) 0;
		SQQs[0] = (long) 0;
		ABCs[0] = (long) 0;
		ABQs[0] = (long) 0;
		AQCs[0] = (long) 0;
		AQQs[0] = (long) 0;
		QBCs[0] = (long) 0;
		QBQs[0] = (long) 0;
		QQCs[0] = (long) 0;
		QQQs[0] = (long) 0;
		
		for(int i=1;i<=L;i++){
			s[i] = S.charAt(i-1);
			if(s[i] =='A'){
				As[i] = As[i-1] + 1;
			}else{
				As[i] = As[i-1];
			}
			if(s[i] =='B'){
				Bs[i] = Cs[i-1] + 1;
			}else{
				Bs[i] = Cs[i-1];
			}
			if(s[i] =='C'){
				Cs[i] = Cs[i-1] + 1;
			}else{
				Cs[i] = Cs[i-1];
			}
			if(s[i] =='?'){
				Qs[i] = Qs[i-1] + 1;
			}else{
				Qs[i] = Qs[i-1];
			}
		}
		for(int i=1;i<=L-1;i++){
			if(s[i] == 'B'){
				BCs[i] = Cs[L] - Cs[i];
				BQs[i] = Qs[L] - Qs[i];
			}else{
				BCs[i] =(long)0;
				BQs[i] =(long)0;
			}
			
			SBCs[i] = SBCs[i-1] + BCs[i];
			SBCs[i] %= e;
			SBQs[i] = SBQs[i-1] + BQs[i];
			SBQs[i] %= e;
			
			if(s[i] == '?'){
				QCs[i] = Cs[L] - Cs[i];
				QQs[i] = Qs[L] - Qs[i];
			}else{
				QCs[i] =(long)0;
				QQs[i] =(long)0;
			}
			SQCs[i] = SQCs[i-1] + QCs[i];
			SQCs[i] %= e;
			SQQs[i] = SQQs[i-1] + QQs[i];
			SQQs[i] %= e;
		
		}
		
		
		
		
		for(int i=1;i<=L-2;i++){
			if(s[i] == 'A'){
				ABCs[i] = ABCs[i-1] +(SBCs[L-1] - SBCs[i]);
				ABCs[i] %= e;
				ABQs[i] = ABQs[i-1] +(SBQs[L-1] - SBQs[i]);
				ABQs[i] %= e;
				AQCs[i] = AQCs[i-1] +(SQCs[L-1] - SQCs[i]);
				AQCs[i] %= e;
				AQQs[i] = AQQs[i-1] +(SQQs[L-1] - SQQs[i]);
				AQQs[i] %= e;
			}else{
				ABCs[i] = ABCs[i-1];
				ABQs[i] = ABQs[i-1];
				AQCs[i] = AQCs[i-1];
				AQQs[i] = AQQs[i-1];
					
				
			}
			
			if(s[i] == '?'){
				QBCs[i] = QBCs[i-1] +(SBCs[L-1] - SBCs[i]);
				QBCs[i] %= e;
				QBQs[i] = QBQs[i-1] +(SBQs[L-1] - SBQs[i]);
				QBQs[i] %= e;
				QQCs[i] = QQCs[i-1] +(SQCs[L-1] - SQCs[i]);
				QQCs[i] %= e;
				QQQs[i] = QQQs[i-1] +(SQQs[L-1] - SQQs[i]);
				QQQs[i] %= e;
			}else{
				QBCs[i] = QBCs[i-1];
				QBQs[i] = QBQs[i-1];
				QQCs[i] = QQCs[i-1];
				QQQs[i] = QQQs[i-1];
					
				
			}
		
		}
		long num = 0;
		if(Qs[L]>=3){
			num = (ABCs[L-2] * 27 + ABQs[L-2] * 9 + AQCs[L-2] * 9 + QBCs[L-2] * 9 + AQQs[L-2] * 3+ QBQs[L-2] * 3+ QQCs[L-2] * 3 + QQQs[L-2]);
		}else if(Qs[L]==2){
			num = (ABCs[L-2] * 9 + ABQs[L-2] * 3 + AQCs[L-2] * 3 + QBCs[L-2] * 3 + AQQs[L-2] + QBQs[L-2] + QQCs[L-2]);
		}else if(Qs[L]==1){
			num = (ABCs[L-2] * 3 + ABQs[L-2] + AQCs[L-2] + QBCs[L-2]);
		}else{
			num = ABCs[L-2];
		}
		num = num%e;
		for(int i=0;i<Qs[L]-3;i++){
			t = (t * 3)%e;
			
		}
		
		System.out.println((num * t)%e);
		
		
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