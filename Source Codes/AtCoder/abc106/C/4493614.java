import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        long k = sc.nextLong();

        if (k == 1) {
            System.out.println(s.charAt(0));
        } else {
            char ans = 0;
            for (int i = 0; i < k; i++) {
                if (s.charAt(i) != '1') {
                    ans = s.charAt(i);
                    break;
                }
            }
            if (ans == 0)
                ans = '1';
            System.out.println(ans);
        }
    }
}