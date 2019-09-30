import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String args[]) {
		FastScanner scanner = new FastScanner();
		String s=scanner.next();
		String t=scanner.next();
		Map<Character,Integer>map1=new HashMap<>();
		Map<Character,Integer>map2=new HashMap<>();
		for(int i=0;i<s.length();i++) {
			char key=s.charAt(i);
			if (map1.containsKey(key)) {
				map1.put(key, map1.get(key) + 1);
			} else {
				map1.put(key, 1);
			}
			key=t.charAt(i);
			if (map2.containsKey(key)) {
				map2.put(key, map2.get(key) + 1);
			} else {
				map2.put(key, 1);
			}
		}
		int[] tmp1=new int[map1.size()];
		int ind=0;
		for(int val:map1.values()) {
			tmp1[ind]=val;
			ind++;
		}
		int[] tmp2=new int[map2.size()];
		ind=0;
		for(int val:map2.values()) {
			tmp2[ind]=val;
			ind++;
		}
		if(tmp1.length!=tmp2.length) {
			System.out.println("No");
			return;
		}
		Arrays.sort(tmp1);
		Arrays.sort(tmp2);
		for(int i=0;i<tmp1.length;i++) {
			if(tmp1[i]!=tmp2[i]) {
				System.out.println("No");
				return;
			}
		}
		System.out.println("Yes");
	}
}
class FastScanner {
    private final InputStream in = System.in;
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
    public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
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
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() { return Double.parseDouble(next());}
}