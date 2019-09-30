import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();

        String ans = "";
        while (true) {
            if (N % 2 == 0) {
                ans = "0" + ans;
                N = (N) / -2;
            } else {
                ans = "1" + ans;
                N = (N - 1) / -2;
            }
            if (N == 0) {
                System.out.println(ans);
                break;
            }
        }

    }
}