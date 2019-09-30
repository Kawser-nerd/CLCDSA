import java.util.*;
import java.io.*;

public class arewelostyet {
    private static Reader in;
    private static PrintWriter out;
    public static final String NAME = "C-small-attempt3";
    
    public static int [] eadj, eprev, elast, emin, emax, efrom;
    public static int eidx;
    
    public static void addEdge (int a, int b, int min, int max) {
        efrom [eidx] = a; eadj [eidx] = b; emin [eidx] = min; emax [eidx] = max; eprev [eidx] = elast [a]; elast [a] = eidx++;
    }
    private static int N, M, P;
    
    private static int [] parm, pem, pwm;

    private static void main2() throws IOException {
        N = in.nextInt(); M = in.nextInt(); P = in.nextInt();
        eadj = new int [M + 1];
        eprev = new int [M + 1];
        elast = new int [N];
        efrom = new int [M + 1];
        emin = new int [M + 1];
        emax = new int [M + 1];
        Arrays.fill (elast, -1);
        eidx = 1;

        for (int i = 0; i < M; i++)
            addEdge (in.nextInt() - 1, in.nextInt() - 1, in.nextInt(), in.nextInt());
        
        used = new boolean [M + 1];
        shortest0();
        
        int found = -1;
        for (int i = 0; i < P; i++) {
            int edge = in.nextInt();
            if (found == -1 && !used (edge))
                found = edge;
        }
        
        out.println (found == -1 ? "Looks Good To Me" : found);
    }
    
    static class Pair implements Comparable <Pair> {
        public int a, b, c, d;
        public Pair (int a, int b, int c, int d) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
        }
        
        public int compareTo (Pair other) {
            return b - other.b;
        }
    }
    
    private static boolean [] used;
    private static void shortest0() {
        PriorityQueue <Pair> pq = new PriorityQueue <Pair> ();
        pq.add (new Pair (0, 0, 0, -1));
        boolean [] vis = new boolean [N];
        int [] par = new int [N];
        int [] edge = new int [N];
        int [] weight = new int [N];
        while (pq.size() > 0) {
            Pair c = pq.poll();
            if (vis [c.a]) continue;
            vis [c.a] = true;
            par [c.a] = c.d;
            edge [c.a] = c.c;
            weight [c.a] = c.b;
            
            for (int e = elast [c.a]; e != -1; e = eprev [e]) {
                if (vis [eadj [e]]) continue;
                int cost = emin [e];
                pq.add (new Pair (eadj [e], cost + c.b, e, c.a));
            }
        }
        parm = par;
        pem = edge;
        pwm = weight;
    }

    static class Pair2 implements Comparable <Pair2> {
        public int node, weight;
        public boolean vis;
        
        public Pair2 (int node, int weight, boolean vis) {
            this.node = node;
            this.weight = weight;
            this.vis = vis;
        }
        
        public int compareTo (Pair2 other) {
            if (weight == other.weight) {
                if (vis && !other.vis) return -1;
                if (other.vis && !vis) return 1;
                return 0;
            }
            return weight - other.weight;
        }
    }
    
    private static boolean used (int edge) {
        int node = eadj [edge];
        PriorityQueue <Pair2> pq = new PriorityQueue <Pair2> ();
        pq.add (new Pair2 (0, 0, false));
        pq.add (new Pair2 (eadj [edge], pwm [efrom [edge]] + emin [edge], true));
        int [] weight = new int [N];
        Arrays.fill (weight, 1 << 29);
        weight [0] = 0;
        weight [eadj [edge]] = pwm [efrom [edge]] + emin [edge];
        boolean [] vis = new boolean [N];
        
        boolean [] fix = new boolean [M + 1];
        int k = efrom [edge];
        while (k != -1) {
            fix [pem [k]] = true;
            k = parm [k];
        }
        
        while (pq.size() > 0) {
            Pair2 c = pq.poll();
            if (c.weight != weight [c.node]) continue;
            vis [c.node] = c.vis;
            if (c.node == 1) break;
            
            for (int e = elast [c.node]; e != -1; e = eprev [e]) {
                int cost = fix [e] || c.vis ? emin [e] : emax [e];
                if (c.weight + cost <= weight [eadj [e]]) {
                    weight [eadj [e]] = c.weight + cost;
                    pq.add (new Pair2 (eadj [e], c.weight + cost, c.vis));
                }
            }
        }
        return vis [1];
    }
    
    public static void main(String[] args) throws IOException {
        in = new Reader(NAME + ".in");
        out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));

        int numCases = in.nextInt();
        for (int test = 1; test <= numCases; test++) {
            out.print("Case #" + test + ": ");
            main2();
        }

        out.close();
        System.exit(0);
    }

    /** Faster input **/
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[1024];
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            else
                return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            else
                return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9')
                    ret += (c - '0') / (div *= 10);
            }
            if (neg)
                return -ret;
            else
                return ret;
        }

        public char nextChar() throws IOException {
            char ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            return (char) c;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }
}
