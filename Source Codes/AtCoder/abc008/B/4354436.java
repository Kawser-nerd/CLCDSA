import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] args){
    try {
      Scanner sc = new Scanner(System.in);
      int n;

      n=Integer.parseInt(sc.next());
      String[] s = new String[n];
      int[] v = new int[n];

      for(int i=0; i<n; i++){
        v[i]=0;
      }

      for(int i=0; i<n; i++){
        s[i]=sc.next();
        for(int j=0; j<=i; j++){
          if(s[i].equals(s[j])){
            v[j]++;
            break;
          }
        }
      }

      int ans=0;
      for(int i=1; i<n; i++){
        if(v[ans]<v[i]){
          ans=i;
        }
      }

      System.out.println(s[ans]);
      
    
      }catch (Exception e) {
      System.out.println("out");
    }
  }
}