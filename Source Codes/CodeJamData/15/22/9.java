import java.io.*;
import java.math.BigInteger;
import java.util.*;

/**
 * Created by shamir0xe on 1/5/2015 AD.
 */

public class Solution {

    public static void main(String[] args) {
        MyInput in;
        try {
            in = new MyInput(new FileInputStream(new File("input.txt")));
        }
        catch (IOException e) {
            throw new UnknownError();
        }
        PrintWriter out;
        try {
            out = new PrintWriter(new FileOutputStream(new File("output.txt")));
        }
        catch (IOException e) {
            throw new UnknownError();
        }

//        MyInput in = new MyInput(System.in);
//        PrintWriter out = new PrintWriter(System.out);

        Solver solver = new Solver();
        int testCase = in.nextInt();
        for (int test = 0; test < testCase; test++) {
            solver.solve(in, out, test + 1);
            out.flush();
        }

//        solver.solve(in, out, 1);

//        int test = 1;
//        try {
//            while (true) {
//                solver.solve(in, out, test++);
//            }
//        } catch (UnknownError unknownError) {
//            out.flush();
//            out.close();
//        }

        out.flush();
        out.close();
    }
}

class Solver {

    int dx[] = {0, +1, 0, -1};
    int dy[] = {+1, 0, -1, 0};
    public void solve (MyInput in, PrintWriter out, int testCase) {
        int r = in.nextInt();
        int c = in.nextInt();
        int n = in.nextInt();

        int ans = Integer.MAX_VALUE / 2;
        {
            int[][] board = new int[r][c];
            int[] neighbourCnt = new int[5];

            int cur;
            int init = 0;
            for (int i = 0; i < r; i++) {
                cur = init;
                init ^= 1;
                for (int j = 0; j < c; j++) {
                    board[i][j] = cur;
                    cur ^= 1;
                }
            }
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    int cnt = countN(board, i, j, r, c);
                    neighbourCnt[cnt]++;
                }
            }
//            for (int i = 0; i < r; i++) {
//                for (int j = 0; j < c; j++) {
//                    System.out.print(board[i][j]);
//                }
//                System.out.println();
//            }
//
//            for (int i = 0; i < 5; i++) {
//                System.out.println(i + ": " + neighbourCnt[i]);
//            }


            int curAns = 0;
            int nn = n;
            int iter = 0;
            while (n > 0) {
                int m = Math.min(n, neighbourCnt[iter]);
                n -= m;
                curAns += m * iter;
                iter++;
            }
            n = nn;

            ans = Math.min(ans, curAns);
        }

        {
            int[][] board = new int[r][c];
            int[] neighbourCnt = new int[5];

            int cur;
            int init = 1;
            for (int i = 0; i < r; i++) {
                cur = init;
                init ^= 1;
                for (int j = 0; j < c; j++) {
                    board[i][j] = cur;
                    cur ^= 1;
                }
            }
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    int cnt = countN(board, i, j, r, c);
                    neighbourCnt[cnt]++;
                }
            }
//            for (int i = 0; i < r; i++) {
//                for (int j = 0; j < c; j++) {
//                    System.out.print(board[i][j]);
//                }
//                System.out.println();
//            }
//
//            for (int i = 0; i < 5; i++) {
//                System.out.println(i + ": " + neighbourCnt[i]);
//            }

            int curAns = 0;
            int nn = n;
            int iter = 0;
            while (n > 0) {
                int m = Math.min(n, neighbourCnt[iter]);
                n -= m;
                curAns += m * iter;
                iter++;
            }
            n = nn;

            ans = Math.min(ans, curAns);
        }

        out.print("Case #" + testCase + ": ");
        out.println(ans);
    }

    private boolean inRange(int x, int y, int r, int c) {
        return x >= 0 && x < r && y >= 0 && y < c;
    }

    private int countN(int [][] board, int x, int y, int r, int c) {
        int cnt = 0;
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (inRange(xx, yy, r, c) && board[xx][yy] == 1) {
                cnt++;
            }
        }
        return cnt;
    }

    private int countNeighber(int[][] board, int r, int c) {
        int cnt = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (inRange(x, y, r, c) && board[x][y] == 1) {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt / 2;
    }

}

class SuffixTrie {
    int nodeCount;
    ArrayList<int[]> dictionary;
    boolean end[];
    int pathTrough[];

    int dicSize;
    /**
     *
     * @param maxn : maximum amount of nodes expected
     */
    public SuffixTrie(int maxn, int dicSize) {
        nodeCount = 0;
        dictionary = new ArrayList<int[]>();

        this.dicSize = dicSize;
        int [] newArr = new int[dicSize];
        Arrays.fill(newArr, -1);
        dictionary.add(newArr);

        nodeCount++;
        end = new boolean[maxn];
        pathTrough = new int[maxn];
    }

    public boolean addLenWord_min(int u, int len) {
        if (len == 0) {
            return false;
        }
        pathTrough[u]++;
        final int curNode[] = dictionary.get(u);

        Integer order[] = new Integer[dicSize];
        for (int i = 0; i < dicSize; i++) {
            order[i] = i;
        }
        Arrays.sort(order, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if (curNode[o1] == -1 && curNode[o2] == -1) {
                    return 0;
                }
                if (curNode[o1] == -1) {
                    return -1;
                }
                if (curNode[o2] == -1) {
                    return +1;
                }
                return pathTrough[curNode[o1]] - pathTrough[curNode[o2]];
            }
        });

//        for (int i = 0; i < dicSize; i++) {
//            System.out.print("(" + order[i] + ", " + pathTrough[curNode[order[i]]] + "), ");
//        }
//        System.out.println();
        for (int i = dicSize - 1; i >= 0; i--) {
            if (curNode[order[i]] != -1 && addLenWord_min(curNode[order[i]], len - 1)) {
                return true;
            }
        }

        for (int i = 0; i < dicSize; i++) {
            if (curNode[i] == -1) {
                curNode[i] = nodeCount++;
                int [] newArr = new int[dicSize];
                Arrays.fill(newArr, -1);
                dictionary.add(newArr);

                if (len == 1) {
                    pathTrough[nodeCount - 1]++;
                    end[nodeCount - 1] = true;
                }
                else {
                    addLenWord_min(nodeCount - 1, len - 1);
                }
                return true;
            }
        }

        return false;
    }


    public boolean addLenWord_max(int u, int len) {
        if (len == 0) {
            return false;
        }
        pathTrough[u]++;
        final int curNode[] = dictionary.get(u);
        for (int i = 0; i < dicSize; i++) {
            if (curNode[i] == -1) {
                curNode[i] = nodeCount++;
                int [] newArr = new int[dicSize];
                Arrays.fill(newArr, -1);
                dictionary.add(newArr);

                if (len == 1) {
                    pathTrough[nodeCount - 1]++;
                    end[nodeCount - 1] = true;
                }
                else {
                    addLenWord_max(nodeCount - 1, len - 1);
                }
                return true;
            }
        }

        Integer order[] = new Integer[dicSize];
        for (int i = 0; i < dicSize; i++) {
            order[i] = i;
        }
        Arrays.sort(order, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return pathTrough[curNode[o1]] - pathTrough[curNode[o2]];
            }
        });

//        for (int i = 0; i < dicSize; i++) {
//            System.out.print("(" + order[i] + ", " + pathTrough[order[i]] + "), ");
//        }
//        System.out.println();

        for (int i = 0; i < dicSize; i++) {
            if (addLenWord_max(curNode[order[i]], len - 1)) {
                return true;
            }
        }

        return false;
    }
}


class LabelGenerator {
    Random random;

    LabelGenerator () {
        random = new Random(System.currentTimeMillis());
    }

    public String RandomNameGenerator(int len) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len; i++) {
            sb.append((char)('a' + random.nextInt(26)));
        }
        return sb.toString();
    }
}

class GraphGenerator {

    public void printGraph(ArrayList<Integer>[] g, String[] name, int u, boolean[] color, PrintWriter out) {
        color[u] = true;
        for (int v : g[u]) {
            if (!color[v]) {
                out.println(name[u] + " " + name[v]);
                printGraph(g, name, v, color, out);
            }
        }
    }

    /**
     *
     * @param u
     * @param nodeCnt : childs node of u
     * @param whichNodeBegin
     * @param tree
     */
    private void DFS_TreeGenerator(int u, int nodeCnt, int whichNodeBegin, ArrayList <Integer>[] tree) {
        if (nodeCnt == 0) {
            return ;
        }
        int childCnt = new Random(System.currentTimeMillis()).nextInt(nodeCnt) + 1;
        int[] randomSequence = randomSumSequence(childCnt, nodeCnt);
        for (int i = 0; i < childCnt; i++) {
            int curNode = whichNodeBegin;
            tree[u].add(curNode);
            tree[curNode].add(u);

            DFS_TreeGenerator(curNode, randomSequence[i] - 1, whichNodeBegin + 1, tree);
            whichNodeBegin += randomSequence[i];
        }
    }

    public ArrayList<Integer>[] getRandomTree(int n) {
        ArrayList <Integer>[] tree = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }
        DFS_TreeGenerator(0, n - 1, 1, tree);
        return tree;
    }

    /**
     *
     * @param n
     * @param sum
     * @return random array which have n elements that each element is greater than zero
     */
    int[] randomSumSequence(int n, int sum) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = 1;
            sum--;
        }

        Random random = new Random(System.currentTimeMillis());
        for (int i = 0; i < sum; i++) {
            arr[random.nextInt(n)]++;
        }
        return arr;
    }


}


class LCA {
    ArrayList <Integer> adj[];
    int n;
    int level[];
    int jads[][];

    LCA (int n) {
        this.n = n;
        level = new int[n];
        jads = new int[n][22];
    }

    public void preProcess(int root) {
        setLevel(root, root, 0);

        for (int L = 1; (1 << L) <= n; L++) {
            for (int i = 0; i < n; i++) {
                jads[i][L] = jads[jads[i][L - 1]][L - 1];
            }
        }
    }

    public int getMinJad(int u, int v) {
        if (level[u] < level[v]) {
            int temp = u;
            u = v;
            v = temp;
        }

        int len = u - v;
        for (int i = 0; i < 22; i++) {
            if ((len >> i & 1) != 0) {
                u = jads[u][i];
            }
        }
        if (u == v) {
            return u;
        }

        for (int i = 21; i >= 0; i--) {
            if (jads[u][i] != jads[v][i]) {
                u = jads[u][i];
                v = jads[v][i];
            }
        }
        return jads[u][0];
    }

    public void setLevel(int u, int par, int curLevel) {
        level[u] = curLevel;
        jads[u][0] = par;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u].get(i);
            if (v == par) {
                continue;
            }
            setLevel(v, u, curLevel + 1);
        }
    }

}

class MyInput {
    private BufferedReader br;
    private StringTokenizer st;

    MyInput (InputStream inputStream) {
        br = new BufferedReader(new InputStreamReader(inputStream));
        st = null;
    }

    public String next() {
        if (st == null || !st.hasMoreElements()) {
            try {
                String line = br.readLine();
                if (line == null) {
                    throw new UnknownError();
                }
                while (line.trim().equals("")) {
                    line = br.readLine();
                    if (line == null) {
                        throw new UnknownError();
                    }
                }
                st = new StringTokenizer(line);
            } catch (IOException e) {
                throw new UnknownError();
            }
        }
        return st.nextToken();
    }

    public String nextLine() {
        try {
            String line = br.readLine();
            if (line == null) {
                throw new UnknownError();
            }
            return line;
        }
        catch (IOException e) {
            throw new UnknownError();
        }
    }

    public void readEmptyLine() {
        try {
            br.readLine();
        }
        catch (IOException e) {
            throw new UnknownError();
        }
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

}

/**
 * Created by shamir0xe on 2/28/14.
 */
class MyMath {

    /**
     * Sieve Of Eratosthens[O(NloglogN)]
     * @param n
     * @return int[] with all primes within [0, n]
     */
    public static int[] sieve(int n){
        int[] pr = new int[n + 1];
        Arrays.fill(pr, 1);
        ArrayList <Integer> prime = new ArrayList<Integer>();
        pr[0] = pr[1] = 0;
        for(int i = 2; i <= n; i++) {
            if(pr[i] == 1) {
                prime.add(i);
                if((long)i * i <= n)
                    for(long j = (long)i * i; j <= n; j += i)
                        pr[(int)j] = 0;
            }
        }
        int [] ret = new int[prime.size()];
        for (int i = 0; i < ret.length; i++) {
            ret[i] = prime.get(i);
        }
        return ret;
    }

    /**
     * GCD[O(logMAX(a, b))]
     * @param a
     * @param b
     * @return GCD(a, b)
     */
    public static int GCD(int a, int b){return b!=0 ? GCD(b, a % b) : a;}

    /**
     * Fast Power [O(logB)]
     * @param a
     * @param b
     * @param m
     * @return bth power of a modolu m
     */
    public static int fastPow(int a, int b, int m){
        int ans = 1;
        while(b != 0){
            if((b & 1) == 1)
                ans = mul(ans, a, m);
            a = mul(a, a, m);
            b >>= 1;
        }
        return ans%m;
    }

    public static void buildPascal(int[][] pas, int MOD) {
        int n = pas.length;
        for (int i = 0; i < n; i++) {
            pas[i][0] = 0;
        }
        for (int i = 0; i < n; i++) {
            pas[0][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                pas[i][j] = (pas[i][j-1] + pas[i-1][j-1]) % MOD;
            }
        }
    }

    // ext. Euclidean [O(log(Max(a, b))]
    // Assumes nonnegative input. Returns d such that d=a*X+b*Y
    public static long GCDex (long a, long b, long[] x, long[] y) {
        if (a == 0) {
            x[0] = 0; y[0] = 1;
            return b;
        }
        long[] x1 = new long[1];
        long[] y1 = new long[1];

        long d = GCDex(b % a, a, x1, y1);
        x[0] = y1[0] - (b / a) * x1[0];
        y[0] = x1[0];
        return d;
    }

    // Return X such that A * X == 1 (mod M)
    // Return -1 if it doesn't exist such an X
    public static long invMod(long a, long m){
        long[] x = new long[1];
        long[] q = new long[1];
        if(GCDex(a, m, x, q) == 1){
            x[0] = x[0] % m;
            if (x[0] < m) {
                x[0] = (x[0] + m) % m;
            }
            return x[0];
        }
        return -1;
    }

    /**
     *  this function gives the prime factors of n
     *  @param n an integer that wanna it primes
     *  @param primes the int[] of primes
     **/
    public static ArrayList<int[]> getFactors(int n, int[] primes) {
        ArrayList <int[]> factors = new ArrayList<int[]>();
        for (int prime: primes) {
            if (n % prime == 0) {
                int cnt = 0;
                while (n % prime == 0) {
                    n /= prime;
                    cnt++;
                }
                factors.add(new int[] {prime, cnt});
            }
        }
        if (n != 1) {
            factors.add(new int[] {n, 1});
        }
        return factors;
    }

    public static int add(int a, int b, int MOD) {
        return ((a + b) % MOD + MOD) % MOD;
    }

    public static int mul(int a, int b, int MOD) {
        return ((int)(((long) a * b) % MOD) + MOD) % MOD;
    }

}


/**
 * Created by shamir14 on 2/27/14.
 */
class InputReader {
    // this IO reading - writing is provided by Egor Kulikov
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new UnknownError();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new UnknownError();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }


    public boolean hasNext(){
        return peek()!=-1;
    }

    public int peek() {
        if (numChars == -1)
            return -1;
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                return -1;
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar];
    }

    public int nextInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new UnknownError();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public long nextLong() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new UnknownError();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String readString() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuffer res = new StringBuffer();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private String readLine0() {
        StringBuffer buf = new StringBuffer();
        int c = read();
        while (c != '\n' && c != -1) {
            if (c != '\r')
                buf.appendCodePoint(c);
            c = read();
        }
        return buf.toString();
    }

    public String readLine() {
        String s = readLine0();
        while (s.trim().length() == 0)
            s = readLine0();
        return s;
    }

    public String readLine(boolean ignoreEmptyLines) {
        if (ignoreEmptyLines)
            return readLine();
        else
            return readLine0();
    }

    public BigInteger readBigInteger() {
        try {
            return new BigInteger(readString());
        } catch (NumberFormatException e) {
            throw new UnknownError();
        }
    }

    public char readCharacter() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        return (char) c;
    }

    public double readDouble() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!isSpaceChar(c) && c != '.') {
            if (c == 'e' || c == 'E')
                return res * Math.pow(10, nextInt());
            if (c < '0' || c > '9')
                throw new UnknownError();
            res *= 10;
            res += c - '0';
            c = read();
        }
        if (c == '.') {
            c = read();
            double m = 1;
            while (!isSpaceChar(c)) {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new UnknownError();
                m /= 10;
                res += (c - '0') * m;
                c = read();
            }
        }
        return res * sgn;
    }

    public boolean isExhausted() {
        int value;
        while (isSpaceChar(value = peek()) && value != -1)
            read();
        return value == -1;
    }

    public String next() {
        return readString();
    }
}

class Pair <P extends Comparable <? super P>, Q extends Comparable <? super Q> >
        implements Comparable <Pair <P, Q> > {
    P a;
    Q b;
    public Pair (P a, Q b) {
        this.a = a;
        this.b = b;
    }

    public Pair() {
    }

    public void setX(P a) {
        this.a = a;
    }

    public void setY(Q b) {
        this.b = b;
    }

    public P getX() {
        return a;
    }

    public Q getY() {
        return b;
    }

    public String toString() {
        return "(" + a.toString() + ", " + b.toString() + ")";
    }

    @Override
    public int compareTo(Pair<P, Q> o) {
        int cmp = a.compareTo(o.a);
        if (cmp == 0) {
            return b.compareTo(o.b);
        }
        return cmp;
    }
}

class FenwickTree {
    private int[] tree;
    private int maxVal;

    public FenwickTree(int n) {
        maxVal = n;
        tree = new int[maxVal + 1];
    }

    /**
     *  update element val by adding the val to it
     *  O(LOG(N))
     */
    public void update(int idx, int val) {
        idx++;
        while (idx <= maxVal) {
            tree[idx] += val;
            idx += (idx & (-idx));
        }
    }

    /**
     *  return the sum of values of tree[] from idx to 0
     *  O(LOG(N))
     */
    public int read(int idx) {
        idx++;
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    public int getMaxVal() {
        return maxVal;
    }

    public int rangeSum(int left, int right) {
        if(left > right)
            return 0;
        int sumLeft = read(left - 1);
        int sumRight = read(right);
        return sumRight - sumLeft;
    }


}

class PairInt implements Comparable <PairInt>{
    public int X, Y;

    public PairInt(int X, int Y){
        this.X = X;
        this.Y = Y;
    }

    public PairInt add(PairInt b) {
        return new PairInt(X + b.X, Y + b.Y);
    }

    public PairInt sub(PairInt b) {
        return new PairInt(X - b.X, Y - b.Y);
    }

    @Override
    public int compareTo(PairInt o) {
        if(X != o.X)
            return X - o.X;
        return Y - o.Y;
    }
}


class IntArrays {

    public static void reverse(int[] cur){
        int[] temp = new int[cur.length];
        int cnt = 0;
        for(int i=cur.length-1; i>=0; i--){
            temp[cnt++] = cur[i];
        }
        for(int i=0;i<cnt; i++)
            cur[i] = temp[i];
    }

    public static void swap(int[] arr, int a, int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

//    public static void print(int[] arr, OutputWriter out){
//        boolean first = true;
//        for(int temp: arr){
//            if(first)
//                first = false;
//            else
//                out.print(" ");
//            out.print(temp);
//        }
//        out.printLine();
//    }

    private static Integer[] selfOrder(int n) {
        Integer[] self = new Integer[n];
        for (int i = 0; i < n; i++) {
            self[i] = i;
        }
        return self;
    }

    private static int[] convertBoxToPrimitive(Integer[] box) {
        int[] primitive = new int[box.length];
        for (int i = 0; i < box.length; i++) {
            primitive[i] = box[i];
        }
        return primitive;
    }

    public static int[] getOrder(final int[] arr) {
        Integer[] order = selfOrder(arr.length);
        Arrays.sort(order, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if(arr[o1] > arr[o2])
                    return 1;
                if(arr[o1] < arr[o2])
                    return -1;
                return 0;
            }
        });
        return convertBoxToPrimitive(order);
    }

    public static boolean next_permutation(int[] c){
        // 1. finds the largest k, that c[k] < c[k+1]
        int first = getFirst( c );
        if ( first == -1 ) return false; // no greater permutation
        // 2. findJad last index toSwap, that c[k] < c[toSwap]
        int toSwap = c.length - 1;
        while ( c[ first ] >= c[ toSwap ] )
            --toSwap;
        // 3. swap elements with indexes first and last
        swap( c, first++, toSwap );
        // 4. reverse sequence from k+1 to n (inclusive)
        toSwap = c.length - 1;
        while ( first < toSwap )
            swap( c, first++, toSwap-- );
        return true;
    }

    // finds the largest k, that c[k] < c[k+1]
    // if no such k exists (there is not greater permutation), return -1
    private static int getFirst( final int[] c ) {
        for ( int i = c.length - 2; i >= 0; --i )
            if ( c[ i ] <  c[ i + 1 ] )
                return i;
        return -1;
    }

    /**
     * return the minimum index i such that val[ order[ i ] ] >= need
     */
    public static int lowerBound(int[] order, int[] val, int need) {
        int s = 0;
        int e = order.length;
        while(e - s > 1) {
            int mid = (e + s) / 2;
            if(val[order[mid]] < need)
                s = mid;
            else
                e = mid;
        }
        if(val[order[s]] >= need)
            return s;
        return e;
    }

    public static int lowerBound(int[] val, int need) {
        int s = 0;
        int e = val.length;
        while(e - s > 1) {
            int mid = (e + s) / 2;
            if(val[mid] < need)
                s = mid;
            else
                e = mid;
        }
        if(val[s] >= need)
            return s;
        return e;
    }


}
