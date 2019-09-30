import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int ans = 0;

        for(int i = 0; i < n; i++){
            int p = sc.nextInt();
            
            while(p % 2 == 0 || p % 3 == 2){
                p--;
                ans++;
            }
        }

        System.out.println(ans);
    }
}