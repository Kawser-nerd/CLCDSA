import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        int cnt = 1;
        List<Integer> list = new ArrayList<>();
        while (true) {
            int i = a * cnt % b;
            if (i == c) {
                System.out.println("YES");
                System.exit(0);
            } else if (list.contains(i)) {
                System.out.println("NO");
                System.exit(0);
            } else {
                list.add(i);
                cnt++;
            }
        }
    }
}