package codejamquestion;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Canberk
 */

public class CodeJamQuestion {

    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("C-large.in"));
            PrintWriter out = new PrintWriter("C-large.out");

            //int tests = Integer.parseInt(in.nextLine());
            int tests = in.nextInt();
            
            for (int test = 1; test <= tests; test++) {
                String answer = "Case #" + test + ": ";
                String outfits = "";
                int days = 0;
                
                int J = in.nextInt();
                int P = in.nextInt();
                int S = in.nextInt();
                int k = in.nextInt();
                
                for(int j=1;j<=J;j++){
                    for(int p=1;p<=P;p++){
                        for(int i=0; i<S && i<k;i++){
                            outfits += j + " " + p + " " + (((i+p+j)%S) + 1) + "\n";
                            days++;
                        }
                    }
                }
                answer += days +"\n"+outfits;
                
                
                out.println(answer);
            }
            in.close();
            out.close();
        } catch (FileNotFoundException ex) {
            System.out.println("ERROR");
        }

    }
    
}
