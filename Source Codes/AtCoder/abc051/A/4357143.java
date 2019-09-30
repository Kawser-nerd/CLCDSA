import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        //System.out.println("s = " + s);
        
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == ','){
                System.out.print(" ");
            }else{
                System.out.print(s.charAt(i));
            }
        }
        System.out.println();
    }
}