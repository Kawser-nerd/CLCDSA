import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        int M = sc.nextInt();
        int[] B = new int[M];
        for (int i = 0; i < M; i++) {
            B[i] = sc.nextInt();
        }

        int n = 0;

        for (int m = 0; m < M; m++) {
            while (true) {
                if(n >= N){
                    out.println("no");
                    return;
                }

                if (A[n] <= B[m] && B[m] <= A[n] + T) {
                    n++;
                    break;
                }
                n++;
            }
        }

        out.println("yes");
    }
}