import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		HashMap<Long,Integer> map=new HashMap<>();
		for(int i=0;i<n;i++){
			long a=sc.nextInt(), b=sc.nextInt(),c=sc.nextInt(),d=sc.nextInt();
			long hash=getHash(a,b,c,d);
			if(map.containsKey(hash)){
				map.put(hash,map.get(hash)+1);
			}else{
				map.put(hash,1);
			}
		}
		//System.out.println(map);
		Long[] ks=map.keySet().toArray(new Long[map.size()]);
		long res=0;
		for(int i=0;i<ks.length;i++){
			for(int j=i;j<ks.length;j++){
				long coef=0;
				long hai=ks[i],haj=ks[j];
				if(i==j){
					long kosu=map.get(ks[i]);
					coef=(kosu-1)*kosu/2;
				}else{
					coef=map.get(ks[i])*map.get(ks[j]);
				}
				if(coef==0)continue;
				map.put(hai,map.get(hai)-1);
				map.put(haj,map.get(haj)-1);
				long te=0;
				te+=sol(hai,haj,map);
				haj=(haj%1000000000)*1000+haj/1000000000;//ratation
				te+=sol(hai,haj,map);
				haj=(haj%1000000000)*1000+haj/1000000000;//ratation
				te+=sol(hai,haj,map);
				haj=(haj%1000000000)*1000+haj/1000000000;//ratation
				te+=sol(hai,haj,map);
				haj=(haj%1000000000)*1000+haj/1000000000;//ratation
				
				map.put(hai,map.get(hai)+1);
				map.put(haj,map.get(haj)+1);
				res+=coef*te;
			}
		}
		System.out.println(res/3);
	}
	static long getHash(long a,long b,long c,long d){
		long mul=1000;
		long hash=((mul*a+b)*mul+c)*mul+d;
		hash=Math.min(hash,((mul*b+c)*mul+d)*mul+a);
		hash=Math.min(hash,((mul*c+d)*mul+a)*mul+b);
		hash=Math.min(hash,((mul*d+a)*mul+b)*mul+c);
		return hash;
	}
	static long sol(long ue,long sita,HashMap<Long,Integer> map){
		long d=ue%1000;
		ue/=1000;
		long c=ue%1000;
		ue/=1000;
		long b=ue%1000;
		ue/=1000;
		long a=ue;
		long h=sita%1000;
		sita/=1000;
		long g=sita%1000;
		sita/=1000;
		long f=sita%1000;
		sita/=1000;
		long e=sita;
		
		long hash=0;
		long res=1;
		//d c h g
		hash=getHash(d,c,h,g);
		if(map.containsKey(hash)){
			long kai=1;
			if(d==c && c==h && h==g) kai=4;
			else if(d==h && c==g) kai=2;
			res*=map.get(hash)*kai;
			map.put(hash,map.get(hash)-1);
		}else res=0;
		//c b e h
		hash=getHash(c,b,e,h);
		if(map.containsKey(hash)){
			long kai=1;
			if(c==b && b==e && e==h) kai=4;
			else if(c==e && b==h) kai=2;
			res*=map.get(hash)*kai;
			map.put(hash,map.get(hash)-1);
		}else res=0;
		//b a f e
		hash=getHash(b,a,f,e);
		if(map.containsKey(hash)){
			long kai=1;
			if(b==a && a==f && f==e) kai=4;
			else if(b==f && a==e) kai=2;
			res*=map.get(hash)*kai;
			map.put(hash,map.get(hash)-1);
		}else res=0;
		//a d g f
		hash=getHash(a,d,g,f);
		if(map.containsKey(hash)){
			long kai=1;
			if(a==d && d==g && g==f) kai=4;
			else if(a==g && d==f) kai=2;
			res*=map.get(hash)*kai;
			map.put(hash,map.get(hash)-1);
		}else res=0;
		
		//d c h g
		hash=getHash(d,c,h,g);
		if(map.containsKey(hash)){
			map.put(hash,map.get(hash)+1);
		}
		//c b e h
		hash=getHash(c,b,e,h);
		if(map.containsKey(hash)){
			map.put(hash,map.get(hash)+1);
		}
		//b a f e
		hash=getHash(b,a,f,e);
		if(map.containsKey(hash)){
			map.put(hash,map.get(hash)+1);
		}
		//a d g f
		hash=getHash(a,d,g,f);
		if(map.containsKey(hash)){
			map.put(hash,map.get(hash)+1);
		}
		return res;
	}
}