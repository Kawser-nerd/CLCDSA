import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        char[] S = sc.next().toCharArray();
        char[] T = sc.next().toCharArray();

        int[] start = new int[26];
        int[] end = new int[26];

        Arrays.fill(start, -1);
        Arrays.fill(end, -1);

        for (int i = 0; i < S.length; i++) {
            int a = S[i] - 'a';
            int b = T[i] - 'a';

            if ((start[a] != -1 && end[b] != a) || (end[b] != -1 && start[a] != b)) {
                System.out.println("No");
                return;
            }
            start[a] = b;
            end[b] = a;
        }
        System.out.println("Yes");
    }


}