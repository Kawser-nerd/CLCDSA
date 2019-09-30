import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int w = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int ans = 0;
        if (a < b) {
            if (a + w >= b) {
                ans = 0;
            } else {
                ans = b - (a + w);
            }
        } else {
            if (b + w >= a) {
                ans = 0;
            } else {
                ans = a - (b + w);
            }
        }
        System.out.println(ans);
        sc.close();
    }
}