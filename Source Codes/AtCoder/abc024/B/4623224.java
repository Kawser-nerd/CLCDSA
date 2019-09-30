import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        int tmp1 = sc.nextInt();
        int tmp2 = sc.nextInt();
        int output = 0;

        for (int i = 1; i < n; i++) {
            output += Math.min(t, tmp2 - tmp1);
            if (i != n - 1) {
                tmp1 = tmp2;
                tmp2 = sc.nextInt();
            }

        }
        output+=t;
        System.out.println(output);
    }

}