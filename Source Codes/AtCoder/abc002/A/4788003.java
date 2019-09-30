import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int a =scan.nextInt();
        int b =scan.nextInt();
        int answer = 0;
        if(a>b){
            answer = a;
        }else {
            answer = b;
        }
        PrintWriter out = new PrintWriter(System.out);
        out.println(answer);
        out.flush();
    }
}