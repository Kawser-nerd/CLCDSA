import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int ans = 1; 
        int tmp = 0;
                
        while((tmp + 1) * (tmp + 1) <= N){
            ans =  (tmp + 1) * (tmp + 1);
            tmp++;
        }
        System.out.println(ans);
    }
}