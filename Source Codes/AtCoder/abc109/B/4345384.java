import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
      String s[] = new String[n];
     int flag1 = 0;
     int flag2 = 0;
      
      for(int i =0;i<n;i++){
        s[i]  = sc.next();
      if(i>0){
        if(s[i-1].charAt(s[i-1].length()-1)!=s[i].charAt(0)){
          flag1=1;
        }}
      }
		Arrays.sort(s);
      
      for(int i =1;i<n;i++){
        if(s[i-1].equals(s[i])){flag2=1;}
      }
      if(flag1==0&&flag2==0){System.out.print("Yes");}
      else{System.out.print("No");}
      
    }
}