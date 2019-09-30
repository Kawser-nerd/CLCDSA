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
            Scanner in = new Scanner(new File("A-large.in"));
            PrintWriter out = new PrintWriter("A-large.out");

            //int tests = Integer.parseInt(in.nextLine());
            int tests = in.nextInt();
            
            for (int test = 1; test <= tests; test++) {
                String answer = "Case #" + test + ": ";
                int n = in.nextInt();
                int[] ps = new int[n];
                for(int i=0;i<n;i++){
                    int temp = in.nextInt();
                    ps[i] = temp;
                }
                
                int greatest = 1;
                int great = 0; 
                if(ps[0]>ps[1]){
                    greatest = 0;
                    great = 1;
                }
                
                
                for(int i=2;i<n;i++){
                    if(ps[greatest] < ps[i]){
                        great = greatest;
                        greatest = i;
                    }
                    else if(ps[great]< ps[i]) great = i;
                }
                
                while(ps[great]+1 < ps[greatest]){
                    answer += ((char)('A'+greatest)) + "" + ((char)('A'+greatest)) + " ";
                    ps[greatest] -= 2;
                }
                
                if(ps[great] < ps[greatest]){
                    answer += ((char)('A'+greatest)) + " ";
                    ps[greatest]--;
                }
                
                for(int i=0;i<n;i++){
                    if(i!=greatest && i!=great){
                        while(ps[i]>1){
                            answer += ((char)('A'+i)) + "" + ((char)('A'+i)) + " ";
                            ps[i]-=2;
                        }
                        if(ps[i]==1){
                            answer += ((char)('A'+i)) + " ";
                            ps[i]-=1;                            
                        }
                    }
                }
                for(int i=0;i<ps[greatest];i++) answer += ((char)('A'+greatest)) + "" + ((char)('A'+great)) + " ";
                
                out.println(answer);
            }
            in.close();
            out.close();
        } catch (FileNotFoundException ex) {
            System.out.println("ERROR");
        }

    }
    
}
