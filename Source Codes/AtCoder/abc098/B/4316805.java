import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        int max = 0;
        for (int i = 1; i < n; i++) {
            List<String> s1 = Arrays.asList(s.substring(0, i).split(""));
            List<String> s2 = Arrays.asList(s.substring(i).split(""));
            Set<String> set = new HashSet<>(s1);
            set.retainAll(s2);
            if (set.size() > max) {
                max = set.size();
            }
        }
        System.out.println(max);
    }

}