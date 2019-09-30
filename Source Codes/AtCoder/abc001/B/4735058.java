import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        try (Scanner sc = new Scanner(System.in)) {
            while (sc.hasNextInt()) {
                int a = Integer.parseInt(sc.nextLine());
                int VV = 0;
                if(a>=100&&a<=5000){
                    VV = a * 10;
                }else if(a>=6000&&a<=30000){
                  VV = a + 50000;
                }else if(a>=35000&&a<=70000){
                  VV = (a - 30000) / 5 + 80000;
                }else if(a>70000){
                  VV = 89000;
                }
                System.out.println(String.format("%02d", VV/1000));
            }
        }
    }
}