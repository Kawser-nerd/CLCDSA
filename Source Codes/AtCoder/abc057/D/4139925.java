import java.io.IOException;
import java.io.InputStream;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String args[]) {
		FastScanner scanner = new FastScanner();
		int n=scanner.nextInt();
		int a=scanner.nextInt();
		int b=scanner.nextInt();
		long[] v=new long[n];
		Map<Long,Integer>map1=new HashMap<>();
		for(int i=0;i<n;i++) {
			v[i]=scanner.nextLong();
			if (map1.containsKey(v[i])) {
				map1.put(v[i], map1.get(v[i]) + 1);
			} else {
				map1.put(v[i], 1);
			}
		}
		Arrays.sort(v);
		long sum=0;
		Map<Long,Integer>map2=new HashMap<>();
		for(int i=0;i<a;i++) {
			int j=n-1-i;
			sum+=v[j];
			if (map2.containsKey(v[j])) {
				map2.put(v[j], map2.get(v[j]) + 1);
			} else {
				map2.put(v[j], 1);
			}
		}
		long tmp=v[n-1-a+1];
		int cnt=0;
		for(int i=0;i<b-a;i++) {
			int j=n-1-a-i;
			if(v[j]==tmp) {
				cnt++;
			}
		}
		StringBuilder sb=new StringBuilder();
		BigDecimal sumbig=new BigDecimal(String.valueOf(sum));
		BigDecimal abig=new BigDecimal(String.valueOf(a));
		BigDecimal ave=sumbig.divide(abig, 7, RoundingMode.HALF_UP);
		long ans=0;
		if(map2.size()==1) {
			long k=0;
			for(long key:map2.keySet()) {
				k=key;
			}
			for(int i=a;i<=b;i++) {
				ans+=ncr(map1.get(k), i);
			}
		}else {
			ans=ncr(map1.get(tmp),map2.get(tmp));
			
		}
		sb.append(ave+"\n");
		sb.append(ans+"\n");
		System.out.println(sb);
	}

	static long ncr(int a, int b) {
		if (b == 0) return 1;
		long res = ncr(a - 1, b - 1);
		res *= a;
		res /= b;
		return res;
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