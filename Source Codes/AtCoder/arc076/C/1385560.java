import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int R = sc.nextInt();
    int C = sc.nextInt();
    int N = sc.nextInt();
    ArrayList<Vertice> alist = new ArrayList<Vertice>();
    ArrayList<Vertice> blist = new ArrayList<Vertice>();
    ArrayList<Vertice> clist = new ArrayList<Vertice>();
    ArrayList<Vertice> dlist = new ArrayList<Vertice>();
    for(int i = 0; i < N; i++) {
      int x1 = sc.nextInt();
      int y1 = sc.nextInt();
      int x2 = sc.nextInt();
      int y2 = sc.nextInt();
      if(((x1 == 0) || (x1 == R) || (y1 == 0) || (y1 == C)) && ((x2 == 0) || (x2 == R) || (y2 == 0) || (y2 == C))) {
        Vertice v1 = new Vertice(i, x1, y1);
        Vertice v2 = new Vertice(i, x2, y2);
        if((x1 == 0) && (y1 < C)) alist.add(v1);
        if((x1 < R) && (y1 == C)) blist.add(v1);
        if((x1 == R) && (y1 > 0)) clist.add(v1);
        if((x1 > 0) && (y1 == 0)) dlist.add(v1);

        if((x2 == 0) && (y2 < C)) alist.add(v2);
        if((x2 < R) && (y2 == C)) blist.add(v2);
        if((x2 == R) && (y2 > 0)) clist.add(v2);
        if((x2 > 0) && (y2 == 0)) dlist.add(v2);
      }
    }
    Collections.sort(alist, new Comparator<Vertice>() {
      public int compare(Vertice vertice1, Vertice vertice2) {
	return vertice1.y - vertice2.y;
      }
    });
    Collections.sort(blist, new Comparator<Vertice>() {
      public int compare(Vertice vertice1, Vertice vertice2) {
	return vertice1.x - vertice2.x;
      }
    });
    Collections.sort(clist, new Comparator<Vertice>() {
      public int compare(Vertice vertice1, Vertice vertice2) {
	return vertice2.y - vertice1.y;
      }
    });
    Collections.sort(dlist, new Comparator<Vertice>() {
      public int compare(Vertice vertice1, Vertice vertice2) {
	return vertice2.x - vertice1.x;
      }
    });
    String ans = "YES";
    Stack<Integer> st = new Stack<Integer>();
    int[] count = new int[N];
    for(int i = 0; i < alist.size(); i++) {
      Vertice v = alist.get(i);
      if(count[v.id] == 0) {
        st.push(v.id);
        count[v.id]++;
      } else {
        int p = st.pop();
        if(v.id != p) {
          ans = "NO";
          break;
        }
      }
    }

    for(int i = 0; i < blist.size(); i++) {
      Vertice v = blist.get(i);
      if(count[v.id] == 0) {
        st.push(v.id);
        count[v.id]++;
      } else {
        int p = st.pop();
        if(v.id != p) {
          ans = "NO";
          break;
        }
      }
    }

    for(int i = 0; i < clist.size(); i++) {
      Vertice v = clist.get(i);
      if(count[v.id] == 0) {
        st.push(v.id);
        count[v.id]++;
      } else {
        int p = st.pop();
        if(v.id != p) {
          ans = "NO";
          break;
        }
      }
    }

    for(int i = 0; i < dlist.size(); i++) {
      Vertice v = dlist.get(i);
      if(count[v.id] == 0) {
        st.push(v.id);
        count[v.id]++;
      } else {
        int p = st.pop();
        if(v.id != p) {
          ans = "NO";
          break;
        }
      }
    }
    
    System.out.println(ans);    
  }

  static class Vertice {
    int id;
    int x;
    int y;
  
    public Vertice(int id, int x, int y) {
      this.id = id;
      this.x = x;
      this.y = y;
    }
  }
}