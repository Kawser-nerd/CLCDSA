import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int a;
        boolean just = false;
        Scanner scan = new Scanner(System.in);

        a = Integer.parseInt(scan.next());


        for (int donuts = 0; donuts <= a; donuts++) {
                for (int cake = 0; cake <= a; cake++) {
                    int total = (4 * donuts) + (7 * cake);
                    if (total == a) {
                        just = true;
                    }
            }
        }

        System.out.println(just ? "Yes" : "No");
    }
}