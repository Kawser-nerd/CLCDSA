import java.util.Scanner;

public class Main {
    static boolean c[];

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scan.nextInt();
        }
        c = new boolean[100001];
        int ret = 0;
        int rgt =0;
        for (int lft = 0; lft < n; lft++) {
            while (rgt < n  && !c[a[rgt]]) {
                c[a[rgt]] = true;
                rgt++;
            }
            ret = Math.max(ret, rgt - lft);
            if(lft == rgt) {
                rgt++;
            }
            c[a[lft]] = false;
        }
        System.out.println(ret);
    }
}