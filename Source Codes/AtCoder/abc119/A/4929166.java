import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
//        int a = Integer.parseInt(scan.next());
//        int b = Integer.parseInt(scan.next());
        String b = scan.next();
        String ans = null;
        if(Integer.parseInt(b.replaceAll("/",""))>20190430){
            ans = "TBD";
        }else{
            ans = "Heisei";
        }
        PrintWriter out = new PrintWriter(System.out);
        out.println(ans);
        out.flush();
        scan.close();
    }
}