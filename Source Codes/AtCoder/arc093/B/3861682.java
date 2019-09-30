import java.io.IOException;
import java.util.Comparator;
import java.util.NoSuchElementException;
import java.util.Objects;



public class Main{
	
	
	public static void main(String args[])throws Exception{
		
		
		FastScanner sc = new FastScanner();
		int A = sc.nextInt();
		int B = sc.nextInt();
		char[][] table = new char[100][100];
		for(int i=0;i<50;i++){
			for(int j=0;j<100;j++){
				table[i][j] = '.';
			}
		}
		for(int i=50;i<100;i++){
			for(int j=0;j<100;j++){
				table[i][j] = '#';
			}
		}
		
		int pos1 = 0;
		int pos2 = 9999;
		for(int i=1;i<B;i++){
			int x = pos1/100;
			int y = pos1%100;{
				table[x][y] = '#';
			}
			pos1 += 2;
			if(pos1%100 == 0){
				pos1 += 100;
			}
		}
		for(int i=1;i<A;i++){
			int x = pos2/100;
			int y = pos2%100;{
				table[x][y] = '.';
			}
			pos2 -= 2;
			if(pos2%100 == 1){
				pos2 -= 100;
			}
		}
		
		System.out.println(100 + " " + 100);
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				System.out.print(table[i][j]);
			}
			System.out.println();
		}
	}	
	
}
class Pair{
	int a;
	int b;
	
	Pair(int p,int q){
		this.a = p;
		this.b = q;
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
 
class SampleComparator implements Comparator<Pair>{
	public int compare(Pair P, Pair Q) {
		int temp = Q.a-P.a;
		if(temp==0){
			return Q.b - P.b;
		}
		return temp;
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