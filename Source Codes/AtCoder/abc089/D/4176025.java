import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        final int H = sc.nextInt();
        final int W = sc.nextInt();
        int D = sc.nextInt();
        int[][] L = new int[2][H*W+1];
        for(int i = 1;i < H+1;i++){
            for(int j = 1;j < W+1;j++){
                int aij = sc.nextInt();
                L[0][aij] = i;
                L[1][aij] = j;
            }
        }
        int[] A = new int[H*W+1];
            for(int j = D+1;j < H*W+1;j++){
                A[j] = A[j-D]+Math.abs(L[0][j]-L[0][j-D])+Math.abs(L[1][j]-L[1][j-D]);
            }
        int Q = sc.nextInt();
        for(int i = 0;i < Q;i++){
            int li = sc.nextInt();
            int ri = sc.nextInt();
            System.out.println(A[ri]-A[li]);
        }
    }
}