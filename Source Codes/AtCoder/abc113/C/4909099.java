import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int po[]=new int[n+1];
        ArrayList<Po>array=new ArrayList<>();
        for(int i=0;i<m;i++)
            array.add(new Po(sc.nextInt(),sc.nextInt(),i));
        array.sort(new Comparator<Po>() {
					public int compare(Po a, Po b) {
						return a.value - b.value;
					}
				});
        for(int i=0;i<array.size();i++){
            po[array.get(i).place]++;
            array.get(i).make(String.format("%012d",((long)1000000*array.get(i).place)+po[array.get(i).place]));
        }
        array.sort(new Comparator<Po>() {
					public int compare(Po a, Po b) {
						return a.index - b.index;
					}
				});
				for(int i=0;i<array.size();i++){
				    System.out.println(array.get(i).id);
        }
    }
    static class Po{
        int value;
        int place;
        int index;
        String id;
        public Po(int a,int b,int i){
            place=a;
            index=i;
            value=b;
        }
        public void make(String po){
            id=po;
        }
    }
}