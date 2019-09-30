import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            LinkedList<Integer> a1 = new LinkedList<>();
            LinkedList<Integer> a2 = new LinkedList<>();
            LinkedList<Integer> a4 = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                int a = sc.nextInt();
                if ( a % 4 == 0 ) {
                    a4.add(a);
                } else if ( a % 2 == 0 ) {
                    a2.add(a);
                } else {
                    a1.add(a);
                }
            }

            if ( a1.size() > a4.size() + 1 || a1.size() == 1 && a4.isEmpty() ) {
                System.out.println("No");
                continue;
            }

            boolean a1RemFlg = (a1.size() == a4.size() + 1);

            if ( a1RemFlg && !a2.isEmpty() ) {
                System.out.println("No");
                continue;
            }
            if ( !a1RemFlg ) {

            }

            if ( a2.size() % 2 != 0 && a4.isEmpty() ) {
                System.out.println("No");
                continue;
            }

            System.out.println("Yes");
        }
    }
}