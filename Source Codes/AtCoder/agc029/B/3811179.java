import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int n = sc.nextInt();
        ArrayList<Integer> a = new ArrayList<Integer>(200000);
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i=0; i<n; i++){
            int ma = sc.nextInt();
            a.add(ma);
            Integer num = map.get(ma);
            if(num == null){
                map.put(ma, 1);
            }else{
                map.put(ma, num+1);
            }
        }

        int npow = 31;
        int[] pow2 = new int[npow];
        for(int i=0; i<pow2.length; i++){
            pow2[i] = (int)Math.pow(2, i+1);
        }

        Collections.sort(a);

        int ans = 0;
        int powpos = npow-1;
        for(int i=a.size()-1; i>0; i--){
            int cur = a.remove(i);
            Integer num1 = map.get(cur);
            if(num1 == null || num1 == 0) continue;
            map.put(cur, num1-1);

            while(cur*2 < pow2[powpos]){
                powpos--;
            }


            Integer num2 = map.get(pow2[powpos]-cur);
            if(num2 != null && num2 > 0){
                map.put(pow2[powpos]-cur, num2-1);
                ans++;
            }

            // int pos = Collections.binarySearch(a, pow2[powpos]-cur);
            // if(pos >= 0 && pos < i){
            //     a.remove(pos);
            //     ans++;
            //     i--;
            // }
        }

        System.out.println(ans);
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
        } else {
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

    private int readByte() {
        if (hasNextByte())
            return buffer[ptr++];
        else
            return -1;
    }

    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    public boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr]))
            ptr++;
        return hasNextByte();
    }

    public String next() {
        if (!hasNext())
            throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public long nextLong() {
        if (!hasNext())
            throw new NoSuchElementException();
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
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
            throw new NumberFormatException();
        return (int) nl;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}