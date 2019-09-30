import java.io.*;
import java.util.*;
import java.math.*;
 
class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter pw = new PrintWriter(System.out);
    public static String line;
    public static StringTokenizer st;
    public static ArrayList<ArrayList<Integer>> adjList;
    public static int[] dx = {-1, 0, 1, 0, -1, 1, 1, -1, 0};
    public static int[] dy = {0, 1, 0, -1, 1, 1, -1, -1, 0};
    public static int INF = 0x3f3f3f3f;
    public static int MOD = 1000000007;
    public static long LINF = 0x3f3f3f3f3f3f3f3fL;

    public static void main(String[] args) throws Exception {
        int N = Integer.parseInt(br.readLine());
        char[][] grid = new char[N][N];

        for (int i = 0; i < N; i++) {
            line = br.readLine();
            for (int j = 0; j < N; j++) {
                grid[i][j] = line.charAt(j);
            }
        }

        int ans = 0;
        for (int A = 0; A < N; A++) {
            boolean f = true;
            for (int i = 0; i < N && f; i++) {
                for (int j = 0; j < N; j++){
                    if (grid[i][(j+A)%N] != grid[j][(i+A)%N]){
                        f = false;
                        break;
                    }
                }
            }
            // System.out.println();
            if (f) {
                ans += N;
            }
        }
        pw.println(ans);

        pw.close(); 
        br.close();
    }
}

class Point implements Comparable<Point>{
    public int x, y;
 
    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
 
    public String toString(){
        return x + " " + y;
    }

    public int compareTo(Point p){
        if (x != p.x) return x < p.x ? -1 : 1;
        if (y != p.y) return y < p.y ? -1 : 1;
        return 0;
    }
}