import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        System.out.println(str
            .replace("Left", "<")
            .replace("Right", ">")
            .replace("AtCoder", "A"));
        
    }
}