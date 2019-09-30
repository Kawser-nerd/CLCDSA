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
            final List<Integer> numList = Arrays.stream(args.get(1).split(" ")).map(Integer::valueOf).collect(toList());
            final Long dividedBy2ButNot4 = numList.stream().filter(x -> x % 2 == 0 && x % 4 != 0).mapToInt(Integer::intValue).count();
            final Long dividedBy4 = numList.stream().filter(x -> x % 4 == 0).mapToInt(Integer::intValue).count();
            final Long numListSizeIgnoringMultiple2 = numList.size() - (dividedBy2ButNot4 > 0 ? dividedBy2ButNot4 - 1 : 0);
            System.out.println(numListSizeIgnoringMultiple2 - dividedBy4 - 1 <= dividedBy4 ? "Yes" : "No");
        };
    }

}