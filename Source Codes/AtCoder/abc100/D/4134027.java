import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        int M = sc.nextInt();
        long[] X = new long[N];
        long[] Y = new long[N];
        long[] Z = new long[N];
        int[] sg = {1, -1};
        for(int i = 0;i < N;i++){
            X[i] = sc.nextLong();
            Y[i] = sc.nextLong();
            Z[i] = sc.nextLong();
        }
        long ans = 0;
        long[] S = new long[N];
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 2;j++){
                for(int k = 0;k < 2;k++){
                    long ans2 = 0;
                    for(int l = 0;l < N;l++){
                        S[l] = X[l]*sg[i]+Y[l]*sg[j]+Z[l]*sg[k];
                    }
                    Arrays.sort(S);
                    for(int l = N-1;l > N-M-1;l--)   ans2 += S[l]; 
                    ans = Math.max(ans, ans2);
                }   
            }
        }
        System.out.println(ans);
    }
}