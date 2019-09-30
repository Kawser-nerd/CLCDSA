public class Main{
 	public static void main(String args[]){
     int num = new java.util.Scanner(System.in).nextInt();
     String str = "NO";
     
     if(num == 3 || num == 5 || num == 7){
       str = "YES";
     }
      
     System.out.println(str);
      
    }
}