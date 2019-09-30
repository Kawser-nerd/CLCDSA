import java.util.*;
public class MilkShakes {
  static int N,M,gustos[][];
  static boolean clientesSatisfechos[];
  static int preparacion[];
  static int mejorPreparacion[],costoMejorPreparacion;
  static Set<String> set=new TreeSet<String>();
  public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    for (int c=0,NC=sc.nextInt(); c<NC; c++) {
      N=sc.nextInt();
      M=sc.nextInt();
      gustos=new int[M][];
      clientesSatisfechos=new boolean[M];
      preparacion=new int[N];
      mejorPreparacion=null;
      costoMejorPreparacion=10000000;
      set.clear();
      for (int i=0; i<M; i++) {
        int T=sc.nextInt();
        gustos[i]=new int[T];
        for (int j=0; j<T; j++) {
          int X=sc.nextInt(),Y=sc.nextInt();
          gustos[i][j]=Y==0?X:-X;
        }
        Arrays.sort(gustos[i]);
      }
      recursion(0,0,0,"");
      if (mejorPreparacion==null) {
        System.out.println("Case #"+(c+1)+": IMPOSSIBLE");
      }
      else {
        String s=Arrays.toString(mejorPreparacion);
        System.out.println("Case #"+(c+1)+": "+s.replaceAll("\\[|\\,|\\]","").trim());
      }

/*
      int n=sc.nextInt();
      long a1[]=new long[n],a2[]=new long[n];
      for (int i=0; i<n; i++) a1[i]=sc.nextLong();
      for (int i=0; i<n; i++) a2[i]=sc.nextLong();
      Arrays.sort(a1);
      Arrays.sort(a2);
      long res=0;
      for (int i=0; i<n; i++) res+=a1[i]*a2[n-1-i];
      System.out.println("Case #"+(c+1)+": "+res);
*/
    }
  }
  static void recursion(int i, int cont, int satis, String s) {
    if (set.contains(s)) return;
    if (i==N) {
      if (satis!=M) return;
      if (cont<costoMejorPreparacion) {
        costoMejorPreparacion=cont;
        mejorPreparacion=(int[])(preparacion.clone());
      }
      set.add(s);
      return;
    }
    {
      List<Integer> list=new ArrayList<Integer>();
      int MA=-(i+1);
      preparacion[i]=1;
      for (int j=0; j<M; j++) if (!clientesSatisfechos[j]&&Arrays.binarySearch(gustos[j],MA)>=0) {clientesSatisfechos[j]=true; list.add(j);}
      recursion(i+1,cont+1,satis+list.size(),s+"1");
      for (int j:list) clientesSatisfechos[j]=false;
    }
    {
      List<Integer> list=new ArrayList<Integer>();
      int MA=i+1;
      preparacion[i]=0;
      for (int j=0; j<M; j++) if (!clientesSatisfechos[j]&&Arrays.binarySearch(gustos[j],MA)>=0) {clientesSatisfechos[j]=true; list.add(j);}
      recursion(i+1,cont,satis+list.size(),s+"0");
      for (int j:list) clientesSatisfechos[j]=false;
    }
    set.add(s);
 }
}
