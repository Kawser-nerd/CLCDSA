import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        String ans = "";
        while (N != 0) {
            if (N % 2 != 0) {
                N -= 1;
                N /= (-2);
                ans = "1" + ans;
            } else {
                ans = "0" + ans;
                N /= -2;
            }
        }
        if (ans == "") {
            ans = "0";
        }
        System.out.println(ans);
    }
}