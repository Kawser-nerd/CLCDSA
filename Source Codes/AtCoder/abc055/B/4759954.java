import java.math.BigDecimal;
        import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        BigDecimal x = BigDecimal.valueOf(1);
        for (int i=1; i<=N; i++) {
            x = x.multiply(BigDecimal.valueOf(i)).remainder(BigDecimal.valueOf(1000000007));
        }
        System.out.println(x);
    }
}