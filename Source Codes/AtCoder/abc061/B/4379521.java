import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] a = new int[M];
        int[] b = new int[M];
        int[] ans = new int[N];
        
        for(int i = 0; i < M; i++){
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }
        
        for(int i = 1; i <= N; i++){
            for(int j = 0; j < M;  j++){
                if(i == a[j]) ans[i - 1]++; 
                if(i == b[j]) ans[i - 1]++;
            }
        }
        for(int i = 0; i < N; i++) System.out.println(ans[i]);
    }
}