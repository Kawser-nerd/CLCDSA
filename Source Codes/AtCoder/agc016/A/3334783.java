import java.lang.reflect.Array;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;
import java.io.*;



public class Main {

    public static void main(String[] args) throws Exception {
        IO io;
        try{
            io = new IO("in.in",null);
        }
        catch (IOException e) {
            io = new IO(null,null);
        }
        char [] S = io.getNext().toCharArray();
        int [] [] pref = new int[S.length][26];
        int [] [] suff = new int[S.length][26];
        for (char c = 'a';c <= 'z';c++){
            int r = 1 << 20;
            for (int i = 0;i < S.length;i++) {
                if (c == S[i]) r = 0;
                pref[i][c - 'a'] = r;
                r++;
            }
        }
        for (char c = 'a';c <= 'z';c++){
            int r = 1 << 20;
            for (int i = S.length-1;i >= 0;i--) {
                if (c == S[i]) r = 0;
                suff[i][c - 'a'] = r;
                r++;
            }
        }
        int ans = 1 << 20;
        for (char c = 'a';c <= 'z';c++){
            int tmp = 0;
            for (int i = 0;i < S.length;i++){
                int remLen = S.length - tmp;
                if (i < remLen) {
                    int k = S.length-i;
                    tmp = Math.max(tmp, Math.min(suff[i][c - 'a'],k));
                }
            }
            ans = Math.min(ans,tmp);
        }
        io.println(ans);
        io.close();
    }
    private static final int onebillion7 = 1000000007;
}


class IO{
    private BufferedReader br;
    private StringTokenizer st;
    private PrintWriter writer;
    private String inputFile,outputFile;

    public boolean hasMore() throws IOException{
        if(st != null && st.hasMoreTokens()) return true;
        if(br != null && br.ready()) return true;
        return false;
    }

    public String getNext() throws FileNotFoundException, IOException{
        while(st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    public String getNextLine() throws FileNotFoundException, IOException{
        return br.readLine().trim();
    }

    public int getNextInt() throws FileNotFoundException, IOException{
        return Integer.parseInt(getNext());
    }
    public long getNextLong() throws FileNotFoundException, IOException{
        return Long.parseLong(getNext());
    }

    public void print(double x,int num_digits) throws  IOException{
        writer.printf("%." + num_digits + "f" ,x);
    }
    public void println(double x,int num_digits) throws  IOException{
        writer.printf("%." + num_digits + "f\n" ,x);
    }
    public void print(Object o) throws  IOException{
        writer.print(o.toString());
    }

    public void println(Object o) throws  IOException{
        writer.println(o.toString());
    }
    public IO(String x,String y) throws FileNotFoundException, IOException{
        inputFile = x;
        outputFile = y;
        if(x != null) br = new BufferedReader(new FileReader(inputFile));
        else br = new BufferedReader(new InputStreamReader(System.in));
        if(y != null) writer = new PrintWriter(new BufferedWriter(new FileWriter(outputFile)));
        else writer = new PrintWriter(new OutputStreamWriter(System.out));
    }

    protected void close() throws IOException{
        br.close();
        writer.close();
    }
    public void outputArr(Object [] A) throws IOException{
        int L = A.length;
        for (int i = 0;i < L;i++) {
            if(i > 0) writer.print(" ");
            writer.print(A[i]);
        }
        writer.print("\n");
    }
}