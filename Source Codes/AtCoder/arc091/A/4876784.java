import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.function.Consumer;

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
            final List<Long> numList = Arrays.stream(args.get(0).split(" ")).map(Long::valueOf).collect(toList());
            final Long x = numList.get(0);
            final Long y = numList.get(1);
            if (x == 1) {
                if (y == 1) {
                    System.out.println(1);
                } else {
                    System.out.println(y - 2);
                }
            } else if (y == 1) {
                System.out.println(x - 2);
            } else {
                System.out.println((x - 2) * (y - 2));
            }
        };
    }

}