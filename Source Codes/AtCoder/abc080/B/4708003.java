import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int inputNumber = sc.nextInt();
        int tmp = inputNumber, addedNumber = 0;
        while(tmp > 0) {
            addedNumber += tmp % 10;
            tmp /= 10;
        }

        if (inputNumber % addedNumber == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

}