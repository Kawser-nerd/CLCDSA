import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int l = sc.nextInt();
        int h = sc.nextInt();
        int n = sc.nextInt();
        int[] ans = new int[n];

        int diff = h - l;
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int d = l - a;
            if (d > 0)
                ans[i] = d;
            else if (-d <= diff)
                ans[i] = 0;
            else
                ans[i] = -1;
        }
        
        for (int i : ans)
            System.out.println(i);
    }
}