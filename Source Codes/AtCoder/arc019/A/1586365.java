import java.util.*;

public class Main {
    private static String s;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        s = scan.next();
    }

    public static void main(String args[]) {
        //??
        input();

        for (int i=0;i<s.length();i++){
            switch (s.charAt(i)){
                case 'O':s=s.replace('O' , '0');break;
                case 'D':s=s.replace('D' , '0');break;
                case 'I':s=s.replace('I' , '1');break;
                case 'Z':s=s.replace('Z' , '2');break;
                case 'S':s=s.replace('S' , '5');break;
                case 'B':s=s.replace('B' , '8');break;
                default:break;
            }
        }
        System.out.println(s);
    }
}