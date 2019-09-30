import java.util.*;
import java.util.stream.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        String s = IntStream.range(0, scanner.nextInt()).mapToObj(i -> scanner.next()).collect(Collectors.joining()).replace(" ", "");
        int c = Integer.compare(s.replace("R", "").length(), s.replace("B", "").length());
        System.out.println(c == -1 ? "TAKAHASHI" : c == 0 ? "DRAW" : "AOKI");
    }
}