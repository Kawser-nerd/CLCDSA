import java.util.Scanner;

public class Main {
    private static final long MOD = 1_000_000_007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        char[] str = sc.nextLine().toCharArray();
        int[] counts = new int[26];
        for (int i = 0; i < str.length; i++) {
            counts[str[i] - 'a']++;
        }
        long ans = counts[0]+1;
        for (int i = 1; i < counts.length; i++) {
            ans = (ans * (counts[i] + 1)) % MOD;
        }
        System.out.println(ans - 1);
    }
}