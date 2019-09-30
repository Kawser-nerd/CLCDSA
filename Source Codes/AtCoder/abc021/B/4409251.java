import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();

        int [] cnt = new int [n + 1];
        cnt[a] = 1;
        cnt[b] = 1;

        int k = sc.nextInt();
        String ans = "YES";
        
        for(int i = 0; i < k; i++){
            int p = sc.nextInt();
            cnt[p]++;

            if(cnt[p] >= 2){
                ans = "NO";
            }
        }

        System.out.println(ans);
    }
}