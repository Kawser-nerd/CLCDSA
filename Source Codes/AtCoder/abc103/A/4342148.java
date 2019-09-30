import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Integer> a = new ArrayList<>();
        IntStream.range(0, 3).forEach(i -> a.add(sc.nextInt()));
        Collections.sort(a);
        System.out.println(Math.abs(a.get(2) - a.get(1)) + Math.abs(a.get(1) - a.get(0)));
    }

}