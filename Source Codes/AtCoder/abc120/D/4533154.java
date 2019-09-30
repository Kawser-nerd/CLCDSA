import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int  N = sc.nextInt();
        int  M = sc.nextInt();

        int[][] A = new int[M][2];
        for (int i = 0; i < M; i++) {
            A[i][0] = sc.nextInt()-1;
            A[i][1] = sc.nextInt()-1;
        }

        int[][] B = new int[N][2];
        for (int i = 0; i < N; i++) {
            B[i][0] = i;
            B[i][1] = 1;
        }

        long[] inconv = new long[M+1];
        inconv[M] = (long) N * (N-1)/2;


        for (int i = M-1; i >= 0 ; i--) {
            int v1 = A[i][0];
            int v2 = A[i][1];

            int l1 = findRoot(B,B[v1][0]);
            int l2 = findRoot(B,B[v2][0]);

            inconv[i] = inconv[i+1];
            if( l1 != l2){
                int s1 = B[l1][1];
                int s2 = B[l2][1];
                inconv[i] -= s1 * s2;

                if(s1<s2) {
                    int temp = l1;
                        l1 = l2;
                        l2 = temp;
                }
                B[l1][1] += B[l2][1];
                B[l2][0]=l1;
                B[l2][1] =0;
            }
        }

        for (int i = 1; i < M+1; i++) {
            System.out.println(inconv[i]);
        }

    }

    static private int findRoot(int[][] leaders, int n){
        if(leaders[n][0]==n) return n;
        return findRoot(leaders,leaders[n][0]);
    }


}