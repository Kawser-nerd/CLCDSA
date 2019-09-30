import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int h = scanner.nextInt();
        int w = scanner.nextInt();
        String[] a = Stream.generate(() -> null).limit(h)
                .map(b -> scanner.next())
                .filter(b -> b.contains("#"))
                .toArray(String[]::new);

        List<Integer> i = IntStream.range(0, w).boxed().collect(Collectors.toList());
        for (String s : a)
            i.removeIf(i2 -> s.charAt(i2) == '#');

        for (String s : a) {
            char[] c = s.toCharArray();
            for (int j = 0; j < c.length; j++)
                if (!i.contains(j))
                    System.out.print(c[j]);
            System.out.println();
        }
    }
}