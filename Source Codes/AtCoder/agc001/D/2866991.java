import java.util.*;
class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    int N = scan.nextInt();
    int M = scan.nextInt();
    List<Integer> odd = new ArrayList<>();
    List<Integer> even = new ArrayList<>();
    for(int i=0;i<M;++i){
      int a = scan.nextInt();
      if(a%2==0)even.add(a);
      else odd.add(a);
    }
    if(odd.size()>2){
      System.out.println("Impossible");
      return;
    }
    List<Integer> ans = new ArrayList<>();
    if(odd.size()>=1){
      int d = odd.remove(0);
      System.out.print(d+" ");
      while(d>1){
        ans.add(2);
        d-=2;
      }
    }else{
      int d = even.remove(0);
      System.out.print(d+" ");
      ans.add(d-1);
    }
    for(int i=0;i<even.size();++i){
      ans.add(even.get(i));
      System.out.print(even.get(i)+" ");
    }
    if(odd.size()>=1){
      int d = odd.remove(0);
      System.out.print(d+" ");
      while(d>0){
        ans.add(2);
        d-=2;
      }
    }else{
      ans.add(1);
    }
    System.out.println();
    System.out.println(ans.size());
    for(int i : ans)System.out.print(i+" ");
    System.out.println();
  }
}