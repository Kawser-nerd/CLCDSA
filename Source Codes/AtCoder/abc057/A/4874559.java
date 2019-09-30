import java.util.*;

class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        if(a+b<24){
        System.out.println(a+b);
        }else{
        System.out.println((a+b)%24);    
        }
    }
}