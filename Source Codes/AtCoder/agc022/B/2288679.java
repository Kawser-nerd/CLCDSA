import java.util.Scanner;
import java.util.StringJoiner;
import java.util.TreeSet;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        if (scanner.hasNextLine()) {
            int N = Integer.parseInt(scanner.nextLine());

            if (N == 3) {
                System.out.println("3 5 22");
            } else {
                int c6p3 = ((N - 1) / 8) * 2 + 2;
                int c6p2 = (N - c6p3 - 1) / 3 + 1;
                int c6p6 = N - c6p3 - c6p2 - c6p2;

                TreeSet<Integer> set = new TreeSet<>();
                for (int i = 0; i < c6p3; ++i) {
                    set.add(i * 6 + 3);
                }
                for (int i = 0; i < c6p2; ++i) {
                    set.add(i * 6 + 2);
                    set.add(i * 6 + 4);
                }
                for (int i = 0; i < c6p6; ++i) {
                    set.add(i * 6 + 6);
                }
                StringJoiner joiner = new StringJoiner(" ");
                for (Integer v: set) {
                    joiner.add(v.toString());
                }
                System.out.println(joiner.toString());
            }
        }
    }
}