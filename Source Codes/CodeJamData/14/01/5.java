import java.io.*;
import java.util.*;

public class magic {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("magic.in"));
        
        int a = Integer.parseInt(in.nextLine());
        for(int i = 0; i < a; i++) {
            int row = Integer.parseInt(in.nextLine());
            ArrayList<String> str = new ArrayList<String>();
            HashMap<String, Integer> rows = new HashMap<String, Integer>();
            for(int j = 1; j < 5; j++) {
                String[] arr = in.nextLine().split(" ");
                for(String s : arr) {
                    rows.put(s, j);
                    str.add(s);
                }
            }
            int row2 = Integer.parseInt(in.nextLine());
            HashMap<String, Integer> rows2 = new HashMap<String, Integer>();
            for(int j = 1; j < 5; j++) {
                String[] arr = in.nextLine().split(" ");
                for(String s : arr) {
                    rows2.put(s, j);
                }
            }
            ArrayList<String> sols = new ArrayList<String>();
            for(String s : str) {
                if(rows.get(s) == row && rows2.get(s) == row2) {
                    sols.add(s);
                }
            }
            if(sols.size() == 0) {
                System.out.println("Case #" + (i + 1) + ": Volunteer cheated!");
            }
            else {
                if(sols.size() == 1) {
                    System.out.println("Case #" + (i + 1) + ": " + sols.get(0));
                }
                else {
                    System.out.println("Case #" + (i + 1) + ": Bad magician!");
                }
            }
        }
    }
}