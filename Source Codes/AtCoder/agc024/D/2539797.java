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
        node = new List[n];
        List<List<Integer>> query = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            List<Integer> qu = new ArrayList<>();
            qu.add(i);
            query.add(qu);
            node[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 1; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            node[a].add(b);
            node[b].add(a);

            List<Integer> qu = new ArrayList<>();
            qu.add(a);
            qu.add(b);
            query.add(qu);
        }
        if (n == 2) {
            System.out.println("1 2");
            return;
        }
        int[] stPre = new int[n];
        int[] stPos = new int[n];
        int[] stPrePar = new int[n];
        int[] stPosPar = new int[n];
        int pre = 0;
        int pos = 0;
        int[] stDown = new int[n];
        int dwn = 0;
        long dwnMin = Integer.MAX_VALUE;
        int depMin = Integer.MAX_VALUE;

        for (List<Integer> qu: query) {
            pre = 0;
            pos = 0;
            if (qu.size() == 1) {
                stPre[pre++] = qu.get(0);
                stPrePar[0] = -1;
            } else {
                stPrePar[pre] = qu.get(1);
                stPre[pre++] = qu.get(0);

                stPrePar[pre] = qu.get(0);
                stPre[pre++] = qu.get(1);
            }

            int max = 1;
            int depth = 0;
            long dwnAll = 0;
            long leaf = 0;
            while (max > 0) {
                depth++;
                max = 0;
                dwn = 0;
                for (int j = 0; j < pre; j++) {
                    int v = stPre[j];
                    int par = stPrePar[j];
                    int cnt = 0;
                    for (int nv: node[v]) {
                        if (nv == par) continue;
                        stPos[pos] = nv;
                        stPosPar[pos++] = v;
                        cnt++;
                    }
                    stDown[dwn++] = cnt;
                    max = Math.max(cnt, max);
                }
                long downNum = 0;
                long notDown = 0;
                for (int j = 0; j < dwn; j++) {
                    downNum += max - stDown[j];
                    notDown += stDown[j];
                }
                if (max == 0) break;
                dwnAll = dwnAll * max + downNum;
                leaf = notDown + dwnAll;

                int[] tmp = stPre;
                stPre = stPos;
                stPos = tmp;

                tmp = stPosPar;
                stPosPar = stPrePar;
                stPrePar = tmp;

                pre = pos;
                pos = 0;
            }
            if (depth < depMin || depth == depMin && leaf < dwnMin) {
                depMin = depth;
                dwnMin = leaf;
            }
        }
        System.out.println(depMin + " " + dwnMin);
    }

    List<Integer>[] node;

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