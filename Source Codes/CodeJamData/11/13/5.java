package r1a;

import java.util.*;

public class C {
  static class Card{
    int c , s , t;
    Card(int c , int s , int t){
      this.c = c;
      this.s = s;
      this.t = t;
    }
  }
  static int score(Card[] cards , int N , int draw){
    int turn = 1;
    boolean used[] = new boolean[cards.length];
    int hand = N;
    int nd   = 0;
    int score = 0;
    while(turn > 0){
      Card select = new Card(0 , 0 , 0);
      int si = -1;
      for(int i = 0 ; i < hand ; ++i){
        if(used[i])continue;
        Card ci = cards[i];
        if(ci.t > 0){
          select = ci;
          si = i;
          break;
        }else{
          if(nd < draw){
            if(select.c == 0 && ci.c == 1){
              select = ci;
              si = i;
            }else if(select.c == ci.c){
              if(select.s < ci.s){
                select = ci;
                si = i; 
              }
            }
          }else{
            if(select.s < ci.s){
              select = ci;
              si = i;
            }
          }
        }
      }
      if(si < 0)break;
//      System.out.println(draw+" "+select.c+" "+select.s+" "+select.t);
      used[si] = true;
      turn += select.t;
      hand = Math.min(cards.length, hand + select.c);
      nd += select.c;
      score += select.s;
      --turn;
    }
    return score;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int cn = 1 ; cn <= T ; ++cn){
      int N = sc.nextInt();
      List<Card> cards = new ArrayList<Card>();
      for(int i = 0 ; i < N ; ++i){
        Card c = new Card(sc.nextInt(), sc.nextInt(), sc.nextInt());
        cards.add(c);
      }
      int M = sc.nextInt(); 
      for(int i = 0 ; i < M ; ++i){
        Card c = new Card(sc.nextInt(), sc.nextInt(), sc.nextInt());
        cards.add(c);
      }
      int ms = 0;
      Card[] cs = cards.toArray(new Card[0]);
      for(int draw = 0 ; draw <= M ; ++draw){
        int s = score(cs , N , draw);
        ms = Math.max(ms, s);
      }
      System.out.printf("Case #%d: %d\n", cn , ms);
    }
  }
}
