import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.TreeSet;
import java.util.HashMap;
import java.util.Set;
import java.util.Deque;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeSet;

class Main{
    static boolean used[];
    static class Pos{
        int id;
        long x,y;
        Pos(int id,long x,long y ){this.id=id;this.x=x;this.y=y;}
    }
    static Map<Long, TreeSet<Pos>> xlist = new HashMap<>();
    static Map<Long, TreeSet<Pos>> ylist = new HashMap<>();
    static Map<Long, List<Long> > xarr = new HashMap<>();
    static Map<Long, List<Long> > yarr = new HashMap<>();
    static Set<Integer> use =new HashSet<>();
    static long D;
    static Deque<Pos> que = new ArrayDeque<>();
    static long ans = 0;

    static int getRange(List<Long> array, long left, long right){
        int res = 0;
        // left??right??
        // System.out.println(left+" "+right);
        // for(long l : array)System.out.print(l+" ");
        // System.out.println();
        // System.out.println();
        int ng=-1,ok=array.size();
        while(ok-ng>1){
            int i = (ng+ok)/2;
            if(array.get(i)<right+1)ng=i;
            else ok=i;
        }
        res = ok;
        ng=-1;ok=array.size();
        while(ok-ng>1){
            int i =(ng+ok)/2;
            if(array.get(i)<left)ng=i;
            else ok=i;
        }
        return res-ok;
    }

    static void chk(TreeSet<Pos> tset, boolean isX, Pos pos, List<Long> arr){
        if(isX)pos.x-=D;
        else pos.y-=D;
        while(true){
            Pos next = tset.ceiling(pos);
            if(next==null || (isX && next.x>pos.x+2*D) || (!isX && next.y>pos.y+2*D))break;
            if(use.add(next.id)){
                que.add(next);
            }
            tset.remove(next);
        }
        ans += (isX ? getRange(arr, pos.x, pos.x+2*D) : getRange(arr, pos.y, pos.y+2*D));
        if(isX)ans -= getRange(arr, pos.x, pos.x)+getRange(arr, pos.x+2*D, pos.x+2*D);
//        System.out.println(ans);
        if(isX)pos.x+=D;
        else pos.y+=D;
    }

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int aa = scan.nextInt()-1;
        int bb = scan.nextInt()-1;

        for(int i=0;i<N;++i){
            long xx = scan.nextLong();
            long yy = scan.nextLong();
            long x = xx+yy;
            long y = xx-yy;
            Pos pos = new Pos(i, x, y);

            if(i==aa || i==bb){
                use.add(i);
                que.add(pos);
            }

            if(!xlist.containsKey(y)){
                TreeSet<Pos> ts = new TreeSet<>((a,b) -> a.x==b.x ? 0:a.x-b.x<0 ? -1:1);
                xlist.put(y, ts);
            }
            xlist.get(y).add(pos);
            if(!ylist.containsKey(x)){
                TreeSet<Pos> ts = new TreeSet<>((a,b) -> a.y==b.y ? 0:a.y-b.y<0 ? -1:1);
                ylist.put(x, ts);
            }
            ylist.get(x).add(pos);

        }
        for(Map.Entry<Long, TreeSet<Pos>> entry : xlist.entrySet()){
            List<Long> list = new ArrayList<>();
            Iterator itr = entry.getValue().iterator();
            while(itr.hasNext()){
                list.add(((Pos)(itr.next())).x);
            }
            xarr.put(entry.getKey(), list);
        }

        for(Map.Entry<Long, TreeSet<Pos>> entry : ylist.entrySet()){
            List<Long> list = new ArrayList<>();
            Iterator itr = entry.getValue().iterator();
            while(itr.hasNext()){
                list.add(((Pos)itr.next()).y);
            }
            yarr.put(entry.getKey(), list);
        }

        D = Math.max(Math.abs(que.peekFirst().x - que.peekLast().x), Math.abs(que.peekFirst().y - que.peekLast().y));

        while(!que.isEmpty()){
            Pos pos = que.poll();
//            System.out.println("xlist : y+D");
            if(xlist.containsKey(pos.y+D))
                chk(xlist.get(pos.y+D), true, pos, xarr.get(pos.y+D));
//            System.out.println("xlist : y-D");
            if(xlist.containsKey(pos.y-D))
                chk(xlist.get(pos.y-D), true, pos, xarr.get(pos.y-D));
//            System.out.println("ylist : x-D");
            if(ylist.containsKey(pos.x-D))
                chk(ylist.get(pos.x-D), false, pos, yarr.get(pos.x-D));
//            System.out.println("ylist : x+D");
            if(ylist.containsKey(pos.x+D))
                chk(ylist.get(pos.x+D), false, pos, yarr.get(pos.x+D));
//            System.out.println("quEnd");
        }


        System.out.println(ans/2);
    }
}