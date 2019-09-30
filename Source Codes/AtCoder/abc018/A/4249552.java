import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
      	int b = sc.nextInt();
      	int c = sc.nextInt();
      int x = 0;int y = 0; int z = 0;
      
      int[] s = {a, b, c};
      Arrays.sort(s);
      
      if(s[0]==a){x=3;} else if(s[1]==a){x=2;} else if(s[2]==a){x=1;}
      if(s[0]==b){y=3;} else if(s[1]==b){y=2;} else if(s[2]==b){y=1;}
      if(s[0]==c){z=3;} else if(s[1]==c){z=2;} else if(s[2]==c){z=1;}
      
      System.out.println(x);
      System.out.println(y);
      System.out.println(z);

    }
}