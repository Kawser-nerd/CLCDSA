import java.util.*;

public class Main {
    static int n, k;
    static int[] a;
    static int modP = 1000000007;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        k = in.nextInt();

        Set<String> set = new HashSet<>();
        Queue<String> pq = new PriorityQueue<>();
        int len = s.length();
        for(int i = 0; i < len; i++) {
            int lim = i+k+1 < len+1 ? i+k+1 : len+1;
            for(int j = i+1; j < lim; j++) {
                String sub = s.substring(i, j);
                if(!set.contains(sub)) {
                    pq.add(sub);
                    set.add(sub);
                }
            }
        }

        for(int i = 0; i < k-1; i++) {
            pq.poll();
        }

        print(pq.peek());
    }

    static void print(String s) {
        System.out.println(s);
    }
    static void print(int i) {
        System.out.println(i);
    }
}

class P {
    int x, y;
    P(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class E {
    int l, r, d;
    E(int l, int r, int d) {
        this.l = l;
        this.r = r;
        this.d = d;
    }
}