import java.io.*;
import java.util.*;

public class G_1 {

    public static void main(String[] args) throws Exception {
        G_1 instance = new G_1();
        instance.func();
    }

    PrintWriter bw;
    int[][] graph;
    boolean[] vis;
    int N;

    boolean visit(int key) {
        // System.out.println(key);
        vis[key] = true;
        for (int i = 0; i < N; i++) {
            if (graph[key][i] == 1) {
                if (vis[i]) {
                    return true;
                } else {
                    if (visit(i)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public void func() throws Exception {
        bw = new PrintWriter(new FileWriter("1.txt"));
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        for (int i = 0; i < T; i++) {
            N = scan.nextInt();
            graph = new int[N][N];
            for (int j = 0; j < N; ++j) {
                int M = scan.nextInt();
                for (int k = 0; k < M; ++k) {
                    int key = scan.nextInt();

                    // System.out.println(j + "  " + (key - 1));
                    graph[j][key - 1] = 1;
                }
                // System.out.println("--------------");
            }

            vis = new boolean[N];
            boolean can = false;
            for (int j = 0; j < N; ++j) {
                Arrays.fill(vis, false);
                if (visit(j)) {
                    can = true;
                    break;
                }
                // System.out.println("--------------" + can);
            }
            print(String.format("Case #%d: %s", (i + 1), (can ? "Yes" : "No")));
            print("\n");
        }
        bw.flush();
        bw.close();
    }

    void print(String s) {
        System.out.print(s);
        bw.write(s);
    }
}
