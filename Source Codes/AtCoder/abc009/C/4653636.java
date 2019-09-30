import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int k = sc.nextInt();

        char s[] = sc.next().toCharArray();
        char t[] = s.clone();
        char ans[] = new char[n];

        for (int i = 0; i < n; i++) {
            Arrays.sort(t, i, n);
            for (int j = i; j < n; j++) {
                ans[i] = t[j];
                t[j] = t[i];

                int diff = count1(s, ans, i + 1) + count2(s, t, i + 1, n);
                if (diff <= k) {
                    break;
                }

                t[j] = ans[i];
            }
        }

        System.out.println(ans);
    }

    private int count1(char sr[], char tg[], int e) {
        int diff = 0;
        for (int i = 0; i < e; i++) {
            if (sr[i] != tg[i]) {
                diff++;
            }
        }

        return diff;
    }

    private int count2(char sr[], char tg[], int s, int e) {
        int diff = e - s;
        int i = 0;
        int j = 0;

        char src[] = Arrays.copyOfRange(sr, s, e);
        char tgt[] = Arrays.copyOfRange(tg, s, e);
        Arrays.sort(src);
        Arrays.sort(tgt);

        while (i < src.length && j < tgt.length) {
            if (src[i] < tgt[j]) {
                i++;
            } else if (src[i] > tgt[j]) {
                j++;
            } else {
                diff--;
                i++;
                j++;
            }
        }

        return diff;
    }

    public static void main(String[] args) throws Exception {
        try (Scanner sc = new Scanner(System.in)) {
            new Main().main(sc);
        } catch (Exception e) {
            throw e;
        }
    }
}