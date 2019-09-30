import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> d = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            d.add(sc.nextInt());
        }
        List<Integer> steps = d.stream().distinct().collect(Collectors.toList());
        System.out.println(steps.size());
    }
}