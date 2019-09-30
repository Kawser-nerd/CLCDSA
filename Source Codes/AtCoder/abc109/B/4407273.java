import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String> w = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            w.add(sc.next());
        }
        for (int i = 1; i < n; i++) {
            String word = w.get(i);
            String prev = w.get(i - 1);
            for (int j = 0; j < i; j++) {
                if (word.equals(w.get(j))) {
                    System.out.println("No");
                    return;
                }
            }
            if (!word.substring(0, 1).equals(prev.substring(prev.length() - 1))) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }

}