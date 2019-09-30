public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    private static int n = scanner.nextInt();
    public static void main(String[] args) {
        System.out.println(dfs(""));
    }

    public static int dfs(String s) {
        return !s.isEmpty() && Long.parseLong(s) > n ? 0 : (s.contains("3") && s.contains("5") && s.contains("7") ? 1 : 0) + dfs(s + "3") + dfs(s + "5") + dfs(s + "7");
    }
}