import java.util.*;

/**
 * Created by ryosuke on 2017/03/29.
 */
public class Main {
    public static void main(String arf[]) {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.valueOf(scanner.nextLine());
        String command = scanner.nextLine();

        int min = Integer.MAX_VALUE;
        String[] button = {"A", "B", "X", "Y"};

        for (int i = 0; i < button.length; i++) {
            for (int j = 0; j < button.length; j++) {
                for (int k = 0; k < button.length; k++) {
                    for (int l = 0; l < button.length; l++) {
                        String shortA = button[i] + button[j];
                        String shortB = button[k] + button[l];
                        String tmpA = command.replace(shortA, "L").replace(shortB, "R");
                        String tmpB = command.replace(shortB, "L").replace(shortA, "R");
                        min = Math.min(min, Math.min(tmpA.length(), tmpB.length()));
                    }
                }
            }
        }

        System.out.println(min);

    }
}