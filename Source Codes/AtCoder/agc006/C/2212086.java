import java.io.*;
import java.lang.reflect.Array;
import java.math.*;
import java.text.DecimalFormat;
import java.util.*;




public class Main {



    public static void main(String[] args) throws Exception {
        IO io = new IO(null, null);
        int n = io.getNextInt();
        long [] X = new long[n];
        int [] P = new int[n];
        long [] D = new long[n];
        for (int i = 0;i < n;i++) {
            X[i] = io.getNextInt();
            P[i] = i;
            if (i > 0)
                D[i] = X[i] - X[i - 1];
        }
        int m = io.getNextInt();
        long K = io.getNextLong();
        int [] A = new int[m];
        for (int i = 0;i < m;i++) {
            A[i] = io.getNextInt() - 1;
            int t = P[A[i]];
            P[A[i]] = P[A[i] + 1];
            P[A[i]+1] = t;
        }


        boolean [] vis = new boolean[n];
        for (int i = 0;i < n;i++) if (!vis[i]) {
            int j = i;
            ArrayList<Integer> U = new ArrayList<>();
            while (!vis[j]) {
                U.add(j);
                vis[j] = true;
                j = P[j];
            }
            int steps = (int)(K%U.size());
            int [] R = new int[U.size()];
            for (int k = 0;k < R.length;k++)
                R[k] = U.get((k + steps)%U.size());
            for (int k = 0;k < R.length;k++)
                P[U.get(k)] = R[k];
        }


        for (int i = 1;i < n;i++)
            X[i] = X[i - 1] + D[P[i]];

        for (int i = 0;i < n;i++)
            io.println(X[i]);


        io.close();
    }
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