import java.io.*;
import java.lang.reflect.Array;
import java.math.*;
import java.text.DecimalFormat;
import java.util.*;




public class Main {
    private static int n,N;
    private static int [] A;
    private static int [] B;

    private static int getLeft(){
        int s = N/2 + 1;
        while (s > 1 && B[s] != B[s-1]) s--;
        return s;
    }
    private static int getRight(){
        int e = N/2+1;
        while (e < N && B[e] != B[e+1]) e++;
        return e;
    }

    private static boolean valid(int x) {
        for (int i = 1;i <= N;i++)
            B[i] = (A[i] >= x) ? 1 : 0;
        int s = getLeft(),e = getRight(),mid = N/2 + 1;
        if (s == mid || e == mid) return B[mid] == 1;

//        System.err.println(s + " " + e);
        int prv = 0;
        int l = B[s],r = B[e];

        while (s <= e) {
            int h = Math.max(s,e);
            h = Math.min(h,N+1-h) - 1;
            int rem = h - prv;
            prv = h;
            if (rem == 0) break;
            int len = e-s-1;
            if (2*rem <= len) {
                s += rem;
                e -= rem;
            }
            else {
                if (l == r) return l == 1;
                if (mid-s < e-mid) return l == 1;
                else return r==1;
            }
        }
//        System.err.println(": " + s + " " + e);
        if (l == r) return l == 1;
        int pos = mid - s;
        if (l == 0) return pos%2 == 0;
        return pos%2 == 1;
    }
    public static void main(String[] args) throws Exception {
        IO io = new IO(null,null);
        n = io.getNextInt();
        N = 2*n-1;
        A = new int[N+1];
        B = new int[N+1];
        for (int i = 1;i <= N;i++)
            A[i] = io.getNextInt();

        int s = 1,e = N;
        while (s < e) {
            int m = s + (e-s+1)/2;
            if (valid(m)) s = m;
            else e = m - 1;
        }
        io.println(s);

        io.close();
    }
    private static void bf(int n) {
        ArrayList<Integer> A = new ArrayList<>();
        for (int i = 0;i < n;i++)
            A.add(i&1);
        TreeSet<ArrayList<Integer>> vis = new TreeSet<>(new Comparator<ArrayList<Integer>>() {
            @Override
            public int compare(ArrayList<Integer> o1, ArrayList<Integer> o2) {
                for (int i = 0;i < n;i++)
                    if (!o1.get(i).equals(o2.get(i)))
                        return o1.get(i) - o2.get(i);
                return 0;
            }
        });

        while (!vis.contains(A)) {
            System.err.println(A);
            vis.add((ArrayList<Integer>)A.clone());
            int prv = A.get(0);
            for (int i = 1;i+1 < n;i++){
                int cur = A.get(i);
                if (prv != cur) A.set(i,A.get(i+1));
                prv = cur;
            }
        }
    }

    private static void bftri(int n) {
        ArrayList<Integer> A = new ArrayList<>();
        for (int i = 0;i < n;i++)
            A.add(i&1);
        while (!A.isEmpty()) {
            System.err.println(A);

            ArrayList<Integer> B = new ArrayList<>();
            int prv = A.get(0);
            for (int i = 1;i+1 < A.size();i++){
                int cur = A.get(i);
                if (prv != cur) B.add(A.get(i+1));
                else B.add(cur);
                prv = cur;
            }
            A = B;
        }
    }
}

class pair{
    int s,e,v;
    public pair(int s,int e,int v) {
        this.s = s;
        this.e = e;
        this.v = v;
    }
    public int getLen(){
        return e-s+1;
    }
    @Override
    public String toString(){
        return "(" + s + ":" + e + ", " + v + ")";
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.