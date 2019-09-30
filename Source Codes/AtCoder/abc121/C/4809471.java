/*
  comparator(?)?????????
  ????3?long?????????int????????????
  ???
   site:??SE????
   page:Java?Comparator????????????
   --?????????????3?????
  ???
   page:Java Collections - Comparator.comparingLong() Examples
*/

import java.util.*;
public class Main{
  public static void main(String[] args){
    Main r = new Main();
    r.run();
  }
  private void run() {
    //??
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();

    //?????(????)????????
    Drink[] dr = new Drink[n];
    for(int i=0; i<n; ++i)
      dr[i] = new Drink(sc.nextLong(), sc.nextInt());

    //?????????????
    Arrays.sort(dr, Comparator.comparingLong(Drink::geta));

    //M??????
    int cnt=0;
    long ans=0;
    for(int i=0; i<n; ++i) {
      if(dr[i].getb()+cnt <= m) {
        cnt += dr[i].getb();
        ans += dr[i].geta() * dr[i].getb();
      }
      else {
        ans += dr[i].geta() * (m-cnt);
        break;
      }
    }
    System.out.println(ans);

  }
  //?????(????)
  private class Drink {
    private long a; //??
    private int b;  //??
    public Drink(long a, int b){
      this.a=a;
      this.b=b;
    }
    public long geta(){ return a;}
    public int getb(){ return b;}
  }
}
/*???

//?????
for(int i=0; i<n; ++i)
  System.out.println(dr[i].geta() +" "+dr[i].getb());

*/