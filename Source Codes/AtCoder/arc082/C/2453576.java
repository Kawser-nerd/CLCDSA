import java.io.*;
import java.util.*;

public class Main implements Runnable {
    static ContestScanner in;
    static Writer out;
    public static void main(String[] args) {
        new Thread(null, new Main(), "", 16 * 1024 * 1024).start();
    }

    public void run() {
        Main main = new Main();
        try {
            in = new ContestScanner();
            out = new Writer();
            main.solve();
            out.close();
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    void solve() throws IOException {
        int n = in.nextInt();
        final long mod = 998244353;
        Pos[] p = new Pos[n];
        for (int i = 0; i < n; i++) {
            p[i] = new Pos(i, in.nextInt(), in.nextInt());
        }
        int[][] line = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(line[i], -1);
        }
        Pos maximam = new Pos(-1, Integer.MAX_VALUE / 2, 0);
        Pos minimam = new Pos(-1, Integer.MIN_VALUE / 2, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                Pos max = minimam;
                Pos min = maximam;
                int cnt = 0;
                for (int k = 0; k < n; k++) {
                    if (triarea(p[i], p[j], p[k]) != 0) continue;
                    cnt++;
                    if (p[k].compareTo(max) > 0) {
                        max = p[k];
                    }
                    if (p[k].compareTo(min) < 0) {
                        min = p[k];
                    }
                }
                if (line[min.id][max.id] >= 0) continue;
                line[min.id][max.id] = cnt;
            }
        }

        long ans = (modpow(2, n, mod) - n - 1 + mod) % mod;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (line[i][j] <= 0) continue;
                int m = line[i][j];
                long rem = (modpow(2, m, mod) - m - 1 + mod) % mod;
                ans = (ans - rem + mod) % mod;
            }
        }
        System.out.println(ans);
    }

    static int triarea(Pos a, Pos b, Pos c){
        int dx1 = b.x - a.x;
        int dy1 = b.y - a.y;
        int dx2 = c.x - a.x;
        int dy2 = c.y - a.y;
        return dx1*dy2 - dx2*dy1;
    }

    long modpow(long n, long a, long mod){
        long res = 1;
        while(a > 0){
            if((a&1)==1) res = (res * n) % mod;
            n = n * n % mod;
            a >>= 1;
        }
        return res;
    }
}

class Pos implements Comparable<Pos> {
    int x, y, id;
    Pos(int i, int x, int y) {
        id = i;
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Pos o) {
        if (x != o.x) return x - o.x;
        return y - o.y;
    }
}

class Writer extends PrintWriter{
    public Writer(String filename)throws IOException
    {super(new BufferedWriter(new FileWriter(filename)));}
    public Writer()throws IOException {super(System.out);}
}
class ContestScanner implements Closeable {
    private BufferedReader in;private int c=-2;
    public ContestScanner()throws IOException
    {in=new BufferedReader(new InputStreamReader(System.in));}
    public ContestScanner(String filename)throws IOException
    {in=new BufferedReader(new InputStreamReader(new FileInputStream(filename)));}
    public String nextToken()throws IOException {
        StringBuilder sb=new StringBuilder();
        while((c=in.read())!=-1&&Character.isWhitespace(c));
        while(c!=-1&&!Character.isWhitespace(c)){sb.append((char)c);c=in.read();}
        return sb.toString();
    }
    public String readLine()throws IOException{
        StringBuilder sb=new StringBuilder();if(c==-2)c=in.read();
        while(c!=-1&&c!='\n'&&c!='\r'){sb.append((char)c);c=in.read();}
        return sb.toString();
    }
    public long nextLong()throws IOException,NumberFormatException
    {return Long.parseLong(nextToken());}
    public int nextInt()throws NumberFormatException,IOException
    {return(int)nextLong();}
    public double nextDouble()throws NumberFormatException,IOException
    {return Double.parseDouble(nextToken());}
    public void close() throws IOException {in.close();}
}