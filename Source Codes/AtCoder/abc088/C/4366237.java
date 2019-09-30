public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int max1 = 100, max2 = 100, max3 = 100, a[] = new int[9];
        for (int i = 0; i < 3; i++) {
            max1 = Math.min(max1, a[i * 3] = scanner.nextInt());
            max2 = Math.min(max2, a[i * 3 + 1] = scanner.nextInt());
            max3 = Math.min(max3, a[i * 3 + 2] = scanner.nextInt());
        }

        System.out.println((a[0] - max1 == a[1] - max2 && a[1] - max2 == a[2] - max3) &&
                (a[3] - max1 == a[4] - max2 && a[4] - max2 == a[5] - max3) &&
                (a[6] - max1 == a[7] - max2 && a[7] - max2 == a[8] - max3) ? "Yes" : "No");
    }
}