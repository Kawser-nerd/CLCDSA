import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.function.Consumer;
import java.util.stream.IntStream;

import static java.util.stream.Collectors.toList;

public class Main {
    private static final Scanner scanner = new Scanner(System.in);
    private static final Consumer<List<String>> consumer = solve();

    public static void main(String[] args) {
        consumer.accept(readInput());
    }

    private static List<String> readInput() {
        final List<String> lineList = new ArrayList<>();
        while (scanner.hasNextLine()) {
            lineList.add(scanner.nextLine());
        }
        return lineList;
    }

    private static Consumer<List<String>> solve() {
        return args -> {
            final char[] first = args.get(1).toCharArray();
            final char[] second = args.get(2).toCharArray();

            Long ans = 1L;
            Boolean isPrevVertical = null;
            Integer index = 0;
            while (index < first.length) {
                if (first[index] == second[index]) {
                    if (isPrevVertical == null) {
                        ans = (ans * 3) % 1000000007;
                    } else if (isPrevVertical) {
                        ans = (ans * 2) % 1000000007;
                    }
                    isPrevVertical = true;
                    index++;
                } else {
                    if (isPrevVertical == null) {
                        ans = (ans * 6) % 1000000007;
                    } else if (isPrevVertical) {
                        ans = (ans * 2) % 1000000007;
                    } else {
                        ans = (ans * 3) % 1000000007;
                    }
                    isPrevVertical = false;
                    index += 2;
                }
            }

            System.out.println(ans);
        };
    }

}