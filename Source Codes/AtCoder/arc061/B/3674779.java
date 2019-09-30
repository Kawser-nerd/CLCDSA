import java.io.IOException;
import java.util.HashMap;
import java.util.NoSuchElementException;
import java.util.Objects;

 
public class Main{

	public static void main(String args[])throws Exception{
		FastScanner sc = new FastScanner();
		
	 
	    int H = sc.nextInt();
	    int W = sc.nextInt();
	    int N = sc.nextInt();
	    int[] x = {-1,-1,-1,0,0,0,1,1,1};
	    int[] y = {-1,0,1,-1,0,1,-1,0,1};
	    HashMap<Pair,Integer> map = new HashMap<Pair,Integer>();
	    for(int i=0;i<N;i++){
	    	int a = Integer.parseInt(sc.next());
	    	int b = Integer.parseInt(sc.next());
	    	
	    	for(int j=0;j<9;j++){
	    		if(1<a+x[j]&&a+x[j]<H&&1<b+y[j]&&b+y[j]<W){
	    			Pair p = new Pair(a+x[j],b+y[j]);
	    			if(map.containsKey(p)){
	    				map.put(p, map.get(p)+1);
	    			}else{
	    				map.put(p, 1);
	    			}
	    		}
	    	}
	    }
	    
	    int[] ans = new int[10];
	    
	    for(Pair pa:map.keySet()){
	    	int j = map.get(pa);
	    	ans[j]++;
	    }
	    System.out.println((long)(H-2) * (long)(W-2) - map.size());
		for(int i=1;i<10;i++){
			System.out.println(ans[i]);
		}
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