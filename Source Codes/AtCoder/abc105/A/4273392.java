import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        final int K = sc.nextInt();
        
        System.out.println(N % K == 0 ? 0 : 1);
    }
}