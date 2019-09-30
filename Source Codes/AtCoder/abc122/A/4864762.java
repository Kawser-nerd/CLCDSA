import java.util.Scanner;
class Main{

    public static void main(String args[]){
        Main main = new Main();
        main.start();
    }

    public void start(){
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        if(str.equals("A"))System.out.println("T");
        if(str.equals("T"))System.out.println("A");
        if(str.equals("C"))System.out.println("G");
        if(str.equals("G"))System.out.println("C");
    }


}