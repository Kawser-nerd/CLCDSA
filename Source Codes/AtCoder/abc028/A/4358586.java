import java.util.*;
public class Main{
	public static void main(String[]args){
    	Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        System.out.println((a>=60)?(a>=90)?(a==100)?"Perfect":"Great":"Good":"Bad");
    }
}