import java.math.BigDecimal;
        import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String str = sc.next();
        String[] strs = str.split("\\+");

        long ans = strs.length;
        for (int i = 0; i < strs.length; i++) {
            if (strs[i].contains("0")) {
                ans--;
            }
        }
        System.out.println(ans);
    }
}