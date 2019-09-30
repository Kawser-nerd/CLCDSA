import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);

        int a = Integer.parseInt(scan.next());
        int b = Integer.parseInt(scan.next());
        int count = 0;
        if(b%a == 0){
            count =  a+b;
        }else{
            count = b-a;
        }
        PrintWriter out = new PrintWriter(System.out);
        out.println(count);
        out.flush();
        scan.close();
    }
}