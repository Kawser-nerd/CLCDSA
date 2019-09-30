import java.io.*;
import java.lang.reflect.Array;
import java.math.*;
import java.text.DecimalFormat;
import java.util.*;




public class Main {



    public static void main(String[] args) throws Exception {
        IO io = new IO(null, null);
        int n = io.getNextInt(),x = io.getNextInt();
        int N = 2*n - 1;
        if (x == 1 || x == N) io.println("No");
        else if (n == 2) {
            io.println("Yes");
            io.println("1\n2\n3");
        }
        else {
            io.println("Yes");
            int [] P = new int[N];
            boolean [] taken = new boolean[N + 1];
            int m = N/2;
            if (x+1 != N) {
                P[m - 2] = x+1;
                P[m - 1] = 1;
                P[m] = x;
                P[m+1] = N;
                taken[x+1] = taken[x] = taken[1] = taken[N] = true;
            }
            else {
                P[m - 2] = 1;
                P[m - 1] = N;
                P[m] = x;
                P[m+1] = x-1;
                taken[x-1] = taken[x] = taken[1] = taken[N] = true;
            }
            for (int i = 0,j = 1;i < N;i++) {
                if (P[i] != 0) continue;
                while (taken[j]) j++;
                P[i] = j;
                taken[j] = true;
            }
            for (int i = 0;i < N;i++)
                io.println(P[i]);
        }
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