import java.util.*;
public class Main {
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		int a[]=new int[3];
      for(int i=0;i<3;i++)a[i]=sc.nextInt();
      if(a[0]>a[1]){
         if(a[0]>a[2]){
            System.out.println(1);
            if(a[1]>a[2]){System.out.println(2);System.out.println(3);}
            else{System.out.println(3);System.out.println(2);}
        }
        else {
        System.out.println(2);System.out.println(3);System.out.println(1);
        }
      }
      else{
          if(!(a[0]>a[2])){
            System.out.println(3);
            if(a[1]>a[2]){System.out.println(1);System.out.println(2);}
            else{System.out.println(2);System.out.println(1);}
        }
        else {
        System.out.println(2);System.out.println(1);System.out.println(3);
        }   
      }
	}
}