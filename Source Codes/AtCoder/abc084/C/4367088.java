public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        int[] c = new int[n - 1], s = new int[n - 1], f = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            c[i] = scanner.nextInt();
            s[i] = scanner.nextInt();
            f[i] = scanner.nextInt();
        }

        for (int i = 0, time = 0; i < n - 1; i++, time = 0) {
            for (int j = i; j < n - 1; j++)
                time = Math.max(s[j], time % f[j] == 0 ? time : time + f[j] - time % f[j]) + c[j];
            System.out.println(time);
        }
        System.out.println(0);
    }
}