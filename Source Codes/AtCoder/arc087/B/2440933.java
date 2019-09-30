import java.util.*;

public class Main{
	static Scanner s=new Scanner(System.in);
	static int gInt(){
		return Integer.parseInt(s.next());
	}
	public static void main(String[]$){
		String v=s.next();
		int x=gInt(),y=gInt();

		ArrayList<Integer> dx=new ArrayList<>(),dy=new ArrayList<>();

		boolean dir=true;
		int d=0;
		for(int i=0;i<v.length();i++){
			if(v.charAt(i)=='T'){
				(dir?dx:dy).add(d);
				d=0;
				dir^=true;
			}else{
				d++;
			}
		}
		(dir?dx:dy).add(d);

		x-=dx.remove(0);
		System.out.println(dp(dx,x)&&dp(dy,y)?"Yes":"No");
	}

	static boolean dp(List<Integer> list,int goal){
		Set<Integer> set=new HashSet<>(),buf=new HashSet<>();
		set.add(0);

		for(int v:list){
			buf.clear();
			for(int base:set){
				buf.add(base+v);
				buf.add(base-v);
			}
			set.clear();
			set.addAll(buf);
		}

		return set.contains(goal);
	}
}