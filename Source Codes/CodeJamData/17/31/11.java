import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.ConcurrentSkipListSet;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        //ConsoleIO io = new ConsoleIO(new InputStreamReader(System.in), new PrintWriter(System.out));
        String test = "A-large (1)";
        ConsoleIO io = new ConsoleIO(new FileReader("D:\\Dropbox\\code\\practice\\jb\\src\\" + test + ".in"), new PrintWriter(new File("D:\\Dropbox\\code\\practice\\jb\\src\\" + test + "-out.txt")));

        new Main(io).solve();
        io.close();
    }

    ConsoleIO io;
    Main(ConsoleIO io) {
        this.io = io;
    }

    long MOD = 1_000_000_007;
    List<List<Integer>> gr = new ArrayList<>();

    public void solve() {
        int TESTS = io.ri();
        for(int test = 1;test<=TESTS;test++){

            int n = io.ri(), k =io.ri();

            Cake[] all = new Cake[n];
            for(int i =0 ;i<n;i++) {
                int r = io.ri();
                int h = io.ri();
                all[i] = new Cake(r, h);
            }

            Arrays.sort(all, (c1,c2)->c1.r-c2.r);
            double[] sur = new double[n];
            for(int i = 0;i<n;i++){
                Cake c = all[i];
                sur[i] = Math.PI * 2.0 * c.r * c.h;
            }

            double[][] max = new double[n][k+1];
            double[] vv = new double[n];
            for(int i = 0;i<n;i++){
                double[] mi = max[i];
                mi[1] = sur[i];
                vv[0] = mi[k];
                if(i>0) {
                    double[] m1 = max[i-1];
                    for (int j = 1; j <= k; j++) {
                        mi[j] = Math.max(mi[j], m1[j-1] + sur[i]);
                    }
                    vv[i] = mi[k];

                    for (int j = 1; j <= k; j++) {
                        mi[j] = Math.max(mi[j], m1[j]);
                    }
                }
            }

            double res = 0.0;
            for(int i = 0;i<n;i++) {
                Cake c = all[i];
                double area = Math.PI * c.r * c.r;
                res = Math.max(vv[i] + area, res);
            }
            io.writeLine("Case #" + test + ": " + res);
        }
    }

    class Cake{
        public Cake(int R, int H){
            r = R;
            h = H;
        }
        public int r;
        public int h;
    }

}

class ConsoleIO {
    BufferedReader br;
    PrintWriter out;
    public ConsoleIO(Reader reader, PrintWriter writer){br = new BufferedReader(reader);out = writer;}
    public void flush(){this.out.flush();}
    public void close(){this.out.close();}
    public void writeLine(String s) {this.out.println(s);}
    public void writeInt(int a) {this.out.print(a);this.out.print(' ');}
    public void writeWord(String s){
        this.out.print(s);
    }
    public void writeIntArray(int[] a, int k, String separator) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < k; i++) {
            if (i > 0) sb.append(separator);
            sb.append(a[i]);
        }
        this.writeLine(sb.toString());
    }
    public int read(char[] buf, int len){try {return br.read(buf,0,len);}catch (Exception ex){ return -1; }}
    public String readLine() {try {return br.readLine();}catch (Exception ex){ return "";}}
    public long[] readLongArray() {
        String[]n=this.readLine().trim().split("\\s+");long[]r=new long[n.length];
        for(int i=0;i<n.length;i++)r[i]=Long.parseLong(n[i]);
        return r;
    }
    public int[] readIntArray() {
        String[]n=this.readLine().trim().split("\\s+");int[]r=new int[n.length];
        for(int i=0;i<n.length;i++)r[i]=Integer.parseInt(n[i]);
        return r;
    }
    public int[] readIntArray(int n) {
        int[] res = new int[n];
        char[] all = this.readLine().toCharArray();
        int cur = 0;boolean have = false;
        int k = 0;
        boolean neg = false;
        for(int i = 0;i<all.length;i++){
            if(all[i]>='0' && all[i]<='9'){
                cur = cur*10+all[i]-'0';
                have = true;
            }else if(all[i]=='-') {
                neg = true;
            }
            else if(have){
                res[k++] = neg?-cur:cur;
                cur = 0;
                have = false;
                neg = false;
            }
        }
        if(have)res[k++] = neg?-cur:cur;
        return res;
    }
    public int ri() {
        try {
            int r = 0;
            boolean start = false;
            boolean neg = false;
            while (true) {
                int c = br.read();
                if (c >= '0' && c <= '9') {
                    r = r * 10 + c - '0';
                    start = true;
                } else if (!start && c == '-') {
                    start = true;
                    neg = true;
                } else if (start || c == -1) return neg ? -r : r;
            }
        } catch (Exception ex) {
            return -1;
        }
    }
    public long readLong() {
        try {
            long r = 0;
            boolean start = false;
            boolean neg = false;
            while (true) {
                int c = br.read();
                if (c >= '0' && c <= '9') {
                    r = r * 10 + c - '0';
                    start = true;
                } else if (!start && c == '-') {
                    start = true;
                    neg = true;
                } else if (start || c == -1) return neg ? -r : r;
            }
        } catch (Exception ex) {
            return -1;
        }
    }
    public String readWord() {
        try {
            boolean start = false;
            StringBuilder sb = new StringBuilder();
            while (true) {
                int c = br.read();
                if (c!= ' ' && c!= '\r' && c!='\n' && c!='\t') {
                    sb.append((char)c);
                    start = true;
                } else if (start || c == -1) return sb.toString();
            }
        } catch (Exception ex) {
            return "";
        }
    }
    public char readSymbol() {
        try {
            while (true) {
                int c = br.read();
                if (c != ' ' && c != '\r' && c != '\n' && c != '\t') {
                    return (char) c;
                }
            }
        } catch (Exception ex) {
            return 0;
        }
    }
    //public char readChar(){try {return (char)br.read();}catch (Exception ex){ return 0; }}
}