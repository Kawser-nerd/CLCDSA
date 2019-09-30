import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] s = new String[n];
        int ans = 0;
        for(int i = 0; i < n; i++){
            s[i] = sc.next();
            
        }
        for(int i = 0; i < n-1; i++){
            if(s[i].equals("TAKAHASHIKUN")){
                ans ++;
            }else if(s[i].equals("Takahashikun") || s[i].equals("takahashikun")){
                ans ++;
            }
        }
        if(s[n-1].equals("TAKAHASHIKUN.")){
            ans ++;
        }else if(s[n-1].equals("Takahashikun.") || s[n-1].equals("takahashikun.")){
            ans ++;
        }
        System.out.println(ans);
    }
}