import java.util.Scanner;
import java.util.stream.*;
class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        long[] A = new long[N];
        long[] B = new long[N];
        for(int i=0;i<N;++i){
            A[i] = scan.nextLong();
            B[i] = scan.nextLong();
        }
        long ans = 0;
        for(int i=N-1;i>=0;--i){
            ans += (B[i] - (A[i]+ans)%B[i])%B[i];
        }
        System.out.println(ans);
 
    }
}