import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        sc.nextInt();
        long K = sc.nextLong();

        int ret = 0;

        if (K % 2 == 0) {
            ret = A - B;
        } else {
            ret = B - A;
        }

        System.out.println(ret);
    }
}