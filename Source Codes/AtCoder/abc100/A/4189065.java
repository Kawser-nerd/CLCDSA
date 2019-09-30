import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        System.out.println(reader.nextInt() <= 8 && reader.nextInt() <= 8 ? "Yay!" : ":(");
        reader.close();
    }
}