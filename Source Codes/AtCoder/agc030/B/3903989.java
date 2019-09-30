import java.util.*;
    public class Main {
    	public static void main(String[] args){
    		Scanner sc = new Scanner(System.in);
    		// ?????
    		long l = sc.nextLong();
		int n = sc.nextInt();
		ArrayList<Long> x = new ArrayList<>();
		for(int i = 1; i <= n; i++){
		    x.add(sc.nextLong());
		}
		Collections.sort(x);
		
    		// ??
		//System.out.println(burn(x, l, 0, n-1, 0));
		//		ArrayList<Long> path = burn2(x, l, 0, n-1, 0);
		//for(int i = n; i >= 1; i--){
		//if (path.get(i) == 1){
		//System.out.println("right");
	//}else{
	//		System.out.println("left");
	//	    }
	//	}
	//	System.out.println(path.get(0));
		System.out.println(burn3(x, l, n));
    	}

	private static long burn(ArrayList<Long> x1, long l1, int imin, int imax, long now){
	    if(imin == imax){
		long a = Math.abs(x1.get(imin) - now);
		if(a > l1 /2){
		    return a;
		}else{
		    return l1 - a;
		}
	    }else{
		long a = x1.get(imin) - now;
		if(a < 0){
		    a += l1;
		}
		long right = a + burn(x1, l1, imin+1, imax, x1.get(imin));

		a = now - x1.get(imax);
		if(a < 0){
		    a += l1;
		}
		long left = a + burn(x1, l1, imin, imax-1, x1.get(imax));

		if(right > left){
		    return right;
		}else{
		    return left;
		}
	    }
	}

	private static ArrayList<Long> burn2(ArrayList<Long> x1, long l1, int imin, int imax, long now){
	    if(imin == imax){
		ArrayList<Long> path = new ArrayList<>();
		long a = Math.abs(x1.get(imin) - now);
		if(a > l1 /2){
		    path.add(a);
		    if(x1.get(imin) > now){
			path.add((long)1);
		    }else{
			path.add((long)-1);
		    }
		    return path;
		}else{
		    path.add(l1 - a);
		    if(x1.get(imin) > now){
			path.add((long)-1);
		    }else{
			path.add((long)1);
		    }
		    return path;
		}
	    }else{
		long a = x1.get(imin) - now;
		if(a < 0){
		    a += l1;
		}
		ArrayList<Long> path_right = burn2(x1, l1, imin+1, imax, x1.get(imin));
		long right = a + path_right.get(0);

		a = now - x1.get(imax);
		if(a < 0){
		    a += l1;
		}
		ArrayList<Long> path_left = burn2(x1, l1, imin, imax-1, x1.get(imax));
		long left = a + path_left.get(0);

		if(right > left ||
		   right == left && path_right.get(path_right.size() -1) == -1){
		    path_right.set(0, right);
		    path_right.add((long)1);
		    return path_right;
		}else{
		    path_left.set(0, left);
		    path_left.add((long)-1);
		    return path_left;
		}
	    }
	}

	private static long burn3(ArrayList<Long> x1, long l1, int n){
	    ArrayList<Long> right = new ArrayList<>();
	    ArrayList<Long> left = new ArrayList<>();
	    long sum = 0;
	    right.add((long)0);
	    for(int i = 0; i < n; i++){
		sum += x1.get(i)*2;
		right.add(sum);
	    }
	    sum = 0;
	    left.add((long)0);
	    for(int i = n-1; i >= 0; i--){
		sum += (l1 - x1.get(i))*2;
		left.add(sum);
	    }
	    long ans = 0;
	    long ans1;
	    for(int i = 0; i < n; i++){
		if ((n-i)%2 == 0){
		    ans1 = right.get((n+i) / 2) - right.get(i) + left.get((n-i) / 2 -1) + (l1 - x1.get((n+i) / 2));
		    ans = Math.max(ans, ans1);
		    ans1 = left.get((n+i) / 2) - left.get(i) + right.get((n-i) / 2 -1) + x1.get((n-i) / 2 -1);
		    ans = Math.max(ans, ans1);
		}else{
		    ans1 = right.get((n+i-1) / 2) - right.get(i) + left.get((n-i-1) / 2) + x1.get((n+i-1) / 2);
		    ans = Math.max(ans, ans1);
		    ans1 = left.get((n+i-1) / 2) - left.get(i) + right.get((n-i-1) / 2) + (l1 - x1.get((n-i-1) / 2));
		    ans = Math.max(ans, ans1);
		}
	    }
	    return ans;
	}
    }