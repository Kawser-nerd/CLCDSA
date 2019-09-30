import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        long N = sc.nextLong();
        long ans = 1;
        for(long i = 1; i < N + 1; i++) ans =  ans * i % 1000000007;  
        
        System.out.println(ans);
    }
}