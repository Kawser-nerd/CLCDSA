import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    /**
     * ??K
     */
    private static int K;

    /**
     * ??????????????????????????
     */
    private static List<List<Integer>> vec = new ArrayList<>();

    /**
     * ?????????????????????
     */
    private static int ans = 0;

    public static void main(String args[]) {
        //???????2^24??????
        new Thread(null, () -> {
            //try-with-resources?(????????????try???????????????)
            try (Scanner sc = new Scanner(System.in)) {
                int n = sc.nextInt();
                K = sc.nextInt();
                for (int i = 0; i < n; i++) {
                    vec.add(new ArrayList<>());
                }
                for (int i = 0; i < n; i++) {
                    int a = sc.nextInt() - 1;
                    if (i != 0) {
                        vec.get(a).add(i);
                    } else if (a != 0) {
                        ans++;
                    }
                }
            }

            dfs(0, 0);
            System.out.println(ans);
        }, "", 1 << 24).start();
    }

    /**
     * ?????????
     *
     * @param v   ?????
     * @param pre 1????
     * @return ????
     */
    private static int dfs(int v, int pre) {
        int height = 0;

        //??for?(???????????1???????)
        for (int j : vec.get(v)) {
            height = Math.max(height, dfs(j, v));
        }

        if (pre != 0 && height == K - 1) {
            height = 0;
            ans++;
        } else {
            height++;
        }

        return height;
    }
}