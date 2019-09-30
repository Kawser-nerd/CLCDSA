import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.ConcurrentSkipListSet;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        //ConsoleIO io = new ConsoleIO(new InputStreamReader(System.in), new PrintWriter(System.out));
        String test = "B-large (1)";
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

            int res = 0;

            int ac = io.ri(), bc=  io.ri();

            Period[] all = new Period[ac+bc];
            for(int i = 0;i<ac+bc;i++) {
                int s1 = io.ri();
                int s2 = io.ri();
                all[i] = new Period(s1, s2, i < ac ? 1 : 2);
            }

            Arrays.sort(all, (p1,p2)->p1.s1-p2.s1);
            res = Math.max(calc(1,all), calc(2,all));

            io.writeLine("Case #" + test + ": " + res);
        }
    }

    int calc(int type, Period[] all){

        int whole = 24*60;

        int prevT = all[all.length-1].t;
        int prevS2 = all[all.length-1].s2;
        List<Integer>  gaps = new ArrayList<>();
        int have = 0;
        int switches = 0;
        for(int i = 0;i<all.length;i++) {
            Period p = all[i];
            if (p.t == prevT && p.t == type) {
                gaps.add((p.s1 - prevS2 + whole) % whole);
            }
            if (p.t == type) {
                have += p.s2 - p.s1;
                switches+=2;
            }
            prevT = p.t;
            prevS2 = p.s2;
        }

        gaps.sort(Comparator.naturalOrder());

        int half = whole/2;
        for(int i = 0;i< gaps.size();i++) {
            int v = gaps.get(i);
            if (have + v <= half) {
                have += v;
                switches-=2;
            }
        }
        return switches;
    }

    class Period{
        public Period(int s1, int s2, int t){
            this.s1 = s1;
            this.s2 = s2;
            this.t = t;
        }
        public int s1;
        public int s2;
        public int t;
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