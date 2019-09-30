import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Closeable;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
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
        s = in.nextToken().toCharArray();
        int k = in.nextInt();
        len = s.length;
        dp = new int[len][len][k + 1];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                for (int l = 0; l <= k; l++) {
                    dp[i][j][l] = -1;
                }
            }
        }
        System.out.println(dfs(0, len - 1, k));
    }

    int len;
    char[] s;
    int[][][] dp;
    int dfs(int l, int r, int k) {
        if(r < l) return 0;
        else if(r == l) return 1;
        if(dp[l][r][k] >= 0) return dp[l][r][k];
        int ans = 0;
        if(s[l] == s[r]) ans = dfs(l + 1, r - 1, k) + 2;
        else if(k > 0) ans = Math.max(ans, dfs(l + 1, r - 1, k - 1) + 2);
        ans = Math.max(ans, dfs(l + 1, r, k));
        ans = Math.max(ans, dfs(l, r - 1, k));
        return dp[l][r][k] = ans;
    }
}

@SuppressWarnings("serial")
class MultiSet<T> extends HashMap<T, Integer>{
    @Override public Integer get(Object key){return containsKey(key)?super.get(key):0;}
    public void add(T key,int v){put(key,get(key)+v);}
    public void add(T key){put(key,get(key)+1);}
    public void sub(T key){final int v=get(key);if(v==1)remove(key);else put(key,v-1);}
    public MultiSet<T> merge(MultiSet<T> set)
    {MultiSet<T>s,l;if(this.size()<set.size()){s=this;l=set;}else{s=set;l=this;}
        for(Entry<T,Integer>e:s.entrySet())l.add(e.getKey(),e.getValue());return l;}
}

class Writer extends PrintWriter{
    public Writer(String filename)throws IOException
    {super(new BufferedWriter(new FileWriter(filename)));}
    public Writer()throws IOException{super(System.out);}
}
class ContestScanner implements Closeable{
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