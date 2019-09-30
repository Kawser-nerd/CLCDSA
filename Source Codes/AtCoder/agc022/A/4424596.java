public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        String s = scanner.next();
        if (s.equals("zyxwvutsrqponmlkjihgfedcba")) {
            System.out.println(-1);
        } else if (s.length() < 26) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (s.indexOf(c) == -1) {
                    System.out.println(s + c);
                    return;
                }
            }
        } else {
            char c[] = s.toCharArray(), last = c[25];
            boolean[] use = new boolean[26];
            use[c[25] - 'a'] = true;

            for (int i = c.length - 2; i >= 0; i--) {
                if (last < c[i]) {
                    use[(last = c[i]) - 'a'] = true;
                } else {
                    for (int i1 = c[i] - 'a'; i1 < 26; i1++) {
                        if (use[i1]) {
                            System.out.println(s.substring(0, i) + (char)(i1 + 'a'));
                            return;
                        }
                    }
                }
            }
        }
    }
}