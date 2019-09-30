import java.util.*;
import static java.lang.System.*;

//https://atcoder.jp/contests/abc075/tasks/abc075_c
//O(n^2)?????????n=250
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        boolean[][] edges = new boolean[N][N];
        for (int m = 0; m < M; m++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            edges[a-1][b-1] = true;
            edges[b-1][a-1] = true;
        }

        solver(N, edges);
    }

    public static void solver(int N, boolean[][] edges){
        //??????????????
        Set<Integer> left_nodes = new HashSet<Integer>();
        for(int n = 0; n < N; n++) {
            left_nodes.add(n);
        }

        //1????????????????????????????
        //????????????????????(??????????????????)
        int ans = 0;
        int before_ans = ans + 1;
        while (ans != before_ans) {
            before_ans = ans;
            HashMap<Integer, Integer>  bridgeable_nodes = new HashMap<Integer, Integer>(); //?????????????

            for(Integer from: left_nodes) {
                ArrayList<Integer> bridge_nodes = new ArrayList<Integer>();  //n????????
                for(int to=0; to<N; to++){
                    if(edges[from][to] == true){ bridge_nodes.add(to); }
                }

                //1????????????????
                if (bridge_nodes.size() == 1){
                    bridgeable_nodes.put(from, bridge_nodes.get(0));
                }
            }

            //????????????????????
            for(Integer from: bridgeable_nodes.keySet()) {
                int to = bridgeable_nodes.get(from);
                left_nodes.remove(from);

                //????????????1????????????????1<->2???????1?2???????????
                if(edges[from][to] == false){
                    continue;
                }

                edges[from][to] = false; //?????????????????????????????????
                edges[to][from] = false;

                ans++;
            }
        }

        out.println(ans);
    }
}