import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        
        double N = sc.nextInt();
        double K = sc.nextInt();
        double ans = K * Math.pow(K-1,N-1);
        
        System.out.println((int)ans);
    }
}