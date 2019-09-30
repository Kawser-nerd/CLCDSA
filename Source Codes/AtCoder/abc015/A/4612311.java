import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);
        ConsoleInput ci=new ConsoleInput();
        String a=ci.next(),b=ci.next();
        if(a.length()>b.length())out.println(a);
        else out.println(b);
        out.flush();
    }
}
class ConsoleInput{
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int cnt = 0;
    private int buffers = 0;
    private boolean hasNextByte() {
        if (cnt < buffers) {
            return true;
        }else{
            cnt = 0;
            try {
                buffers = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buffers <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { if (hasNextByte()) return buffer[cnt++]; else return -1;}
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
    private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[cnt])) cnt++;}
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
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        if (!hasNext()) throw new NoSuchElementException();
        int n = 0;
        boolean bo = false;
        int b = readByte();
        if (b == '-') {
            bo = true;
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
                return bo ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
}