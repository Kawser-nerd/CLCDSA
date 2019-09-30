import java.util.*;
import java.io.*;

/*
   AtCoder contest code
   coder : yoichidon
 */

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[] A = new long[N+1];
        for(int n=0; n<N; n++) A[n]=sc.nextLong();

        long ans = 0;
        for(int n=0; n<N; n++){
            ans += (A[n]/2);
            if(A[n]%2!=0 && A[n+1]>0){
                A[n+1]--;
                ans++;
            }
        }
        System.out.println(ans);
    }
}