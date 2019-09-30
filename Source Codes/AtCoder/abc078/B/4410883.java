import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int Y = sc.nextInt();
        int Z = sc.nextInt();        
        int ans = 0;
        
        //???N???Y?????Z??????????????
        while((ans + 1) * (Y + Z) + Z  <= N){
            ans++;
        }
        System.out.println(ans);
    }
}