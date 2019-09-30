import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		
		int kleft=1,kright=10;
		while(kleft<kright){
			int kmin=(kleft+kright)/2+(kleft==(kright-1)?1:0);
			int v=1;
			for(int i=0;i<kmin-1;i++) v*=10;
			
			System.out.println("? "+v);
			String respond=sc.next();
			if(respond.equals("Y")){
				kleft=kmin;
			}else{
				kright=kmin-1;
			}
		}
		
		if(kleft==10){
			long dam=2;
			for(int i=0;i<10;i++){
				System.out.println("? "+dam);
				if(sc.next().equals("Y")){
					System.out.println("! "+(dam/2));
					return;
				}
				dam*=10;
			}
		}
		int keta=kleft;
		if(keta==1){
			sol(sc,1,0);
			return;
		}
		int sleft=1,sright=9;
		while(sleft<sright){
			int smid=(sleft+sright)/2+(sleft==(sright-1)?1:0);
			long v=smid;
			for(int i=0;i<keta-2;i++) v*=10;
			
			System.out.println("? "+v);
			String respond=sc.next();
			if(respond.equals("Y")){
				sleft=smid;
			}else{
				sright=smid-1;
			}
		}
		
		int oom=sleft;
		for(int i=0;i<keta-1;i++) oom*=10;
		sol(sc,keta-1,oom);
	}
	static void sol(Scanner sc,int keta,long oom){
		if(keta==0){
			System.out.println("! "+oom);
			return;
		}
		if(keta==1){
			int kag=(oom==0)?1:0;
			for(int i=kag;i<=9;i++){
				System.out.println("? "+((oom+i)*10));
				String respond=sc.next();
				if(respond.equals("Y")){
					System.out.println("! "+(oom+i));
					return;
				}
			}
		}
		
		int sleft=0,sright=9;
		while(sleft<sright){
			int smid=(sleft+sright)/2+(sleft==(sright-1)?1:0);
			long v=smid;
			for(int i=0;i<keta-1;i++) v*=10;
			
			System.out.println("? "+((v+oom)/10));
			String respond=sc.next();
			if(respond.equals("Y")){
				sleft=smid;
			}else{
				sright=smid-1;
			}
		}
		
		int oom2=sleft;
		for(int i=0;i<keta-1;i++) oom2*=10;
		sol(sc,keta-1,oom+oom2);
	}
}