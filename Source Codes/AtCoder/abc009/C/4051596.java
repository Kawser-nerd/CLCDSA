import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] nk = scanner.nextLine().split(" ", 2);
        int n = Integer.parseInt(nk[0]);
        int k = Integer.parseInt(nk[1]);

        String s = scanner.nextLine();
        char[] orig = s.toCharArray();
        char[] chars = s.toCharArray();

        if (k == chars.length) {
            Arrays.sort(chars);
            System.out.println(new String(chars));
            return;
        }

        for (int i = 0; i < chars.length; i++) {
            int minI = i;
            for (int j = i + 1; j < chars.length; j++) {
                if (chars[minI] > chars[j]) {
                    char tmp = chars[i];
                    chars[i] = chars[j];
                    chars[j] = tmp;

                    int count = replaceCount(orig, chars);
                    if (count <= k) {
                        minI = j;
                    }

                    tmp = chars[i];
                    chars[i] = chars[j];
                    chars[j] = tmp;
                }
            }

            if (i != minI) {
                char tmp = chars[i];
                chars[i] = chars[minI];
                chars[minI] = tmp;
            }
        }
        System.out.println(new String(chars));
    }

    private static int replaceCount(char[] orig, char[] chars) {
        int count = 0;
        for (int i = 0; i < orig.length; i++) {
            if (orig[i] != chars[i]) {
                count++;
            }
        }
        return count;
    }
}