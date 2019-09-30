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
            final List<Integer> firstRow = Arrays.stream(args.get(1).split(" ")).map(Integer::valueOf).collect(toList());
            final List<Integer> secondRow = Arrays.stream(args.get(2).split(" ")).map(Integer::valueOf).collect(toList());
            final Integer ans = IntStream.range(0, firstRow.size())
                    .map(index ->
                            firstRow.subList(0, index + 1).stream().mapToInt(Integer::intValue).sum()
                                    + secondRow.subList(index, secondRow.size()).stream().mapToInt(Integer::intValue).sum())
                    .max()
                    .orElse(-1);
            System.out.println(ans);
        };
    }

}