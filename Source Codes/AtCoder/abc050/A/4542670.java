import java.util.Scanner;

public class Main{
    public static void main(String[] arg){
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        String op = in.next();
        int b = in.nextInt();
        
        if(op.equals("+")){
            System.out.print(a + b);
        }else if(op.equals("-")){
            System.out.print(a - b);
        }
    }
}