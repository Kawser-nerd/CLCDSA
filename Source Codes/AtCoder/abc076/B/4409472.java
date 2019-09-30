import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int K = sc.nextInt();
        int ans = 1;
        
        //?2???????ans???????????
        //????ans?K??????????????
        while(N > 0){
            ans += Math.min(ans, K);
            N--;
        }
        System.out.println(ans);
    }
}