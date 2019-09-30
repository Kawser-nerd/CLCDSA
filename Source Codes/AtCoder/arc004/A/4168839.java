import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> x = new ArrayList<>();
        List<Integer> y = new ArrayList<>();
        IntStream.range(0, n).forEach(i -> {
            x.add(sc.nextInt());
            y.add(sc.nextInt());
        });

        double maxLen = 0;
        for (int i = 0; i < x.size(); i++) {
            for (int j = i + 1; j < x.size(); j++) {
                double len = Math.sqrt(Math.pow(x.get(j) - x.get(i), 2)
                        + Math.pow(y.get(j) - y.get(i), 2));
                if (i == 0 && j == 1 || maxLen < len) {
                    maxLen = len;
                }
            }
        }
        System.out.println(maxLen);
    }

}