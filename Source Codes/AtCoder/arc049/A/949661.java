import java.util.Scanner;

/**
 *
 * @author c0115334
 */
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        String strings[] = s.split("");        
        int a = scan.nextInt();
        int b = scan.nextInt();
        int c = scan.nextInt();
        int d = scan.nextInt();
        String result = "";
        for (int i = 0; i < s.length(); i++) {
            if (i==a || i==b || i==c || i==d) {
                result += "\"";
            }

            result += strings[i];
        }
        if (s.length() == d) {
            result += "\"";
        }
        System.out.println(result);
    }    
}