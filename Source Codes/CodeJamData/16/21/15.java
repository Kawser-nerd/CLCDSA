import java.util.*;

public class A {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        s.nextLine();
        boolean[] f = new boolean[10];
        boolean flag = true;
        int[] nums = new int[10];
        char[] chs = new char[10];
        int[] sum = new int[10];
        int m = 0;
        while (flag) {
            flag = false;
            for (char ch = 'A'; ch <= 'Z'; ch++) {
                int count = 0;
                int loc = -1;
                for (int i = 0; i < 10; i++) {
                    if (f[i]) {
                        continue;
                    }
                    String digit = DIGIT[i];
                    int n = digit.length();
                    boolean find = false;
                    for (int j = 0; j < n; j++) {
                        if (digit.charAt(j) == ch) {
                            find = true;
                            break;
                        }
                    }
                    if (find) {
                        count++;
                        loc = i;
                    }
                }
                if (count == 1) {
                    chs[m] = ch;
                    nums[m] = loc;
                    String digit = DIGIT[loc];
                    for (int i = 0; i < digit.length(); i++) {
                        if (digit.charAt(i) == ch) {
                            sum[m]++;
                        }
                    }
                    m++;
                    f[loc] = true;
                    flag = true;
                }
            }
        }
        for (int t = 1; t <= T; t++) {
            String line = s.nextLine();
            int[] count = new int[26];
            for (int i = 0; i < line.length(); i++) {
                count[line.charAt(i) - 'A']++;
            }
            int[] ans = new int[10];
            for (int i = 0; i < 10; i++) {
                int num = nums[i];
                int c = count[chs[i] - 'A'] / sum[i];
                ans[num] = c;
                String digit = DIGIT[num];
                for (int j = 0; j < digit.length(); j++) {
                    char ch = digit.charAt(j);
                    count[ch - 'A'] -= c;
                }
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < ans[i]; j++) {
                    sb.append(i);
                }
            }
            System.out.println(String.format("Case #%d: %s", t, sb.toString()));
        }
        s.close();
    }

    public static final String[] DIGIT = new String[] {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
}