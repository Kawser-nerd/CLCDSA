import java.util.*;
import java.util.function.Consumer;
import java.util.function.Function;
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
            final List<Long> NAB = Arrays.stream(args.get(0).split(" ")).map(Long::valueOf).collect(toList());
            final Long A = NAB.get(1);
            final Long B = NAB.get(2);
            final List<Long> numList = args.stream().skip(1).map(Long::valueOf).collect(toList());

            Long leftExc = 0L;
            Long rightInc = 1_000_000_000L;

            final Function<AbstractMap.SimpleEntry<Long, Long>, Long> ceil =
                    (entry) -> Double.valueOf(Math.ceil(entry.getKey().doubleValue() / entry.getValue().doubleValue())).longValue();
            while (rightInc - leftExc > 1) {
                Long ans = (rightInc + leftExc) / 2;
                if (numList.stream().mapToLong(x -> ceil.apply(new AbstractMap.SimpleEntry<>(Math.max(0, x - ans * B), A - B))).sum() <= ans) {
                    rightInc = ans;
                } else {
                    leftExc = ans;
                }
            }

            System.out.println(rightInc);
        };
    }

}