import java.util.*;
import java.math.*;

public class Juice
{
	static final Scanner sc = new Scanner(System.in);
	static class ArraySet
	{
		int[][] count;
		int N;
		public ArraySet(int N)
		{
			this.N = N;
			count = new int[N+1][];
			for(int i=0;i<=N;i++)
				count[i] = new int[1<<i];
		}
		public void add(int num)
		{
			for(int i=N;i>=0;i--,num>>=1)
				count[i][num]++;
		}
		public void remove(int num)
		{
			for(int i=N;i>=0;i--,num>>=1)
				count[i][num]--;
		}
		public int lesser(int num)
		{
			int res = count[N][num];
			for(int i=N;i>0;i--,num>>=1)
			{
				if((num&1)==1)
					res += count[i][num^1];
			}
			return res;
		}
	}
	static class Person implements Comparable<Person>
	{
		int a, b, c, index;
		int whichOne;
		public Person(int a, int b, int c, int index)
		{
			this.a = a; this.b = b; this.c = c; this.index = index;
			whichOne = 0;
		}
		public int compareTo(Person p)
		{
			int diff = whichOne==0?a-p.a:b-p.b;
			return diff==0?index-p.index:-diff;
		}
	}
	public static void main(String[] args)
	{
		int cases = sc.nextInt();
		for(int caseNum=1;caseNum<=cases;caseNum++)
		{
			System.out.print("Case #"+caseNum+": ");
			int n = sc.nextInt();
			Person[] persons = new Person[n];
			for(int i=0;i<n;i++)
			{
				int a = sc.nextInt();
				int b = sc.nextInt();
				int c = sc.nextInt();
				persons[i] = new Person(a,b,c,i);
			}
			Arrays.sort(persons);
			TreeSet<Person> valid = new TreeSet<Person>();
			for(int i=0;i<n;i++)
			{
				persons[i].whichOne = 1;
				valid.add(persons[i]);
			}
			
			int res = 0;
			for(int i=0;i<n;i++)
			{
				int a = persons[i].a;
				ArraySet set = new ArraySet(16);
				for(Person p:valid)
					set.add(p.c);
				for(Person p:valid)
				{
					int c = 10000 - (a+p.b);
					if(c<0)
						break;
					res = Math.max(res, set.lesser(c));
					set.remove(p.c);
				}
				valid.remove(persons[i]);
			}
			System.out.println(res);
		}
	}
}
