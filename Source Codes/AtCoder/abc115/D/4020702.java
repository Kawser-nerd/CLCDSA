import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long X = sc.nextLong();
        long[] An = new long[N+1];
        long[] Bn = new long[N+1];
        long A = 5;
        long B = 3;
        for(int i = 1;i <= N;i++){
            An[i] = A;
            A = A*2+3;
        }
        for(int i = 1;i <= N;i++){
            Bn[i] = B;
            B = B*2+1;
        }
        System.out.println(f(N, X, An, Bn));
    }
    public static long f(int n, long x, long[] an, long[] bn){
        if(n == 1){
            if(x >= 5)  return 3;
            else    return Math.max(0, x-(long)1);
        }else if(an[n]-(long)1 <= x){
            return bn[n];
        }else if(an[n-1]+(long)2 <= x){
            return bn[n-1]+(long)1+f(n-1, x-(long)2-an[n-1], an, bn);
        }else{
            return f(n-1, x-(long)1, an, bn);
        }
    }
}