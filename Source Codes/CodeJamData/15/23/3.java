import java.util.*;
public class c {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t =  1; t<=T; t++)
	{
		System.out.print("Case #"+t+": ");
		int n = input.nextInt();
		PriorityQueue<Double> finish = new PriorityQueue<Double>();
		PriorityQueue<Hiker> lap = new PriorityQueue<Hiker>();
		for(int i = 0; i<n; i++)
		{
			int d = input.nextInt();
			int h = input.nextInt();
			int m = input.nextInt();
			for(int j = 0; j<h; j++)
			{
				int time = m+j;
				double ft = time * (360.0 - d) / 360;
				finish.add(ft);
				lap.add(new Hiker(ft+time, time));
			}
		}
		int size = lap.size();
		int res = size, count = size;
		//System.out.println(finish.size());
		while(!finish.isEmpty())
		{
			while(count < 2*size && lap.peek().time <= finish.peek())
			{
				//System.out.println(lap.peek().time+" "+finish.peek());
				Hiker h = lap.poll();
				count++;
				h.time += h.add;
				lap.add(h);
			}
			if(count == 2*size) break;
			count--;
			res = Math.min(res, count);
			double x= finish.poll();
			//System.out.println(x);
		}
		System.out.println(res);
	}
}
static class Hiker implements Comparable<Hiker>
{
	double time;
	double add;
	public Hiker(double tt, double aa)
	{
		time = tt; add = aa;
	}
	@Override
	public int compareTo(Hiker o) {
		// TODO Auto-generated method stub
		return Double.compare(time, o.time);
	}
}
}
