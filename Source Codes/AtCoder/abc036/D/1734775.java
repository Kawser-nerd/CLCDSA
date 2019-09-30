import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

    int N;
    List<Integer>[] rinsetsu;
    int mod = (int) Math.pow(10, 9) + 7;

    public static void main(String[] args) {
        new Main().compute();
    }

    void compute() {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        rinsetsu = new List[N];
        for (int i = 0; i < N; i++) {
            rinsetsu[i] = new ArrayList<>();
        }
        for (int i = 0; i < N - 1; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            rinsetsu[a].add(b);
            rinsetsu[b].add(a);
        }

        System.out.println(dfs(0, -1)[0]);
    }

    int[] dfs(int cur, int parent) {
        int whole = 1;
        int black = 1;
        for (int i = 0; i < rinsetsu[cur].size(); i++) {
            if (rinsetsu[cur].get(i) != parent) {
                int[] child = dfs(rinsetsu[cur].get(i), cur);
                whole = (int) ((long) whole * child[0] % mod);
                black = (int) ((long) black * child[1] % mod);
            }
        }
        int[] ret = new int[2];
        ret[0] = (int) (((long) whole + black) % mod);
        ret[1] = whole;
        return ret;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.