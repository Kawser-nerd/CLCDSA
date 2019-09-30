package r1a;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class B {
  static int solve(String w , String L , String[] D){
    char ws[] = w.toCharArray();
    boolean reveal[] = new boolean[ws.length];
    List<String> list = new LinkedList<String>();
    for(int i = 0 ; i < D.length ; ++i){
      if(D[i].length() != ws.length)continue;
      list.add(D[i]);
    }
    int ret = 0;
    for(char c : L.toCharArray()){
      boolean skip = true;
      for(String s: list){
        for(int i = 0 ; i < s.length() ; ++i){
          if(s.charAt(i) == c){
            skip = false;
          }
        }        
      }
      if(skip)continue;
//      System.out.println(c+ " "+list+" "+ret);
      boolean isRev = false;
      for(int i = 0 ; i < reveal.length ; ++i){
        if(ws[i] == c){
          isRev = true;
          reveal[i] = true;
        }
      }
      if(!isRev)++ret;
      Iterator<String> it = list.iterator();
      while(it.hasNext()){
        String s = it.next();
        boolean valid = true;
        for(int i = 0 ; i < reveal.length ; ++i){
          char si = s.charAt(i);
          if(si == c){
            if(!reveal[i]){
              valid = false;
              break;              
            }           
          }
          if(reveal[i] && ws[i] != s.charAt(i)){
            valid = false;
            break;            
          }
        }
        if(!valid){
          it.remove();
        }
      }
    }
//    System.out.println(w+" "+L+" "+ret);
    return ret;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int cn = 1 ; cn <= T ; ++cn){
      int N = sc.nextInt();
      int M = sc.nextInt();
      String D[] = new String[N];
      for(int i = 0 ; i < N ; ++i){
        D[i] = sc.next();
      }
      System.out.printf("Case #%d:", cn);
      for(int i = 0 ; i < M ; ++i){
        String L = sc.next();
        int maxScore = Integer.MIN_VALUE;
        String ret = "";
        for(String w : D){
          int score = solve(w, L, D);
          if(score > maxScore){
            maxScore = score;
            ret = w;
          }
        }
        System.out.print(" " + ret);
      }
      System.out.println();
    }
  }
}
