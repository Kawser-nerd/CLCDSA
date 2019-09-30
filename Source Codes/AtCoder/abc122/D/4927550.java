public class Main {
    private static long[][][][] memo = new long[101][85][85][85];
    public static void main(String[]$) {
        System.out.println(dfs(new java.util.Scanner(System.in).nextInt(), ' ', ' ', ' '));
    }

    private static long dfs(int r, char l1, char l2, char l3) {
        return memo[r][l1][l2][l3] != 0 ? memo[r][l1][l2][l3] : (memo[r][l1][l2][l3] = ((r == 1 ? 2 : dfs(r - 1, l2, l3, 'A') + dfs(r - 1, l2, l3, 'T')) + (l2 != 'G' && l3 != 'G' || l1 != 'A' && l2 != 'A' && l3 != 'A' ? r == 1 ? 1 : dfs(r - 1, l2, l3, 'C') : 0) + (l2 != 'A' || l3 != 'C' ? r == 1 ? 1 : dfs(r - 1, l2, l3, 'G') : 0)) % 1000000007);
    }
}