import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        int n = sc.nextInt();

        if (n == 0) {
            System.out.println('0');
            return;
        }

        while (n != 0) {
            int tmp = n % -2;
            if (tmp == -1) {
                n--;
                tmp = 1;
            }
            sb.append(tmp);

            n /= -2;
        }

        String s = sb.reverse().toString();
        System.out.println(s);
    }
}