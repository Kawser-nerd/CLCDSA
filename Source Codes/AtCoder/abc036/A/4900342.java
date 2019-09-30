import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int a = Integer.parseInt(scan.next());
        int b = Integer.parseInt(scan.next());
        int ans = 0;
        if(b%a == 0){
            ans = b/a;
        }else if(a>b){
         ans = 1;
        }else{
            ans = b/a + 1;
        }

        PrintWriter out = new PrintWriter(System.out);
        out.println(ans);
        out.flush();
        scan.close();
    }
}