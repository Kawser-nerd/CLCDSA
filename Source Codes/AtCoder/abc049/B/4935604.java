import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h=sc.nextInt();
        sc.nextInt();
        String tmp;
        for(int i=0;i<h;i++){
            tmp=sc.next();
            for(int j=0;j<2;j++)System.out.println(tmp);
        }
    }
    
 
}