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
            final List<Integer> matchedIndexList = IntStream.range(0, numList.size())
                    .filter(x -> numList.get(x).equals(x + 1))
                    .boxed()
                    .collect(toList());

            Integer curr = -1;
            Integer cnt = 0;
            Integer ans = 0;
            for (final Integer index : matchedIndexList) {
                if (curr == -1 || curr + 1 == index) {
                    cnt++;
                    curr = index;
                    continue;
                }

                ans += Double.valueOf(Math.ceil(cnt.doubleValue() / 2)).intValue();
                cnt = 1;
                curr = index;
            }
            ans += Double.valueOf(Math.ceil(cnt.doubleValue() / 2)).intValue();

            System.out.println(ans);
        };
    }

}