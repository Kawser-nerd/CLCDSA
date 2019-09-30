import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	long[] sosu = new long[N+1];
	for(int i = 0; i<=N; i++) {
	    int temp = i;
	    int cnt = 2;
	    while(temp > 1 && cnt<N) {
		while(temp%cnt == 0) {
		    sosu[cnt]++;
		    temp = temp/cnt;
		}
		cnt++;
	    }
	}
	//sosu???????????
	long ans = 0;
	HashMap<Integer,Long> map = new HashMap<Integer, Long>();

	long n74,n24,n14,n4,n2;
	for(int i=0; i<=N; i++) {
	    n74 = (map.get(74)==null)?0:map.get(74);
	    n24 = (map.get(24)==null)?0:map.get(24);
	    n14 = (map.get(14)==null)?0:map.get(14);
	    n4 = (map.get(4)==null)?0:map.get(4);
	    n2 = (map.get(2)==null)?0:map.get(2);
	    if(sosu[i] >= 74) map.put(74, n74+1);
	    if(sosu[i] >= 24) map.put(24, n24+1);
	    if(sosu[i] >= 14) map.put(14, n14+1);
	    if(sosu[i] >= 4) map.put(4, n4+1);
	    if(sosu[i] >= 2) map.put(2, n2+1);
	}

	n74 = (map.get(74)==null)?0:map.get(74);
	n24 = (map.get(24)==null)?0:map.get(24);
	n14 = (map.get(14)==null)?0:map.get(14);
	n4 = (map.get(4)==null)?0:map.get(4);
	n2 = (map.get(2)==null)?0:map.get(2);

	ans += n74;
	ans += n24*(n2-1);
	ans += n14*(n4-1);
	ans += (n4*(n4-1))/2 * (n2-2);
	System.out.println(ans);

    }
}