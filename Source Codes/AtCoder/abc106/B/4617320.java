import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = 0;
        for(int i=3; i<=n; i+=2){
            int cnt = 0;
            for(int j=1; j<=i; j++){
                if(i % j == 0) cnt++;
            }
            if(cnt == 8) ans++;
        }
        System.out.println(ans);
    }
}