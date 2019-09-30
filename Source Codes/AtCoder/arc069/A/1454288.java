import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long s = in.nextLong(), c = in.nextLong();
        Long ans = Math.min(s, c / 2);
        c -= s * 2;
        if(c > 0) {
            ans += c / 4;
        }
        System.out.println(ans);
    }
}