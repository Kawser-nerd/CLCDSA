import java.io.*;
import java.lang.reflect.Array;
import java.math.*;
import java.text.DecimalFormat;
import java.util.*;




public class Main {
    private static final int mod = 924844033;
    private static int n;
    private static int [] fr,to,val,siz;
    private static ArrayList<Integer> [] E;
    private static int [] fact,rev;

    private static int add(int a,int b) {
        a += b;
        if (a >= mod) a -= mod;
        if (a < 0) a += mod;
        return a;
    }

    private static int mul(int a,int b) {
        return (int)((a*(long)b)%mod);
    }
    private static void init() throws Exception{
        fr = new int[n-1];
        to = new int[n-1];
        val = new int[n-1];
        siz = new int[n+1];
        E = new ArrayList[n+1];
        for (int u = 1;u <= n;u++)
            E[u] = new ArrayList<>();

        fact = new int[n+1];
        fact[0] = 1;
        for (int i = 1;i <= n;i++)
            fact[i] = mul(fact[i-1],i);

        int [] r = new int[n+1];
        rev = new int[n+1];
        rev[0] = rev[1] = r[1] = 1;
        for (int i = 2;i <= n;i++) {
            r[i] = add(mod ,-mul(mod/i, r[mod%i]));
            rev[i] = mul(rev[i-1],r[i]);
            if (mul(fact[i],rev[i]) != 1)
                throw new Exception("!= 1");
        }

    }

    private static int C(int n,int k) {
        if (k > n) return 0;
        int res = fact[n];
        res = mul(res,rev[k]);
        res = mul(res,rev[n-k]);
        return res;
    }

    private static int powmod(int x,int p) {
        if (p == 0) return 1;
        int y = 1;
        for (;p > 1;p >>= 1) {
            if (p%2 == 1) y = mul(x,y);
            x = mul(x,x);
        }
        return mul(x,y);
    }

    private static void dfs(int u,int p){
        siz[u] = 1;
        for (int e : E[u]) {
            int v = fr[e] + to[e] - u;
            if (v == p) continue;
            fr[e] = u; to[e] = v;
            dfs(v,u);
            siz[u] += siz[v];
        }
    }

    public static void main(String[] args) throws Exception {
        IO io = new IO(null, null);
        n = io.getNextInt();
        init();
        for (int e = 0;e < n-1;e++) {
            int a = io.getNextInt(),b = io.getNextInt();
            fr[e] = a;
            to[e] = b;
            E[a].add(e);
            E[b].add(e);
        }
        dfs(1,0);

        int [] b = new int[n+1];
        for (int e = 0;e < n-1;e++) {
            int v = to[e];
            b[siz[v]] = add(b[siz[v]],-1);
            b[n-siz[v]] = add(b[n-siz[v]],-1);
        }
        b[n] = n;

        int [] c = new int[n+1];
        for (int i = 0;i <= n;i++)
            c[i] = mul(fact[i],b[i]);

        int [] d = new int[n+1];
        for (int i = 0;i <= n;i++)
            d[i] = rev[n-i];



        // 2187
        int g = powmod(3,441);
        int [] R = NTT.mult(c,d,mod);


        for (int i = 1;i <= n;i++)
            io.println(mul(R[i+n],rev[i]));


        io.close();
    }
}



class NTT{
    private static int add(int a,int b,int mod) {
        a %= mod;
        b %= mod;
        a += b;
        if (a >= mod) a -= mod;
        if (a < 0) a += mod;
        return a;
    }

    private static int mul(int a,int b,int mod) {
        a %= mod; b %= mod;
        return (int)((a*(long)b)%mod);
    }
    public static int [] mult(int [] fA,int [] fB,int P) {
        int n = Math.max(fA.length,fB.length);
        while (n != (n & -n)) n++;
        n <<= 1;
        int g = powmod(5,(P-1)/n,P);

        int [] pA = new int[n];
        int [] pB = new int[n];
        int [] pC = new int[n];
        for (int i = 0;i < fA.length;i++) pA[i] = fA[i];
        for (int i = 0;i < fB.length;i++) pB[i] = fB[i];

        pA = ntt(pA,false,g,P);
        pB = ntt(pB,false,g,P);

        for (int i = 0;i < n;i++)
            pC[i] = mul(pA[i],pB[i],P);
        return ntt(pC,true,g,P);
    }
    private static int getLen(int n) {
        if (n == 0) return 1;
        int r = 0;
        while (n > 0) {
            r ++;
            n /= 2;
        }
        return r;
    }
    private static int rev(int n,int l){
        int r = 0;
        for (int i = 0;i < l;i++){
            r = (r << 1) | (n & 1);
            n >>= 1;
        }
        return r;
    }

    private static void bit_rev(int [] IN,int [] OUT,int m) {
        int l = getLen(m) - 1;
        for (int i = 0; i < m; i++) {
            OUT[rev(i, l)] = IN[i];
        }
    }

    private static int powmod(int x,int p,int mod) {
        if (p == 0) return 1;
        int y = 1;
        for (;p > 1;p >>= 1) {
            if (p%2 == 1) y = mul(x,y,mod);
            x = mul(x,x,mod);
        }
        return mul(x,y,mod);
    }
    private static int [] ntt(int [] f,boolean inv,int g,int P) {
        if (f.length == 1) return f;
        int n = f.length;
        int [] O = new int[n];
        bit_rev(f,O,n);
        int lg = getLen(n) - 1;
        int [] G = new int[lg + 1];
        G[lg] = g;
        int [] rG = new int[lg + 1];
        rG[lg] = powmod(g,P-2,P);
        for (int i = lg-1;i >= 0;i--) {
            G[i] = mul(G[i + 1],G[i + 1],P);
            rG[i] = mul(rG[i+1],rG[i+1],P);
        }
        for(int m = 2,s = 1;m <= n;m <<= 1,s++){
            int gk = inv ? rG[s] : G[s];

//            System.err.println(m + ":");
            for(int k = 0;k < n;k += m){
                int w = 1;
                for(int j = 0;j < m/2;j++){
                    int t = mul(w,O[k + j + m/2],P);
                    int u = O[k + j];
                    O[k + j] = add(u,t,P);
                    O[k + j + m/2] = add(u,P-t,P);
//                    if (O[k + j] != 0) System.err.println(O[k + j]);
//                    if (O[k + j + m/2] != 0) System.err.println(O[k + j + m/2]);;
                    w = mul(w,gk,P);
                }
            }
        }
        if(inv) {
            int in = powmod(n,P-2,P);
            for(int i = 0;i < n;i++) O[i] = mul(O[i],in,P);
        }
        return O;
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