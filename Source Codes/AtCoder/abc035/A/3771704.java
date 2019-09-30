import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        String[] line = new Scanner(System.in).nextLine().split(" ", 2);
        int w = Integer.parseInt(line[0]);
        int h = Integer.parseInt(line[1]);
        if (w * 3 == h * 4) {
            System.out.println("4:3");
        } else {
            System.out.println("16:9");
        }
    }
}