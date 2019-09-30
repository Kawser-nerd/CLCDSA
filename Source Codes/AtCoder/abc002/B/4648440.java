import java.util.Scanner;
class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        String a = "";

        a = str.replace("a","");
        String b = a.replace("i","");
        String c = b.replace("u","");
        String d = c.replace("e","");
        String e = d.replace("o","");




 

        System.out.println(e);

    }

}