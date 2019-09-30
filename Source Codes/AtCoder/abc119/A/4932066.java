import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.ResolverStyle;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
//        long startTime = System.currentTimeMillis();
        Scanner scanner = new Scanner(System.in);

        String S = scanner.next();
        scanner.close();

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy/MM/dd");
        formatter.withResolverStyle(ResolverStyle.LENIENT);

        LocalDate tDate = LocalDate.parse("2019/04/30", formatter);
        LocalDate ldt = LocalDate.parse(S, formatter);

        if (ldt.isEqual(tDate) || ldt.isBefore(tDate)) {
            System.out.println("Heisei");
        } else {
            System.out.println("TBD");
        }
//        System.out.println(System.currentTimeMillis() - startTime);
    }
}