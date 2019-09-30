import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        boolean[] isPush = new boolean[n];
        int cnt = 0;
        int botten = 1;
        while (botten != 2) {
            if (isPush[botten-1]) {
                cnt = -1;
                break;
            }
            isPush[botten-1] = true;
            botten = a[botten-1];
            cnt++;
        }
        
        System.out.println(cnt);
    }
}