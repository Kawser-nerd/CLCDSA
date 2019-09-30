import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int value = sc.nextInt();
        if (value < 100) {
            System.out.println("00");

        } else if (100 <= value && value <= 5000) {
            System.out.println(adjustValue(value / 100));

        } else if (6000 <= value && value <= 30000) {
            System.out.println(value / 1000 + 50);

        } else if (35000 <= value && value <= 70000) {
            System.out.println((value / 1000 - 30) / 5 + 80);

        } else {
            System.out.println(89);

        }
    }


    static String adjustValue(int value) {
        if (10 > value) {
            return "0" + value;
        } else {
            return value + "";
        }
    }
}