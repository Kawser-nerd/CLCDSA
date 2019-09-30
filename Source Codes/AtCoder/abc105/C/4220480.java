import java.util.*;

public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        if (N == 0) {
            System.out.println("0");
            return;
        }

        String ans = "";
        while (N != 0) {
            if (N % 2 != 0) {
                N--;
                ans = "1" + ans;
            } else {
                ans = "0" + ans;
            }
            N /= -2;
        }
        System.out.println(ans);
    }

}