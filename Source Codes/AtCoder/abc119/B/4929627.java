import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);

        int c = Integer.parseInt(scan.next());
        scan.nextLine();
        double yourfortune = 0;
        double btcprice = 380000.0;

        for(int i = 0;i<c;i++){
            double a = 0;
            a = Double.parseDouble(scan.next());
            String b = null;
            if(scan.hasNext()){
                 b = scan.next();
            }else{
                 b = "";
            }
                if(b.equals("JPY")){
                yourfortune += a;
            }else{
                yourfortune += (a*btcprice);
            }
        }
//        Double a = Double.parseDouble(scan.next());
////        int b = Integer.parseInt(scan.next());
//        String b = scan.next();
        String ans = null;
        PrintWriter out = new PrintWriter(System.out);
        out.println(yourfortune);
        out.flush();
        scan.close();
    }
}