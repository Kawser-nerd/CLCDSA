import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.security.KeyStore;
import java.util.*;
import java.io.*;
import java.util.function.*;
import java.util.stream.Collectors.*;
import java.util.stream.IntStream;
import java.util.stream.Stream;
import java.util.Map.Entry;

public class Main {

    public static void main(String[] args) { new Main().stream(); }

    final IO          io  = new IO();
    final PrintWriter out = new PrintWriter(System.out);

    final int INF = Integer.MAX_VALUE/2;

    void stream(){ solve(); out.flush(); }

    /// ********** ?? ********** ///

    void solve() {
        int N = io.Int();
        int R = io.Int();
        char[] S = io.String().toCharArray();

        int cost = 0;
        int yetRightEdge = -1;
        int mustMoveRightEdge = -1;
        int pos = S.length - 1;
        while (true) {
            yetRightEdge = -1;
            for (int i = pos; i >= 0; --i) {
                if(S[i]=='.'){
                    yetRightEdge = i;
                    break;
                }
            }
            pos = Math.max(0,yetRightEdge - (R-1));
            if(mustMoveRightEdge == -1){ mustMoveRightEdge =  Math.max(0,pos); }
            if(pos == 0) break;
            cost++;
            for(int i = pos; i < Math.min(pos + R,S.length); ++ i){
                S[i] = 'o';
            }
        }
        boolean isAnyLeft = false;
        for(int i = 0; i < S.length; ++i) isAnyLeft |= S[i] == '.';
        if(isAnyLeft) cost++;
        cost += mustMoveRightEdge;
        out.println(cost);

    }

    /// ********** __ ********** ///

    void FOR(int a, int b, Consumer<Integer>act) { for(int i = a; i < b; ++i) act.accept(i); }
    void REP(int a, Consumer<Integer>act) { FOR(0, a, act); }
}
/// ********** ??? ********** ///


/// ********** ___ ********** ///

class IO{
    private final InputStream in = System.in;
    private final byte[] buffer  = new byte[1<<12];
    private int   ptr = 0, buffLen = 0;
    private boolean hasNextByte     ()      {
        if(ptr < buffLen) return true;
        ptr = 0;
        try{ buffLen = in.read(buffer); } catch (IOException e){ e.printStackTrace(); }
        return buffLen > 0;
    }
    private int     readByte        ()      { return hasNextByte()? buffer[ptr++] : -1; }
    private boolean isPrintableChar (int c) { return 33 <= c && c <= 126; } //ASCII
    private void    skipUnprintable ()      { while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; }
    private boolean hasNext         ()      { skipUnprintable(); return hasNextByte();}
    private String  next            ()      {
        if(!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)){ sb.appendCodePoint(b); b = readByte(); }
        return sb.toString();
    }
    public String String () { return next(); }
    public char   Char   () { return next().charAt(0);}
    public int    Int    () { return Integer.parseInt(next());}
    public long   Long   () { return Long.parseLong(next());}
    public double Double () { return Double.parseDouble(next());}
    public String[] StringArr (final int n) { final String[] arr = new String[n]; for(int i = 0; i < n; ++i) arr[i] = String(); return arr; }
    public char  [] CharArr   (final int n) { final char  [] arr = new char  [n]; for(int i = 0; i < n; ++i) arr[i] = Char  (); return arr; }
    public int   [] IntArr    (final int n) { final int   [] arr = new int   [n]; for(int i = 0; i < n; ++i) arr[i] = Int   (); return arr; }
    public long  [] LongArr   (final int n) { final long  [] arr = new long  [n]; for(int i = 0; i < n; ++i) arr[i] = Long  (); return arr; }
    public double[] DoubleArr (final int n) { final double[] arr = new double[n]; for(int i = 0; i < n; ++i) arr[i] = Double(); return arr; }
}