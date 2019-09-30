import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String x=s.next(); 
        int y=Integer.parseInt(x.substring(5,7));

        //System.out.println(y);
        
        if(y>4){
            System.out.println("TBD");
        }
        else{
            System.out.println("Heisei");
        }
    }  
}