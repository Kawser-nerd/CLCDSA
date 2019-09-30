import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int k = sc.nextInt();
        TreeSet<String> ts = new TreeSet<>();
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < s.length() - i + 1; j++) {
                ts.add(s.substring(j, j+i));
            }
        }
        List<String> list = new ArrayList<>(ts);
        Collections.sort(list);
        System.out.println(list.get(k-1));
    }
}