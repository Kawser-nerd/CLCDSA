import java.util.Scanner;

class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.next());
        String command = scanner.next();

        String[] button = {"A", "B", "X", "Y"};
        int min = Integer.MAX_VALUE;

        for (int i = 0; i < button.length; i++) {
            for (int j = 0; j < button.length; j++) {
                for (int k = 0; k < button.length; k++) {
                    for (int l = 0; l < button.length; l++) {
                        String shortA = button[i] + button[j];
                        String shortB = button[k] + button[l];
                        String tempA = command.replace(shortA, "L").replace(shortB, "R");
                        String tempB = command.replace(shortB, "L").replace(shortA, "R");
                        min = Math.min(min, Math.min(tempA.length(), tempB.length()));
                    }
                }
            }
        }
        System.out.println(min);
    }
}