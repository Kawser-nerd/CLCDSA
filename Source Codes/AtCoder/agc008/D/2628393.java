import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;
import java.io.*;

public class Main {



    public static void main(String[] args) throws Exception {
        IO io = new IO(null, null);
        int n = io.getNextInt();
        int [] X = new int[n+1];
        for (int i = 1;i <= n;i++)
            X[i] = io.getNextInt();
        int [] A = new int[n*n+1];
        for (int i = 1;i <= n;i++)
            A[X[i]] = i;
        boolean can = true;
        Deque<Integer> dq = new ArrayDeque<>();
        for (int i = A.length-1;i > 0 && can;i--){
            if (A[i] != 0)
                for (int j = 0;j < A[i]-1;j++)
                    dq.addFirst(A[i]);
        }
//        System.err.println(can);
//        System.err.println(Arrays.toString(A));
        for (int i = 1;i < A.length && can;i++) {
            if (A[i] == 0) {
                if (dq.isEmpty()) can = false;
                else A[i] = dq.pollFirst();
            }
            else {
                for (int j = A[i];j < n;j++)
                    dq.addLast(A[i]);
            }
        }
//        System.err.println(Arrays.toString(A));
        HashMap<Integer,Integer> HM = new HashMap<>();
        int [] C = new int[n*n+1];
        for (int i = 1;i <= n;i++) HM.put(i,0);
        for (int i = 1;i < A.length && can;i++){
            HM.put(A[i],HM.get(A[i]) + 1);
            C[i] = HM.get(A[i]);
        }
//        System.err.println(Arrays.toString(C));
        for (int i = 1;i <= n && can;i++)
            can &= C[X[i]] == i;
        if (can) {
            io.println("Yes");
            for (int i = 1;i < A.length;i++)
                io.print(A[i] + " ");
        }
        else io.println("No");
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