import java.util.*;

class Main {
        private static int N, K;
        private static List<Integer>[] vec;
        private static int ans;
        public static void main(String args[]) {
                new Thread(null, () -> {
                        Scanner sc = new Scanner(System.in);
                        N = sc.nextInt();
                        K = sc.nextInt();
                        ans = 0;
                        vec = new ArrayList[N];
                        for (int i = 0; i < N; i++) {
                                vec[i] = new ArrayList<>(0);
                        }
                        for (int i = 0; i < N; i++) {
                                int a = sc.nextInt() - 1;
                                if (i != 0) {
                                        vec[a].add(i);
                                } else {
                                        if (a != 0) {
                                                ans++;
                                        }
                                }
                        }
                        dfs(0, 0);


                        System.out.println(ans);
                }, "", 1<<24).start();
        }
        private static int dfs(int v, int pre){
                int hight = 0;
                for (int j = 0; j < vec[v].size(); j++) {
                        hight = Math.max(hight, dfs(vec[v].get(j), v));
                }
                if (pre != 0 && hight == K - 1) {
                        hight = 0;
                        ans++;
                } else {
                        hight++;
                }
                return hight;
        }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.