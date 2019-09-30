import java.util.*;
public class Main{
    static int N, A, B, C;
    static int[] l;
    private final static int INF = (int)Math.pow(10, 9);

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        A = sc.nextInt();
        B = sc.nextInt();
        C = sc.nextInt();
        l = new int[N];
        for(int i = 0; i < N; i++){
            l[i] = sc.nextInt();
        }        
        System.out.println(dfs(0, 0, 0, 0)); 
    }

    public static int dfs(int cur, int a, int b, int c){
        if(cur == N){
            if(min(a, b, c) > 0){
                return Math.abs(a-A) + Math.abs(b-B) + Math.abs(c-C) - 30;
            } else{
                return INF;
            }             
        }
        int ret0 = dfs(cur + 1, a, b, c),
        ret1 = dfs(cur + 1, a + l[cur], b, c) + 10,
        ret2 = dfs(cur + 1, a, b + l[cur], c) + 10,
        ret3 = dfs(cur + 1, a, b, c + l[cur]) + 10;
        return min(ret0, ret1, ret2, ret3);
    }

    public static int min(int... value){
        int min = value[0];
        for(int i = 1; i < value.length; i++){
            if(value[i] < min){
                min = value[i];
            }
        }
        return min;
    }
}