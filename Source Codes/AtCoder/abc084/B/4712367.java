import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        char[] postcode = sc.next().toCharArray();
        for (int i = 0; i < a + b + 1; i++) {
            if(i == a && !String.valueOf(postcode[i]).equals("-")) {
                System.out.println("No");
                System.exit(0);
            }
            if(i != a && 0 > Character.getNumericValue(postcode[i]) || Character.getNumericValue(postcode[i]) > 9) {
                System.out.println("No");
                System.exit(0);
            }
        }
        System.out.println("Yes");
    }
}