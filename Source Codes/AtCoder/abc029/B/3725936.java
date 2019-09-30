import java.util.InputMismatchException;
import java.util.Scanner;
public class Main{

    
    public static void find (String [] str1,int n) {
        int i=0;
        int j=0;
        int count=0;
        while(i<n) {
            
            for(j=0;j<str1[i].length();j++)
            {
                if(str1[i].substring(j, j+1).equals("r"))
                {
                    count = count + 1 ;
                    break;
                }
            }
                   
            i++;
        }
        System.out.println(count);
        
        
    }
    
    public static void input() {
        Scanner sc = null;  
        try {
       sc = new Scanner(System.in);
            int i = 0;
            String str;
            String []str1 = new String[12];
            while (i < 12) {
              
                str = sc.next();
                str1[i] = str;
                i++;
            }

            find(str1,12);
        } catch (InputMismatchException e) {

        } finally {
        }
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub

        input();

    }

}