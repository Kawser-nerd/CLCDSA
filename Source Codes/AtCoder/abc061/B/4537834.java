import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] bridge = new int[n + 1];
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            bridge[a]++;
            bridge[b]++;
        }
        for (int i = 1; i < n + 1; i++) {
            System.out.println(bridge[i]);
        }
        sc.close();
    }
}