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
        char[] s = new StringBuilder(in.nextToken()).reverse().toString().toCharArray();
        int n = s.length;
        int[][] edge = new int[n][26];
        int[] next = new int[26];
        Arrays.fill(next, n);
        for (int i = 0; i < 26; i++) {
            next[i] = n + i;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                edge[i][j] = next[j];
            }
            next[s[i] - 'a'] = i;
        }
        int[] dp = new int[n + 27];
        int[] pre = new int[n + 27];
        char[] pchar = new char[n + 27];
        Arrays.fill(pchar, (char)('z' + 1));
        Arrays.fill(pre, -1);
        Arrays.fill(dp, Integer.MAX_VALUE / 2);
        for (int i = 0; i < 26; i++) {
            dp[next[i]] = 1;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (dp[edge[i][j]] > dp[i] + 1 || dp[edge[i][j]] == dp[i] + 1 && s[i] < pchar[edge[i][j]]) {
                    dp[edge[i][j]] = dp[i] + 1;
                    pre[edge[i][j]] = i;
                    pchar[edge[i][j]] = s[i];
                }
            }
        }

//        for (int i = 0; i < n; i++) {
//            System.out.printf("%3c", s[i]);
//        }
//        System.out.println();
//        for (int i = 0; i < n + 26; i++) {
//            System.out.printf("%3d", dp[i]);
//        }
//        System.out.println();
//        for (int i = 0; i < n + 26; i++) {
//            System.out.printf("%3d", pre[i]);
//        }
//        System.out.println();

        int min = Integer.MAX_VALUE;
        int minId = -1;
        for (int i = 0; i < 26; i++) {
            if (dp[n + i] < min) {
                min = dp[n + i];
                minId = i;
            }
        }

        sb.append((char)(minId + 'a'));
        minId = pre[minId + n];

        while (minId >= 0) {
            sb.append(s[minId]);
            minId = pre[minId];
        }

        System.out.println(sb.toString());
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