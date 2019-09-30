import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int l = sc.nextInt();
        int h = sc.nextInt();
        int n = sc.nextInt();
        int[] ans = new int[n];

        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            if (a < l)
                ans[i] = l - a;
            else if (a > h)
                ans[i] = -1;
            else
                ans[i] = 0;
        }

        for (int i : ans)
            System.out.println(i);
    }
}