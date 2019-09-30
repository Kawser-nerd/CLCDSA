public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        long m = 0, a = 0, r = 0, c = 0, h = 0;
        for (int i = 0; i < n; i++) {
            switch (scanner.next().charAt(0)) {
                case 'M': m++; continue;
                case 'A': a++; continue;
                case 'R': r++; continue;
                case 'C': c++; continue;
                case 'H': h++;
            }
        }
        System.out.println(m * a * r + m * a * c + m * a * h + m * r * c + m * r * h + m * c * h + a * r * c + a * r * h + a * c * h + r * c * h);
    }
}