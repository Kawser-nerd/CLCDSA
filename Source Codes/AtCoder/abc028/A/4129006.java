import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
 
		if(x<60){System.out.println("Bad");}
        else if(x>=60&&x<90){System.out.println("Good");}
        else if(x>=90&&x<100){System.out.println("Great");}
        else if(x==100){System.out.println("Perfect");}
  
    }
}