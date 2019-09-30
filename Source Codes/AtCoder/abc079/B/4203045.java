import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Long> lucas = new ArrayList<>();
        lucas.add(2L);
        lucas.add(1L);
        for (int i = 2; i <= n; i++) {
            lucas.add(lucas.get(i - 1) + lucas.get(i - 2));
        }
        System.out.println(lucas.get(n));
    }

}