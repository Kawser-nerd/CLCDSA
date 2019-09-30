import java.util.*;

public class Main {
    private static int n;
    private static String command;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        n = scan.nextInt();
        command = scan.next();

    }

    public static void main(String args[]) {
        //??
        input();

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