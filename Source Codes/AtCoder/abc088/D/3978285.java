import java.util.*;
public class Main {
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};
    static int INF = 1000000000;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        List<String> str = new ArrayList<>();
        for (int i = 0; i < h; i++) {
            str.add(sc.next());
        }
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (str.get(i).charAt(j) == '#') {
                    cnt++;
                }
            }
        }
        Point s = new Point(0, 0);
        int[][] dist = bfs(s, str);
        if (dist[w - 1][h - 1] == INF) {
            System.out.println(-1);
            return;
        }
        int ans = h * w - (dist[w - 1][h - 1] + 1) - cnt;
        System.out.println(ans);
    }
    public static int[][] bfs(Point s, List<String> str) {
        int[][] dist = new int[51][51];
        for (int[] d : dist) {
            Arrays.fill(d, INF);
        }
        Queue<Point> que = new LinkedList<>();
        que.offer(s);
        dist[s.x][s.y] = 0;
        while (!que.isEmpty()) {
            Point p = que.poll();
            // System.out.println("p = " + p);
            for (int i = 0; i < 4; i++) {
                int ny = p.y + dy[i];
                int nx = p.x + dx[i];
                if (nx < 0 || ny < 0 || nx >= str.get(0).length() || ny >= str.size()) {
                    continue;
                }
                if (str.get(ny).charAt(nx) == '.' && dist[p.x][p.y] + 1 < dist[nx][ny]) {
                    dist[nx][ny] = dist[p.x][p.y] + 1;
                    //       System.out.printf("nx = %d ,ny = %d %n", nx, ny);
                    que.offer(new Point(nx, ny));
                }
            }
        }
        return dist;
    }
}
class Point {
    int x;
    int y;
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
    public String toString() {
        return String.format("(x = %d,y = %d)", this.x, this.y);
    }
}