public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
	    long n = scanner.nextLong(), ans = String.valueOf(n).length();
	    for (long i = 1; i * i <= n; i++)
            if (n % i == 0)
                ans = Math.min(ans, Math.max(String.valueOf(i).length(), String.valueOf(n / i).length()));
        System.out.println(ans);
    }
}