import java.util.Scanner;
import java.util.Arrays;

public class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        try{
            //??
            int N = scan.nextInt();
            int M = scan.nextInt();
            int[] X_ = new int[M];
            for(int i = 0; i < M; i++){
                X_[i] = scan.nextInt();
            }

            //???????
            Arrays.sort(X_);
            int dist = getDistance(X_, M, N);

            System.out.println(dist);

        }finally{
            scan.close();
        }
    }

    static int getDistance(int[] A, int m, int n){
        //?????????
        int[] B = new int[m-1];
        for(int i = 0; i < m-1; i++){
            B[i] = A[i+1]-A[i];
        }
        Arrays.sort(B);

        int sum = 0;
        for(int i = 0; i < m-n; i++){
            sum += B[i];
        }
        return sum;
    }
}