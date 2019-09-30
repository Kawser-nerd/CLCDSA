import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc= new Scanner(System.in);
        int num = sc.nextInt();

        if(num % 2 == 0){
            System.out.println(num);
        }else
            System.out.println(num*2);
    }
}