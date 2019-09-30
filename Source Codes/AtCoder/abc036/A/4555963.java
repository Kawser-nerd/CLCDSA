import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int ans = 0;
        while (ans * a < b) {
            ans++;
        }
        System.out.println(ans);

        sc.close();
    }
}