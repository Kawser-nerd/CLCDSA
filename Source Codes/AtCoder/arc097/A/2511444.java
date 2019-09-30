import java.util.*;

public class Main {
    public void main(Scanner sc) {
        String s = sc.next();
        int k = sc.nextInt();

        Set<String> set = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            for (int j = 1; j <= k && (i + j) <= s.length(); j++) {
                set.add(s.substring(i, i + j));
            }
        }

        String sort[] = set.stream().sorted().toArray(String[]::new);
        System.out.println(sort[k - 1]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}