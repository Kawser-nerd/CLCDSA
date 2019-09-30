import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong();
		long xor0 = 0;
		List<Long> list = new ArrayList<>();
		List<Pair> pairs = new ArrayList<>();

		if(k==0) {
			for(int i=0;i<n;i++) {
				list.add(sc.nextLong());
			}
			long sum = 0;
				for(long l:list) {
					sum = (sum + xor(0,l));
				}
			System.out.println(sum);
			sc.close();
			return;
		}

		int logk = log(k);
		boolean[] kbit = new boolean[(int)logk+2];
		for(int i=0;i<n;i++) {
			list.add(sc.nextLong());
		}

		for(long l:list) {
			xor0 = (xor0 + xor(0,l));
		}

		int count = 0;
		for(long i=1;i<=k;i=i*2) {
			long sum = 0;
			for(long l:list) {
				sum = (sum + xor(i,l));
			}
			pairs.add(new Pair(i, sum-xor0));
			kbit[count] = (k/i)%2==1?true:false;
			count++;
		}

		//X=k?????
		long ans = xor0;
		for(int j=0;j<=logk;j++) {
			if(kbit[j]) {
				ans = ans+pairs.get(j).b;
			}
		}
		for(int i=0;i<=logk;i++) {
			long tmpans = xor0;
			//????1
			if(kbit[i]) {
				//??????k??????(j=i?0)
				for(int j=i+1;j<=logk;j++) {
					if(kbit[j]) {
						tmpans = tmpans+pairs.get(j).b;
					}
				}
				//?????????
				for(int j=0;j<i;j++) {
					if(pairs.get(j).b>0) {
						tmpans = tmpans + pairs.get(j).b;
					}
				}
				ans = ans>tmpans?ans:tmpans;
			}
			else {
				continue;
			}
		}
		sc.close();
		System.out.println(ans);
		//????????
	}


	static long xor(long j,long b) {
		long c = j>b?j:b;
		long sum = 0;
		for(long i=1;i<=c;i=i*2) {
			if(j%2!=b%2) {
				sum = sum + i;
			}
			j = j/2;
			b = b/2;
		}
		return sum;
	}

	static int log(long x, int base)
	{
	    return (int) (Math.log(x) / Math.log(base));
	}

	static int log(long x)
	{
		long exp = 2;
		int count = 0;
	    while(exp<=x) {
	    	exp = exp *2;
	    	count++;
	    }
	    return count;

	}

	static class Pair implements Comparable<Pair> {
	    long a,b;
	    public Pair(long a,long b) {
	        this.a = a;
	        this.b = b;
	    }

	    //(a,b)???
	    @Override
	    public boolean equals(Object o) {
	        if (o instanceof Pair) {
	            Pair p = (Pair) o;
	            return a == p.a && b == p.b;
	        }
	        return super.equals(o);
	    }

	    /*
	     * x.equals(y) ??? hashCode(x) == hashCode(y)??????????
	     * ??????????????????????????????????????????
	     */
//	    @Override
//	    public int hashCode() {
//	        return a ^ b;
//	    }

	    //?????
	    @Override
	    public int compareTo(Pair o) {
	        if (a != o.a) {
	            return Long.compare(a, o.a);
	        }
	        //???
	        return Long.compare(b, o.b);
	    }
	}

}