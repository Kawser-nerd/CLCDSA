import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
      String n=sc.nextLine();
      System.out.println((n.equals("a")||n.equals("i")||n.equals("u")||n.equals("e")||n.equals("o"))?"vowel":"consonant");
    }
}