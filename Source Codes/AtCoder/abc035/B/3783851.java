import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int t = Integer.parseInt(scanner.nextLine());

        int x = 0;
        int y = 0;
        int questions = 0;

        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
                case '?':
                    questions++;
                    break;
            }
        }

        int distance = Math.abs(x) + Math.abs(y);
        if (t == 1) { // moving to max
            System.out.println(distance + questions);
        } else { // moving to min
            if (questions <= distance) {
                System.out.println(distance - questions);
            } else {
                System.out.println((questions - distance) % 2);
            }
        }
    }
}