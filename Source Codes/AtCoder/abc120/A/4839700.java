import java.util.*;

class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int s = b / a;
        if(s > c){
            System.out.println(c);
        }else{
            System.out.println(s);
        }
            
        
    }
}