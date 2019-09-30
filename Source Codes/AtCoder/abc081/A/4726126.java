import java.util.Scanner;
public class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        String [] strArray = s.split("");
        int sum = 0;

        for (int i = 0; i < strArray.length; i++) {
            sum = sum + Integer.parseInt(strArray[i]);
        }
        
        System.out.println(sum);

    }
}