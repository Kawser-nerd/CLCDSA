import java.math.BigDecimal;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        System.out.println(BigDecimal.valueOf(K).multiply(BigDecimal.valueOf(K - 1).pow(N-1)));
    }
}