import java.util.Scanner;

/**
 * Created by zzt on 17-1-16.
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        s = s.replaceAll("eraser", "");
        s = s.replaceAll("erase", "");
        s = s.replaceAll("dreamer", "");
        s = s.replaceAll("dream", "");

        System.out.println(s.length()>0?"NO":"YES");
    }
}