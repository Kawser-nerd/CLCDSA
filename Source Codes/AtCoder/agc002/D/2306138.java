import java.util.*;
public class Main {
    static Scanner in = new Scanner(System.in);
    static class Edge {
        int u, v;
        Edge() {
            u = in.nextInt() - 1; v = in.nextInt() - 1;
        }
    }
    static class QueryItem {
        int x, y, z;
        QueryItem(int x_, int y_, int z_) {
            x = x_; y = y_; z = z_;
        }
    }
    static class Dsu {
        int f[], size[], cnt;
        Edge e[];
        Dsu(int n, Edge edge[]) {
            f = new int[n];
            size = new int[n];
            for(int i = 0; i < f.length; i++) f[i] = i;
            Arrays.fill(size, 1);
            cnt = 0;
            e = edge;
        }
        int find(int x) {
            if(f[x] == x) return f[x];
            return f[x] = find(f[x]);
        }
        void merge(int x, int y) {
            x = find(x); y = find(y);
            if(x != y) {
                f[x] = y;
                size[y] += size[x];
            }
        }
        void update(int m) {
            if(cnt > m) {
                for(int i = 0; i < f.length; i++) f[i] = i;
                Arrays.fill(size, 1);
                cnt = 0;
            }
            while(cnt < m) {
                merge(e[cnt].u, e[cnt].v);
                cnt++;
            }
        }
    }
    static class QueueItem {
        int l, r, qIndex[];
        QueueItem(int qIndex_[], int l_, int r_) {
            qIndex = qIndex_; l = l_; r = r_;
        }
    }
    static class Solver {
        int n, m, q, ans[];
        Edge edge[];
        Dsu dsu;
        QueryItem query[];
        void input() {
            n = in.nextInt(); m = in.nextInt();
            edge = new Edge[m];
            dsu = new Dsu(n, edge);
            for(int i = 0; i < m; i++) edge[i] = new Edge();
            q = in.nextInt();
            query = new QueryItem[q];
            ans = new int[q];
            for(int i = 0; i < q; i++) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                int z = in.nextInt();
                query[i] = new QueryItem(x, y, z);
            }
        }
        void solve() {
            Queue<QueueItem> que = new LinkedList<>();
            int qIndex[] = new int[q];
            for(int i = 0; i < q; i++) qIndex[i] = i;
            que.offer(new QueueItem(qIndex, 1, m));
            while(!que.isEmpty()) {
                QueueItem cur = que.poll();
                if(cur.r == cur.l) {
                    for(int i = 0; i < cur.qIndex.length; i++) ans[cur.qIndex[i]] = cur.r;
                }
                else {
                    int mid = (cur.l + cur.r) / 2;
                    dsu.update(mid);
                    int cntL = 0;
                    boolean inL[] = new boolean[cur.qIndex.length];
                    for(int i = 0; i < cur.qIndex.length; i++) {
                        int x = query[cur.qIndex[i]].x;
                        int y = query[cur.qIndex[i]].y;
                        int z = query[cur.qIndex[i]].z;
                        int res = dsu.size[dsu.find(x)] + dsu.size[dsu.find(y)];
                        if(dsu.find(x) == dsu.find(y)) res /= 2;
                        if(res >= z) {
                            cntL++;
                            inL[i] = true;
                        }
                    }
                    QueueItem nxtL = new QueueItem(new int[cntL], cur.l, mid);
                    QueueItem nxtR = new QueueItem(new int[cur.qIndex.length - cntL], mid + 1, cur.r);
                    int curL = 0, curR = 0;
                    for(int i = 0; i < cur.qIndex.length; i++) {
                        if(inL[i]) nxtL.qIndex[curL++] = cur.qIndex[i];
                        else nxtR.qIndex[curR++] = cur.qIndex[i];
                    }
                    if(curL > 0) que.offer(nxtL);
                    if(curR > 0) que.offer(nxtR);
                }
            }
            for(int i = 0; i < q; i++) System.out.println(ans[i]);
        }
    }
    static public void main(String args[]) {
        Solver solver = new Solver();
        solver.input();
        solver.solve();
    }
}