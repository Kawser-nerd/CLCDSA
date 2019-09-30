import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int r = in.nextInt();
        System.out.println("A" + (r < 1200 ? "B" : (r < 2800 ? "R" : "G")) + "C");
        in.close();
    }
}