import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Long> a = new ArrayList<>();
        int oddCount = 0;
        for (int i = 0; i < n; i++) {
            Long num = sc.nextLong();
            if (num % 2 == 1) {
                oddCount++;
            }
            a.add(num);
        }
        if (oddCount % 2 == 0) {
            System.out.println("YES");
            return;
        }
        System.out.println("NO");
    }

}