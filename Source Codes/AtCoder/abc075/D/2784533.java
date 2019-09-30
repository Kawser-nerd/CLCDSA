import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static int modP = 1000000007;
    static long inf  = Long.MAX_VALUE;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        List<P> points = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            P p = new P(in.nextLong(), in.nextLong());
            points.add(p);
        }

        List<Long> xList = points.stream().map(p -> p.x).collect(Collectors.toList());
        List<Long> yList = points.stream().map(p -> p.y).collect(Collectors.toList());

        long area = inf;
        for(int x1 = 0; x1 < n; x1++) {
            for(int x2 = x1+1; x2 < n; x2++) {
                for(int y1 = 0; y1 < n; y1++) {
                    for(int y2 = y1+1; y2 < n; y2++) {
                        if(xList.get(x1) == xList.get(x2) || yList.get(y1) == yList.get(y2)) continue;

                        P p1 = new P(xList.get(x1), yList.get(y1));
                        P p2 = new P(xList.get(x2), yList.get(y2));

                        int cnt = 0;
                        for(P p : points) {
                            if(check(p1, p2, p)){
                                cnt++;
                            }
                        }

                        if(cnt >= k){
                            area = Math.min(area, calcArea(p1, p2));
                        }
                    }
                }
            }
        }

        print(area);
    }

    static long calcArea(P a, P b) {
        return Math.abs(a.x-b.x) * Math.abs(a.y-b.y);
    }

    static boolean check(P a, P b, P c) {
        long leftMost  = Math.max(a.x, b.x);
        long rightMost = Math.min(a.x, b.x);
        long upMost    = Math.max(a.y, b.y);
        long downMost  = Math.min(a.y, b.y);
        if(c.x < rightMost || leftMost < c.x) return false;
        if(c.y < downMost  || upMost   < c.y) return false;
        return true;
    }

    static void print(String s) {
        System.out.println(s);
    }

    static void print(int i) {
        System.out.println(i);
    }

    static void print(long i) {
        System.out.println(i);
    }
}

class P {
    long x, y;
    P(long x, long y) {
        this.x = x;
        this.y = y;
    }
}

class E {
    int from, to;
    long w;
    E(int from, int to, long w) {
        this.from = from;
        this.to = to;
        this.w = w;
    }
}