import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] array = sc.nextLine().split("");
        int sum = 0;
        for (String s : array) {
            if (Integer.parseInt(s) == 1) {
                sum++;
            }
        }
        System.out.println(sum);
    }
}