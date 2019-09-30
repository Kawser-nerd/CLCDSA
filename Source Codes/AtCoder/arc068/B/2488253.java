import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);
        int kind = 1;
        for (int i = 1; i < n; i++) {
            kind += a[i - 1] == a[i] ? 0 : 1;
        }
        System.out.println(kind - (kind%2==1? 0 : 1));
    }
}