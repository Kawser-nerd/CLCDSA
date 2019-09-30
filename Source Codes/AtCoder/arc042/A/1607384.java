import java.util.*;

public class Main {
    void solve() {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt();
        boolean[] b = new boolean[n + 1];
        Deque<Integer> q = new ArrayDeque<>(m);
        for(int i = 0; i < m; i++){
            q.push(in.nextInt());
        }
        while(!q.isEmpty()){
            int i = q.poll();
            if(!b[i]){
                System.out.println(i);
                b[i] = true;
            }
        }
        for(int i = 1; i <= n; i++){
            if(!b[i]){
                System.out.println(i);
            }
        }
    }
    public static void main(String[] args){
        new Main().solve();
    }
}