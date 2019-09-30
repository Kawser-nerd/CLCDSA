import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int D = sc.nextInt();
        int ans = Math.min(B, D) - Math.max(A, C);
        System.out.println(ans >= 0 ? ans : 0) ;
    }
}