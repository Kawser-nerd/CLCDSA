import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        System.out.print(n/3600<10?"0"+n/3600:n/3600);
        System.out.print(":");
        System.out.print(n%3600/60<10?"0"+n%3600/60:n%3600/60);
        System.out.print(":");
        System.out.println(n%60<10?"0"+n%60:n%60);
        
        
    }
    

}