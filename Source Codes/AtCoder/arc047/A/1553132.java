import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), l = in.nextInt(); in.nextLine();
        String s = in.next();
        int tab = 1, ans = 0;
        for(char c : s.toCharArray()){
            if(c == '+') tab++;
            if(c == '-') tab--;
            if(tab > l){
                tab = 1;
                ans++;
            }
        }
        System.out.println(ans);
    }
}