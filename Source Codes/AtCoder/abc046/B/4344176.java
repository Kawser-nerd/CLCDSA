import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        long N = sc.nextInt();
        long K = sc.nextInt();
        long ans = K;
        
        for(int i = 0; i < N-1; i++)ans *= K-1;
        
        System.out.println(ans);
    }
}