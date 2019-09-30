import java.util.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        System.out.println(java.util.stream.IntStream.range(0,scanner.nextInt()).map(i->scanner.nextInt()).filter(m->m<80).map(m->80-m).sum());
    }
}