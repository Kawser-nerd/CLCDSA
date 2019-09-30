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

    List<Integer>[] tree;
    int[] opposit;
    int[] limit;
    void solve() throws IOException {
        int n = in.nextInt();
        tree = new List[n];
        opposit = new int[n];
        limit = new int[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }
        for (int i = 1; i < n; i++) {
            int p = in.nextInt() - 1;
            tree[p].add(i);
        }

        for (int i = 0; i < n; i++) {
            limit[i] = in.nextInt();
        }

        if (dfs(0)) System.out.println("POSSIBLE");
        else System.out.println("IMPOSSIBLE");
    }

    boolean dfs(int cur) {
        if (tree[cur].isEmpty()) return true;
        int sum = 0;
        for (int v: tree[cur]) {
            if (!dfs(v)) return false;
            sum += limit[v] + opposit[v];
        }
        final int lim = limit[cur] + 1;
        boolean[] dp = new boolean[lim];
        dp[0] = true;
        for (int v: tree[cur]) {
            boolean[] newdp = new boolean[lim];
            for (int i = 0; i < lim; i++) {
                if (!dp[i]) continue;
                if (i + limit[v] < lim) newdp[i + limit[v]] = true;
                if (i + opposit[v] < lim) newdp[i + opposit[v]] = true;
            }
            dp = newdp;
        }
        for (int i = lim - 1; i >= 0; i--) {
            if (dp[i]) {
                opposit[cur] = sum - i;
                return true;
            }
        }
        return false;
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.