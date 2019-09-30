import java.util.Scanner;
import java.util.Arrays;
import java.io.InputStream;
import java.io.IOException;
import java.util.NoSuchElementException;

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


//????????????
class BinarySearch{
    int[] array;
    BinarySearch(int[] array){
        this.array=array;
    }
    int lower_bound(int key){
        int lower=-1;int upper=array.length;
        while(upper - lower>1){
            int center =(upper+lower)/2;
            if(array[center]>=key)upper=center;
            else lower=center;
        }
        return upper;
    }
    int upper_bound(int key){
        int lower=-1;int upper=array.length;
        while(upper-lower >1){
            int center=(upper+lower)/2;
            if(array[center]>key)upper=center;
            else lower=center;
        }
        return upper;
    }
}

class Main{



    public static void main(String[] args){
        FastScanner scan = new FastScanner();
        int N = scan.nextInt();
        int[] a = new int[N];
        int[] b = new int[N];
        for(int i=0;i<N;++i)a[i]=scan.nextInt();
        for(int i=0;i<N;++i)b[i]=scan.nextInt();

        int ans = 0;
        int[] B = new int[N];
        int[] A = new int[N];
        //?bit???
        BinarySearch bs = new BinarySearch(b);
        for(int i=0;i<29;++i){
            for(int j=0;j<N;++j)B[j]=b[j]&((1<<(i+1))-1);
            for(int j=0;j<N;++j)A[j]=a[j]&((1<<(i+1))-1);
            Arrays.sort(B);
            bs.array = B;
            boolean isOdd=false;
            for(int j=0;j<N;++j){
                isOdd ^= (bs.lower_bound((1<<i)*2 - A[j]) - bs.lower_bound((1<<i) - A[j]))%2==1;
                isOdd ^= (bs.lower_bound((1<<i)*4 - A[j]) - bs.lower_bound((1<<i)*3 - A[j]))%2==1;
            }
            if(isOdd)ans+=(1<<i);
        }

        System.out.println(ans);

    }
}