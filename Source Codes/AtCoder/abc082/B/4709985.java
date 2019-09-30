import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        Arrays.sort(s);
        String sortedS = String.valueOf(s);

        char[] t = sc.next().toCharArray();
        Arrays.sort(t);
        String sortedT = String.valueOf(t);
        String sortedTDesc = new StringBuilder(sortedT).reverse().toString();

        if (sortedS.compareTo(sortedTDesc) < 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

}