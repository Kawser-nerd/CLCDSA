import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    int n;
    int[] as;
    int[] ans;
    PriorityQueue<Val> queue;
    SegmentTree oddTree;
    SegmentTree evenTree;

    public static void main(String[] args) {
        Main m = new Main();
        m.read();
        m.solve();
    }

    private void read() {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }
        ans = new int[n];
        queue = new PriorityQueue<>((v1, v2) -> Integer.compare(as[v1.st], as[v2.st]));
        evenTree = new SegmentTree(n);
        oddTree = new SegmentTree(n);
        evenTree.init(0);
        oddTree.init(1);
    }

    private void solve() {
        part(0, n);
        int count = 0;

        while (!queue.isEmpty()) {
            Val v = queue.poll();
            ans[count++] = as[v.st];
            ans[count++] = as[v.ed];
            if (v.st - v.rangeST > 0)
                part(v.rangeST, v.st);
            if (v.ed - v.st - 1 > 0)
                part(v.st+1, v.ed);
            if (v.rangeED - v.ed - 1 > 0)
                part(v.ed+1, v.rangeED);
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n-1; i++) {
            sb.append(ans[i]);
            sb.append(" ");
        }
        sb.append(ans[n-1]);
        System.out.println(sb.toString());
    }

    private void part(int start, int end) {
        int min1 = getMin(start, end);
        int min2 = getMin(min1+1, end);
        if (min1 == -1 || min2 == -1)
            return;
        queue.add(new Val(min1, min2, start, end));
    }

    private int getMin(int start, int end) {
        if (start >= end)
            return -1;
        Tuple ret;
        if (start % 2 == 0) {
            ret = evenTree.query(start, end);
        }
        else {
            ret = oddTree.query(start, end);
        }
        return ret.y;
    }


    private class Val {
        int st;
        int ed;
        int rangeST;
        int rangeED;
        Val (int st, int ed, int rg_st, int rg_ed) {
            this.st = st;
            this.ed = ed;
            rangeST = rg_st;
            rangeED = rg_ed;
        }
    }

    private class SegmentTree {
        Tuple[] ts;
        int t;
        SegmentTree(int n) {
            t = 1;
            while (t < n) t <<= 1;
            ts = new Tuple[2*t];
            Arrays.fill(ts, new Tuple(Integer.MAX_VALUE, -1));
        }

        void init(int st) {
            for (int i = st; i < n; i += 2) {
                update(i, as[i]);
            }
        }

        void update(int idx, int x) {
            idx += t - 1;
            ts[idx] = new Tuple(x, idx - t + 1);
            while (idx > 0) {
                idx = (idx - 1) / 2;
                ts[idx] = ts[2 * idx + 1].min(ts[2 * idx + 2]);
            }
        }

        Tuple query(int a, int b) {return query(a, b, 0, 0, t);}
        private Tuple query(int a, int b, int k, int l, int r) {
            if (r <= a || b <= l) return new Tuple(Integer.MAX_VALUE, -1);
            if (a <= l && r <= b) return ts[k];
            int mid = (l + r) / 2;
            return query(a, b, k * 2 + 1, l, mid).min(
                            query(a, b, k * 2 + 2, mid, r));
        }

    }

    private class Tuple {
        int x, y;
        Tuple(int a, int b){
            x = a;
            y = b;
        }

        Tuple min(Tuple trg) {
            if (trg.x < this.x)
                return trg;
            return this;
        }
    }
}