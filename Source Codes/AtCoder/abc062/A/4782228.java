import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int x = sc.nextInt();
        int y = sc.nextInt();

        Integer[] a = {1,3,5,7,8,10,12};
        Integer[] b = {4,6,9,11};
        Integer[] c = {2};

        if ((Arrays.asList(a).contains(x) && Arrays.asList(a).contains(y)) || (Arrays.asList(b).contains(x) && Arrays.asList(b).contains(y)) || (Arrays.asList(c).contains(x) && Arrays.asList(c).contains(y))) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}