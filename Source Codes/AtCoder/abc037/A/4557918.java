import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int min = Math.min(a, b);
        int ans = c / min;
        System.out.println(ans);
        sc.close();
    }
}