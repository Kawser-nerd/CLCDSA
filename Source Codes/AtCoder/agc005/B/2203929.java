import java.io.*;
import java.lang.reflect.Array;
import java.math.*;
import java.text.DecimalFormat;
import java.util.*;




public class Main {
    private static int [] A;
    private static int [] L,R;
    private static int n;

    public static void main(String[] args) throws Exception {
        IO io = new IO(null, null);
        n = io.getNextInt();
        A = new int[n+2];
        for (int i = 1;i <= n;i++) A[i] = io.getNextInt();
        L = new int[n+2];
        R = new int[n+2];
        Stack<Integer> ST = new Stack<>();
        ST.add(0);
        A[0] = A[n+1] = 0;
        for (int i = 1;i <= n;i++) {
            while (A[i] <= A[ST.peek()]) ST.pop();
            L[i] = ST.peek();
            ST.add(i);
        }
        ST.clear();
        ST.add(n+1);
        for (int i = n;i >= 1;i--) {
            while (A[i] <= A[ST.peek()]) ST.pop();
            R[i] = ST.peek();
            ST.add(i);
        }

        long ans = 0;
        for (int i = 1;i <= n;i++) {
            long l = i - L[i],r = R[i] - i;
            long cnt = l*r;
            ans += cnt * A[i];
        }
        io.println(ans);
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