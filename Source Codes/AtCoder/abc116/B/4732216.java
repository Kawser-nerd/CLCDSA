import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int s = sc.nextInt();

        int i = 1;
        int a = s;
        HashSet<Integer> nums = new HashSet<>();
        nums.add(a);
        while (true) {
            i++;
            if (a % 2 == 0) {
                a /= 2;
            } else {
                a = 3 * a + 1;
            }
            if (nums.contains(a)) {
                System.out.println(i);
                return;
            }
            nums.add(a);
        }
    }
}