import java.io.IOException;
import java.io.InputStream;
import java.util.*;
import java.util.function.IntFunction;
import java.util.function.Supplier;
import java.util.stream.IntStream;
import java.util.stream.Stream;


public class Main {
    static int x;
    public static void main(String[] args) {
        Scanner scanner = new Scanner();
        long n=scanner.nextLong();
        long m=scanner.nextLong();
        long res1=(long)Math.floor((m-2*n)/4);
        if(res1<0) res1=0;
        long res2=res1+1;
        //put(format("res1,res2=%d,%d",res1,res2));
        long ans1=Math.min(n+res1,(m-2*res1)/2);
        long ans2=Math.min(n+res2,(m-2*res2)/2);
        put(Math.max(ans1,ans2));

    }


    public static void print(Object object){
        System.out.print(object);
    }
    public static void put(Object object) {
        System.out.println(object);
    }
    public static void put(){
        System.out.println();
    }
    public static String format(String string, Object... args) {
        return String.format(string, args);
    }
}

final class Scanner {
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

    private boolean isPrintableChar(int c) {
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
final class Pair {
    final public int x, y;

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int hashCode() {
        return x+y;
    }

    @Override
    public boolean equals(Object obj) {
        boolean result=super.equals(obj);
        if(obj.getClass()!=this.getClass()){
            return false;
        }
        Pair pair=(Pair)obj;
        if(this.x==pair.x&&this.y==pair.y) return true;
        return false;
    }

    @Override
    public String toString() {
        return String.format("(%d,%d)", x, y);
    }
}
final class Tuple<T,V>{
    //immutabl1????????(T,V?mutable???????)
    final public T t;
    final public V v;
    Tuple(T t,V v){
        this.t=t;
        this.v=v;
    }

    @Override
    public int hashCode() {
        return (t.hashCode()+v.hashCode());
    }

    @Override
    public boolean equals(Object obj) {
        if(obj.getClass()!=this.getClass()){
            return false;
        }
        Tuple<T,V> tuple=(Tuple)obj;
        return tuple.t.equals(this.t)&&tuple.v.equals(this.v);
    }

    @Override
    public String toString() {
        return String.format("<Tuple>=<%s,%s>",t,v);
    }
}
final class LowerBoundComparator<T extends Comparable<? super T>>
        implements Comparator<T>
{
    public int compare(T x, T y)
    {
        return (x.compareTo(y) >= 0) ? 1 : -1;
    }
}

final class UpperBoundComparator<T extends Comparable<? super T>>
        implements Comparator<T>
{
    public int compare(T x, T y)
    {
        return (x.compareTo(y) > 0) ? 1 : -1;
    }
}
final class Util {
    static long gcd(long a,long b){
        if(a%b==0)return b;
        return gcd(b,a%b);
    }
    static long lcm(long a,long b){
        long gcd=gcd(a,b);
        long result=b/gcd;
        return a*result;
    }
    static long kaijoMod(int n,int mod){
        if(n<1) return -1;
        long result=1;
        for(int i=n;i>1;i--){
            result*=i;
            result%=mod;
        }
        return result;
    }
    static <T extends Comparable> Map<T,Integer> count(List<T> list){
        //???
        Collections.sort(list);
        Map<T,Integer> result=new HashMap<>();
        int l=0,r=0;
        while(l<list.size()){
            while(r<list.size()-1&&list.get(r).equals(r+1)){
                r++;
            }
            result.put(list.get(r),r-l+1);
            r++;
            l=r;
        }
        return result;

    }
    static Map<Integer,Integer> count(int[] array){
        //???
        Arrays.sort(array);
        Map<Integer,Integer> result=new HashMap<>();
        int l=0,r=0;
        while(l<array.length){
            while(r<array.length-1&&array[r]==array[r+1]){
                r++;
            }
            result.put(array[l],r-l+1);
            r++;
            l=r;
        }
        return result;
    }
    static String toStringBWS(Iterable iterable){
        Iterator ite=iterable.iterator();
        return toStringBWS(ite);
    }
    static String toStringBWS(Iterator ite){
        StringBuilder sb=new StringBuilder();
        sb.append(ite.next());
        while(ite.hasNext()){
            sb.append(" ");
            sb.append(ite.next());
        }
        return sb.toString();
    }
    static String toStringBWS(int[] array){
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<array.length-1;i++){
            sb.append(array[i]);
            sb.append(" ");
        }
        sb.append(array[array.length-1]);
        return sb.toString();
    }
    static String toStringBWS(long[] array){
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<array.length-1;i++){
            sb.append(array[i]);
            sb.append(" ");
        }
        sb.append(array[array.length-1]);
        return sb.toString();
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.