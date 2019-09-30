import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt();
        int[] salary = new int[n];
        List<Integer>[] list = IntStream.range(0, n).mapToObj(i -> new ArrayList<>()).toArray(List[]::new);
        for (int i = 1; i < n; i++)
            list[scanner.nextInt() - 1].add(i);

        boolean flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < n; i++) {
                int[] array = list[i].stream().mapToInt(j -> salary[j]).toArray();
                if (salary[i] == 0 && Arrays.stream(array).noneMatch(j -> j == 0)) {
                    flag = true;
                    salary[i] = Arrays.stream(array).min().orElse(0) + Arrays.stream(array).max().orElse(0) + 1;
                }
            }
        }
        System.out.println(salary[0]);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.