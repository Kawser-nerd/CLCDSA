import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String probCount = scanner.nextLine();
        String[] timesList = scanner.nextLine().split(" ");
        Integer drinkCount = new Integer(scanner.nextLine());

        IntStream.range(0, drinkCount).forEach(i -> {
            String[] pair = scanner.nextLine().split(" ");
            Integer nProb = new Integer(pair[0]);
            String nTime = pair[1];

            String[] copiedList = new String[timesList.length];
            System.arraycopy(timesList, 0, copiedList, 0, timesList.length);

            copiedList[nProb - 1] = nTime;

            System.out.println(addTimes(copiedList));
        });



    }
    private static Integer addTimes(String[] timesList) {
        Integer sum = 0;
        for (int i = 0; i < timesList.length; i++ ) {
            sum = sum + new Integer(timesList[i]);
        }
        return sum;
    }
}