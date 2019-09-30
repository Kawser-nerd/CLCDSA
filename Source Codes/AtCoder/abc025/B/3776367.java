import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] line = scanner.nextLine().split(" ", 3);
        int n = Integer.parseInt(line[0]);
        int a = Integer.parseInt(line[1]);
        int b = Integer.parseInt(line[2]);

        // West => +

        int position = 0;
        for (int i = 0; i < n; i++) {
            line = scanner.nextLine().split(" ", 2);
            int distance = Integer.parseInt(line[1]);
            if (distance < a) {
                distance = a;
            } else if (distance > b) {
                distance = b;
            }

            String direction = line[0];
            if (direction.equals("West")) {
                position += distance;
            } else {
                position -= distance;
            }
        }

        if (position == 0) {
            System.out.println("0");
        } else if (position > 0) {
            System.out.printf("West %d\n", position);
        } else {
            System.out.printf("East %d\n", position * -1);
        }
    }
}