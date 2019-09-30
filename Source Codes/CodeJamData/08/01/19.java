import java.util.Comparator;


public class CompareUnit implements Comparator{
	public int compare(Object o1,Object o2)
	{
		Unit u1,u2;
		u1 = (Unit)o1;
		u2 = (Unit)o2;
		if(u1.turnTime<u2.turnTime)
			return -1;
		else if(u1.turnTime == u2.turnTime)
			return 0;
		else
			return 1;
	}

}
