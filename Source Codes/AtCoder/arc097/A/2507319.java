import java.util.Scanner;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int k = sc.nextInt();
        TreeSet<String> set = new TreeSet<>();
        for (int c = 'a'; c <= 'z'; c++) {
            char ch = (char) c;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == ch) {
                    for (int j = i, x = 0; j < s.length() && x < 5; j++, x++) {
                        set.add(s.substring(i, j + 1));
                    }
                }
            }
            if (set.size() >= k) {
                break;
            }
        }
        set.stream().skip(k-1).findFirst().ifPresent(System.out::println);
    }
}