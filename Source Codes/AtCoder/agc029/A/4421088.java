public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        long count = 0, ans = 0;
        for (char c : scanner.next().toCharArray())
            if (c == 'B') count++;
            else ans += count;
        System.out.println(ans);
    }
}