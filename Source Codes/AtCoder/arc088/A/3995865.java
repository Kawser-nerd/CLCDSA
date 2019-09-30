import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        long x = sc.nextLong();
        long y = sc.nextLong();
        int ans = 0;
        while (x <= y) {
            x *= 2l;
            ans++;
        }
        System.out.println(ans);
    }
}