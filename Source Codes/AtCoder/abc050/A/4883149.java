import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();

        String[] formula = line.split(" ");
        if (formula[1].equals("+")) {
            System.out.println(new BigDecimal(formula[0]).add(new BigDecimal(formula[2])));
        }

        if (formula[1].equals("-")) {
            System.out.println(new BigDecimal(formula[0]).subtract(new BigDecimal(formula[2])));
        }


    }
}