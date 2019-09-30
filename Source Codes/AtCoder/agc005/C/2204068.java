import java.io.*;
import java.lang.reflect.Array;
import java.math.*;
import java.text.DecimalFormat;
import java.util.*;




public class Main {
    private static int n;
    private static int [] A;


    private static boolean solve(){
        if (n == 1) return A[0] == 0;
        TreeMap<Integer,Integer> TM = new TreeMap<>();
        for (int i = 1;i < n;i++) TM.put(i,0);
        int diameter = 0;
        for (int x : A) {
            TM.put(x,TM.get(x) + 1);
            diameter = Math.max(diameter,x);
        }

        if (TM.get(diameter) < 2) return false;
        TM.put(diameter,TM.get(diameter) - 2);
        boolean [] have = new boolean[n];
        have[diameter] = true;
        for (int x = 1;x < diameter;x++) {
            int y = x;
            if (diameter - x > x) y = diameter - x;
            if (TM.get(y) == 0) return false;
            TM.put(y,TM.get(y) - 1);
            have[y] = true;
        }
        for (int x : TM.keySet()) {
            int y = x;
            if (TM.get(y) == 0) continue;
            if (!have[y - 1]) return false;
            have[y] = true;
        }
        return true;
    }
    public static void main(String[] args) throws Exception {
        IO io = new IO(null, null);
        n = io.getNextInt();
        A = new int[n];
        for (int i = 0;i < n;i++) A[i] = io.getNextInt();

        io.println(solve() ? "Possible" : "Impossible");

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