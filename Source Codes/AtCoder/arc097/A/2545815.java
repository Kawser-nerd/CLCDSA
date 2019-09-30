import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int n = sc.nextInt();
        Set<String> substr = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < str.length() - i + 1; j++) {
                substr.add(str.substring(j, j + i));
            }
        }
        String result = "";
        for (int i = 0; i < n; i++) {
            String min = substr.iterator().next();
            for (String cur : substr) {
                if (min.compareTo(cur) > 0) {
                    min = cur;
                }
            }
            substr.remove(min);
            result = min;
        }
        System.out.println(result);
    }
}