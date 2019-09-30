import java.io.*;
import java.util.*;

public class cookie {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("cookie.in"));
        
        int a = Integer.parseInt(in.nextLine());
        
        for(int i = 0; i < a; i++) {
            String str = in.nextLine();
            double cost = Double.parseDouble(str.substring(0, str.indexOf(" ")));
            double rate = Double.parseDouble(str.substring(str.indexOf(" ") + 1, str.lastIndexOf(" ")));
            double goal = Double.parseDouble(str.substring(str.lastIndexOf(" ") + 1));
            
            double mintime = goal/2;
            double temptime = 0;
            double cps = 2;
            for(int j = 0; j < 1000001; j++) {//j = number of current farms
                temptime += cost/cps;
                cps += rate;
                mintime = Math.min(mintime, temptime + goal/cps);
            }
            
            System.out.printf("Case #%s: %.7f%n", i + 1 + "", mintime);
        }
    }
}