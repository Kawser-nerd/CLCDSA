import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
    static long __startTime = System.currentTimeMillis();

    static class Point {
        int id;
        long x;
        long y;

        Point(int i, long _x, long _y) {
            id = i;
            x = _x;
            y = _y;
        }

        public String toString() {
            return "id=" + id + "/x=" + x + "/y=" + y;
        }
    }

    static final Comparator<Point> xComparator = (u, v) -> u.x == v.x ? Long.compare(u.y, v.y) : Long.compare(u.x, v.x);
    static final Comparator<Point> yComparator = (u, v) -> u.y == v.y ? Long.compare(u.x, v.x) : Long.compare(u.y, v.y);


    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        int a = in.nextInt()-1;
        int b = in.nextInt()-1;

        Point[] pt =  new Point[n];
        for (int i = 0; i < n ; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            pt[i] = new Point(i, x+y, x-y);
        }
//        pt[n] = new Point(n, (long)-1e12, (long)-1e12);
//        pt[n+1] = new Point(n, (long)1e12, (long)1e12);
//        n += 2;

        long D = Math.max(Math.abs(pt[a].x-pt[b].x), Math.abs(pt[a].y-pt[b].y));

        Point[] xpt = pt.clone();
        Arrays.sort(xpt, xComparator);
        int[] xord = new int[n];
        for (int i = 0; i < n ; i++) {
            xord[xpt[i].id] = i;
        }

        Point[] ypt = pt.clone();
        Arrays.sort(ypt, yComparator);
        int[] yord = new int[n];
        for (int i = 0; i < n ; i++) {
            yord[ypt[i].id] = i;
        }

//        debug("== x");
//        for (Point x : xpt) {
//            debug(x);
//        }
//        debug("== y");
//        for (Point y : ypt) {
//            debug(y);
//        }



        boolean[] visited = new boolean[n];
        visited[a] = true;
        Queue<Integer> que = new ArrayDeque<>();
        que.add(a);

        TreeSet<Integer> xy = new TreeSet<>();
        TreeSet<Integer> yx = new TreeSet<>();
        for (int i = -1 ; i <= n ; i++) {
            xy.add(i);
            yx.add(i);
        }

        while (que.size() >= 1) {
            int now = que.poll();
            for (long dx = -D ; dx <= D ; dx += D*2) {
                long tx = pt[now].x + dx;
                long tyfrom = pt[now].y - D;
                long tyto = pt[now].y + D;

                Point yfrom = new Point(-1, tx, tyfrom);
                Point yto = new Point(-1, tx, tyto);

                int f = Arrays.binarySearch(xpt, yfrom, xComparator);
                if (f < 0) {
                    f = -f-1;
                }
                int t = Arrays.binarySearch(xpt, yto, xComparator);
                if (t < 0) {
                    t = -t-2;
                }
                if (f <= t) {
                    while (true) {
                        int nex = xy.ceiling(f);
                        if (nex > t || nex == -1) break;
                        int nid = xpt[nex].id;
                        visited[nid] = true;
                        que.add(nid);
                        xy.remove(xord[nid]);
                        yx.remove(yord[nid]);
                    }
                }
            }
            for (long dy = -D ; dy <= D ; dy += D*2) {
                long ty = pt[now].y + dy;
                long txfrom = pt[now].x - D;
                long txto = pt[now].x + D;

                Point xfrom = new Point(-1, txfrom, ty);
                Point xto = new Point(-1, txto, ty);

                int f = Arrays.binarySearch(ypt, xfrom, yComparator);
                if (f < 0) {
                    f = -f-1;
                }
                int t = Arrays.binarySearch(ypt, xto, yComparator);
                if (t < 0) {
                    t = -t-2;
                }

                if (f <= t) {
                    while (true) {
                        int nex = yx.ceiling(f);
                        if (nex > t || nex == -1) break;
                        int nid = ypt[nex].id;
                        visited[nid] = true;
                        que.add(nid);
                        xy.remove(xord[nid]);
                        yx.remove(yord[nid]);
                    }
                }
            }
        }


        long ret = 0;
        for (int now = 0; now < n ; now++) {
            if (!visited[now]) {
                continue;
            }
            for (long dx = -D ; dx <= D ; dx += D*2) {
                long tx = pt[now].x + dx;
                long tyfrom = pt[now].y - D;
                long tyto = pt[now].y + D;

                Point yfrom = new Point(-1, tx, tyfrom);
                Point yto = new Point(-1, tx, tyto);

                int f = Arrays.binarySearch(xpt, yfrom, xComparator);
                if (f < 0) {
                    f = -f-1;
                }
                int t = Arrays.binarySearch(xpt, yto, xComparator);
                if (t < 0) {
                    t = -t-2;
                }
                if (f <= t) {
                    ret += t-f+1;
                }
            }
            for (long dy = -D ; dy <= D ; dy += D*2) {
                long ty = pt[now].y + dy;

                // make sure not-double-counting corner
                long txfrom = pt[now].x - D + 1;
                long txto = pt[now].x + D - 1;

                Point xfrom = new Point(-1, txfrom, ty);
                Point xto = new Point(-1, txto, ty);

                int f = Arrays.binarySearch(ypt, xfrom, yComparator);
                if (f < 0) {
                    f = -f-1;
                }
                int t = Arrays.binarySearch(ypt, xto, yComparator);
                if (t < 0) {
                    t = -t-2;
                }
                if (f <= t) {
                    ret += t-f+1;
                }
            }
        }

        out.println(ret/2);
        out.flush();
    }

    public static class IntegerSet {
        public int n;


        public IntegerSet(int n) {
            this.n = n;

        }
    }

    public static class LST {
        public long[][] set;
        public int n;
//		public int size;

        public LST(int n) {
            this.n = n;
            int d = 1;
            for(int m = n;m > 1;m>>>=6, d++);

            set = new long[d][];
            for(int i = 0, m = n>>>6;i < d;i++, m>>>=6){
                set[i] = new long[m+1];
            }
//			size = 0;
        }

        // [0,r)
        public LST setRange(int r)
        {
            for(int i = 0;i < set.length;i++, r=r+63>>>6){
                for(int j = 0;j < r>>>6;j++){
                    set[i][j] = -1L;
                }
                if((r&63) != 0)set[i][r>>>6] |= (1L<<r)-1;
            }
            return this;
        }

        // [0,r)
        public LST unsetRange(int r)
        {
            if(r >= 0){
                for(int i = 0;i < set.length;i++, r=r+63>>>6){
                    for(int j = 0;j < r+63>>>6;j++){
                        set[i][j] = 0;
                    }
                    if((r&63) != 0)set[i][r>>>6] &= ~((1L<<r)-1);
                }
            }
            return this;
        }

        public LST set(int pos)
        {
            if(pos >= 0 && pos < n){
//				if(!get(pos))size++;
                for(int i = 0;i < set.length;i++, pos>>>=6){
                    set[i][pos>>>6] |= 1L<<pos;
                }
            }
            return this;
        }

        public LST unset(int pos)
        {
            if(pos >= 0 && pos < n){
//				if(get(pos))size--;
                for(int i = 0;i < set.length && (i == 0 || set[i-1][pos] == 0L);i++, pos>>>=6){
                    set[i][pos>>>6] &= ~(1L<<pos);
                }
            }
            return this;
        }

        public boolean get(int pos)
        {
            return pos >= 0 && pos < n && set[0][pos>>>6]<<~pos<0;
        }

        public int prev(int pos)
        {
            for(int i = 0;i < set.length && pos >= 0;i++, pos>>>=6, pos--){
                int pre = prev(set[i][pos>>>6], pos&63);
                if(pre != -1){
                    pos = pos>>>6<<6|pre;
                    while(i > 0)pos = pos<<6|63-Long.numberOfLeadingZeros(set[--i][pos]);
                    return pos;
                }
            }
            return -1;
        }

        public int next(int pos)
        {
            for(int i = 0;i < set.length && pos>>>6 < set[i].length;i++, pos>>>=6, pos++){
                int nex = next(set[i][pos>>>6], pos&63);
                if(nex != -1){
                    pos = pos>>>6<<6|nex;
                    while(i > 0)pos = pos<<6|Long.numberOfTrailingZeros(set[--i][pos]);
                    return pos;
                }
            }
            return -1;
        }

        private static int prev(long set, int n)
        {
            long h = Long.highestOneBit(set<<~n);
            if(h == 0L)return -1;
            return Long.numberOfTrailingZeros(h)-(63-n);
        }

        private static int next(long set, int n)
        {
            long h = Long.lowestOneBit(set>>>n);
            if(h == 0L)return -1;
            return Long.numberOfTrailingZeros(h)+n;
        }

        @Override
        public String toString()
        {
            List<Integer> list = new ArrayList<Integer>();
            for(int pos = next(0);pos != -1;pos = next(pos+1)){
                list.add(pos);
            }
            return list.toString();
        }
    }


    private static void printTime(String label) {
        debug(label, System.currentTimeMillis() - __startTime);
    }

    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public char nextChar() {
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}