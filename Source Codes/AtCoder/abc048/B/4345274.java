import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        long a = sc.nextLong();
        long b = sc.nextLong();
        long x = sc.nextLong();
        long ans;
        
        if(a != 0){
            ans = b / x - (a-1) / x;
        }else{
            ans = b / x + 1;
        }
        
        System.out.println(ans);
    }
}