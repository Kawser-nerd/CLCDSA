import java.util.*;

public class Main {
    public void main(Scanner sc) {
        char s[] = sc.next().toCharArray();
        char t[] = sc.next().toCharArray();
        boolean resolve = false;

        int slen = s.length;
        int tlen = t.length;
        for (int i = slen - tlen; i >= 0; i--) {
            if (check(Arrays.copyOfRange(s, i, i + tlen), t)) {
                for (int j = 0; j < tlen; j++) {
                    s[i + j] = t[j];
                }
                resolve = true;
                break;
            }
        }

        System.out.println(resolve ? new String(s).replace('?', 'a') : "UNRESTORABLE");
    }

    private boolean check(char s[], char t[]) {
        for (int i = 0; i < s.length; i++) {
            if (s[i] != '?' && s[i] != t[i]) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) throws Exception {
        try (Scanner sc = new Scanner(System.in)) {
            new Main().main(sc);
        } catch (Exception e) {
            throw e;
        }
    }
}