import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<String> n = Arrays.asList(sc.next().split(""));
        for (String str : n) {
            if ("9".equals(str)) {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }

}