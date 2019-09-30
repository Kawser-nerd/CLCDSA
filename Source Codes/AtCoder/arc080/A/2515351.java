import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt4 = 0;
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            if (a % 4 == 0) {
                cnt4++;
            } else if (a % 2 == 0) {
                cnt2++;
            } else {
                cnt1++;
            }
        }

        System.out.println(((cnt1 > cnt4) ? (((cnt1 - cnt4) == 1) && (cnt2 == 0)) : true) ? "Yes"
            : "No");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}