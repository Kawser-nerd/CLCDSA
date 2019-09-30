import java.util.*;
 
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean boo = false;
        while(n > 0){
            if(n % 4 == 0){
                boo = true;
                break;
            }
            else if(n % 7 == 0){
                boo = true;
                break;
            }
            else n -= 7;
        }
        if(boo) System.out.println("Yes");
        else System.out.println("No");
    }
}