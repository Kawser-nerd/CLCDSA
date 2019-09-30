import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] a = new int[N];
        int[] b = new int[N];
        int[] c = new int[M];
        int[] d = new int[M];
        int[] ans = new int[N];
        
        for(int i = 0; i < N; i++){
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            ans[i] = Integer.MAX_VALUE - 1;
        }
        for(int i = 0; i < M; i++){
            c[i] = sc.nextInt();
            d[i] = sc.nextInt();
        }
        
        for(int i = 0; i < N; i++){
            
            int temp = Integer.MAX_VALUE;
            for(int j = 0; j < M; j++){
                int min = Math.abs(a[i] - c[j]) + Math.abs(b[i] - d[j]);
                if(temp > min){
                    temp = min;
                    ans[i] = j + 1;
                }
            }
        }
        for(int i : ans) System.out.println(i);
    }
}