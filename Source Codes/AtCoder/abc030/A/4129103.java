import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
      
      int ta = (b*100)/a;
      int ao = (d*100)/c;
    if(ta>ao){System.out.println("TAKAHASHI");}
    else if(ao>ta){System.out.println("AOKI");}
    else if(ta==ao){System.out.println("DRAW");}

    }
}