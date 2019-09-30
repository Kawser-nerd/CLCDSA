public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int d = scanner.nextInt(), g = scanner.nextInt();
        int[] p = new int[d], c = new int[d];
        for (int i = 0; i < d; i++) {
            p[i] = scanner.nextInt();
            c[i] = scanner.nextInt();
        }

        int ans = 10000;
        for (int i = 0; i < 1 << d; i++) {
            int sum = 0, count = 0, zero = 0;
            for (int j = 0; j < d; j++) {
                if ((1 << j & i) != 0) {
                    sum += (j + 1) * 100 * p[j] + c[j];
                    count += p[j];
                } else {
                    zero = j;
                }
            }
            if (sum < g) {
                int t = (int)Math.ceil((g - sum) / ((zero + 1) * 100F));
                if (p[zero] < t)
                    continue;
                count += Math.ceil((g - sum) / ((zero + 1) * 100F));
            }
            ans = Math.min(ans, count);
        }
        System.out.println(ans);
    }
}