import java.util.*;
import static java.lang.System.*;

// https://atcoder.jp/contests/abc006/tasks/abc006_3
// ???????????????O(n^2)->O(n)
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        //solver(N, M);
        solver1(N, M);
    }

    public static void solver1(int N, int M){
        // O(n) ?????
        // ??: n1, ??: n2, ????: n3
        for(int n1 = 0; n1 <= N; n1++){
            int n2 = -M + 4*N - 2*n1;
            int n3 = M - 3*N + n1;
            if (n3 >= 0 && n2 >=0){
                out.println(n1+" "+n2+" "+n3);
                exit(0);
            }
        }
        out.println("-1 -1 -1");
    }

    public static void solver(int N, int M){
        // O(n^2)
        // N?????????????????
        // ??: n1, ??: n2, ????: n3
        for(int n1 = 0; n1 <= N; n1++){
            for(int n2 = 0; n2 <= N-n1; n2++){
                int n3 = N-n1-n2;
                if (n1*2 + n2*3 + n3*4 == M) {
                    out.println(n1+" "+n2+" "+n3);
                    exit(0);
                }
            }
        }
        out.println("-1 -1 -1");
    }
}