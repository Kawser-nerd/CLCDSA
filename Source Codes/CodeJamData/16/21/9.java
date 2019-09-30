import java.util.*;
import static java.lang.Math.*;

public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        int[] num = {0, 6, 2, 8, 3, 4, 5, 7, 1, 9};
        char[] ch = {'Z', 'X', 'W', 'G', 'H', 'R', 'F', 'V', 'O', 'E'};
        String[] word = {"ZERO", "SIX", "TWO", "EIGHT", "THREE", "FOUR", "FIVE", "SEVEN", "ONE", "NINE"};
        for (int zz = 1; zz <= T; zz++) {
            String S = in.next();
            int[] C = new int[26];
            for (int i = 0; i < S.length(); i++) {
                C[(int)(S.charAt(i)-'A')]++;
            }
            int[] ans = new int[10];
            for (int i = 0; i < 10; i++) {
                int count = C[(int)(ch[i]-'A')];
                ans[num[i]] += count;
                for (int j = 0; j < word[i].length(); j++) {
                    C[(int)(word[i].charAt(j)-'A')] -= count;
                }
            }
            for (int i = 0; i < 10; i++) {
                if (C[i] != 0) {
                    throw new RuntimeException();
                }
            }
            System.out.format("Case #%d: ", zz);
            for (int i = 0; i < 10; i++)
                for (int j = 0; j < ans[i]; j++)
                    System.out.print(i);
            System.out.println();
        }
    }
}
