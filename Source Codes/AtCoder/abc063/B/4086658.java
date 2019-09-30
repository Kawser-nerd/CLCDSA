import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        scan.close();
        String tmp = "";
        for (String c : s.split(""))
        {
            if (tmp.contains(c) == false)
                tmp += c;
        }
        System.out.println(s.length() == tmp.length() ? "yes" : "no");
    }
}