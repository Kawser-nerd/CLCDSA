import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int k = sc.nextInt();
        if (s.length() < k) {
            System.out.println(0);
            return;
        }
        Set<String> set = new HashSet<String>();
        for (int i = 0; i <= s.length() - k; i++) {
            String sub = s.substring(i, i + k);
            set.add(sub);
        }
        System.out.println(set.size());
    }
}