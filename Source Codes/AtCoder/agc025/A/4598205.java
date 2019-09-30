import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();

        String s = String.valueOf(n);
        if (n % 10 == 0) {
            System.out.println("10");
        } else {
            int ans = 0;
            for (int i = 0; i < s.length(); i++) {
                ans += Integer.parseInt(String.valueOf(s.charAt(i)));
            }
            System.out.println(ans);
        }
    }
}