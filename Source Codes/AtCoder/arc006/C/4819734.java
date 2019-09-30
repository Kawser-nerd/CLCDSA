import java.util.Scanner;
 
public class Main {
    private static final int INF = 1000000;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
 
        int n = sc.nextInt();
 
        int[] w = new int[n];
        for(int i = 0; i < n; i++) {
            w[i] = sc.nextInt();
        }
 
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(w[i] == INF) continue;
 
            int tmp = INF;
            for(int j = i; j < n; j++) {
                if(tmp >= w[j]) {
                    tmp = w[j];
                    w[j] = INF;
                }
            }
            ans++;
        }
 
        System.out.println(ans);
 
        sc.close();
    }
}