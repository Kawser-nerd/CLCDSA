import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        s = s.replaceAll("eraser" , "");
        s = s.replaceAll("erase", "");
        s = s.replaceAll("dreamer", "");
        s = s.replaceAll("dream", "");

        if(s.length() != 0) System.out.println("NO");
        else System.out.println("YES");
    }
}