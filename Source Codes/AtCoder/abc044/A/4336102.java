import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int X = sc.nextInt();
        int Y = sc.nextInt();

        //?????
        int price = (N <= K)? N * X : (K * X) + ((N - K) * Y );
        
        System.out.println(price);
    }
}