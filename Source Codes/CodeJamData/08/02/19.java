package qround;

import java.util.*;

class Event implements Comparable<Event>{
  final static int DEPART = 1;
  final static int ARRIVE = 0;
  int kind;  
  int time;
  Event(int k , int t){
    kind = k;
    time = t;
  }
  public int compareTo(Event o) {
    if(time == o.time){
      return kind - o.kind;
    }
    return time - o.time;
  }
}
public class B {
  static int toI(String str){
    return Integer.parseInt(str.substring(0, 2)) * 60 
      + Integer.parseInt(str.substring(3));
  }
  public static void main(String[] args) {
    Scanner sc = new  Scanner(System.in);
    int N = sc.nextInt();
    for(int i = 1 ; i<= N ; i++){
      int T = sc.nextInt();
      int na = sc.nextInt();
      int nb = sc.nextInt();
      List<Event> ea = new ArrayList<Event>();
      List<Event> eb = new ArrayList<Event>();
      for(int j = 0 ; j < na ; j++){
        int depart = toI(sc.next());
        int arrive = toI(sc.next());
        ea.add(new Event(Event.DEPART , depart));
        eb.add(new Event(Event.ARRIVE , arrive + T));
      }      
      for(int j = 0 ; j < nb ; j++){
        int depart = toI(sc.next());
        int arrive = toI(sc.next());
        eb.add(new Event(Event.DEPART , depart));
        ea.add(new Event(Event.ARRIVE , arrive + T));
      }
      Collections.sort(ea);
      Collections.sort(eb);
      int ra = number(ea);
      int rb = number(eb);
      System.out.printf("Case #%d: %d %d\n" , i , ra , rb);
    }
  }
  static int number(List<Event> es){
    int count = 0;
    int stock = 0;
    for(Event e : es){
      if(e.kind == Event.ARRIVE){
        stock++;
      }else{
        if(stock > 0)stock--;
        else count++;
      }
    }
    return count;
  }
}
