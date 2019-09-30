import java.util.Scanner;

public class Main {
static int ans,N;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s=sc.nextLine();
        String S[]=s.split("");
        s="";
        for(int i=0;i<S.length;i++) {
        	s+=10-Integer.parseInt(S[i]);
        }
System.out.println(s);
        }
    }