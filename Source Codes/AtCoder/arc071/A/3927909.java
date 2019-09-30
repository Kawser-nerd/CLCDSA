import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        int[] nums = new int['z' - 'a' + 1];
        int[] tmp = new int['z' - 'a' + 1];
        for (char c : sc.next().toCharArray()) {
            nums[c - 'a']++;
        }

        for (int i = 1; i < n; i++) {
            for (char c : sc.next().toCharArray()) {
                tmp[c - 'a']++;
            }

            for (int j = 0; j < 'z' - 'a' + 1; j++) {
                nums[j] = Math.min(nums[j], tmp[j]);
            }

            Arrays.fill(tmp, 0);
        }

        for (int i = 0; i < 'z' - 'a' + 1; i++) {
            for (int j = 0; j < nums[i]; j++) {
                System.out.printf("%c", 'a' + i);
            }
        }
        System.out.println();
    }
}