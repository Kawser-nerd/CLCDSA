import java.util.*;

public class Main {
    static int n;
    static int k;
    static ArrayList<Integer>[] edge;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        edge = new ArrayList[n];
        int[][] ab = new int[n-1][2];
        for(int i=0; i<n; i++) edge[i] = new ArrayList<Integer>();
        for(int i=0; i<n-1; i++){
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            edge[a].add(b);
            edge[b].add(a);
            ab[i][0] = a;
            ab[i][1] = b;
        }
        sc.close();

        if(k == 1){
            System.out.println(n-2);
            return;
        }

        int ans = Integer.MAX_VALUE;
        if(k%2 == 0){
            for(int i=0; i<n; i++){
                ans = Math.min(ans, countDelNum(i, i));
            }
        }else{
            for(int i=0; i<n-1; i++){
                ans = Math.min(ans, countDelNum(ab[i][0], ab[i][1])
                                +countDelNum(ab[i][1], ab[i][0])-n);
            }
        }
        // for(int i=0; i<n; i++){
        //     int tmp = countDelNum(i);
        //     if(tmp < ans){
        //         ans = tmp;
        //     }
        // }
        System.out.println(ans);
    }

    public static int countDelNum(int root, int root2){
        int count = n;
        ArrayDeque<Integer[]> que = new ArrayDeque<Integer[]>();
        boolean[] use = new boolean[n];
        que.add(new Integer[]{root, 0});
        use[root] = true;
        use[root2] = true;
        while(que.size()>0){
            Integer[] cur = que.poll();
            if(cur[1] > k/2) break;
            for(int i=0; i<edge[cur[0]].size(); i++){
                Integer next = edge[cur[0]].get(i);
                if(!use[next]){
                    que.add(new Integer[]{next, cur[1]+1});
                    use[next] = true;
                }
            }
            count--;
        }
        return count;
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.