import java.io.*;
import java.util.*;

public class Main {

    public static ArrayList[] al;
    public static int[] pos;

    public static void main(String[] args) {
        //Scanner sc = new Scanner(System.in);
        FastScanner sc = new FastScanner();

        int n = sc.nextInt();
        int m = sc.nextInt();
        //sc.nextLine();

        al = new ArrayList[n];
        pos = new int[n];

        for(int i=0; i<n; i++){
            al[i] = new ArrayList<Integer[]>();
            pos[i] = Integer.MAX_VALUE;
        }

        for(int i=0; i<m; i++){
            int l = sc.nextInt() - 1;
            int r = sc.nextInt()- 1;
            int d = sc.nextInt();
            // String s = sc.nextLine();
            // String[] sl = s.split(" ");
            // int l = Integer.parseInt(sl[0]) - 1;
            // int r = Integer.parseInt(sl[1]) - 1;
            // int d = Integer.parseInt(sl[2]);
            al[l].add(new int[]{r, d});
            al[r].add(new int[]{l, -d});
        }
        //sc.close();

        boolean ret = true;

        for(int i=0; i<n; i++){
            if(al[i].size() != 0){
                if(pos[i] == Integer.MAX_VALUE) pos[i] = 0;
                ret = bfs(i, 0);
            }
            if(!ret) break;
        }

        if(ret){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }

    public static boolean bfs(int i, int p){
        if(al[i].size() == 0) return true;
        while(al[i].size() > 0){
            int[] tmp = (int[])(al[i].remove(0));
            if(pos[tmp[0]] == Integer.MAX_VALUE){
                pos[tmp[0]] = p + tmp[1];
            }else if(pos[tmp[0]] != p + tmp[1]){
                return false;
            }
            if(!bfs(tmp[0], p + tmp[1])) return false;
        }
        return true;
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.