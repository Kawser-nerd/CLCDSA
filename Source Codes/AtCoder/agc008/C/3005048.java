import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int i = sc.nextInt();
        int o = sc.nextInt();
        int t = sc.nextInt();
        int j = sc.nextInt();
        int l = sc.nextInt();
        int s = sc.nextInt();
        int z = sc.nextInt();

        long ans1 = o;
        ans1 += (i / 2) * 2;
        ans1 += (j / 2) * 2;
        ans1 += (l / 2) * 2;
        ans1 += 3 * ((i % 2) * (j % 2) * (l % 2));

        long ans2 = o;
        if (i >= 1 && j >= 1 && l >= 1) {
            ans2 += 3;
            i--;
            j--;
            l--;
        }
        ans2 += (i / 2) * 2;
        ans2 += (j / 2) * 2;
        ans2 += (l / 2) * 2;

        System.out.println(Math.max(ans1, ans2));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}